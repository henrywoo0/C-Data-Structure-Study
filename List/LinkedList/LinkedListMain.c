#include <stdio.h>
#include "List.h"

// ���̳��
int MySort(int n1, int n2) { // ��������
	if (n1 < n2)
		return 0; // �� �ٲ۴�
	else
		return 1; // �ٲ۴�
}

int main(void) {
	List list;
	int data;
	ListInit(&list);
	SetSortRule(&list, MySort); // ���� ���� ���
	
	LInsert(&list, 1); LInsert(&list, 1);
	LInsert(&list, 2); LInsert(&list, 2);
	LInsert(&list, 3); LInsert(&list, 1);
	LInsert(&list, 7); LInsert(&list, 6);

	printf("���� �������� �� : %d \n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d ", data);
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	// ���� 2�� �˻��Ͽ� ��� ����
	if (LFirst(&list, &data)) {
		if (data == 2)
			LRemove(&list);
		while (LNext(&list, &data)) {
			if (data == 2)
				LRemove(&list);
		}
	}

	printf("���� �������� �� : %d \n", LCount(&list));

	return 0;
}