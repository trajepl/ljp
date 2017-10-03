// prim
void prim(Graph g, int v0, int *sum) {
    int lowcost[maxSize], vset[maxSize], v;
    int i, j, k, min;

    for(int i = 1; i <= g.n; i++) {
        lowcost[i] = g.edges[v0][i];
        vset[i] = 0;
    }
    vset[v0] = 1;
    sum = 0;
    for(int i = 1; i < g.n; i++) {
        min = INF;
        for(j = 1; j <= g.n; j++) {
            if(vset[j] == 0 && lowcost[j] < min) {
                min = lowcost[j]; k = j;
            }
        }
        vset[k] = 1;
        v = k;
        sum += min;

        // update lowcost array
        for(j = 1; j <= g.n; j++) {
            if(vset[j] = 0 && g.edges[v][j] < lowcost[j]) 
                lowcost[j] = g.edges[v][j];
        }
    }

}
// kruskal & union-find
typedef struct {
    int a, b; // a -- b: two nodes have edge
    int w     // wight of edge
} Road;

Road road[maxSize];
int v[maxSize]; // union-find array

int getRoot(int a) {
    while(a != v[a]) a = v[a];
    return a;
}

void kruskal(Graph g, int *sum, Road road[]) {
    int i;
    int N, E, a, b;
    N = g.n; E = g.e;
    sum = 0;

    for(int i = 1; i < N; i++) v[i] = i;
    sort(road, E);  // sort by wight of edge

    for(int i = 1; i < E; i++) {
        a = getRoot(road[i], a);
        b = getRoot(road[i], b);
        if(a != b) {
            v[a] = b;
            sum += road[i].w;
        }
    }
}

