//#include <iostream>
//
//using namespace std;
//
//#define MAX 8
//
//int search(int a[], int num, int key)
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
//int sentrySearch(int a[], int num, int key)
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
//int main()
//{
//	/*
//	Q3. ���� �˻��� �ϱ� ���� �⺻ �������� �̸� ��������
//	���� �˻� ���α׷��� �ۼ��϶�
//	ex >	������ �Է� : 6 5 2 1 8 9 7 4
//			�˻� ������ : 9
//			�ڷ��߿� 9 �� �ֽ��ϴ�.
//			�˻� ������ : 3
//			�ڷ��߿� 3 �� �����ϴ�.
//	1) ���� �˻� ������
//	2) ���ʹ� ����
//	3) p120 Q2 �� ���� ���·� ���
//	*/
//	int key;
//
//	int n[MAX] = { 6,5,2,1,8,9,7,4 };
//
//	cout << "ã�� Ű �Է� :";
//	cin >> key;
//
//	cout << " I";
//	for (int i = 0; i < MAX; i++)
//	{
//		cout << " " << i << " ";
//	}
//	cout << "\n-+-----------------------------" << endl;
//
//	int find = 0;
//	while (true)
//	{
//		cout << " I";
//		for (int i = 0;i <= find; i++)
//		{
//			if (i == find) cout << " * ";
//			else cout << "   ";
//		}
//		cout << "\n" << find << "I";
//		for (int i = 0; i < MAX; i++)
//		{
//			cout << " " << n[i] << " ";
//		}
//		cout << endl << endl;
//		if (n[find] == key)
//		{
//			cout << "ã��" << endl;
//			break;
//		}
//		find++;
//	}
//
//	/*int find = search(n, MAX, key);
//	if (find != -1)
//		cout << key << "�� " << find << "��°�� �ֽ��ϴ�." << endl;
//	else
//		cout << key << "�� �����ϴ�." << endl;*/
//
//	/*int *nx = (int*)calloc(MAX + 1, sizeof(int));
//	for (int i = 0; i < MAX; i++)
//	{
//		cout << i << "��° ��� �Է�";
//		cin >> nx[i];
//	}
//
//	int find = sentrySearch(nx, MAX, key);
//	if (find != -1)
//		cout << key << "�� " << find << "��°�� �ֽ��ϴ�." << endl;
//	else
//		cout << key << "�� �����ϴ�." << endl;
//	free(nx);*/
//}