#include<stdio.h>
#include<string.h>
int top=-1;
char a[100];
void push(char x){
	top++;
	a[top]=x;
}
void pop(char &x){
	if (top==-1) {
		printf("\nStack rong");
		return ;
	}
	else {
		x= a[top];
		top--;
	}
}
int size(){
	if (top==-1) return 0;
	else return top+1;
}
int xacdinh(char a){
	if (a=='{'||a=='['||a=='(') return 1;
	if (a=='}'||a==']'||a==')') return 2;
	else return 0;
}
int loaingoac(char a){
	if (a=='('||a==')') return 1;
	if (a=='['||a==']') return 2;
	if (a=='{'||a=='}') return 3;
}
int main(){
	char b[100];
	char x;
	printf("\nNhap chuoi: ");
	gets(b);
	int n=strlen(b);
	for (int i=0;i<n;i++){
		if (xacdinh(b[i])==1) push(b[i]);
		if (xacdinh(b[i])==2) {
			if (size()==0) break;
			else {
				char x;
				pop(x);
				if (loaingoac(x)!=loaingoac(b[i])) {
					while (size()!=0) pop(x);
				}
			}
		}
	}
	if (size()==0) printf("\nHem");
	else printf("\nCoa");
	return 0;
}
