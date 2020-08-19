#include<stdio.h>
int sotho(int thang){
	if (thang<3) return 1;
	else return (sotho(thang-1)+sotho(thang-2));
}
int tien(int thang){
	int tiennuoi=0;
	for (int i=1;i<=thang;i++){
		tiennuoi+=sotho(i)*1;
	}
	int tienlai=0;
	tienlai = sotho(thang)*10-tiennuoi-5;
	return tienlai;
}
int main(){
	int thang;
	printf("%d",tien(2));
	return 0;
}
