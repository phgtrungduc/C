#include<stdio.h>
#include<stdlib.h>
int matran[8][8];
int duongdi[8][8];
int diqua[8][8];
int movex[4]={1,0,-1,0};
int movey[4]={0,1,0,-1};
void khoitaomecung(){
	FILE *f;
	f=fopen("D://matran.txt","r+");
	for (int i=0;i<7;i++){
		for (int j=0;j<7;j++){
			fscanf(f,"%d",&matran[i][j]);
		}
	}
	fclose(f);
	for (int i=0;i<8;i++){
		for (int j=0;j<8;j++){
			duongdi[i][j]=0;
		}
	}
}
void xuatmecung(){
	for (int i=0;i<7;i++){
		for (int j=0;j<7;j++){
			printf("%d  ",matran[i][j]);
		}
		printf("\n");
	}
}
void giaimecung(int i,int j){
	if (i==7&&j==7) return;
	if (diqua[i][j]==0){
		diqua[i][j]=1;
		if (duongdi[i+1][j]!=0){
			giaimecung(i+1,j);
		}
		if (duongdi[i-1][j]!=0){
			giaimecung(i-1,j);
		}
		if (duongdi[i][j+1]!=0){
			giaimecung(i+1,j);
		}
		if (duongdi[i][j-1]!=0){
			giaimecung(i,j-1);
		}
		
	}
}
int main(){
	khoitaomecung();
	xuatmecung();
	return 0;
}
