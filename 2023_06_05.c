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
//	BigO ǥ��� (�ð� ���⵵)
//	O(1)		 : �Է°��� �����ص� ���� �ð��� ������ �˰���
//	O(log N)	 : ������ �� �� ���۵� �� ���� �������� ũ�Ⱑ �������� �����ϴ� �˰���
//	O(N)		 : �Է°� N �� �����Կ� ���� ����ð��� ���������� �����ϴ� �˰���
//	O(N log N)	 : O(N) �� �˰���� O(log N) �� �˰����� ��ø�� �˰���
//	O(N^2)		 : O(N) �� �˰���� O(log N) �� �˰����� ��ø�� �˰���
//	O(2^N)		 : ��� ǥ��� �� ���� ���� �ð� ���⵵ �ַ� ��������� �����ϴ� �˰���
//	*/
//
//	/*int nx, ky;
//	puts("bsearch �Լ��� ����Ͽ� �˻�");
//	printf("��� ���� :");
//	scanf_s("%d", &nx);
//	int *x = calloc(nx, sizeof(int));
//
//	printf("������������ �Է��ϼ���. \n");
//	printf("x[0]: ");
//	scanf_s("%d", &x[0]);
//	for (int i = 1; i < nx; i++)
//	{
//		do {
//			printf("x[%d]: ", i);
//			scanf_s("%d", &x[i]);
//		} while (x[i] < x[i - 1]);
//	}
//	printf("�˻��� : ");
//	scanf_s("%d", &ky);
//	int* p = bsearch(&ky, x, nx, sizeof(int),(int(*)(const void*, const void*))int_cmp);
//	if (p == NULL)	puts("�˻��� �����߽��ϴ�.");
//	else			printf("%d �� x[%d] �� �ֽ��ϴ�.\n", ky,(int)(p-x));
//	free(x);*/
//
//	/*
//	Q9. bsearch �Լ�
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
//	if (p == NULL)	printf("�˻� ����");
//	else			printf("%d �� x[%d] �� �ֽ��ϴ�. \n", ky, (int)(p - x));
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
