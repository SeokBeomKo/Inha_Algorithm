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
//		cout << endl << "1. ����, 2. ����, 3. Ž��, 4. �ʱ�ȭ" << endl;
//		cin >> temp_sel;
//
//		switch (temp_sel)
//		{
//		case 1:
//			cout << "������ �Է� : ";
//			cin >> temp_data;
//			binTree.Add(temp_data);
//			break;
//		case 2:
//			cout << "������ �Է� : ";
//			cin >> temp_data;
//			binTree.Remove(temp_data);
//			break;
//		case 3:
//			cout << "������ �Է� : ";
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