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
