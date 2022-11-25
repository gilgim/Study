//
//  IntQueue.c
//  Queue
//
//  Created by KimWooJin on 2022/11/25.
//

#include "IntQueue.h"
#include <stdio.h>
#include <stdlib.h>

/// * 큐 초기화
int init(IntQueue *q, int max) {
    q->num = q->front = q->rear = 0;

    q->que = calloc(max, sizeof(int));
    if (q->que == NULL) {
        q->max = 0;
        return -1;
    }
    q->max = max;
    return 0;
}
/// * 인 큐
int Enque(IntQueue *q, int x) {
    if (q->num >= q->max) {
        return -1;
    }
    q->num++;
    q->que[q->rear++] = x;
    if (q->rear == q->max) {
        q->rear = 0;
    }
    return 0;
}
/// * 디 큐
int Deque(IntQueue *q, int *x) {
    if (q->num <= 0) {
        return -1;
    }
    q->num--;
    *x = q->que[q->front++];
    if (q->front >= q->max) {
        q->front = 0;
    }
    return 0;
}
/// * 피크
int Peek(const IntQueue *q, int *x) {
    if (q->num >= 0) {
        return -1;
    }
    *x = q->que[q->front];
    return 0;
}
/// * 모든 데이터 삭제
void Clear(IntQueue *q) {
    q->num = q->front = q->rear = 0;
}
/// * 최대 용량
int Capacity(const IntQueue *q) {
    return q->max;
}
/// * 저장된 데이터 개수
int Size(const IntQueue *q) {
    return q->num;
}
/// * 빈 큐 여부
int isEmpty(const IntQueue *q) {
    return q->num <= 0;
}
/// * 꽉 찬 큐 여부
int isFull(const IntQueue *q) {
    return q->num >= q->max;
}
/// * 큐에서 검색
int Search(const IntQueue *q, int x) {
    int idx,i;
    for (i = 0; i < q->num; i++) {
        if (q->que[idx = (i+q->front) % q->max] == x) {
            return idx;
        }
    }
    return -1;
}
/// * 모든 데이터 출력
void PrintAll(const IntQueue *q) {
    for (int i = 0; i < q->num; i++) {
        printf("%d ",q->que[(i+q->front) % q->max]);
    }
    putchar('\n');
}
/// * 큐 종료
void Terminate(IntQueue *q) {
    if (q->que != NULL) {
        free(q->que);
        q->num = q->max = q->front = q->rear = 0;
    }
}
