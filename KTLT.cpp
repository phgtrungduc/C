#include<stdio.h>
int main(){
	int A[ ] = {16, 23, 34, 19} ;
int *p = A ;
*p += 2 ;
p += 2 ;
*p--;
*p += 2 ;
for (int i=0;i<4;i++){
printf("%d",A[i]);
printf("\n");	
}
return 0;
}
