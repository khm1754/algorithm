#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define maxlen 100000
int data[maxlen];

void create10() {
    int i;
    for (i = 0; i < maxlen; i++) {
        data[i] = i + 1;
    }
}
void swap(int a, int b) {
    int c;
    c = data[a];
    data[a] = data[b];
    data[b] = c;
}
void suffle() {
    int i;
    int a, b;
    for (i = 0; i < maxlen; i++) {
        do {
            a = rand() % maxlen * rand() % maxlen;
            b = rand() % maxlen * rand() % maxlen;
            a = a % maxlen;
            b = b % maxlen;
        } while (a == b);
        swap(a, b);
    }
}
int main() {
    FILE* fd = fopen("abc.txt", "w");
    create10();
    suffle();
    for (int i = 0; i < maxlen; i++) {
        fprintf(fd, "%d\n", data[i]);
    }
    fclose(fd);
}
/*
시프트 or 연산 방법도 있음
*/