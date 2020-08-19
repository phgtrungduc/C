#include<stdio.h>
void funny(int a[],int size){
	int i,j,temp;
	printf("%d\n",a[7]);
	for (i=0;i<size-1;i++){       // n bi thay doi vi o vong lap dau tien thay doi vi tri voi ca arr[7], ma thuc chat khi khai bao int a[6]
		for (j=0;j<size-i;j++){   // chuong trinh se xin bo nho du dung cho 6 bien trong vung stack nen khi goi sang arr[7] bi tran ra khoi vung 
			if (a[j]>a[j+1]){     // da xin danh cho mang arr, bien n duoc luu o vi tri tiep theo nen arr[7]=n
				temp = a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		printf("lan thu %d\n",i);
		for (int k=0;k<7;k++){
			printf("%d     ",a[k]);
			printf("\n");
		}
	}

}
int main(){
	int arr[]={19,16,122,14,13,12,11},n=9;
	int k=7;
	printf("%d\n",&k);
	printf("%d\n",&n);
	printf("%d\n",&arr[0]);
	printf("%d",&arr[6]);
//	printf("%d\n",&arr[7]);
//	printf("%d\n",&n);
//	printf("before n = %d\n",n);
//	funny(arr,n);
//	printf("after n= %d\n",n);
	return 0;
}
