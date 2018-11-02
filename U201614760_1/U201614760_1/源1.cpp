#include <stdio.h>
#include<stdlib.h>
#include <malloc.h>

struct STACK {
	int  *elems;	//申请内存用于存放栈的元素
	int   max;	//栈能存放的最大元素个数
	int   pos;	//栈实际已有元素个数，栈空时pos=0;
};
void initSTACK(STACK *const p, int m);	//初始化p指向的栈：最多m个元素
void initSTACK(STACK *const p, const STACK&s); //用栈s初始化p指向的栈
int  size(const STACK *const p);		//返回p指向的栈的最大元素个数max
int  howMany(const STACK *const p);	//返回p指向的栈的实际元素个数pos
int  getelem(const STACK *const p, int x);	//取下标x处的栈元素
STACK *const push(STACK *const p, int e); 	//将e入栈，并返回p
STACK *const pop(STACK *const p, int &e); 	//出栈到e，并返回p
STACK *const assign(STACK*const p, const STACK&s); //赋s给p指的栈,并返回p
void print(const STACK*const p);			//打印p指向的栈
void destroySTACK(STACK*const p);		//销毁p指向的栈

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

void initSTACK(STACK *const p, int m)	//初始化p指向的栈：最多m个元素
{
	p->max = m;
	p->elems = (int*)malloc(m * sizeof(int));
	p->pos = 0;
}
void initSTACK(STACK *const p, const STACK&s) //用栈s初始化p指向的栈
{
	initSTACK(p, s.max);
	int i;
	if (s.elems == NULL)
		printf("s栈为空，请初始化s！！\n");
	else
		for (i = 0; i < s.pos; i++) {
			p->elems[i] = s.elems[i];
			p->pos++;
		}
}

int  size(const STACK *const p)		//返回p指向的栈的最大元素个数max
{
	return p->max;
}
int  howMany(const STACK *const p)	//返回p指向的栈的实际元素个数pos
{
	return p->pos;
}
int  getelem(const STACK *const p, int x)	//取下标x处的栈元素
{
	return p->elems[x];
}
STACK *const push(STACK *const p, int e) 	//将e入栈，并返回p
{
	int m;
	if (p->pos >= p->max) {
		printf("栈已满\n");
		printf("是否扩展栈？ 1为是，0为否\n");
		scanf_s("%d", &m);
		if (m == 1) {
			p->elems = (int*)realloc(p,(p->pos+1) * sizeof(int));
			p->elems[p->pos + 1] = e;
			p->pos = p->pos + 1;
			return (p);
		}
		else printf("插入失败\n");
	}
	else {
		p->elems[p->pos + 1] = e;
		p->pos = p->pos + 1;
		return (p);
	}
}
STACK *const pop(STACK *const p, int &e) 	//出栈到e，并返回p
{
	if (p->pos == 0) {
		printf("栈为空\n");
	}
	else {
		e = p->elems[p->pos];
		p->pos = p->pos - 1;
		return (p);
	}
}
STACK *const assign(STACK*const p, const STACK&s) //赋s给p指的栈,并返回p
{
	p->elems = s.elems;
	p->max = s.max;
	p->pos = s.pos;
	return p;
}
void print(const STACK*const p)			//打印p指向的栈
{	
	int i;
	if (p->pos == 0) {
		printf("栈为空\n");
		printf("最大容量为：\t%d", p->max);
	}
	else {
		printf("最大容量为：\t%d", p->max);
		printf("当前的数为：\t%d", p->pos);
		printf("\n 里面的内容为：\n");
		for (i = p->pos - 1; i >= 0; i--) {
			printf("%d\t", p->elems[i]);
		}
	}
}
void destroySTACK(STACK*const p)		//销毁p指向的栈
{
	free(p->elems);
	p->max = 0;
	p->pos = 0;
	if (p->max == 0)printf("摧毁成功\n");
	else printf("摧毁失败\n");
}
