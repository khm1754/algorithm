#include<stdio.h>

struct Node
{
	int x;
	Node* next;
};

Node buf[110];
int stackCnt;
int bufCnt;
Node* head;

Node* myAlloc(int value, Node* next)
{
	buf[bufCnt].x = value;
	buf[bufCnt].next = next;
	return &buf[bufCnt++];
}

void push(int value)
{
	stackCnt++;
	head = myAlloc(value, head);
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
		scanf(" %c", &cmd);
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