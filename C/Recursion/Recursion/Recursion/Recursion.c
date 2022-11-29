//
//  Recursion.c
//  Recursion
//
//  Created by KimWooJin on 2022/11/25.
//
#include <stdio.h>
#include <stdlib.h>
#include "Recursion.h"

int Factorial(int x) {
    if (x == 1) {
        printf("1");
        return x;
    }
    else {
        printf("%d * ",x);
        return x * Factorial(x-1);
    }
}
//  내가 생각한 함수
int GCD(int x, int y) {
    if (x == 1 || y == 1) {
        printf("최대 공배수가 없습니다.\n");
        return -1;
    }
    if (x > y) {
        int remainder = x % y;
        if (remainder == 0) {return y;}
        return GCD(remainder, y);
    }
    else if (x < y) {
        int remainder = y % x;
        if (remainder == 0) {return x;}
        return GCD(x, remainder);
    }
    else {
        return x;
    }
}
//  책에서 설명한 함수
int test(int x, int y) {
    //  어차피 여기서 리턴 치니까 더 긴변의 길이를 판단안해도 된다.
    if (y == 0)
        return x;
    else
        return test(y, x % y);
}
//  MARK: 퀸 설명
int flag_a[8];
int flag_b[15];
int flag_c[15];
int pos[8];
int count = 1;
void print(void) {
    int i;
    printf("%d 현재 보드판 현황 :",count);
    for (i=0; i<8; i++) {
        printf("%d",pos[i]);
    }
    putchar('\n');
    count = count + 1;
}
void set(int i) {
    int j;
    for (j=0; j < 8; j++) {
        pos[i] = j;
        if (!flag_a[j] && !flag_b[i+j] && !flag_c[i-j+7]) {
            pos[i] = j;
            if (i == 7) {
                print();
            }
            else {
                flag_a[j] = flag_b[i+j] = flag_c[i-j+7] = 1;
                set(i+1);
                flag_a[j] = flag_b[i+j] = flag_c[i-j+7] = 0;
            }
        }
    }
}
void setQuene(void) {
    int i;
    for (i = 0; i < 8; i++) {
        flag_a[i] = 0;
    }
    for (i = 0; i < 15; i++) {
        flag_b[i] = flag_c[i] = 0;
    }
    set(0);
}

void customQuene(int row, int (*chess)[], int (*columnArr)[], int (*rightUpArr)[], int (*leftUpArr) [], int *count) {
    /// * 퀸의 행 위치
    int column;
    for (column = 0; column < 8; column++) {
        if (!(*columnArr)[column] && !(*rightUpArr)[row+column] && !(*leftUpArr)[row-column+7]) {
            (*chess)[row] = column;
            if (row == 7) {
                printf("%d -> 현재 보드판 현황 : ", *count);
                int i;
                for (i= 0; i<8; i++) {
                    printf("%d",(*chess)[i]);
                }
                putchar('\n');
                *count = *count + 1;
            }
            else {
                (*columnArr)[column] = (*rightUpArr)[row+column] = (*leftUpArr)[row-column+7] = 1;
                customQuene(row+1, chess, columnArr, rightUpArr, leftUpArr, count);
                (*columnArr)[column] = (*rightUpArr)[row+column] = (*leftUpArr)[row-column+7] = 0;
            }
        }
    }
}
