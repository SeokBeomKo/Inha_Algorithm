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
		cout << endl << "1. 머리노드 입력, 2. 꼬리노드 입력, 3. 머리노드 삭제, 4. 꼬리노드 삭제, 5. 선택노드 삭제, 6. 초기화" << endl;
		cin >> temp_sel;

		switch (temp_sel)
		{
		case 1:
			cout << "데이터 입력 : ";
			cin >> temp_str;
			arrList.AddFront(temp_str);
			break;
		case 2:
			cout << "데이터 입력 : ";
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