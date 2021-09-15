#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// 이분 탐색, 이진 탐색 : 정렬된 배열 속 데이터 찾기

int arr[100] = { 5, 7, 33, 66, 67, 88, 99, 120, 134, 156, 201 };
int n, k; // k는 내가 찾을 숫자

int binarySearch(int s, int e, int* count) { // 매개변수 start, end
	while (s <= e) {
		(*count)++;
		int m = (s + e) / 2; // m은 middle
		if (arr[m] == k)
			return m; // 찾은 배열의 인덱스(위치)
		if (arr[m] > k)
			e = m - 1; // 내가 찾을 k가 m(중간)보다 더 작을 경우 더 큰 부분은 의미가 없기 때문에 m-1로 옮겨서 다시 찾음.
		else
			s = m + 1; // 내가 찾을 k가 m(중간)보다 더 클 경우 더 작은 부분은 의미가 없기 때문에 m+1로 옮겨서 다시 찾음.
	}
	return -1; // 숫자를 찾지 못함.
}

int main(void)
{
	int count = 0;
	int result;

	printf("찾을 숫자 입력 : ");
	scanf("%d", &k); // k = 66

	result = binarySearch(0, 10, &count);

	if (result == -1)
	{
		printf("%d번 시도했으나 찾지 못했습니다.", count);
		return 0;
	}

	printf("%d번째에서 발견\n", result);
	printf("%d번만에 찾았습니다.", count);

	return 0;
}
