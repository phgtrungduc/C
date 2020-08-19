#include <stdio.h>
#include <conio.h>

#define TenFile "Bai2.inp"

void Doc_File(int **A,int &n)  {
 FILE*f = fopen("D:\\matran.txt","r+t");
 fscanf(f,"%d",&n);
 *A = new int [n];
printf("ma tran lien ket cua do thi\n");
 for(int i =0;i<n;i++) {
 A[i] = new int [n];
  for(int j =0;j<n;j++) {
  fscanf(f,"%d",&A[i][j]);
 
  }
 }
 fclose(f);
}
int TPLien_Thong(int **A, int n){
 char*DanhDau = new char [n];
 char ThanhCong; 
 int Dem=0, i,j, MLT=0;
 for( i = 0; i<n; i++)     
 DanhDau[i] = 0;
 do {
 j = 0;
  while(DanhDau[j]==1) 
  j++;
  DanhDau[j] = 1;   
  Dem++;     
  MLT++;      
  do {
  ThanhCong =0;
   for(i = 0; i<n; i++)
    if(DanhDau[i]==1)
    for(j = 0; j<n; j++)
     if (DanhDau[j] == 0 && A[i][j] > 0) {
      DanhDau[j] = 1;
      ThanhCong =1;
      Dem++;
     if(Dem == n) return MLT;
     }
  }while (ThanhCong == 1);
 } while(Dem<n);     
 return MLT;
}

int main(){
 int **A,n;
 Doc_File(A,n);
 
 delete *A;
 return 0;
}
