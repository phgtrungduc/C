#include<stdio.h>
int myst(int x,int n){
	int y;
	if (n==0) return 1;
	if (n%2==1){
		y=myst(x,(n-1)/2);
		return x*y*y;
	}
	else {
		y=myst(x,n/2);
		return y*y;
	}
}
int a[6];
int top=-1;
int push(int x){
	top++;
	a[top]=x;
}
int pop(){
	int x=a[top];
	top--;
	return x;
}
int main(){
	int i=5,dem=1;
	while (i!=0){
		if (i%2==1){
			push(i);
			i=(i-1)/2;
		}
		else {
			push(i);
			i=(i/2);
		}
	}
	while (top!=-1){
		int x=pop();
		if (x%2==1) dem=dem*dem*2;
		else dem=dem*dem;
	}
	printf("%d",dem);
	return 0;
}

