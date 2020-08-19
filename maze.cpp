#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h>
#include<conio.h>
#define size 22
int diem=0;
struct maze{
	char wall;
	bool visited;
} a[size][size];
void initmaze(){
	time_t t;
	srand((unsigned) time(&t));
	for (int i=0;i<size;i++){
		for (int j=0;j<size;j++){
			a[i][j].wall=1;
			a[i][j].visited=0;
		}
	}
	for (int i=0;i<size;i++){
		a[i][0].wall=1;
		a[0][i].wall=1;
		a[size-1][i].wall=1;
		a[i][size-1].wall=1;
		a[i][0].visited=1;
		a[0][i].visited=1;
		a[size-1][i].visited=1;
		a[i][size-1].visited=1;
	}
	a[1][1].wall=0;
	a[size-2][size-2].wall=0;
}
int makeaway(int x,int y){
	time_t t;
	srand((unsigned) time(&t));
	Sleep(5);
	int go = rand()%(4-1+1)+1;//1 sang trai, 2 sang phai, 3 len tren, 4 xuong duoi
	a[x][y].visited=1;
	a[x][y].wall=0;
	if(x==size-2&&y==size-2) return 0;
	else {
		if (go==1&&a[x][y-1].visited==0){
			a[x][y-1].wall=0;
			makeaway(x,y-1);
		}
		else if (go==2&&a[x][y+1].visited==0){
			a[x][y+1].wall=0;
			makeaway(x,y+1);
		}
		else if (go==3&&a[x-1][y].visited==0){
			a[x-1][y].wall=0;
			makeaway(x-1,y);
		}
		else if (go==4&&a[x+1][y].visited==0){
			a[x+1][y].wall=0;
			makeaway(x+1,y);
		}
		else {
			makeaway(x,y);
		}
	}
}
void set(){
	time_t t;
	srand((unsigned) time(&t));
	for (int i=1;i<size-1;i++){
		for (int j=1;j<size-1;j++){
			if(a[i][j].wall !=0) a[i][j].wall=rand()%5;
		}
	}
	for (int i=1;i<size;i++){
		for (int j=1;j<size;j++){
			a[i][j].visited=0;
		}
	}
}

void draw(){
	for (int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(a[i][j].wall==0) printf(" ");
			else if(a[i][j].wall==1) printf("*"); 
			else if(a[i][j].wall=='S') printf("%c",a[i][j].wall);
			else printf("%d",a[i][j].wall);
		}
		printf("\n");
	}
}
void checkpass(int x,int y){
	if(a[x][y].visited==1) a[x][y].wall='S';
}
int solvemaze(int x,int y){
	if (x==size-1&&y==size-1) return 1;
	if (a[x][y].wall=='*'||a[x][y].wall=='S') return 0;
	a[x][y].wall='S';
	
		if(solvemaze(x+1,y)==1) {
			diem = diem +a[x+1][y].wall;
			return 1;
		}
		if(solvemaze(x-1,y)==1) {
			diem = diem +a[x-1][y].wall;
			return 1;
		}
		if(solvemaze(x,y+1)==1) {
			diem = diem +a[x][y+1].wall;
			return 1;
		}
		if(solvemaze(x,y-1)==1) {
			diem = diem +a[x][y-1].wall;
			return 1;
		
//	if()
	return 0;
}
int main(){
	initmaze();
	makeaway(1,1);
	set();
	printf("==================ME CUNG BAN DAU=====================\n");
    draw();
	return 0;
}
