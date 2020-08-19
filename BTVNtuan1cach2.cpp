#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
int *p=(int *) malloc(10*sizeof(int));
int size=0;
void resize(int newsize){     // ham cap phat lai mang voi he so nap 2/3
	int dem = size;
	while(newsize >=(2*dem/3)) {
		dem=2*dem;
	    realloc(p,dem*sizeof(int));
	}
	while(newsize <=(1*dem/3)) {
		dem=dem/2;
	    realloc(p,dem*sizeof(int));
	}
}
void add(int posi, int value){            
	int *p1,i;
	p1 = (int *)malloc(size*sizeof(int));
    if (posi == -1){
		for (i=size;i>0;i--){
    		*(p+i)=*(p+i-1);	
		}
		*(p)=value;
	}
	else if (posi==-2){
		*(p+size)= value;
	}
	else {
		for (i=posi;i<size;i++){
			*(p1+i)= *(p+i);   //sao chep mang
	    }
	    *(p+posi)= value;
	    for (i=posi;i<size;i++){
		*(p+i+1)=*(p1+i);
	    }
	}
}
void deleteat(int posi){
	int i;
	for (i=posi;i<size;i++){ 
		*(p+i)= *(p+i+1);
	}
}
int main(){
	int posi,value,lamda,chon,i;
	char test='n';
	do {
		system("cls");
		printf("============MENU===========\n");
		printf("1,Them phan tu vao mang\n");
		printf("2,Xoa phan tu khoi mang\n");
		printf("Moi nhap vao lua chon: ");
		scanf("%d",&chon);
		size =0;
		switch (chon){
			case 1: {
	           	while (1){
	           		printf("Nhap phan tu thu %d ?(y/n)",size);
	           		fflush(stdin);
					test= getchar();
	           		if(test =='y'||test=='Y' ){
	           			scanf("%d",(p+size));
	           			size++;
	           			resize(size);
					}
					else break;    
	            }
	            printf("Nhap vi tri them vao phan tu: ");
               	scanf("%d",&posi);
            	printf("Nhap gia tri them vao: ");
            	scanf("%d",&value);
             	add(posi,value);
             	for (i=0;i<=size;i++){
	         	printf("%d  ",*(p+i));
	            }
	            free(p-size);
	            break;
	        }
	        
	        case 2:{
             	while (1){
		        printf("Nhap phan tu thu %d? (y/n) ",size);
		        fflush(stdin);
				test= getchar();
		        if (test=='y'||test=='Y'){
		        	scanf("%d",(p+size));
		        	size++;
				}
				else break;
            	}
	            printf("Nhap vi tri xoa phan tu: ");
               	scanf("%d",&posi);
             	deleteat(posi);
             	for (i=0;i<size-1;i++){
	         	printf("%d  ",*(p+i));
	            }
	            free(p-(size-1));
				break;
			}
			default: {
				printf("Chuc nang ban nhap chua duoc ho tro");
				free(p);
				break;
			}
	    }
	    printf("\nBan co muon tiep tuc? (Y/N)\n");
		scanf("%s",&test);
    } while (test=='Y'||test=='y');
	return 0;
}

