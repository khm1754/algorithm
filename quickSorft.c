#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max 100000
int data[max];

// 퀵 정렬을 수행하는 함수
void quickSort(int arr[], int left, int right) {
    int i = left;
    int j = right; // 왼쪽 인덱스와 오른쪽 인덱스
    int pivot = arr[(left + right) / 2]; // 피벗은 배열 중간 값으로 설정

    // 분할 과정
    while (i <= j) {
        // 피벗보다 큰 값을 찾을 때까지 왼쪽에서 오른쪽으로 이동
        while (arr[i] < pivot)
            i++;
        // 피벗보다 작은 값을 찾을 때까지 오른쪽에서 왼쪽으로 이동
        while (arr[j] > pivot)
            j--;
        // 찾은 두 값의 위치를 교환
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    // 재귀적으로 정렬 과정 수행
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
int main(){
    FILE *fd1, *fd2;
    fd1 = fopen("abc.txt","r");
    for(int i = 0; i<max;i++){
        fscanf(fd1, "%d\n",&data[i]);
    }
    quickSort(data,0,max-1);
    fd2 = fopen("quick12314.txt","w");
    for(int j = 0; j<max; j++){
        fprintf(fd2,"%d\n",data[j]);
    }
    fclose(fd1);
    fclose(fd2);
}