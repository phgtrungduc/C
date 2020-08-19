#include<stdio.h>
int main()
{
	int n,i;
	printf("nhap so cac phan tu cua mang: ");
	scanf("%d",&n);
	float a[n],max;
	for (i=0;i<n;i++)
	{
		printf("nhap a[%d]: ",i);
		scanf("%f",&a[i]);
	}
	 max = a[0];
	 for(i=0;i<n;i++)
	 {
	 	if (a[i]> max) max=a[i];
	 }
	printf("gia tri lon nhat cua day so la: %f",max);
return 0;
}

