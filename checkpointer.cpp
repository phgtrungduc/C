#include<stdio.h>
void check(int &a){
	(a)++;
}
int main()
{
    int n=100;
    check(n);
    printf("%d",n);
	return 0;
}
