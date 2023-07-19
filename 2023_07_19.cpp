#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;


int main()
{
	DoublyLinkedList<string> arrList;
	int temp_sel = 0;
	bool temp_print = true;

	string temp_str;
	
	while (true)
	{
		cout << endl << "1. 머리노드 입력, 2. 꼬리노드 입력, 3. 머리노드 삭제, 4. 꼬리노드 삭제, 5. 검색, 6. 초기화 7. 출력 방향 변경" << endl;
		cin >> temp_sel;
	
		switch (temp_sel)
		{
		case 1:
			cout << "데이터 입력 : ";
			cin >> temp_str;
			arrList.push_front(temp_str);
			break;
		case 2:
			cout << "데이터 입력 : ";
			cin >> temp_str;
			arrList.push_back(temp_str);
			break;
		case 3:
			arrList.pop_front();
			break;
		case 4:
			arrList.pop_back();
			break;
		case 5:
			cout << "데이터 입력 : ";
			cin >> temp_str;
			cout << arrList.search(temp_str) << endl;
			break;
		case 6:
			arrList.clear();
			break;
		case 7:
			temp_print = !temp_print;
			break;
		default:
			break;
		}
		if (temp_print)	arrList.print();
		else			arrList.printreverse();
	}

	return 0;
}