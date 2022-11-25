//
//  main.c
//  Queue
//
//  Created by KimWooJin on 2022/11/25.
//

#include <stdio.h>
#include "IntQueue.h"
int main(int argc, const char * argv[]) {
    IntQueue q;
    if (init(&q, 4) == -1) {
        printf("큐 생성에 실패했습니다.\n");
        return -1;
    }
    int menu, x;
    while (1) {
        printf("================================\n");
        printf("현재 큐 인덱스 개수 : %d\n",q.num);
        printf("인큐(1) 디큐(2) 피크(3) 전체삭제(4) \n저장된데이터(5) 빈 큐(6) 꽉 큐(7) 요소검색(8) 종료(0)\n");
        printf("================================\n");
        printf("선택 : ");
        scanf("%d",&menu);
        getchar();
        if (menu == 0) {printf("큐를 종료합니다.\n");break;}
        switch (menu) {
            case 1:
                printf("삽입할 데이터를 입력해주세요 : ");
                scanf("%d",&x);
                getchar();
                if (Enque(&q, x) == -1) {
                    printf("인큐에 실패했습니다.\n");
                }
                else {
                    printf("%d이 인큐 되었습니다.\n",x);
                }
                break;
            case 2:
                if (Deque(&q, &x) == -1) {
                    printf("디큐에 실패했습니다.\n");
                }
                else {
                    printf("%d이 디큐 되었습니다.\n",x);
                }
                break;
            case 3:
                if (Peek(&q, &x) == -1) {
                    printf("피크 조회에 실패했습니다.\n");
                }
                else {
                    printf("피크 : %d",x);
                }
                break;
            case 4:
                Clear(&q);
                break;
            case 5:
                PrintAll(&q);
                break;
            case 6:
                if (isEmpty(&q)) {
                    printf("현재 비어있습니다.\n");
                }
                else {
                    printf("현재 비어있지 않습니다.\n");
                }
                break;
            case 7:
                if (isFull(&q)) {
                    printf("현재 큐가 모두 차 있습니다.\n");
                }
                else {
                    printf("현재 큐가 모두 채워져있지 않습니다.\n");
                }
                break;
            case 8:{
                printf("검색할 데이터를 입력해주세요 : ");
                scanf("%d",&x);
                getchar();
                int result = Search(&q, x);
                if (result == -1) {
                    printf("해당 요소를 찾을 수 없습니다.\n");
                }
                else {
                    printf("요소는 %d번째에 있습니다.\n", result);
                }
                break;
            }
        }
    }
}
