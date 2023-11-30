#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>

#define max 100000
int data[max];

int heap(int A[], int s, int i){
    int p = i;
    int left = (i * 2) + 1;
    int right = (i * 2) + 2;
    if(left < s && A[left]<A[p]){
        p = left;
    }
    if(right < s && A[right] < A[p]){
        p = right;
    }
    if(p!=i){
        int temp = A[i];
        A[i] = A[p];
        A[p] = temp;
        heap(A,s,p);
    }
}
int heapSorft(int A[],int s){
    for(int i = (s/2)-1; i >= 0; i--){
        heap(A,s,i);
    }
    for(int i = s-1;i>=0; i--){
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        heap(A,i,0);
    }
}
int main(){
    FILE *fd1, *fd2;
    fd1 = fopen("abc.txt","r");
    for(int i = 0;i<max;i++){
        fscanf(fd1,"%d\n",&data[i]);
    }
    heapSorft(data,max);
    fd2 = fopen("heap.txt","w");
    for(int j = 0;j<max;j++){
        fprintf(fd2,"%d\n",data[j]);
    }
    fclose(fd1);
    fclose(fd2);
}