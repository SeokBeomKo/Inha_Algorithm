//#include <iostream>
//#include <iomanip>
//#include <time.h>
//
//using namespace std;
//
//const int index = 11;
//
//int bin_Search(int a[], int num, int key);
//
//int binSearch_time(int a[], int num, int key);
//int search_time(int a[], int num, int key);
//int sentrySearch_time(int a[], int num, int key);
//
//int main()
//{
//	/*
//	���� �˻�
//	p.122 �������� 
//	Q4. ó�� ���� �˻� ������ 
//	�ڼ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�
//	*/
//
//	/*int arr[index] = { 5,7,15,28,29,31,39,58,68,72,95 };
//	int key = 31;
//
//	cout << "ã�� Ű �� :";
//	cin >> key;
//
//	int res = bin_Search(arr, index, key);
//	if (res != -1)
//		cout << endl <<res << "��°�� �ִ�" << endl;
//	else
//		cout << endl << key << "��Ͽ� ����" << endl;*/
//	double start, end;
//
//	start = (double)clock() / CLOCKS_PER_SEC;
//	for (int i = 0; i < 1000000000; i++)
//	{
//		100 / 16;
//	}
//	end = (((double)clock()) / CLOCKS_PER_SEC);
//	printf("������ :%lf\n", (end - start));
//
//	start = (double)clock() / CLOCKS_PER_SEC;
//	for (int i = 0; i < 1000000000; i++)
//	{
//		100 >> 4;
//	}
//	end = (((double)clock()) / CLOCKS_PER_SEC);
//	printf("����Ʈ ���� :%lf\n", (end - start));
//
//	/*double start, end;
//	
//	start = (double)clock() / CLOCKS_PER_SEC;
//	for (int i = 0; i < 100000000; i++)
//	{
//		search_time(arr, index, key);
//	}
//	end = (((double)clock()) / CLOCKS_PER_SEC);
//	printf("���� Ž�� :%lf\n", (end - start));
//	
//	int* nx = (int*)calloc(index + 1, sizeof(int));
//	for (int i = 0; i < index; i++)
//	{
//		nx[i] = arr[i];
//	}
//	start = (double)clock() / CLOCKS_PER_SEC;
//	for (int i = 0; i < 100000000; i++)
//	{
//		sentrySearch_time(nx, index, key);
//	}
//	end = (((double)clock()) / CLOCKS_PER_SEC);
//	printf("���ʼ��� Ž�� :%lf\n", (end - start));
//
//	start = (double)clock() / CLOCKS_PER_SEC;
//	for (int i = 0; i < 100000000; i++)
//	{
//		binSearch_time(arr, index, key);
//	}
//	end = (((double)clock()) / CLOCKS_PER_SEC);
//	printf("���� Ž�� :%lf\n", (end - start));*/
//
//	return 0;
//}
//
//int bin_Search(int a[], int num, int key)
//{
//	int f = 0, l = num - 1;
//	int iter = 0;
//	cout << "   I";
//	for (int i = 0; i < num; i++)
//	{
//		cout << setw(3) << i;
//	}
//	cout << "\n-+-----------------------------" << endl;
//
//	while (f <= l)
//	{
//		iter = (l + f) >> 1;
//
//		cout << "   I";
//		for (int i = 0;i <= num; i++)
//		{
//			if (i == iter) cout << setw(3)  << "+";
//			else if (i == f)	cout << setw(3) << "<-";
//			else if (i == l)	cout << setw(3) << "->";
//			else cout << setw(3) << "   ";
//		}
//		cout << "\n" << setw(3) << iter << "I";
//		for (int i = 0; i < num; i++)
//		{
//			cout << setw(3) << a[i];
//		}
//		cout << endl;
//
//		if (a[iter] == key)	return iter;
//		else if (a[iter] < key)	f = iter + 1;
//		else	l = iter - 1;
//	}
//	return -1;
//}
//
//int binSearch_time(int a[], int num, int key)
//{
//	int f = 0, l = num - 1;
//	int iter = 0;
//	while (f <= l)
//	{
//		iter = (l + f) * 0.5;
//
//		if (a[iter] == key)	return iter;
//		else if (a[iter] < key)	f = iter + 1;
//		else	l = iter - 1;
//	}
//	return -1;
//}
//int search_time(int a[], int num, int key)
//{
//	for (int i = 0; i < num; i++)
//	{
//		if (a[i] == key)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//int sentrySearch_time(int a[], int num, int key)
//{
//	int i = 0;
//	a[num] = key;
//	
//	while (true)
//	{
//		if (a[i] == key)	break;
//		i++;
//	}
//	if (i == num) return -1;
//	else	return i;
//}
