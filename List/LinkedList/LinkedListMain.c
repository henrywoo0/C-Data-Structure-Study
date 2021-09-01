#include <stdio.h>
#include "List.h"

// 더미노드
int MySort(int n1, int n2) { // 오름차순
	if (n1 < n2)
		return 0; // 안 바꾼다
	else
		return 1; // 바꾼다
}

int main(void) {
	List list;
	int data;
	ListInit(&list);
	SetSortRule(&list, MySort); // 정렬 기준 등록
	
	LInsert(&list, 1); LInsert(&list, 1);
	LInsert(&list, 2); LInsert(&list, 2);
	LInsert(&list, 3); LInsert(&list, 1);
	LInsert(&list, 7); LInsert(&list, 6);

	printf("현재 데이터의 수 : %d \n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d ", data);
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	// 숫자 2를 검색하여 모두 삭제
	if (LFirst(&list, &data)) {
		if (data == 2)
			LRemove(&list);
		while (LNext(&list, &data)) {
			if (data == 2)
				LRemove(&list);
		}
	}

	printf("현재 데이터의 수 : %d \n", LCount(&list));

	return 0;
}