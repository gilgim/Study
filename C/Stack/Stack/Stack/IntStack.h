//
//  IntStack.h
//  Stack
//
//  Created by KimWooJin on 2022/11/24.
//

#ifndef IntStack_h
#define IntStack_h
#include <stdio.h>
typedef struct {
    /// * 스택 용량
    int max;
    /// * 스택 마지막 인덱스 위치를 나타내는 포인터
    int ptr;
    /// * 스택 첫 요소 포인터
    int *stk;
} IntStack;

//  MARK: -Define functions
/// * 스택 초기화
int init(IntStack *s, int max);
/// * 요소 삽입
int push(IntStack *s, int x);
/// * 요소 출하
int pop(IntStack *s, int *x);
/// * 맨 위 요소 검색
int peek(const IntStack *s, int *x);
/// * 스택 비우기
void removeAll(IntStack *s);
/// * 스택 최대 용량 조회
int capacity(const IntStack *s);
/// * 스택 데이터 개수 조회
int size(const IntStack *s);
/// * 스택 Empty 여부
int isEmpty(const IntStack *s);
/// * 스택 가득참 여부
int isFull(const IntStack *s);
/// * 스택 데이터 검색
int search(const IntStack *s, int x);
/// * 모든 데이터 출력 함수
void printAll(const IntStack *s);
/// * 스택 종료
void terminate(IntStack *s);
void Answer(void);
#endif /* IntStack_h */
