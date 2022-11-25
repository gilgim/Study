//
//  main.c
//  Stack
//
//  Created by KimWooJin on 2022/11/24.
//

#include <stdio.h>
#include "IntStack.h"

int main(int argc, const char * argv[]) {
    IntStack s;
    //  초기화 실패 경우
    if(init(&s, 64) == -1) {
        puts("스택 생성에 실패하였습니다.");
        return 1;
    }
    int menu, x;
    while(1) {
        printf("\n=================================================\n");
        printf("현재 데이터 수 : %d / %d\n", size(&s), capacity(&s));
        printf("=================================================\n");
        printf("푸쉬(1) 팝(2) 피크(3) 전체삭제(4)\n비어있는 스택 조회(5) 모든데이터 출력(6) 스택종료(0)\n");
        printf("=================================================\n");
        printf("입력 : ");
        scanf("%d", &menu);
        getchar();
        if (menu == 0) {printf("스택 프로그램을 종료하겠습니다.\n"); break;}
        switch (menu) {
            case 1:
                printf("데이터를 입력해주세요.\n");
                printf("데이터 :");
                scanf("%d",&x);
                getchar();
                if (push(&s, x) == -1) {
                    printf("푸시에 실패했습니다.");
                }
                else {
                    printf("%d 데이터를 푸시에 성공했습니다.",x);
                }
                break;
            case 2:
                if (pop(&s, &x) == -1) {
                    printf("팝에 실패했습니다.");
                }
                else {
                    printf("%d 이(가) 팝 되었습니다.",x);
                }
                break;
            case 3:
                if (peek(&s, &x) == -1) {
                    printf("가장 최근 값 조회에 실패했습니다.");
                }
                else {
                    printf("최근 데이터는 %d 입니다.",x);
                }
                break;
            case 4:
                removeAll(&s);
                printf("모든 값을 삭제했습니다.");
                break;
            case 5:
                if (isEmpty(&s)) {
                    printf("스택이 비어있습니다.");
                }
                else {
                    printf("스택이 비어있지 않습니다.");
                }
                break;
            case 6:
                printAll(&s);
                printf("조회 완료되었습니다.");
                break;
            default:
                break;
        }
    }
    terminate(&s);
    return 0;
}
