//
//  Solution.c
//  C grammer
//
//  Created by KimWooJin on 2022/09/28.
//

#include "Solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cleanBuffer_a(void) {
    while (getchar() != '\n');
}
void Q12(void) {
    for (int i = 0; i <= 9; i++) {
        if (i == 0) {
            printf("\n   |");
        }
        else if (i == 1) {
            printf("---+----------------------------------------------------\n");
        }
        if (!(i == 0)) {
            printf("%d  |",i);
        }
        for (int j = 1; j <= 9; j++) {
            int mulValue = j * i;
            if (mulValue == 0) {
                mulValue = j;
            }
            if (mulValue < 10) {
                printf("  %d   ", mulValue);
            }
            else {
                printf("  %d  ", mulValue);
            }
        }
        printf("\n");
    }
}
void Q13(void) {
    for (int i = 0; i <= 9; i++) {
        if (i == 0) {
            printf("\n   |");
        }
        else if (i == 1) {
            printf("---+----------------------------------------------------\n");
        }
        if (!(i == 0)) {
            printf("%d  |",i);
        }
        for (int j = 1; j <= 9; j++) {
            int mulValue = j + i;
            if (mulValue == 0) {
                mulValue = j;
            }
            if (mulValue < 10) {
                printf("  %d   ", mulValue);
            }
            else {
                printf("  %d  ", mulValue);
            }
        }
        printf("\n");
    }
}
void Q16LB(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        if (!(i == 0)) {
            putchar('\n');
        }
    }
}
void Q16LU(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        if (!(i == 0)) {
            putchar('\n');
        }
    }
}
void Q16RU(int n) {
    for (int i = n; i >= 1; i--) {
        for (int k = 1; k <= n-i; k++) {
            printf(" ");
        }
        for (int j=1; j <= i; j++) {
            printf("*");
        }
        if (!(i == 0)) {
            putchar('\n');
        }
    }
}
void Q16RB(int n) {
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= n-i; k++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        if (!(i == 0)) {
            putchar('\n');
        }
    }
}
void Q17(int n) {
    for (int i = 1; i <= n; i++) {
        for (int spacer = 1; spacer <= n-i; spacer++) {
            printf(" ");
        }
        for (int asta = 1; asta <= (i*2)-1; asta++) {
            printf("*");
        }
        printf("\n");
    }
}
void Q18(int n) {
    for (int i = n; i >= 1; i--) {
        for (int spacer = 1; spacer <= n-i; spacer++) {
            printf(" ");
        }
        for (int asta = 1; asta <= (i*2)-1; asta++) {
            printf("*");
        }
        printf("\n");
    }
}

int Q1_74p(const int a[], int n) {
    int min = a[0];
    for(int i = 0; i < n; i++) {
        if (min > a[i]) {min = a[i];}
    }
    return min;
}

int Q2_74p(const int  a[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

double Q3_75p(const int a[], int n) {
    double avg = 0;
    for(int i = 0; i < n; i++) {
        avg += a[i];
    }
    avg = avg / (double)n;
    return avg;
}

void Q4_75p(void) {
    srand(time(NULL));
    //  사람 수는 5-20 사이
    int number = rand() % 20 + 5;
    printf("등록된 사람 수는 %d 입니다.\n", number);
    int *heights = calloc(number, sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < number; i++) {
        heights[i] = rand() % 90 + 100;
        printf("heights[%d] = %d \n", i, heights[i]);
    }
    int max = heights[0];
    for (int i = 0; i < number; i++) {
        if (max<heights[i]) max = heights[i];
    }
    printf("%d명 중 가장 큰 키는 %d 입니다.\n", number, max);
}
#define swap(type, x, y) do{ type t = x; x = y; y = t;} while(0)

void Q5_reverse(int a[], int n) {
    printf("기존 배열 : ");
    for (int i = 0; i < n; i++) {
        printf(" %d ", a[i]);
    }
    puts("\n");
    for(int i = 0; i < n/2; i++) {
        swap(int, a[i], a[n - i - 1]);
        printf("a[%d] 와 a[%d]를 교환합니다. \n", i, n-i-1);
        printf("변경 배열 : ");
        for (int i = 0; i < n; i++) {
            printf(" %d ", a[i]);
        }
        puts("\n");
    }
}
void Q5_75p(void) {
    srand(time(NULL));
    int count = rand() % 10 + 2;
    srand(time(NULL));
    int *a = calloc(count, sizeof(int));
    
    for (int i = 0; i < count; i++) {
        a[i] = rand() % 20;
    }
    Q5_reverse(a, count);
    printf("역순 정렬을 종료합니다.");
}
/**
 d는 변환한 문자들을 넣어둔 배열
 digits 는 자릿 수
 */
int Q6_card(unsigned x, int n, char d[]) {
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digits = 0;
    if (x == 0) {
        d[digits++] = dchar[0];
    }else {
        while (x) {
            d[digits++] = dchar[x % n];
            
            if (x != 1 && x > 9) {
                printf("%d|    %u ... %c\n", n, x, d[digits - 1]);
                printf(" +------\n");
            }
            else if (x != 1 && x < 10) {
                printf("%d|    %u  ... %c\n", n, x, d[digits - 1]);
                printf(" +------\n");
            }
            else if ((x / n) == 0) {
                printf("      %d\n",x);
            }
            x /= n;
        }
        for (int i = 0; i < digits/2; i++) {
            int temp = d[i];
            d[i] = d[digits - i - 1];
            d[digits - i - 1] = temp;
        }
    }
    return digits;
}
void Q6_75p(void) {
    unsigned userNumber;
    int changNumber;
    char cno[512];
    char userRestart = 'y';
    
    do {
        printf("Please input number that is changed.(number > 0) : ");
        scanf("%u", &userNumber);
        
        do {
            printf("Please select change number.(2-32) : ");
            scanf("%d", &changNumber);
        } while(changNumber < 2 || changNumber > 32);
        
        int array_count = Q6_card(userNumber, changNumber, cno);
        
        printf("Change number : ");
        for (int i = 0; i < array_count; i++) {
            printf("%c", cno[i]);
        }
        printf("\n");
        cleanBuffer_a();
        printf("Do you want restart?(y/...anything) : ");
        scanf("%c", &userRestart);
    } while(userRestart == 'y');
    
    printf("\n okay! bye! \n");
}

void Q8_75p(int a[], const int b[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }
}
void Q9_75p(int a[], const int b[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = b[n - i - 1];
    }
}
void Q10_76p(int a[], int n) {
    printf("입력 배열 : ");
    for (int i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }
    printf("배열 개수 : %d\n",n);
    int temp[n];
    int isAppend = 0;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        do {
            int random = rand() % n;
            for (int k = 0; k < n; k++) {
                if (temp[k] == random) {
                    isAppend = 1;
                    break;
                }else {
                    isAppend = 0;
                }
            }
            if (isAppend == 0) {
                temp[i] = random;
                break;
            }
        }while(isAppend);
    }
    for (int i = 0; i < n; i++) {
        int tempInt = a[i];
        a[i] = a[temp[i]];
        a[temp[i]] = tempInt;
    }
    printf("무작위로 혼합된 배열 : ");
    for (int i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

