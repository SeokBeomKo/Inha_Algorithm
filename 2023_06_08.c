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
//		puts("���� ����");
//		return 1;
//	}
//	while (1)
//	{
//		int m, x;
//		printf("���� ������ �� : %d / %d \n", Size(&que), Capacity(&que));
//		printf("(1)��ť (2)��ť (3)��ũ (4)��� (5)�˻� (6)����á���� (7)����ִ��� (8)�ʱ�ȭ :");
//		scanf_s("%d", &m);
//
//		if (m == 0) break;
//		switch (m)
//		{
//		case 1:
//			printf("������: ");
//			scanf_s("%d", &x);
//			if (Enque(&que, x) == -1)	puts("\a����: ��ť ����");
//			break;
//		case 2:
//			if (Deque(&que, &x) == -1)	puts("\a����: ��ť ����");
//			else					printf("��ť �����ʹ� %d �Դϴ�.\n",x);
//			break;
//		case 3:
//			if (Peek(&que, &x) == -1)	puts("\a����: ��ũ ����");
//			else					printf("��ũ �����ʹ� %d �Դϴ�.\n",x);
//			break;
//		case 4:
//			Print(&que);
//			break;
//		case 5:
//			printf("������: ");
//			scanf_s("%d", &x);
//			if(Search(&que, x) == -1) puts("\a����: �˻� ����");
//			else					printf("%d �� �ֽ��ϴ�.\n",x);
//			break;
//		case 6:
//			if (IsFull(&que))	puts("���� á��");
//			else		puts("���� ����");
//			break;
//		case 7:
//			if (IsEmpty(&que))puts("��� ����");
//			else		puts("���� ����");
//			break;
//		case 8:
//			Clear(&que);
//			break;
//		}
//	}
//	Terminate(&que);
//
//}