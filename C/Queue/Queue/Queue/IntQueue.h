//
//  IntQueue.h
//  Queue
//
//  Created by KimWooJin on 2022/11/25.
//

#ifndef IntQueue_h
#define IntQueue_h

#include <stdio.h>
typedef struct {
    /// * 큐 최대 크기
    int max;
    /// * 현재 요소 개수
    int num;
    /// * 맨 앞 요소 위치 : front
    int front;
    /// * 맨 뒤 요소의 바로 뒤 위치 : rear
    int rear;
    /// * 큐 맨 앞 포인터
    int *que;
} IntQueue;
/// * 큐 초기화
int init(IntQueue *q, int max);
/// * 인 큐
int Enque(IntQueue *q, int x);
/// * 디 큐
int Deque(IntQueue *q, int *x);
/// * 피크
int Peek(const IntQueue *q, int *x);
/// * 모든 데이터 삭제
void Clear(IntQueue *q);
/// * 최대 용량
int Capacity(const IntQueue *q);
/// * 저장된 데이터 개수
int Size(const IntQueue *q);
/// * 빈 큐 여부
int isEmpty(const IntQueue *q);
/// * 꽉 찬 큐 여부
int isFull(const IntQueue *q);
/// * 큐에서 검색
int Search(const IntQueue *q, int x);
/// * 모든 데이터 출력
void PrintAll(const IntQueue *q);
/// * 큐 종료
void Terminate(IntQueue *q);
#endif /* IntQueue_h */
