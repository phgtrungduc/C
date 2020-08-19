#include<stdio.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 25
int top;
char a[MAX];
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
int main(){
	char x;
	init();
	push('a');
	push('b');
	push('c');
	push('d');
	while (top!=2){
		pop(x);
		printf("%c",x);
	}
	return 0;
}
