// Queue 구현
// FIFO, front, back, Enqueue, Dequeue

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int queue[5];

void menuf() 
{
	printf("\n1. 큐에 삽입   2. 큐에서 삭제\n");
	printf("3. 내용 보기   4. 종료\n");
}

void Enqueue(int* back, int item) // 큐에 삽입
{ 
	if (*back == 4) { // 현재 큐의 사이즈는 5, back이 4라면 가득 찬 것
		printf("큐가 가득참\n");
		return;
	}
	queue[++ * back] = item; // back에 1을 더한 인덱스의 배열에 삽입
}

int Dequeue(int* front, int back) // 큐에 삭제
{
	if (*front == back) // 프론트와 백이 같다면 (데이터가 없다면)
	{
		return -1; // -1이라면 큐가 비었다고 생각
		// 보통 0이 리턴되면 정상적인 종료
	}
	return queue[++ * front]; // front에 1을 더함
								// 실제로 삭제하는 것이 아니고, 인덱스를 옮겨 아예 쓰지 않음
}

void Display(int front, int back) {
	if (front == back)
		printf("큐가 비었음\n");
	for (int i = front + 1; i <= back; i++)
		printf("%4d", queue[i]);
}

int main(void)
{
	// 큐, 스택 모두 1차원 배열로 구현
	int front = -1, back = -1;
	// queue : front, back // stack : top
	int menu, item;
	while (1) {
		menuf();
		scanf("%d", &menu);
		switch (menu) {
		case 1: // 큐에 데이터 또는 job 삽입
			scanf("%d", &item);
			Enqueue(&back, item);
			break;
		case 2: // 큐에서 삭제
			item = Dequeue(&front, back);
			if (item == -1)
				printf("큐가 비었음");
			else
				printf("%d가 삭제됨\n", item);
			break;
		case 3: // 큐의 내용 보여주기
			Display(front, back);
			break;
		case 4:
			return 0;
		default:
			printf("다시 입력하세요.");
		}
	}
}
