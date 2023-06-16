//#include <stdlib.h>
//#include <stdio.h>
//#include "IntQueue.h"
//
//int main()
//{
//	/*
//	
//	*/
//
//	IntQueue que;
//	if (Initialize(&que, 64) == -1)
//	{
//		puts("생성 실패");
//		return 1;
//	}
//	while (1)
//	{
//		int m, x;
//		printf("현재 데이터 수 : %d / %d \n", Size(&que), Capacity(&que));
//		printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (5)검색 (6)가득찼는지 (7)비어있는지 (8)초기화 :");
//		scanf_s("%d", &m);
//
//		if (m == 0) break;
//		switch (m)
//		{
//		case 1:
//			printf("데이터: ");
//			scanf_s("%d", &x);
//			if (Enque(&que, x) == -1)	puts("\a오류: 인큐 실패");
//			break;
//		case 2:
//			if (Deque(&que, &x) == -1)	puts("\a오류: 디큐 실패");
//			else					printf("디큐 데이터는 %d 입니다.\n",x);
//			break;
//		case 3:
//			if (Peek(&que, &x) == -1)	puts("\a오류: 피크 실패");
//			else					printf("피크 데이터는 %d 입니다.\n",x);
//			break;
//		case 4:
//			Print(&que);
//			break;
//		case 5:
//			printf("데이터: ");
//			scanf_s("%d", &x);
//			if(Search(&que, x) == -1) puts("\a오류: 검색 실패");
//			else					printf("%d 는 있습니다.\n",x);
//			break;
//		case 6:
//			if (IsFull(&que))	puts("가득 찼음");
//			else		puts("여유 있음");
//			break;
//		case 7:
//			if (IsEmpty(&que))puts("비어 있음");
//			else		puts("내용 있음");
//			break;
//		case 8:
//			Clear(&que);
//			break;
//		}
//	}
//	Terminate(&que);
//
//}