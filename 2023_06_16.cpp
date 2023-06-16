#include <iostream>
#include <conio.h>

using namespace std;
 
#define MAX 4

int queen[MAX];					// ���� ��ġ
int rowCheck[MAX];				// �ش� �࿡ ���� �ִ��� üũ
int diagRCheck[MAX * 2 - 1];	// ������ üũ
int diagLCheck[MAX * 2 - 1];	// / ���� üũ

int cnt = 0;

void printBoard()
{
	int queenrow = 0;
	for (int i = 0; i < MAX; i++)
	{
		queenrow = queen[i];
		for (int j = 0; j < MAX; j++)
		{
			if (queenrow == j)	cout << "��";
			else				cout << "��";
		}
		cout << "\n";
	}
	cout << "\n";
	char a;
	//a = _getch();
	cnt++;
}

void set(int _column)
{
	for (int _row = 0; _row < MAX; _row++)
	{
		// ��, ���밢, �޴밢 ���� üũ
		if (!rowCheck[_row] && !diagRCheck[_column - _row + MAX-1] && !diagLCheck[_column + _row])
		{
			// ���� �����Ѵٸ�, �̹� ���(��) �� ���� ���� ��ġ�� ����
			queen[_column] = _row;

			// ��� ���� ���� ��ġ�� �����Ǵٸ�, ������ ���
			if (_column == MAX - 1)
			{
				printBoard();
			}
			else
			{
				// ��, ���밢, �޴밢 ����
				// diagRCheck : MAX �� 8 �� ��� x - y �� 7 ~ -7 ������ �����̱� ������ +7 (15 ~ 0)
				rowCheck[_row] = diagRCheck[_column - _row + MAX - 1] = diagLCheck[_column + _row] = 1;
				// ���� ���� �Ѿ��
				set(_column + 1);
				// ���ư��鼭 ���� �ʱ�ȭ
				rowCheck[_row] = diagRCheck[_column - _row + MAX - 1] = diagLCheck[_column + _row] = 0;
			}
		}
	}
}


int main()
{
	/*
	��� �˰��� : 8�� ����
	*/
	for (int i = 0; i < MAX; i++)
	{
		queen[i] = rowCheck[i] = 0;
	}
	for (int i = 0; i < MAX * 2 - 1; i++)
	{
		diagRCheck[i] = diagLCheck[i] = 0;
	}
	set(0);

	cout << "����� �� : " << cnt << endl;

	return 0;
}