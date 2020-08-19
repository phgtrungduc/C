#include<stdio.h>
#include<stdlib.h>
void resize(int *p,int firstsize,int newsize){     
	if( newsize > firstsize) {
	    realloc(p,2*firstsize*sizeof(int)); 
	}
	if(newsize <=(1*firstsize/3)) {   
	    realloc(p,(firstsize/2)*sizeof(int));
	}
	
}
void add(int *p,int newsize,int posi, int value){            
	int *p1,i;
	p1 = (int *)malloc(newsize*sizeof(int));
    if (posi == -1){
		for (i=newsize;i>0;i--){
    		*(p+i)=*(p+i-1);	
		}
		*(p)=value;
	}
	else if (posi==-2){
		*(p+newsize)= value;
	}
	else {
		for (i=posi;i<newsize;i++){
			*(p1+i)= *(p+i);   //sao chep mang
	    }
	    *(p+posi)= value;
	    for (i=posi;i<newsize;i++){
		*(p+i+1)=*(p1+i);
	    }
	}
}
void deleteat(int *p,int newsize,int posi){
	int i;
	for (i=posi;i<newsize;i++){ 
		*(p+i)= *(p+i+1);
	}
}
int main(){
	int *p; 
	int firstsize=10;
	p=(int *) malloc(firstsize*sizeof(int));
	int posi,value,chon,i,newsize=0;
	char test='n';
	printf("Bat dau thuc hien nhap, nhan p va enter khi muon dung lai");
	while(1){		
		printf("\nnhap phan tu thu %d: ",newsize);
		scanf("%d",(p+newsize));
	    printf("Ban co muon nhap tiep: (Y/N)");
        fflush(stdin);	   
	    test = getchar();
	    if (test=='y'||test=='Y') newsize++;
	    else break;
	}
		    resize(p,firstsize,newsize);
	do {
		printf("============MENU===========\n");
		printf("1,Them phan tu vao mang\n");
		printf("2,Xoa phan tu khoi mang\n");
		printf("Moi nhap vao lua chon: ");
		scanf("%d",&chon);
		switch (chon){
			case 1: {
	            printf("Nhap vi tri them vao phan tu: ");
               	scanf("%d",&posi);
            	printf("Nhap gia tri them vao: ");
            	scanf("%d",&value);
             	add(p,newsize,posi,value);
             	for (i=0;i<=newsize;i++){
	         	printf("%d  ",*(p+i));
	            }
	            free(p-newsize);
	            break;
	        }
	        
	        case 2:{
	            printf("Nhap vi tri xoa phan tu: ");
               	scanf("%d",&posi);
             	deleteat(p,newsize,posi);
             	for (i=0;i<newsize-1;i++){
	         	printf("%d  ",*(p+i));
	            }
	            free(p-(newsize-1));
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

