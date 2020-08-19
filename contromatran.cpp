#include<stdio.h>
int main(){
	int mt[3][3]={{7,8,9},{10,11,12},{13,14,15}};
	int i,j;
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			printf("%d   ",*(*(mt+i)+j));
		}
		printf("\n");
	}
	return 0;
}
