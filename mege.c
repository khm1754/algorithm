#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define maxlen 100000
int data[maxlen];
int arr[maxlen];

int mergeSorft(int A[], int p, int q, int r) {
   int x = p;
   int y = q + 1;
   int k = p;
   while (x <= q && y <= r) {
      if (A[x] >= A[y]) {
         arr[k++] = A[x++];
      }
      else {
         arr[k++] = A[y++];
      }
   }
   if (x > q) {
      for (int i = y; i <= r; i++) {
         arr[k++] = A[i];
      }
   }
   else {
      for (int i = x; i <= q; i++) {
         arr[k++] = A[i];
      }
   }for (int i = p; i <= r; i++) {
      A[i] = arr[i];
   }
}
int merge(int A[], int p, int r) {
   if (r <= p) {
      return;
   }
   int q = (r + p) / 2;
   merge(A, p, q);
   merge(A, q + 1, r);
   mergeSorft(A, p, q, r);
}
int main() {
   FILE* fd1, * fd3;
   fd1 = fopen("out.txt", "r");
   for (int k = 0; k < maxlen; k++) {
      fscanf(fd1, "%d\n", &data[k]);
   }
   merge(data, 0, maxlen - 1);
   fd3 = fopen("mergeSorft.txt", "w");
   for (int i = 0; i < maxlen; i++) {
      fprintf(fd3, "%d\n", data[i]);
   }
   fclose(fd1);
   fclose(fd3);
}