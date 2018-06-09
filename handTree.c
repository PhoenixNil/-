//ʹ��ջ�����������ݽṹ������������Ҫ���ú�s.pop��ֵ
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode *Tree;
struct TreeNode
{
	char Data;
	Tree lchild;
	Tree rchild;
};
Tree Create()
{
	Tree T;
	char data;
	scanf("%c", &data);
	if (data == '#')
		T = NULL;
	else
	{
		T = (Tree)malloc(sizeof(struct TreeNode));
		T->Data = data;
		T->lchild = Create();
		T->rchild = Create();
	}
	return T;
}
void PreOrder(Tree T)
{
	Tree S[100];
	int top = 0;
	while (T || top != 0)
	{
		if (T)
			printf("%c ", T->Data);
		if (T)
		{
			top += 1;
			S[top] = T;
			T = T->lchild; //ֱ��������Ϊ��
		}
		else
		{
			T = S[top];
			top = top - 1;
			T = T->rchild;
		}
	}
}

void InOrder(Tree T)
{
	Tree S[100], P = T;
	int top = 0;
	while (P || top != 0)
	{
		if (P)
		{
			S[top++] = P;
			P = P->lchild; //ֱ��������Ϊ��
		}
		else
		{
			P = S[--top];
			printf("%c ", P->Data); //print(P->data)
			P = P->rchild;
		}
	}
}

void AfterOrder(Tree T) /*����ýڵ���ʹ��ˣ�����ֱ����������߸ýڵ���������������������ʹ��ˣ�Ҳ����ֱ�������
	 				ʹ�ñ�־λflag ��ȷ����ڵ��Ƿ����*/
{
	Tree S[100], pre; //KΪ��ǰ�ڵ㣬preΪ��ǰ�ڵ��ǰ���ڵ㣬����ΪNULL
	int flag = 0;
	int top = -1;
	while (T || top != 0)
	{
		if (T)
		{
			S[++top] = T;
			T = T->lchild; //push(p)
			flag = 1;	  //�������Ѿ�����
		}
		else
		{
			pre = NULL;
			while (flag == 1) //��ڵ��Ѿ����ʹ���
			{
				T = S[top];
				if (T->rchild == pre || T->rchild == NULL) //����ҽڵ�Ҳ���ʹ��ˣ�����û���ҽڵ�
				{
					top--; //s.pop()
					printf("%c", T->Data);
					pre = T; //preָ��ǰ�ڵ㣨��ǰ�ڵ��Ϊ��һ���ڵ��ǰ���ڵ㣩
				}
				else //�������ǰ�ڵ�����ҽڵ㣬����ǰ�ڵ���ҽڵ���ջ
				{
					T = T->rchild;
					flag = 0; //������ڵ㻹û����
				}
			}
		}
	}
}

int main()
{
	char ch, y;
	Tree T;
	printf("please input Tree\n");
	T = Create();
	printf("please  Select operation\n");
	scanf("%c", &y);
	scanf("%c", &ch);
	switch (ch)
	{
	case 'a':
		PreOrder(T);
		break;
	case 'b':
		InOrder(T);
		break;
	case 'c':
		AfterOrder(T);
		break;
	default:
		break;
	}
	return 0;
}
