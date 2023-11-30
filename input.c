#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define maxlen 100000
int data[maxlen];

void inputFile() {
   int i, j, temp;
   for (i = 1; i < maxlen; i++) {
      temp = data[i];
      for (j = i-1; j >=0 && data[j]>temp; j--) {
         data[j + 1] = data[j];
         
      }
      data[j+1] = temp;
   }
}
int main() {
   FILE* fd1, * fd2;
   fd1 = fopen("abc.txt", "r");
   for (int k = 0; k < maxlen; k++) {
      fscanf(fd1, "%d\n", &data[k]);
   }
   inputFile();
   fd2 = fopen("input.txt", "w");
   for (int i = 0; i < maxlen; i++) {
      fprintf(fd2, "%d\n", data[i]);
   }
   fclose(fd1);
   fclose(fd2);
}