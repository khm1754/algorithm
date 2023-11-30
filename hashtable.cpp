#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10000

struct Node {
    int x;
    char name[100];
    Node* next;
};

Node buf[20000];

int bufCnt;
Node* head;
Node* last;

Node* myAlloc(int value, Node* next)
{
    buf[bufCnt].x = value;
    buf[bufCnt].next = next;
    return &buf[bufCnt++];
}

void addNode(char* value) {
    Node* newNode = myAlloc(0, NULL);
    for(int i = 0; value[i] != '\0'; i++){
        newNode->name[i] = value[i];
    }
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        last = newNode;
    }
    else {
        last->next = newNode;
        last = newNode;
    }
}

int search(char* value) {
    Node* cur = head;
    while (cur != NULL) {
        if (strcmp(cur->name, value) == 0) {
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

int del(char* value) {
    Node* cur = head;
    Node* prev = NULL;

    while (cur != NULL) {
        if (strcmp(cur->name, value) == 0) {
            if (prev == NULL) {
                head = cur->next;
            }
            else {
                prev->next = cur->next;
            }
            free(cur);
            return 1; // 데이터 삭제 성공
        }
        prev = cur;
        cur = cur->next;
    }
    return 0; // 데이터 삭제 실패 (찾지 못함)
}

int hash(char key[]) {
    int hashCode = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hashCode = hashCode * 26 + (key[i] - 'A');
    }
    return hashCode % TABLE_SIZE;
}

int main()
{
    char cmd;
    char name[100];
    while (1) {
        printf("명령어: ");
        scanf(" %c", &cmd);

        switch (cmd)
        {
        case 'i':
            printf("Key 입력: ");
            scanf("%s", name);
            addNode(name);
            break;
        case 's':
            printf("Key 입력: ");
            scanf("%s", name);
            if (search(name)) {
                printf("찾았습니다.\n");
            }
            else {
                printf("못찾았습니다.\n");
            }
            break;
        case 'd':
            printf("Key 입력: ");
            scanf("%s", name);
            if (del(name)) {
                printf("데이터가 삭제되었습니다.\n");
            }
            else {
                printf("데이터를 못찾았습니다.\n");
            }
            break;
        default:
            printf("올바른 명령어를 입력하세요.\n");
            break;
        }
    }

    return 0;
}
