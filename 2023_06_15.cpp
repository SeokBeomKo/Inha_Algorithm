//#include <iostream>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//void htest(int f, int m, int l, int cnt);
//
//void hanoitower(vector<int> s[], int f, int m, int l, int cnt);
//
//int main()
//{
//	/*String s1(" and I am a C++ student.");
//	String s2 = "영문 이름을 입력하십시오:";
//	String s3 = "AaaBbbCcc";
//
//	s2 = "My name is " + s3;
//	cout << s2 << ".\n";
//	s2 = s2 + s1;
//	s2.stringup();
//	cout << s2 << ".\n";
//	cout << "다음 문자열에는\n" << s2 << "\n문자 'A' 가"
//		<< s2.has('A') << "개 들어 있습니다.\n";
//	s1 = "red";
//	String rgb[3] = { String(s1), String("green"), String("blue") };
//	cout << "빛의 삼원색의 이름을 하나만 입력 :";
//	String ans;
//	bool success = false;
//	while (cin >> ans)
//	{
//		ans.stringlow();
//		for (String a : rgb)
//		{
//			if (ans == a)
//			{
//				cout << "맞았습니다 !\n";
//				success = true;
//				break;
//			}
//		}
//		if (success) break;
//		else		cout << "다시 입력 :";
//	}
//	cout << "프로그램 종료.\n";*/
//
//	/*
//	하노이 타워
//	*/
//
//	vector<int> s[3];
//	int cnt;
//
//	cin >> cnt;
//	for (int i = 1; i < cnt + 1; i++)
//	{
//		s[0].push_back(i);
//	}
//
//	hanoitower(s, 0, 1, 2, cnt);
//
//	/*for (int i = 1; i < cnt + 1; i++)
//	{
//		for (int j = 0; j < cnt; j++)
//		{
//			cout << s[i - 1][j];
//		}
//		cout << endl;
//	}*/
//
//	return 0;
//}
///*
//1
//2
//3
//a b c
//
//01
//2
//3   1
//a b c
//
//02
//3 2 1
//a b c
//
//03
//  1
//3 2
//a b c
//
//04
//  1
//  2 3
//a b c
//
//05
//1 2 3
//a b c
//
//06
//	2
//1   3
//a b c
//
//07
//	1
//	2
//	3
//a b c
//*/
//
//void htest(int f, int m, int l, int cnt)
//{
//	if (cnt == 1)
//	{
//		//move(f, l);
//		return;
//	}
//	htest(f, l, m, cnt - 1);
//	//move(f, l);
//	htest(m, f, l, cnt - 1);
//}
//
//
//void hanoitower(vector<int> s[], int f, int m, int l, int cnt)
//{
//	for (int i = 0; i < 3; i++)
//	{
//		if (s[0].size() > i)	cout << s[0][i];
//		else cout << ' ';
//		cout << '\t';
//		if (s[1].size() > i)	cout << s[1][i];
//		else cout << ' ';
//		cout << '\t';
//		if (s[2].size() > i)	cout << s[2][i];
//		else cout << ' ';
//		cout << '\t';
//		cout << endl;
//	}
//	if (cnt == 0)
//	{
//		return;
//	}
//	hanoitower(s, f, l, m, cnt - 1);
//	s[l].push_back(s[f][s[f].size() - 1]);
//	s[f].pop_back();
//	hanoitower(s, m, f, l, cnt - 1);
//}