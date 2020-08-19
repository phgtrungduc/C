#include<stdio.h>
typedef struct time{
	int gio;
	int phut;
	int giay;
}time;
void display(time t){
	printf("bay gio la: %dh:%dm:%ds",t.gio,t.phut,t.giay);
}
time operator +(time a,time b){
	time tong;
	if (a.giay+b.giay<60){
		tong.giay=a.giay+b.giay;
		if (a.phut+b.phut<60){
			tong.phut=a.phut+b.phut;
			if(a.gio+b.gio<24){
				tong.gio=a.gio+b.gio;
			}
			else printf("qua mot ngay roi");
		} 
		else (a+phut)
	}
}
int main(){
	time t;
	t.gio=5;
	t.phut=6;
	t.giay=7;
	display(t);
}
