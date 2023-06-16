//#include <stdlib.h>
//#include <stdio.h>
//#include "IntStack.h"
//
//int main()
//{
//	IntStack s;
//	if (Initialize(&s, 64) == -1)
//	{
//		puts("스택 생성 실패");
//		return 1;
//	}
//
//	while (1)
//	{
//		int menu, x;
//		printf("현재 데이터 수 : %d / %d\n", Size(&s), Capacity(&s));
//		printf("(1)푸시 (2)팝 (3)피크 (4)출력 (5)검색 (6)가득찼는지 (7)비어있는지 (8)초기화 :");
//		scanf_s("%d", &menu);
//
//		if (menu == 0) break;
//		switch (menu)
//		{
//		case 1:
//			printf("데이터: ");
//			scanf_s("%d", &x);
//			if (Push(&s, x) == -1)	puts("\a오류: 푸시 실패");
//			break;
//		case 2:
//			if (Pop(&s, &x) == -1)	puts("\a오류:   팝 실패");
//			else					printf("팝 데이터는 %d 입니다.\n",x);
//			break;
//		case 3:
//			if (Peek(&s, &x) == -1)	puts("\a오류: 피크 실패");
//			else					printf("피크 데이터는 %d 입니다.\n",x);
//			break;
//		case 4:
//			Print(&s);
//			break;
//		case 5:
//			printf("데이터: ");
//			scanf_s("%d", &x);
//			if(Search(&s, x) == -1) puts("\a오류: 검색 실패");
//			else					printf("%d 는 있습니다.\n",x);
//			break;
//		case 6:
//			if (IsFull(&s))	puts("가득 찼음");
//			else		puts("여유 있음");
//			break;
//		case 7:
//			if (IsEmpty(&s))puts("비어 있음");
//			else		puts("내용 있음");
//			break;
//		case 8:
//			Clear(&s);
//			break;
//		}
//	}
//	Terminate(&s);
//	return 0;
//}
