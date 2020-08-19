#include<stdio.h>
#include<math.h>
int ktsonguyento(int n)
{
	int i;
	if (n==1) return 1;
	else 
	{
	    for (i=2;i<sqrt(n);i++)
	          {
	            if (n%i==0) 
          	       {
		              return 0;
	                	break;
	               }
	           return 1;
	          }
}
}
int main()
{
int n,dem=0,i=1;
printf("nhap n: ");
scanf("%d",&n);
while (dem<n)
{
	if (ktsonguyento(i)==1) dem++;
	i++;
    if (dem ==n) printf ("%d",i);
}

return 0;
}

