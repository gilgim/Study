//
//  IntStack.c
//  Stack
//
//  Created by KimWooJin on 2022/11/24.
//

#include "IntStack.h"
#include <stdio.h>
#include <stdlib.h>

/// * 스택 초기화
int init(IntStack *s, int max) {
    s->ptr = 0;
    s->stk = calloc(max, sizeof(int));
    if (s->stk == NULL) {
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}
/// * 요소 삽입
int push(IntStack *s, int x) {
    if (s->ptr >= s->max) {
        return -1;
    }
    s->stk[s->ptr++] = x;
    return 0;
}
/// * 요소 출하
int pop(IntStack *s, int *x) {
    if (s->ptr <= 0) {
        return -1;
    }
    printAll(s);
    *x = s->stk[(s->ptr--)-1];
    return 0;
}
/// * 맨 위 요소 검색
int peek(const IntStack *s, int *x) {
    if (s->ptr <= 0) {
        return -1;
    }
    *x = s->stk[s->ptr-1];
    return 0;
}
/// * 스택 비우기
void removeAll(IntStack *s) {
    s->ptr = 0;
}
/// * 스택 최대 용량 조회
int capacity(const IntStack *s) {
    return s->max;
}
/// * 스택 데이터 개수 조회
int size(const IntStack *s) {
    return s->ptr;
}
/// * 스택 Empty 여부
int isEmpty(const IntStack *s) {
    return s->ptr <= 0;
}
/// * 스택 가득참 여부
int isFull(const IntStack *s) {
    return s->ptr >= s->max;
}
/// * 스택 데이터 검색
int search(const IntStack *s, int x) {
    int i;
    for(i = s->ptr-1; i >= 0; i--) {
        if(s->stk[i] == x) {
            return i;
        }
    }
    return -1;
}
/// * 모든 데이터 출력 함수
void printAll(const IntStack *s) {
    int i;
    for(i = 0; i < s->ptr; i++) {
        printf("%d ", s->stk[i]);
    }
    putchar('\n');
}
/// * 스택 종료
void terminate(IntStack *s) {
    if(s->stk != NULL) {
        free(s->stk);
    }
    s->max = s->ptr = 0;
}
/// - 하나의 배열을 공유하여 2개의 스택을 구현하는 스택프로그램을 만드시오.
void Answer(void) {
    
    //  배열 크기 지정
    int arrayMax;
    printf("배열의 크기를 지정해주세요");
    scanf("%d",&arrayMax);
    
    //  배열 생성
    int array[arrayMax];
   
}
