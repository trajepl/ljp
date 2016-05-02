#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_Length 1000

bool ischar(char c){
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return true;
	return false;
}

int cmp ( const void *a , const void *b )  
{  
	return strcmp((char *)a, (char *)b);  
} 

//
void reverse(FILE *fp)
{
	 char ch;
	 if ((ch=fgetc(fp))!= EOF) reverse(fp);
	 if (ch!= EOF) printf("%c",ch);
}

int main() 
{
	FILE* file;
	if((file = fopen("test.txt", "r+")) == NULL) {
		printf("Cannot open the file!\n");
		return -1;
	}
	
	char c;
	char swap[MAX_Length][20];
	int i = 0;
	int j = 0;
	bool flag = false;

	//from a article delete ' '|| ','||'.?!@..' and so on 
	while(!feof(file)) {
		c = fgetc(file);
	//	printf("%c	", c);
		if(ischar(c)){
			flag = true;
			if(c >= 'A' && c <= 'Z')
				swap[i][j++] = c - 'A' + 'a';
			else
				swap[i][j++] = c;
		}else{
			if(flag){	
				flag = false;
				i++;		
				j = 0;
			}
		}
	}

	int length_freq[MAX_Length];
	qsort(swap,i, sizeof(swap[0]), cmp);

	int m,n;
	int count = 1;
	bool flag2 = false;
	for( m = 0; m < i; m++) {
		count = 1;
		for(n = m + 1; n < i; n++){
			if(strcmp(swap[m], swap[n]) == 0){
				count++;
			}else{
				m = n;
				break;
			}
		}
		printf("%d: %s\n", count, swap[m-1]);
	}
	rewind(file);
	reverse(file);	
	printf("\n");

	fclose(file);	
	return 0;
}
