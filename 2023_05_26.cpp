//#include <iostream>
//
//
//using namespace std;
//
//
//void Swap(int a, int b);
//int Gauss(int n);
//int nGauss(int a, int b);
//void hourglass(int n);
//
//int main()
//{
//	/*int n = 0;
//
//	int a = 0, b = 0;
//
//	cout << "입력값 (a,b):";
//	cin >> a >> b;
//	cout << a << "~" << b << " 의 합 : " << nGauss(a,b) << endl;
//
//	cout << "입력값 :";
//	cin >> n;
//	cout << "1 ~ " << n << " 의 합 : " << Gauss(n) << endl;*/
//
//	hourglass(5);
//}
//
//void hourglass(int n)
//{
//	int row = n + n - 1;
//	int i = 0, j = 0, k = n;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < row; j++)
//		{
//			if (i < n)
//			{
//				if (j >= i && j < row - i) cout << i + 1;
//				else cout << " ";
//			}
//			else
//			{
//				if (j <= i && j > i - k) cout << row - i;
//				else cout << " ";
//			}
//		}
//		if (i >= n) k+=2;
//		cout << endl;
//	}
//}
//
//int Gauss(int n)
//{
//	return (n + 1) * n / 2;
//}
//
//int nGauss(int a, int b)
//{
//	if (a > b)
//	{
//		int temp = a;
//		a = b;
//		b = temp;
//	}
//	
//	return ((b + 1) * b / 2) - ((a - 1) * a / 2);
//}