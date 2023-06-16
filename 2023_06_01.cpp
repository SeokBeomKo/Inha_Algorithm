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
//	Q3. 선형 검색을 하기 위한 기본 순서도와 이를 바탕으로
//	선형 검색 프로그램을 작성하라
//	ex >	데이터 입력 : 6 5 2 1 8 9 7 4
//			검색 데이터 : 9
//			자료중에 9 가 있습니다.
//			검색 데이터 : 3
//			자료중에 3 은 없습니다.
//	1) 선형 검색 만으로
//	2) 보초법 적용
//	3) p120 Q2 와 같은 형태로 출력
//	*/
//	int key;
//
//	int n[MAX] = { 6,5,2,1,8,9,7,4 };
//
//	cout << "찾을 키 입력 :";
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
//			cout << "찾음" << endl;
//			break;
//		}
//		find++;
//	}
//
//	/*int find = search(n, MAX, key);
//	if (find != -1)
//		cout << key << "는 " << find << "번째에 있습니다." << endl;
//	else
//		cout << key << "는 없습니다." << endl;*/
//
//	/*int *nx = (int*)calloc(MAX + 1, sizeof(int));
//	for (int i = 0; i < MAX; i++)
//	{
//		cout << i << "번째 요소 입력";
//		cin >> nx[i];
//	}
//
//	int find = sentrySearch(nx, MAX, key);
//	if (find != -1)
//		cout << key << "는 " << find << "번째에 있습니다." << endl;
//	else
//		cout << key << "는 없습니다." << endl;
//	free(nx);*/
//}