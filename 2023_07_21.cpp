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
//		cout << endl << "1. ����, 2. ����, 3. Ž��, 4. �ʱ�ȭ" << endl;
//		cin >> temp_sel;
//
//		switch (temp_sel)
//		{
//		case 1:
//			cout << "Ű ��, ������ �� �Է� : ";
//			cin >> temp_data >> temp_key;
//			hashTable.Add(ChainHashNode{ temp_key, temp_data });
//			break;
//		case 2:
//			cout << "Ű �� �Է� : ";
//			cin >> temp_key;
//			hashTable.Remove(temp_key);
//			break;
//		case 3:
//			cout << "Ű �� �Է� : ";
//			cin >> temp_key;
//			if (hashTable.Search(temp_key))	cout << "�ִ�" << endl;
//			else							cout << "����" << endl;
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