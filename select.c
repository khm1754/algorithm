#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define maxlen 100000
int data[maxlen];

int sel(){
    int i, j;
    int temp = 0;
    int index;
    for(i = 0; i < maxlen; i++){
        int min = INT_MAX;
        for(j = i; j < maxlen; j++){
            if(min > data[j]){
                min = data[j];
                index = j;
            }
        }
        temp = data[i];
        data[i] = data[index];
        data[index] = temp;
    }
}
int main() {
   FILE* fd1, * fd2;
   fd1 = fopen("abc.txt", "r");
   for (int k = 0; k < maxlen; k++) {
      fscanf(fd1, "%d\n", &data[k]);
   }
   sel();
   fd2 = fopen("sel.txt", "w");
   for (int i = 0; i < maxlen; i++) {
      fprintf(fd2, "%d\n", data[i]);
   }
   fclose(fd1);
   fclose(fd2);
}