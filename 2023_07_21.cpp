//#include <iostream>
//#include "ChainHashTable.h"
//
//using namespace std;
//
//
//int main()
//{
//	ChainHashTable hashTable;
//	int temp_sel = 0;
//
//	int temp_key;
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
//			cout << "키 값, 데이터 값 입력 : ";
//			cin >> temp_data >> temp_key;
//			hashTable.Add(ChainHashNode{ temp_key, temp_data });
//			break;
//		case 2:
//			cout << "키 값 입력 : ";
//			cin >> temp_key;
//			hashTable.Remove(temp_key);
//			break;
//		case 3:
//			cout << "키 값 입력 : ";
//			cin >> temp_key;
//			if (hashTable.Search(temp_key))	cout << "있다" << endl;
//			else							cout << "없다" << endl;
//			break;
//		case 4:
//			//hashTable.Free();
//			break;
//		default:
//			break;
//		}
//		hashTable.Print();
//	}
//
//	return 0;
//}