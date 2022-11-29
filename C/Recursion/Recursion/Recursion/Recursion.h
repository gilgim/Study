//
//  Recursion.h
//  Recursion
//
//  Created by KimWooJin on 2022/11/25.
//

#ifndef Recursion_h
#define Recursion_h

#include <stdio.h>
//  ㅡMARK: -팩토리얼 구현
/// * X 까지의 모든 자연수의 곱
int Factorial(int x);
//  MARK: - 최대 공약수 구하는 방법
/// * greatest common divisor
int GCD(int x, int y);
int test(int x, int y);
//  MARK: - 8퀸 문제
void setQuene(void);
void customQuene(int row, int (*chess)[], int (*columnArr)[], int (*rightUpArr)[], int (*leftUpArr) [], int *count);
#endif /* Recursion_h */
