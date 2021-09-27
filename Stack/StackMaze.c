#include <stdio.h>

int m[9][9] = { //maze
             {2,2,2,2,2,2,2,2,2},
             {2,0,0,0,0,0,0,0,2},
             {2,0,2,2,0,2,2,0,2},
             {2,0,2,0,0,2,0,0,2},
             {2,0,2,0,2,0,2,0,2},
             {2,0,0,0,0,0,2,0,2},
             {2,2,0,2,2,0,2,2,2},
             {2,0,0,0,0,0,0,0,2},
             {2,2,2,2,2,2,2,2,2} };

int Si, Sj, Ei, Ej; // Start 출발, End 도착 지점 표시
int success, top, Path_i[100], Path_j[100];
// S : Start, 출발점 E : End, 도착점, idx 경로 배열 인덱스
// Path_i, Path_j : 지나간 길을 저장함 (i는 행, j는 열)

int visit(int, int);

int main(void) {
    top = 0; // stack의 top변수를 0으로 초기화
    success = 0; // 미로 탈출 여부
    printf("===미로 탈출 경로 찾기 게임===\n");
    Si = 1, Sj = 1; // 출발점 m 배열의 1행 1열
    Ei = 7, Ej = 7; // 도착점 m 배열의 7행 7열
    if (visit(Si, Sj) == 0)
        printf("미로의 출구를 찾을 수 없음\n");
    else
        printf("미로의 모든 경로를 찾았음\n");
    return 0;
}

int visit(int i, int j) {
    static int pathCount = 1; // 찾은 경로의 수 카운트
    m[i][j] = 1; // 배열에 0이 있다면 아직 가지 않은 길이란 의미
    // 지나간 길에는 1을 저장해 둔다.
    Path_i[top] = i;
    Path_j[top] = j;
    top++;

    if (i == Ei && j == Ej) { // 도착점에 도착했을 때
        printf("찾은 경로 %d번\n", pathCount++);
        printPath(); // 경로를 출력해주는 함수
        success = 1; // 경로를 찾았음을 표시
    }

    //미로 탐색하기

    if (m[i][j + 1] == 0) // 배열 오른쪽 이동
        visit(i, j + 1);
    if (m[i + 1][j] == 0) // 배열 아래행으로 이동
        visit(i + 1, j);
    if (m[i][j - 1] == 0) // 배열 왼쪽으로 이동
        visit(i, j - 1);
    if (m[i - 1][j] == 0) // 배열 위로 이동
        visit(i - 1, j);
    top--; // 모든 길이 막혀있으면 이전 단계로 돌아감
    // 재귀적 함수의 호출에 따른 시스템 스택의 깊이를 표시
    m[i][j] = 0; // 이전 단계로 돌아가면서 1을 0으로 다시 세팅
    // 새로운 길을 찾도록 다시 0으로 세팅 

    return success;
}
