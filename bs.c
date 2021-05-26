#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
#include"bs.h"
int compare(const void *a, const void *b){
      int c = *(int *)a;
      int d = *(int *)b;
      if(c < d) {return -1;}               //傳回 -1 代表 a < b
      else if (c == d) {return 0;}      //傳回   0 代表 a = b
      else return 1;                          //傳回  1 代表 a>b
}
void bs(int data[],int srch[],int datacnt,int qcnt){
    printf("bs:\n");
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff1,diff2;
    gettimeofday(&start, NULL);/////////////////
    int bs[datacnt];
    for(int i=0;i<datacnt;i++){
        bs[i]=data[i];
    }
    qsort(bs,datacnt,sizeof(int),compare);
    gettimeofday(&end, NULL);/////////////////
    diff1 = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("building time: %f sec\n",diff1 / 1000000.0);
    gettimeofday(&start, NULL);/////////////////
    for(int k=0;k<qcnt;k++){
        int w=binarysearch(bs,srch[k],datacnt);
    }
    gettimeofday(&end, NULL);/////////////////
    diff2 = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("query time: %f sec\n",diff2 / 1000000.0);
}
int binarysearch(int data[], int num, int n){
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (data[mid] == num)
        {
            return mid;
        }
        else if (data[mid] > num)
        {
            high = mid - 1;
        }
        else if (data[mid] < num)
        {
            low = mid + 1;
        }
    }

    return -1;
}
