#ifndef _D_LINKED_LIST_H
#define _D_LINKED_LIST_H
// 더미(dummy) 노드 링크드 리스트

#define TRUE 1
#define FALSE 0

typedef int LData;
typedef struct _n {
	LData data; // int data;
	struct _n* next;
}Node;

typedef struct _linkedList {
	Node* head; // 헤드 노드
	Node* cur; // 현재 노드
	Node* before;
	int numOfData; // 노드의 숫자 저장
	int (*comp)(LData d1, LData d2); // 함수 포인터
}LinkedList;

// 선언
typedef LinkedList List;
void ListInit(List* plist); // init : 초기화
void LInsert(List* plist, LData data);
int LFirst(List* plist, LData* pdata); // LData == int
int LNext(List* plist, LData* pdata);
LData LRemove(List* plist);
int LCount(List* plist);
void SetSortRule(List* plist, int (*comp)(LData d1, LData d2));

#endif
