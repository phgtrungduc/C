#include<stdio.h>
int main(){
	int B[]={2,4,7,8,9,15};
	int c;
	int *p=&B[1];
	*p+=1;
	c=*p--;
	p=p+=3;
	*p+=c;
	for (int i=0;i<6;i++){
		printf("%d  ",B[i]);
	}
	return 0;
}
