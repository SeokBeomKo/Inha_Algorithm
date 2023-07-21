//#include <iostream>
//#include "BinaryTree.h"
//
//using namespace std;
//
//
//int main()
//{
//	BinaryTree binTree;
//	int temp_sel = 0;
//
//	int temp_data;
//
//	while (true)
//	{
//		cout << endl << "1. 삽입, 2. 삭제, 3. 탐색, 4. 초기화" << endl;
//		cin >> temp_sel;
//
//		switch (temp_sel)
//		{
//		case 1:
//			cout << "데이터 입력 : ";
//			cin >> temp_data;
//			binTree.Add(temp_data);
//			break;
//		case 2:
//			cout << "데이터 입력 : ";
//			cin >> temp_data;
//			binTree.Remove(temp_data);
//			break;
//		case 3:
//			cout << "데이터 입력 : ";
//			cin >> temp_data;
//			cout << binTree.Search(temp_data) << endl;
//			break;
//		case 4:
//			binTree.Free();
//			break;
//		default:
//			break;
//		}
//		binTree.Print(binTree.GetRoot());
//	}
//
//	return 0;
//}