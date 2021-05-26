#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include"bst.h"
#include"bs.h"
#include"arr.h"
#include"ll.h"
//#include"hash.h"
int data[1000000];
int srch[100000];
void datamk(int n){ 
    int i;
	srand(time(NULL));
	data[0]=rand();
    for(i=1;i<n;i++){
        data[i]=rand();
        for(int j=0;j<=i;j++){
            if(data[i]==data[j]){
                i--;
            }
            break;
        }
    }
}
void srchmk(int n){
    int i;
	srand(time(NULL));
    srch[0]=rand();
    for(i=1;i<n;i++){
        srch[i]=rand();
        for(int j=0;j<=i;j++){
            if(srch[i]==srch[j]){
                i--;
            }
            break;
        }
    }
}
int main(int argc,char *argv[]){
    int datacnt;
    int qcnt;
    if(strcmp(argv[2],"1e4")==0){   //ex   [0]./a.out [1]-d [2]1e4 [3]-q [4]1e3 [5]-bst [6]-arr
        datacnt=10000;
        datamk(10000);
    }
    else if(strcmp(argv[2],"1e5")==0){
        datacnt=100000;
        datamk(100000);
    }
    else if(strcmp(argv[2],"1e6")==0){
        datacnt=1000000;
        datamk(1000000);
    }
    if(strcmp(argv[4],"1e3")==0){   //ex   [0]./a.out [1]-d [2]1e4 [3]-q [4]1e3 [5]-bst [6]-arr
        qcnt=1000;
        srchmk(1000);
    }
    else if(strcmp(argv[4],"1e4")==0){
        qcnt=10000;
        srchmk(10000);
    }
    else if(strcmp(argv[4],"1e5")==0){
        qcnt=100000;
        srchmk(100000);
    }
    int ways[argc-5] = {0};
    for(int i = 0; i < argc-5; i++){
        if(strcmp(argv[i+5], "-bst") == 0) ways[i] = 1;
        if(strcmp(argv[i+5], "-bs") == 0) ways[i] = 2;
        if(strcmp(argv[i+5], "-arr") == 0) ways[i] = 3;
        if(strcmp(argv[i+5], "-ll") == 0) ways[i] = 4;
        if(strcmp(argv[i+5], "-hash") == 0) ways[i] = 5;
    }
    for(int j=0;j<argc-5;j++){
        if(ways[j]==1)bst(data,srch,datacnt,qcnt);
        if(ways[j]==2)bs(data,srch,datacnt,qcnt);
        if(ways[j]==3)arr(data,srch,datacnt,qcnt);
        if(ways[j]==4)ll(data,srch,datacnt,qcnt);
        //if(ways[j]==5)hash(data,srch,datacnt,qcnt);
    }
    return 0;
}
