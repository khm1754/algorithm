#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#define maxlen 100000
int data[maxlen];

void bubble() {
   int i, j, temp;
   int cnt;
   clock_t start,end;
   for (i = 0; i < maxlen; i++) {
      for (j = 0; j < maxlen - i - 1; j++) {
         if (data[j] > data[j + 1]) {
            temp = data[j];
            data[j] = data[j + 1];
            data[j + 1] = temp;
         }
      }
   }
}

int main() {
   clock_t start,end;
   FILE* fd1, * fd3;
   fd1 = fopen("abc.txt", "r");
   for (int k = 0; k < maxlen; k++) {
      fscanf(fd1, "%d\n", &data[k]);
   }
   start = clock();
   bubble();
   end = clock();
   fd3 = fopen("bubbuble.txt", "w");
   for (int i = 0; i < maxlen; i++) {
      fprintf(fd3, "%d\n", data[i]);
   }
   printf("%f",(double)(end-start)/CLOCKS_PER_SEC);
   fclose(fd1);
   fclose(fd3);
}