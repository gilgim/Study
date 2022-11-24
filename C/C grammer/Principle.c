//
//  Principle.c
//  C grammer
//
//  Created by KimWooJin on 2022/09/28.
//
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Principle.h"

//  do while 문을 쓴 이유는 컴파일 시 오류를 피하고 C언어 스타일을 정립하기 위해서 이다.
#define swap(type,  x, y) do{ type t = x; x = y; y = t;} while(0)

int maxof(const int a[], int n) {
    int max = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i]>max) max = a[i];
    }
    return max;
}

void exampleHeight(void) {
    srand(time(NULL));
    int *height;
    //  0~32767 사이의 난수가 생성된다.
    //  time(NULL) 값은 매 번 새로운 난수를 불러온다.
    int number = rand() % 150;
    srand(time(NULL));
//    printf("People Count : ");
//    scanf("%d", &number);
    height = calloc(number, sizeof(int));
    
    printf("Please input people height.\n");
    for(int i = 0; i < number; i++) {
        height[i] = 100 + rand() % 90;
        printf("height[%d] : %d \n",i,height[i]);
//        scanf("%d", &height[i]);
    }
    printf("Max height is %d \n", maxof(height, number));
    free(height);
}

void arr_reverse(int a[], int n) {
    for(int i = 0; i < n/2; i++) {
        swap(int, a[i], a[n - i - 1]);
    }
}
void exeReverse(void) {
    int *x;
    int nx;
    
    printf("요소개수 : ");
    scanf("%d",&nx);
    
    //  배열의 크기 할당
    x = calloc(nx, sizeof(int));
    
    printf("%d개의 정수를 입력하세요.\n", nx);
    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ",i);
        scanf("%d",&x[i]);
    }
    arr_reverse(x, nx);
    printf("배열을 역순으로 정리했습니다.\n");
    for (int i = 0; i < nx; i++) {
        printf("a[%d] = %d\n", i, x[i]);
    }
    free(x);
}

//  MARK: 기수파트 10진법의 경우(0~9까지의 수)
int card_convr(unsigned x, int n, char d[]) {
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digits = 0;
    printf("\ndigits : %d\n",digits);
    if(x==0) {
        d[digits++] = dchar[0];
    } else {
        while(x) {
            d[digits++] = dchar[x % n];
            x /= n;
        }
    }
    return digits;
}
void cleanBuffer(void) {
    while (getchar() != '\n');
}
void exeCard_convr(void) {
    int i;
    unsigned no;
    int cd;
    int dno;
    
    //  변환한 값의 각 자리의 숫자를 저장하는 문자 배열
    char cno[512];
    int retry;
    
    puts("10진수를 기수 변환 합니다.");
    
    do {
        printf("변환하는 음이 아닌 정수 : ");
        scanf("%u", &no);
        cleanBuffer();
        
        do {
            printf("어떤 진수로 변환할까요?(2-36) : ");
            scanf("%d", &cd);
            cleanBuffer();
        } while(cd < 2 || cd > 36);
        
        dno = card_convr(no, cd, cno);
        printf("%d진수로는",cd);
        //  스택에 쌓여진 순으로 꺼내야한다.
        for (i = dno; i >= 0; i--) {
            printf("%c", cno[i]);
        }
        printf("입니다.\n");
        printf("한 번 더 할까요?(1...예/0...아니오) : ");
        
        scanf("%d", &retry);
        cleanBuffer();
    } while(retry == 1);
}

void decimal(void) {
    int i, n;
    unsigned long counter = 0;
    for (n = 2; n <= 1000; n++) {
        
    }
}

int int_cmp(const int *a, const int *b) {
    if (*a < *b) {
        return  -1;
    }
    else if (*a > *b) {
        return  1;
    }
    else {
        return  0;
    }
}

void bseachTest(void) {
    int i, nx, ky;
    int *x;
    int *p;
    
    puts("bsearch 함수를 사용하여 검색");
    printf("요소 개수 : ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    
    printf("오름차순으로 입력하세요.\n");
    printf("x[0] : ");
    scanf("%d", &x[0]);
    
    for(i = 1; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while(x[i] < x[i-1]);
    }
    printf("검색값 : ");
    scanf("%d", &ky);
    
    p = bsearch(&ky, x, nx, sizeof(int), (int(*)(const void *, const void *))int_cmp);
    if (p == NULL) {
        puts("검색에 실패했습니다.");
    }
    else {
        printf("%d는(은) x[%d]에 있습니다.\n",ky, (int)(p-x));
    }
    free(x);
}
