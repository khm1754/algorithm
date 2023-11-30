#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int x;
    struct Node* next;
};

struct Node buf[110];
int stackCnt;
int bufCnt;
struct Node* head;
struct Node* tail;

struct Node* myAlloc(int value, struct Node* next)
{
    buf[bufCnt].x = value;
    buf[bufCnt].next = next;
    return &buf[bufCnt++];
}
        
void push(int value)
{
    stackCnt++;
    if (stackCnt == 1) {
        head = myAlloc(value, NULL); 
        tail = head;
    }
    else {
        tail->next = myAlloc(value, NULL);
        tail = tail->next;
    }
}

void pop()
{
    stackCnt--;
    head = head->next;
}

int top()
{
    return head->x;
}

int main()
{
    //freopen("Text.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    char cmd;
    int num;
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &cmd);
        if (cmd == 'i') {
            scanf("%d", &num);
            push(num);
        }
        if (cmd == 'c') {
            printf("%d\n", stackCnt);
        }
        if (cmd == 'o') {
            if (stackCnt == 0) printf("empty\n");
            else if (stackCnt > 0) {
                printf("%d\n", top());
                pop();
            }
        }
    }
    return 0;
}