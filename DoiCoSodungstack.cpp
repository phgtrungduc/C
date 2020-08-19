#include<stdio.h>
int a[100];
int top=-1;
void push(int x){
	top++;
	a[top]=x;
}
int pop(){
	int x;
	if (top==-1) printf("\nNgan xep rong");
	else {
		x = a[top];
		top--;
	}
	return x;
}
int main(){
	int x;
	int b[100];
	int i=0,n,k=0;
	printf("Nhap so: ");
	scanf("%d",&n);
	do {
		push(n%2);
		n=n/2;
		k++;
	} while (n>0);
	for (int j=0;j<=top;j++){
		printf("%d ",a[j]);
	}
	while(top!=-1){
		b[i]=pop();
		i++;
	}
	for (int i=0;i<k;i++){
		printf("%d  ",b[i]);
	}
	return 0;
}
