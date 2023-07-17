#include <iostream>
#include "SingleLinkedList.h"

using namespace std;

/*
Q1. 학생 관리하는 구조체를 생성하고
	번호, 이름 을 멤버로 포함
	구조체 리스트 만들고
	1. 입력 
		> 번호, 이름

	2. 삭제
		> 번호 입력받아서 리스트에서 삭제

	3. 전체 출력
		> 리스트에 있는 모든 학생의 번호, 이름 출력
*/


int main()
{
	SingleLinkedList* list = new SingleLinkedList();

	int		select;	

	int		temp_num;
	string	temp_name;
	Node*	temp_node = new Node();

	while (true)
	{
		temp_num = 0;

		cout << endl << "1. 입력, 2. 삭제, 3. 전체 출력, 4. 종료" << endl;
		cin >> select;

		switch (select)
		{
		case 1:
			cout << endl << "번호, 이름 입력" << endl;
			cin >> temp_num >> temp_name;

			temp_node = new Node{temp_num, temp_name , nullptr};
			list->push_back(temp_node);
			break;
		case 2:
			cout << endl << "삭제할 번호 입력" << endl;
			cin >> temp_num;

			list->pop_num(temp_num);
			break;
		case 3:
			cout << endl;
			list->print();
			cout << endl;
			break;
		default:
			break;
		}
	}

	return 0;
}