#include<stdio.h>
#include<stdlib.h>
struct phanso{
	int tu;
	int mau;
};
typedef struct phanso phanso;
int uocchung(int a,int b){
	while(a!=b){
		if (a>b) a=a-b;
		else{
			b=b-a;
		}	
	}
	return a;
}
phanso operator ~ (phanso a){
	int c=uocchung(a.tu,a.mau);
	a.tu=a.tu/c;
	a.mau=a.mau/c;
	return a;
}
phanso display(phanso a){
	printf("%d/%d",a.tu,a.mau);
}
int main(){
	phanso a,b;
	a.tu=12;
	a.mau=3;
	b=~a;
	display(a);
	display(b);
	return 0;
}

