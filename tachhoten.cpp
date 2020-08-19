#include<stdio.h>
#include<string.h>
char hoten[3][30],ten[3][30];
int n=0;
int tenpos(char *s){
	int i= strlen(s);
	while (s[i]==' '&&i>-1) i--;
	while (s[i]!=' '&&i>-1) i--;
	return i+1;
}
void sapxepVN(){
	int i,j,dai,dem;
	char tg[30];
    for (i=0;i<n-1;i++){
    	for (j=i+1;j<n;j++){
    		if (strcmp((hoten[i]+tenpos(hoten[i])),(hoten[j]+tenpos(hoten[j])))>0){
    			strcpy(tg,hoten[i]);
    			strcpy(hoten[i],hoten[j]);
    			strcpy(hoten[j],tg);
			}
			else if (strcmp((hoten[i]+tenpos(hoten[i])),(hoten[j]+tenpos(hoten[j])))==0){
				if (strcmp(hoten[i],hoten[j])>0){
				strcpy(tg,hoten[i]);
    			strcpy(hoten[i],hoten[j]);
    			strcpy(hoten[j],tg);
				}
			}
		}	
	}
	printf("\nDanh sach da sap xep xong");
}
int main(){
    int i;
	while (n<3){
    	printf("Nhap ho va ten cua sv thu %d: ",n+1);
    	fflush(stdin);
		gets(hoten[n]);
    	n++;
	}
	sapxepVN();
	for (i=0;i<n;i++){
		printf("\nSinh vien thu %d: ",i+1);
		puts(hoten[i]);
	}
	printf("%d",tenpos("dong"));
	return 0;
}
