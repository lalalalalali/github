#include <stdio.h>
#include<stdlib.h>
#include <malloc.h>

struct STACK {
	int  *elems;	//�����ڴ����ڴ��ջ��Ԫ��
	int   max;	//ջ�ܴ�ŵ����Ԫ�ظ���
	int   pos;	//ջʵ������Ԫ�ظ�����ջ��ʱpos=0;
};
void initSTACK(STACK *const p, int m);	//��ʼ��pָ���ջ�����m��Ԫ��
void initSTACK(STACK *const p, const STACK&s); //��ջs��ʼ��pָ���ջ
int  size(const STACK *const p);		//����pָ���ջ�����Ԫ�ظ���max
int  howMany(const STACK *const p);	//����pָ���ջ��ʵ��Ԫ�ظ���pos
int  getelem(const STACK *const p, int x);	//ȡ�±�x����ջԪ��
STACK *const push(STACK *const p, int e); 	//��e��ջ��������p
STACK *const pop(STACK *const p, int &e); 	//��ջ��e��������p
STACK *const assign(STACK*const p, const STACK&s); //��s��pָ��ջ,������p
void print(const STACK*const p);			//��ӡpָ���ջ
void destroySTACK(STACK*const p);		//����pָ���ջ

int main(int argc, char* argv[]) {
	STACK *p =  (STACK*)malloc(sizeof(STACK));
	int m;
	FILE *fp;
	if (argc > 2) {
		for (int i =0;argv[i][0]=='-';i++)
		{if (i<argc) }
	}
	fp = fopen("U201614760.txt", "w+");
	if (argv[1] == "-S")
	{
		fprintf(fp, "%c", "S");
		
	}

}

void initSTACK(STACK *const p, int m)	//��ʼ��pָ���ջ�����m��Ԫ��
{
	p->max = m;
	p->elems = (int*)malloc(m * sizeof(int));
	p->pos = 0;
}
void initSTACK(STACK *const p, const STACK&s) //��ջs��ʼ��pָ���ջ
{
	initSTACK(p, s.max);
	int i;
	if (s.elems == NULL)
		printf("sջΪ�գ����ʼ��s����\n");
	else
		for (i = 0; i < s.pos; i++) {
			p->elems[i] = s.elems[i];
			p->pos++;
		}
}

int  size(const STACK *const p)		//����pָ���ջ�����Ԫ�ظ���max
{
	return p->max;
}
int  howMany(const STACK *const p)	//����pָ���ջ��ʵ��Ԫ�ظ���pos
{
	return p->pos;
}
int  getelem(const STACK *const p, int x)	//ȡ�±�x����ջԪ��
{
	return p->elems[x];
}
STACK *const push(STACK *const p, int e) 	//��e��ջ��������p
{
	int m;
	if (p->pos >= p->max) {
		printf("ջ����\n");
		printf("�Ƿ���չջ�� 1Ϊ�ǣ�0Ϊ��\n");
		scanf_s("%d", &m);
		if (m == 1) {
			p->elems = (int*)realloc(p,(p->pos+1) * sizeof(int));
			p->elems[p->pos + 1] = e;
			p->pos = p->pos + 1;
			return (p);
		}
		else printf("����ʧ��\n");
	}
	else {
		p->elems[p->pos + 1] = e;
		p->pos = p->pos + 1;
		return (p);
	}
}
STACK *const pop(STACK *const p, int &e) 	//��ջ��e��������p
{
	if (p->pos == 0) {
		printf("ջΪ��\n");
	}
	else {
		e = p->elems[p->pos];
		p->pos = p->pos - 1;
		return (p);
	}
}
STACK *const assign(STACK*const p, const STACK&s) //��s��pָ��ջ,������p
{
	p->elems = s.elems;
	p->max = s.max;
	p->pos = s.pos;
	return p;
}
void print(const STACK*const p)			//��ӡpָ���ջ
{	
	int i;
	if (p->pos == 0) {
		printf("ջΪ��\n");
		printf("�������Ϊ��\t%d", p->max);
	}
	else {
		printf("�������Ϊ��\t%d", p->max);
		printf("��ǰ����Ϊ��\t%d", p->pos);
		printf("\n ���������Ϊ��\n");
		for (i = p->pos - 1; i >= 0; i--) {
			printf("%d\t", p->elems[i]);
		}
	}
}
void destroySTACK(STACK*const p)		//����pָ���ջ
{
	free(p->elems);
	p->max = 0;
	p->pos = 0;
	if (p->max == 0)printf("�ݻٳɹ�\n");
	else printf("�ݻ�ʧ��\n");
}
