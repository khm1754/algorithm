#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

struct node {
	char ch;
	node* next;
};

int N;
node* head;
node* tail;
node* cur;

void insert_node(char str) {
	node* newNode = new node();
	newNode->ch = str;
	newNode->next = cur->next;
	cur->next = newNode;
	cur = newNode;
	if (newNode->next == NULL) {
		tail = newNode;
	}
}

void input_data() {
	char* str = new char[100000 + 10];
	scanf("%s", str);
	scanf("%d", &N);
	head = tail = cur = new node();
	for (int i = 0; str[i] != '\0'; i++) {
		insert_node(str[i]);
	}
	delete[] str;
}
void solve() {
	char cmd;
	for (int i = 0; i < N; i++) {
		scanf(" %c", &cmd);
		switch (cmd) {
		case 'i':
		{
			char in;
			scanf(" %c", &in);
			insert_node(in);
			break;
		}
		case 'P':
		{
			if (head != NULL) {
				char data = head->ch;
				node* tmp = head;
				head = head->next;
				delete tmp;
				printf("%c\n", data);
			}
			break;
		}
		case 'S': 
		{
			char in;
			scanf(" %c", &in);
			int cnt = 1, f = 0;
			node* tmp = head;
			while (tmp != NULL) {
				if (strcmp(&tmp->ch, &in) == 0) {
					f = 1;
					break;
				}
				else {
					cnt++;
					tmp = tmp->next;
				}
			}
			if (f) {
				printf("%d\n", cnt);
			}
			else {
				printf("0\n");
			}
			break;
		}
		case 'D':
		{
			int c;
			scanf("%d", &c);
			node* tmp, * h;
			h = head;
			if (c != 1) {
				for (int i = 0; i < c - 1; i++) {
					h = h->next;

				}
				tmp = h->next->next;
				delete h->next;
				h->next = tmp;
			}
			else {
				head = head->next;
				delete h;
			}
			break;
		}
		case 'T':
		{
			node* tmp = head;
			while(tmp != tail) {
				printf("%c", tmp->ch);
				tmp = tmp->next;
			}
			printf("%c", tmp->ch);
			break;
		}
		}
	}
}
void output_data() {
	node* out = head;
	while (out != NULL) {
		printf("%c", out->ch);
		out = out->next;
	}
}

int main() {
	input_data();
	solve();
	output_data();
	return 0;
}