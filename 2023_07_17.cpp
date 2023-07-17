#include <iostream>
#include "ArrayLinkedList.h"

using namespace std;


int main()
{
	ArrayLinkedList arrList;
	arrList.Init(10);

	int temp_sel = 0;

	string temp_str;

	while (true)
	{
		cout << endl << "1. �Ӹ���� �Է�, 2. ������� �Է�, 3. �Ӹ���� ����, 4. ������� ����, 5. ���ó�� ����, 6. �ʱ�ȭ" << endl;
		cin >> temp_sel;

		switch (temp_sel)
		{
		case 1:
			cout << "������ �Է� : ";
			cin >> temp_str;
			arrList.AddFront(temp_str);
			break;
		case 2:
			cout << "������ �Է� : ";
			cin >> temp_str;
			arrList.AddNear(temp_str);
			break;
		case 3:
			arrList.RemoveFront();
			break;
		case 4:
			arrList.RemoveNear();
			break;
		case 5:
			arrList.RemoveCurrent();
			break;
		case 6:
			arrList.Clear();
			break;
		default:
			break;
		}

		arrList.Print();
	}

	return 0;
}