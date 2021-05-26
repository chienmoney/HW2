#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
#include"bst.h"
struct node{
    int num;
    struct node *left;
    struct node *right;
};
int find(struct node *root, int key){
	if(root == NULL)
	{
		return -1;
	}
	else if(root->num == key)
	{
		return 0;
	}
	else if(root->num > key)
	{
		return find(root->left, key);
	}
	else if(root->num < key)
	{
		return find(root->right, key);
	}
}
struct node *BSTinsert(struct node *root, int key){
	if(root == NULL)
	{
		root = (struct node*)malloc(sizeof(struct node));
		root->left = NULL;
		root->right = NULL;
		root->num = key;
		return root;
	}
	if(root->num > key)
	{
		root->left = BSTinsert(root->left, key);
	}
	else
	{
		root->right = BSTinsert(root->right, key);
	}
	return root;
}

void bst(int data[],int srch[],int datacnt,int qcnt){
    printf("bst:\n");
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff1,diff2;
    gettimeofday(&start, NULL);/////////////////
    ///////////build////////
    struct node *root;
    root=NULL;
    for(int i=0;i<datacnt;i++){
        struct node *p=BSTinsert(root,data[i]);
    }
    gettimeofday(&end, NULL);/////////////////
    diff1 = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("building time: %f sec\n",diff1 / 1000000.0);
    gettimeofday(&start, NULL);/////////////////
    //////search////////
    for(int k=0;k<qcnt;k++){
        int ans=find(root,srch[k]);
    }
    gettimeofday(&end, NULL);/////////////////
    diff2 = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("query time: %f sec\n",diff2 / 1000000.0);
}
