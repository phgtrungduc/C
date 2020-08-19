#include<stdio.h>
#include<stdio.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#define MAX 25
int top;
char a[MAX];
char hauto[50];
void init(){
	top=-1;
}
int isempty(){
	if(top==-1) return 1;
	else return 0;
}
int isfull(){
	if (top == MAX -1) return 1;
	else return 0;
}
int push(char x){
	if (isfull()) {
		printf("\nStack day roi");
		return 0;
	}
	else {
		top++;
		a[top]=x;
		return 1;
	}
}
char pop(char &x){
	if (isempty()) {
		printf("\nStack dang rong roi");
		return 0;
	}
	else {
		x=a[top];
		top--;
		return 1;
	}
}
int checkop(char a){
	if (a=='^'||a=='+'||a=='-'||a=='*'||a=='/'||a=='%') return 1;
	return 0;
}
int uutien(char a){
	if (a=='^') return 6;
	if (a=='*'||a=='/'||a=='%') return 5;
	if (a=='+'||a=='-') return 4;
	return 0;
}
int chuyendoi(char c){
	return (c-'0');
}
int pheptinh(int c,int d,char op){
	switch (op){
		case '^':{
			return (pow(c,d));
			break;
		}
		case '+':{
			return c+d;
			break;
		}
		case '-':{
			return c-d;
			break;
		}
		case '*':{
			return c*d;
			break;
		}
		case '/':{
			return c/d;
			break;
		}
		default:{
			return c%d;
			break;
		}
	}
}
struct node{
	int data;
	struct node *next;
};
typedef struct node NODE;
struct list{
	NODE *head;
	int top;
};
typedef struct list LIST;
void init(LIST &l){
	l.head=NULL;
	l.top=-1;
}
NODE *initnode(int x){
	NODE *p;
	p = (NODE *)malloc(sizeof(NODE));
	p->data=x;
	p->next=NULL;
	return p;
}
void push(LIST &l,NODE *p){
	if(l.top==-1){
		l.head=p;
		l.top++;
	}
	else {
		p->next=l.head;
		l.head=p;
		l.top++;
	}
}
void pop(list &l,int &x){
	if (l.top==-1) printf("\nStack rong");
	else {
		x=l.head->data;
		l.head=l.head->next;
		l.top--;
	}
}
int main(){
	char c[50];
	int dem=0;
	printf("\nNhap phep tinh: ");
	gets(c);
	for (int i=0;i<strlen(c);i++){
		if (c[i]!='('&&c[i]!=')'){    //TH1: khong phai dau dong mo ngoac
			if (isdigit(c[i])) {     
				hauto[dem]=c[i];
				dem++;
			}
			else {
				if (top==-1||a[top]=='('||uutien(c[i]==6)||uutien(c[i])>uutien(a[top])) push(c[i]);
				else {
					while (top!=-1&&uutien(c[i])<=uutien(a[top])){
						pop(hauto[dem]);
						dem++;
					}
					push(c[i]);
				}
			}
		}
		else {     //TH2: Neu la dau dong mo ngoac 
			if (c[i]=='(') push(c[i]);
			if (c[i]==')'){
				while (checkop(a[top])==1&&top!=-1){
					pop(hauto[dem]);
					dem++;
				}
				pop(a[top]);
			}
		}
		if (i==strlen(c)-1){
			while (top!=-1) {
				pop(hauto[dem]);
				dem++;
			}
		}
	}
	printf("\nViet theo kieu hau to: \n");
	for (int i=0;i<dem-1;i++){
		printf("%c",hauto[i]);
	}
	printf("\nNhan enter de thuc hien tinh toan");
	getch();
	LIST l;
	init(l);
	NODE *p;
	for (int i=0;i<dem-1;i++){
		if (isdigit(hauto[i])) {
			int x;
			x= chuyendoi(hauto[i]);
			p = initnode(x);
			push(l,p);
		}
		else {
			int x, y;
			pop(l,x);
			pop(l,y);
			p= initnode(pheptinh(y,x,hauto[i]));
			push(l,p);
		}
	}
	int x;
	pop(l,x);
	printf("\nGia tri phep tinh : %d",x);
	return 0;
}
