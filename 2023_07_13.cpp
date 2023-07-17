#include <iostream>
#include "SingleLinkedList.h"

using namespace std;

/*
Q1. �л� �����ϴ� ����ü�� �����ϰ�
	��ȣ, �̸� �� ����� ����
	����ü ����Ʈ �����
	1. �Է� 
		> ��ȣ, �̸�

	2. ����
		> ��ȣ �Է¹޾Ƽ� ����Ʈ���� ����

	3. ��ü ���
		> ����Ʈ�� �ִ� ��� �л��� ��ȣ, �̸� ���
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

		cout << endl << "1. �Է�, 2. ����, 3. ��ü ���, 4. ����" << endl;
		cin >> select;

		switch (select)
		{
		case 1:
			cout << endl << "��ȣ, �̸� �Է�" << endl;
			cin >> temp_num >> temp_name;

			temp_node = new Node{temp_num, temp_name , nullptr};
			list->push_back(temp_node);
			break;
		case 2:
			cout << endl << "������ ��ȣ �Է�" << endl;
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