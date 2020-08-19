#include<iostream>
#include<string.h>
#include<stdlib.h>
typedef struct HocSinh{
	char *name;
	float gpa;
}HS;

void changeName(HS &b){
	if(b.name[0] >= 'A' && b.name[0] <= 'Z'){
		b.name[0] = b.name[0] -('A' - 'a');
	}
}
float check (void *a,void *b){
	float *fl1= (float *)a;
	float *fl2=(float *)b;
	return (*fl1-*fl2);
}
int main(){
	int a;
	scanf("%d",a);
//	int *p;
//	*p=5;
//	printf("%d",p);
//	HS hs;
//	hs.name = c;
//	std::cout<<hs.name<<std::endl;
//	changeName(hs);
//	std::cout<<hs.name<<std::endl;
	return 0;
}
