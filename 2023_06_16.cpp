#include <iostream>
#include <conio.h>

using namespace std;
 
#define MAX 4

int queen[MAX];					// 퀸의 위치
int rowCheck[MAX];				// 해당 행에 퀸이 있는지 체크
int diagRCheck[MAX * 2 - 1];	// ＼방향 체크
int diagLCheck[MAX * 2 - 1];	// / 방향 체크

int cnt = 0;

void printBoard()
{
	int queenrow = 0;
	for (int i = 0; i < MAX; i++)
	{
		queenrow = queen[i];
		for (int j = 0; j < MAX; j++)
		{
			if (queenrow == j)	cout << "■";
			else				cout << "□";
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
		// 행, 오대각, 왼대각 조건 체크
		if (!rowCheck[_row] && !diagRCheck[_column - _row + MAX-1] && !diagLCheck[_column + _row])
		{
			// 조건 만족한다면, 이번 재귀(행) 의 퀸의 열의 위치를 설정
			queen[_column] = _row;

			// 모든 행의 퀸의 위치가 결정되다면, 보드판 출력
			if (_column == MAX - 1)
			{
				printBoard();
			}
			else
			{
				// 행, 오대각, 왼대각 설정
				// diagRCheck : MAX 가 8 일 경우 x - y 가 7 ~ -7 까지의 범위이기 때문에 +7 (15 ~ 0)
				rowCheck[_row] = diagRCheck[_column - _row + MAX - 1] = diagLCheck[_column + _row] = 1;
				// 다음 열로 넘어간다
				set(_column + 1);
				// 돌아가면서 조건 초기화
				rowCheck[_row] = diagRCheck[_column - _row + MAX - 1] = diagLCheck[_column + _row] = 0;
			}
		}
	}
}


int main()
{
	/*
	재귀 알고리즘 : 8퀸 문제
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

	cout << "경우의 수 : " << cnt << endl;

	return 0;
}