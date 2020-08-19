#include<stdio.h>
#include<string.h>
struct giadinh{
	char vaive[50],hoten[50];
	int tuoi;
	char nghenghiep[50];
};                                

int main(){
	struct giadinh duc;
	struct giadinh *pduc;
	pduc= &duc;
	int n,i;
	strcpy(pduc->hoten,"Phuong Trung Duc");
	strcpy(pduc->vaive,"Chau");
	pduc->tuoi= 20;
	strcpy(pduc->nghenghiep,"sinh vien");
	printf("==========DANH SACH THANH VIEN TRONG GIA DINH==========");
	printf("\nHo va ten           Vai ve          Nghe nghiep         Tuoi\n");
	printf("%-20s %-36s %-56s %d",pduc->hoten,pduc->vaive,pduc->nghenghiep,pduc->tuoi);
	return 0;
}
