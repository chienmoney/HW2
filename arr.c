#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
#include"arr.h"
void arr(int data[],int srch[],int datacnt,int qcnt){
    printf("arr:\n");
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff1,diff2;
    gettimeofday(&start, NULL);/////////////////
    int arr[datacnt];
    for(int i=0;i<datacnt;i++){
        arr[i]=data[i];
    }
    gettimeofday(&end, NULL);/////////////////
    diff1 = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("building time: %f sec\n",diff1 / 1000000.0);
    gettimeofday(&start, NULL);/////////////////
    for(int j=0;j<qcnt;j++){
        for(int k=0;k<datacnt;k++){
            if(arr[k]==srch[j]){
                break;
            }
        }
    }
    gettimeofday(&end, NULL);/////////////////
    diff2 = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("query time: %f sec\n",diff2 / 1000000.0);
}
