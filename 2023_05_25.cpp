//#include <iostream>
//#include <time.h>
//
//int max4(int a, int b, int c, int d);
//int middle(int a, int b, int c);
//int med(int a, int b, int c);
//
//int main()
//{
//    // 어떤 문제를 해결하기 위한 절차
//    // 명확하게 정의되고 순서가 있는 유한 개의 규칙으로 이루어진 집합
//
//    /*
//    Q3. p.20 연습문제 Q1. max4 함수를 작성
//    순서도 포함
//    */
//    /*
//    printf("%d", max4(9, 3, 5, 2));
//    */
//
//    /*
//    Q4. p.23 연습문제 Q4 세값으 대소 관계 13종류의 모든 조합에 대해 중앙값을 구하여 출력
//    Q5 와 효율성 비교
//    */
//
//    /*double start, end;
//
//    start = (double)clock() / CLOCKS_PER_SEC;
//
//    for (int i = 0; i < 1000000000; i++)
//    {
//        med(9, 5, 3);
//    }
//
//    end = (((double)clock()) / CLOCKS_PER_SEC);
//
//    printf("프로그램 수행 시간 :%lf\n", (end - start));
//
//    start = (double)clock() / CLOCKS_PER_SEC;
//    
//    for (int i = 0; i < 1000000000; i++)
//    {
//        middle(9, 5, 3);
//    }
//
//    end = (((double)clock()) / CLOCKS_PER_SEC);
//
//    printf("프로그램 수행 시간 :%lf\n", (end - start));*/
//
//    
//}
//
//int middle(int a, int b, int c)
//{
//    if (a >= b)
//    {
//        if (c >= b) return b;
//        else if (a >= c) return c;
//        else return a;
//    }
//    else if (c > b) return b;
//    else if (a >= c) return a;
//    else return c;
//}
//
//int med(int a, int b, int c)
//{
//    if ((b >= a && c <= a) || (b <= a && c >= a)) return a;
//    else if ((a > b && c < b) || (a < b && c > b)) return b;
//    return c;
//}
//
//int max4(int a, int b, int c, int d)
//{
//    int max = a;
//    if (max < b) max = b;
//    if (max < c) max = c;
//    if (max < d) max = d;
//    return max;
//}
