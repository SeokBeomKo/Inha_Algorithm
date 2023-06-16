//#include <stdlib.h>
//#include <stdio.h>
//
//
//int int_cmp(const int *a, const int *b)
//{
//	if (*a < *b)	return -1;
//	else if (*a > *b)	return 1;
//	else				return 0;
//}
//
//int cmp(const int* a, const int* b)
//{
//}
//
//void* bsearchx(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*));
//
//#define MAX 15
//
//int main()
//{
//	/*
//	BigO 표기법 (시간 복잡도)
//	O(1)		 : 입력값이 증가해도 실행 시간은 동일한 알고리즘
//	O(log N)	 : 연산이 한 번 실핼될 때 마다 데이터의 크기가 절반으로 감소하는 알고리즘
//	O(N)		 : 입력값 N 이 증가함에 따라 실행시간도 선형적으로 증가하는 알고리즘
//	O(N log N)	 : O(N) 의 알고리즘과 O(log N) 의 알고리즘이 중첩된 알고리즘
//	O(N^2)		 : O(N) 의 알고리즘과 O(log N) 의 알고리즘이 중첩된 알고리즘
//	O(2^N)		 : 빅오 표기법 중 가장 느린 시간 복잡도 주로 재귀적으로 수행하는 알고리즘
//	*/
//
//	/*int nx, ky;
//	puts("bsearch 함수를 사용하여 검색");
//	printf("요소 개수 :");
//	scanf_s("%d", &nx);
//	int *x = calloc(nx, sizeof(int));
//
//	printf("오름차순으로 입력하세요. \n");
//	printf("x[0]: ");
//	scanf_s("%d", &x[0]);
//	for (int i = 1; i < nx; i++)
//	{
//		do {
//			printf("x[%d]: ", i);
//			scanf_s("%d", &x[i]);
//		} while (x[i] < x[i - 1]);
//	}
//	printf("검색값 : ");
//	scanf_s("%d", &ky);
//	int* p = bsearch(&ky, x, nx, sizeof(int),(int(*)(const void*, const void*))int_cmp);
//	if (p == NULL)	puts("검색에 실패했습니다.");
//	else			printf("%d 는 x[%d] 에 있습니다.\n", ky,(int)(p-x));
//	free(x);*/
//
//	/*
//	Q9. bsearch 함수
//	*/
//	int x[MAX] = { 1,2,2,3,3,3,4,4,4,4,5,5,5,5,5 };
//
//	int ky = 0;
//	for (int i = 0; i < MAX; i++)
//	{
//		printf(" %d ", x[i]);
//	}
//	printf("\n");
//	scanf_s("%d", &ky);
//	
//	int* p = bsearchx(&ky, x, MAX, sizeof(int), (int(*)(const void*, const void*))int_cmp);
//
//	if (p == NULL)	printf("검색 실패");
//	else			printf("%d 는 x[%d] 에 있습니다. \n", ky, (int)(p - x));
//
//	return 0;
//}
//
//void* bsearchx(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*))
//{
//	int *a = (int*)base;
//	size_t f = 0, l = nmemb - 1;
//	size_t iter = 0, comp = 0;
//	while (f <= l)
//	{
//		comp = compar(&a[iter = (l + f) >> 1], key);
//		if (comp == 0)
//		{
//			while (1)
//			{
//				if (a[iter] == a[iter - 1])		iter--;
//				else							return &a[iter];
//			}
//		}
//		else if (comp == -1)	f = iter + 1;
//		else					l = iter - 1;
//	}
//	return NULL;
//}
