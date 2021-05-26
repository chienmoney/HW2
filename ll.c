#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
#include"ll.h"
struct list{
    int num;
    struct list *next;
};
struct list* insert(struct list *last,int n){
    struct list *p;
    p=(struct list*)malloc(sizeof(struct list));
    p->num=n;
    last->next=p;
    p->next=NULL;
    return p;
}
int search(struct list *head,int n){
    struct list *k=head;
    while(k){
        if(k->num==n){
            return 0;
        }
        k=k->next;
    }
    return 1;
}
void ll(int data[],int srch[],int datacnt,int qcnt){
    printf("ll:\n");
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff1,diff2;
    gettimeofday(&start, NULL);/////////////////
    struct list *head;
    head=(struct list*)malloc(sizeof(struct list));
    head->num=data[0];
    head->next=NULL;
    struct list *last=head;
    for(int i=1;i<datacnt;i++){
        last=insert(last,data[i]);
    }
    gettimeofday(&end, NULL);/////////////////
    diff1 = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("building time: %f sec\n",diff1 / 1000000.0);
    gettimeofday(&start, NULL);/////////////////
    for(int k=0;k<qcnt;k++){
        int ans=search(head,srch[k]);
    }
    gettimeofday(&end, NULL);/////////////////
    diff2 = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("query time: %f sec\n",diff2 / 1000000.0);
}
