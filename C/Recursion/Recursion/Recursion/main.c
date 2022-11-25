//
//  main.c
//  Recursion
//
//  Created by KimWooJin on 2022/11/25.
//

#include <stdio.h>
#include "Recursion.h"
int main(int argc, const char * argv[]) {
    int menu, x;
    while (1) {
        printf("순차곱셉(1) 최대공배수(2) 종료(0)\n");
        printf("메뉴를 입력하세요 : ");
        scanf("%d",&menu);
        getchar();
        if (menu == 0) {break;}
        switch (menu) {
            case 1:
                printf("n값을 입력해주세요 : ");
                scanf("%d",&x);
                getchar();
                printf(" = %d\n",Factorial(x));
                break;
            case 2: {
                int a,b, result;
                printf("첫번째 값을 입력해주세요 : ");
                scanf("%d",&a);
                getchar();
                printf("두번째 값을 입력해주세요 : ");
                scanf("%d",&b);
                getchar();
                result = test(a, b);
                if (result != 1) {
                    printf("최대 공배수 : %d\n", result);
                }
                else {
                    printf("공배수가 존재하지 않습니다.\n");
                }
                break;
            }
        }
    }
    return 0;
}
