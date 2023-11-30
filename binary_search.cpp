#include <stdio.h>

struct st {
    char ch;
    st* next;
    st* prev;
};

int N;
st* head; // 맨 첫 글자의 위치
st* tail;
st* cur; // 현재 위치

void solve() {
    int i;
    char cmd;
    for (i = 1; i <= N; i++) {
        scanf(" %c", &cmd);
        switch (cmd) {
            case 'L':
                if (cur->prev != head)
                    cur = cur->prev;
                break;
            case 'D':
                if (cur->next != tail)
                    cur = cur->next;
                break;
            case 'B':
                if (cur->prev != head)
                    delete_node();
                break;
            case 'P':
                scanf(" %c", &cmd);
                insert_node(cmd);
                break;
        }
    }
}

void output_data() {
    cur = head->next;
    while (cur != tail) {
        printf("%c", cur->ch);
        st* prevNode = cur->prev;
        delete cur;
        cur = prevNode->next;
    }
}

void insert_node(char ch) {
    st* newNode = new st();
    newNode->ch = ch;
    newNode->prev = cur;
    newNode->next = cur->next;

    if (cur->next != NULL)
        cur->next->prev = newNode;
    cur->next = newNode;
    cur = newNode;
}

void delete_node() {
    st* prevNode = cur->prev;
    prevNode->prev->next = cur;
    cur->prev = prevNode->prev;
    delete prevNode;
}

void input_data() {
    int i;
    char* str = new char[100000 + 10];
    scanf("%s", str);
    scanf("%d", &N);

    head = new st();
    cur = head;
    tail = new st();

    head->next = tail;
    tail->prev = head;

    for (i = 0; str[i] != 0; i++) {
        insert_node(str[i]);
    }

    delete[] str;
}

int main() {
    input_data();
    solve();
    output_data();
    return 0;
}