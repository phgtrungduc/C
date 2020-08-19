#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int checkflower(char *s){   //kiem tra ki tu hoa 
	int n= strlen(s);
	if (n==1){
		if (s[0]>=65&&s[0]<=90) return 1;
		else return 0;
	}
	else {
		for (int i=0;i<n;i++){
			if (s[i]>=65&&s[i]<=90) return 1;
		}
		return 0;
	}
}
int checknumber(char *s){          //kiem tra ki tu so
	int n= strlen(s);
	if (n==1){
		if (s[0]>=48&&s[0]<=57) return 1;
		else return 0;
	}
	else {
		for (int i=0;i<n;i++){
			if (s[i]>=48&&s[i]<=57) return 1;
		}
		return 0;
	}
}
int edit_distance(char *A, char *B){
    int n=strlen(A), m=strlen(B);
    int ED[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
        	ED[i][j]=0;
		}
    }
    for(int j=0;j<=m;j++){
        ED[0][j]=j;
    }
    for(int i=0;i<=n;i++){
        ED[i][0]=i;
    }
    int tg;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ED[i][j]=ED[i-1][j] + 1;
            ED[i][j]=( ED[i][j]<ED[i][j-1]+1?ED[i][j]:ED[i][j-1]+1 );
            tg = ( A[i-1]==B[j-1]?0:1 );
            ED[i][j]=( ED[i][j]<ED[i-1][j-1]+tg?ED[i][j]:ED[i-1][j-1]+tg );
        }
    }
    return ED[n][m];
}
int main(){
	int size=3608,dem=0,count=0,count2=0;
	char tu[20];
	char **vb=(char **)malloc(200000*sizeof(char*));
	char **vb2=(char **)malloc(200000*sizeof(char*));
	char **sai;
	int *flag;
	int *check;
	int n;
	FILE *f; 
	char tudien[3608][20],tg[20];;
	f= fopen("D://tudien.txt","r+");
	if(f==NULL) printf("mo file tu dien k thanh cong");
	else{
		for (int i=0;i<3608;i++){
			fscanf(f,"%s",&tudien[i]);
		}
	}
	fclose(f);
	f=fopen("D://vanban.txt","r+");
	if (f==NULL) printf("Mo file van ban khong thanh cong");
	else {
		int i=0;
		while(feof(f)==0){
			fscanf(f,"%s",&tg);
			vb2[i]=(char *)malloc((strlen(tg)+1)*sizeof(char));
			strcpy(vb2[i],tg);
			i++;
		}
		count2=i;
	}
	fclose(f);
	for (int i=0;i<count2;i++){
		for(int j=0;j<strlen(vb2[i]);j++){
			if(vb2[i][j]>=33&&vb2[i][j]<=47) vb2[i][j]=' ';
		}
	}
	f=fopen("D://vanban2.txt","a+");
	if(f==NULL) printf("Mo file vanban2 khong thanh cong");
	else {
		for(int i=0;i<count2;i++){
			fputs(vb2[i],f);       //ghi mang vb2 la mang da xu li dau cau vao file vanban cai nay chi lam 1 lan
			fputs(" ",f);
		}
	}
	fclose(f);
	f=fopen("D://vanban2.txt","r+");
	if(f==NULL) printf("Mo file vanban2 khong thanh cong");
	else {
		int i=0;
		while(feof(f)==0){
			fscanf(f,"%s",&tg);
			vb[i]=(char *)malloc((strlen(tg)+1)*sizeof(char));
			strcpy(vb[i],tg);
			i++;
		}
		count =i;
	}
	fclose(f);
	flag = (int *)malloc((count)*sizeof(int));
    check = (int *)malloc((count)*sizeof(int));
    for (int i=0;i<count;i++){               //kiem tra xem vb[i] co trong tu dien k, neu co thi gan nhan check[i]=1 va =0 neu nguoc lai
    	for (int j=0;j<size;j++){
    		if (strcmp(vb[i],tudien[j])==0) {
    			check[i]=1;
    			break;
			}
			else check[i]=0;		
		}
	}
    for (int i=0;i<count;i++){
    	if (checkflower(vb[i])==1||checknumber(vb[i])==1) flag[i]=1;     //nhung tu nao trong van ban la chu hoa hoac la so thi bi loai bo bang cach gan nhan flag[]=1
    	else flag[i] =0;
	}
    for (int i=0;i<count;i++){
    	if (flag[i]==0&&check[i]==0) { //tim ra so luong tu sai
    		dem++;
		}
	}
	sai = (char **)malloc(dem*sizeof(char**));
	int j=0;
	for (int i=0;i<count;i++){
    	if (flag[i]==0&&check[i]==0) {                                         //nhung tu sai duoc sao chep sang mang sai
    		sai[j] = (char *)malloc((strlen(vb[i])+1)*sizeof(char*));
			strcpy(sai[j],vb[i]);
    		j++;
		}
	}
	dem =j; // so luong tu sai
	//cac tu sai co the giong nhau nen chung ta se loai bo nhung tu giog nhau chi giu lai 1 tu
	for (int i=0;i<dem;i++){
		for (int j=i+1;j<dem;j++){  
			if (strcmp(sai[i],sai[j])==0){
				for (int k=j;k<dem;k++){
					strcpy(sai[k],sai[k+1]);
					dem--;
				}
			}
		}
	}
	//dem gio se la so tu bi sai va k co tu nao giong nhau
	int ed[dem][size];
	for (int i=0;i<dem;i++){
		for (int j=0;j<size;j++){
			ed[i][j]=edit_distance(sai[i],tudien[j]);    //luu lai khoang cach giua cac tu trong tu dien va cac tu bi sai tu van ban
		}
	}
	int min[dem][3];   // mang luu lai gia tri edit dis be nhat cua cac tu bi sai 
	int luuvet[dem][3];   // mang luu lai vi tri tu co edit be nhat voi tu bi sai
	for (int i=0;i<dem;i++){           //cho
		for (int j=0;j<3;j++){
			min[i][j]=999;
		}
	}
	for (int i=0;i<dem;i++){
		for (int j=1;j<size;j++){
			if (min[i][1]>ed[i][j]){
				min[i][1]= ed[i][j];
				luuvet[i][1]= j;
			}
		}
	}
	for (int i=0;i<dem;i++){
		for (int j=1;j<size;j++){
			if (min[i][2]>ed[i][j]&&j!=luuvet[i][1]){
				min[i][2]= ed[i][j];
				luuvet[i][2]= j;
			}
		}
	}
	for (int i=0;i<dem;i++){
		for (int j=1;j<size;j++){
			if (min[i][3]>ed[i][j]&&j!=luuvet[i][1]&&j!=luuvet[i][2]){
				min[i][3]= ed[i][j];
				luuvet[i][3]= j;
			}
		}
	}
	printf("Danh sach cac tu sai:\n");
	for (int i=0;i<dem;i++){
		printf("%s: %s, %s,%s ",sai[i],tudien[(luuvet[i][1])],tudien[(luuvet[i][2])],tudien[(luuvet[n][2])]);
	    printf("\n");
	}
	return 0;
}
