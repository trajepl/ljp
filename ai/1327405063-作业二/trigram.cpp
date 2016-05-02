#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_ASSERT_H
#include <assert.h>
#endif

#ifdef HAVE_GETOPT_H
#include <getopt.h>
#endif

#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
#include <climits>

#include "../sim_fmerge.h"
#include "idngram.h"
#include "idngram_merge.h"

template<int N>
void WriteOut(FILE* out, std::map<CSIM_Idngram<N>, unsigned int> & map)
{
    typedef typename std::map<CSIM_Idngram<N>,
                              unsigned int>::iterator TMapIterator;
    TMapIterator its = map.begin(), ite = map.end();
    for (; its != ite; ++its) {
        fwrite(its->first.ids, sizeof(TSIMWordId), N, out);
        fwrite(&(its->second), sizeof(unsigned int), 1, out);
    }
    map.clear();
}

template<int N>
void ProcessingRead(FILE *fp,
               FILE* swap,
               std::vector<long>& para_offsets,
               size_t paraMax)
{
    typedef CSIM_Idngram<N> TNgram;
    typedef typename std::map<CSIM_Idngram<N>, unsigned int> TMap;

    TMap map;
    TNgram ngram;

    TSIMWordId* ids = ngram.ids;
    fread(ids, sizeof(TSIMWordId), N - 1, fp);
    while (fread(ids + N - 1, sizeof(TSIMWordId), 1, fp) == 1) {
        assert(map[ngram] < UINT_MAX);
        ++map[ngram];
        if (map.size() >= paraMax) {
            printf("."); fflush(stdout);
            WriteOut(swap, map);
            para_offsets.push_back(ftell(swap));
        }
        for (int i = 0; i < N - 1; ++i) ids[i] = ids[i + 1];
    }
    if (map.size() > 0) {
        printf("."); fflush(stdout);
        WriteOut(swap, map);
        para_offsets.push_back(ftell(swap));
    }
}

static struct option long_options[] =
{
    { "NMax", 1, 0, 'n' },
    { "out", 1, 0, 'o' },
    { "swap", 1, 0, 's' },
    { "para", 1, 0, 'p' },
    { 0, 0, 0, 0 }
};

static int N = 0;
static int paraMax = 0;
static char* output = NULL;
static char* swapfile = NULL;

static void getParameters(int argc, char* const argv[])
{
    int option_index = 0;
    int c;
    while ((c =
                getopt_long(argc, argv, "p:n:s:o:", long_options,
                            &option_index)) != -1) {
        switch (c) {
        case 'n':
            N = atoi(strdup(optarg));
            break;
        case 'p':
            paraMax = atoi(strdup(optarg));
            break;
        case 'o':
            output = strdup(optarg);
            break;
        case 's':
            swapfile = strdup(optarg);
            break;
        default:
            ShowUsage();
        }
    }
    if (N < 1 || N > 3 || paraMax < 1024 || output == NULL || swapfile == NULL)
        ShowUsage();
}

static std::vector<long> para_offsets;

int main(int argc, char* argv[])
{
    getParameters(argc, argv);
    FILE *swap = fopen(swapfile, "wb+");
    FILE *out = fopen(output, "wb+");
    if (optind >= argc) ShowUsage();
    while (optind < argc) {
        printf("Processing %s:", argv[optind]); fflush(stdout);
        FILE *fp = fopen(argv[optind], "rb");
        switch (N) {
        case 1:
            ProcessingRead<1>(fp, swap, para_offsets, paraMax);
            break;
        case 2:
            ProcessingRead<2>(fp, swap, para_offsets, paraMax);
            break;
        case 3:
            ProcessingRead<3>(fp, swap, para_offsets, paraMax);
            break;
        }
        fclose(fp);
        printf("\n"); fflush(stdout);
        ++optind;
    }
    printf("Merging..."); fflush(stdout);
    switch (N) {
    case 1:
        ProcessingIdngramMerge<1>(swap, out, para_offsets);
        break;
    case 2:
        ProcessingIdngramMerge<2>(swap, out, para_offsets);
        break;
    case 3:
        ProcessingIdngramMerge<3>(swap, out, para_offsets);
        break;
    }
    printf("Done\n"); fflush(stdout);
    fclose(out);
    fclose(swap);
    return 0;
}
