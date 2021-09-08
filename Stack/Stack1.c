#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 5	//스택에 넣을 수 있는 최대 사이즈

void push(int);	//스택에 데이터 1개 삽입
void pop();		//스택에 데이터 1개 삭제
void display();	//스택에 있는 데이터 보여주기

int stack[SIZE];
int top = -1;//스택에 저장할 위치

int main()
{
	int val, choice;
	printf("\n---------------------Menu---------------------");
	while (1)
	{
		printf("\n\n1.push     2.pop      3.display      4.exit\n");
		printf("Choice : ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1: // 스택에 push
			printf("데이터를 입력하세요 : ");
			scanf("%d", &val);
			push(val);
			break;
		case 2: // 스택에 pop
			pop();
			break;
		case 3: // 스택 내용 display
			display();
			break;
		case 4: // 프로그램 종료 exit
			return 0;
		default:
			printf("다시 입력하세요.");
		}
	}

	return 0;
}

// (참고) 쪽지시험, 암기 필요
void push(int val) 
{
	if (top == SIZE - 1) // top >= size - 1
		printf("스택이 가득 참\n");
	else
		stack[++top] = val;
}

// (참고) 쪽지시험, 암기 필요
void pop() 
{
	if (top == -1)
		printf("스택이 비었음\n");
	else
		printf("%d이(가) 삭제됨\n", stack[top--]);
}

void display() 
{
	if (top == -1)
		printf("스택이 비었음\n");
	else
		for (int i = top; i >= 0; i--)
			printf("%4d", stack[i]);
	printf("\n");
}
