#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max 100000
int data[max];

// �� ������ �����ϴ� �Լ�
void quickSort(int arr[], int left, int right) {
    int i = left;
    int j = right; // ���� �ε����� ������ �ε���
    int pivot = arr[(left + right) / 2]; // �ǹ��� �迭 �߰� ������ ����

    // ���� ����
    while (i <= j) {
        // �ǹ����� ū ���� ã�� ������ ���ʿ��� ���������� �̵�
        while (arr[i] < pivot)
            i++;
        // �ǹ����� ���� ���� ã�� ������ �����ʿ��� �������� �̵�
        while (arr[j] > pivot)
            j--;
        // ã�� �� ���� ��ġ�� ��ȯ
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    // ��������� ���� ���� ����
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