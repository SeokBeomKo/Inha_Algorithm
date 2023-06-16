//#include <stdlib.h>
//#include <stdio.h>
//#include "IntStack.h"
//
//int main()
//{
//	IntStack s;
//	if (Initialize(&s, 64) == -1)
//	{
//		puts("���� ���� ����");
//		return 1;
//	}
//
//	while (1)
//	{
//		int menu, x;
//		printf("���� ������ �� : %d / %d\n", Size(&s), Capacity(&s));
//		printf("(1)Ǫ�� (2)�� (3)��ũ (4)��� (5)�˻� (6)����á���� (7)����ִ��� (8)�ʱ�ȭ :");
//		scanf_s("%d", &menu);
//
//		if (menu == 0) break;
//		switch (menu)
//		{
//		case 1:
//			printf("������: ");
//			scanf_s("%d", &x);
//			if (Push(&s, x) == -1)	puts("\a����: Ǫ�� ����");
//			break;
//		case 2:
//			if (Pop(&s, &x) == -1)	puts("\a����:   �� ����");
//			else					printf("�� �����ʹ� %d �Դϴ�.\n",x);
//			break;
//		case 3:
//			if (Peek(&s, &x) == -1)	puts("\a����: ��ũ ����");
//			else					printf("��ũ �����ʹ� %d �Դϴ�.\n",x);
//			break;
//		case 4:
//			Print(&s);
//			break;
//		case 5:
//			printf("������: ");
//			scanf_s("%d", &x);
//			if(Search(&s, x) == -1) puts("\a����: �˻� ����");
//			else					printf("%d �� �ֽ��ϴ�.\n",x);
//			break;
//		case 6:
//			if (IsFull(&s))	puts("���� á��");
//			else		puts("���� ����");
//			break;
//		case 7:
//			if (IsEmpty(&s))puts("��� ����");
//			else		puts("���� ����");
//			break;
//		case 8:
//			Clear(&s);
//			break;
//		}
//	}
//	Terminate(&s);
//	return 0;
//}
