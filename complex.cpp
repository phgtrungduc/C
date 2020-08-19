#include<stdio.h>  
#include<conio.h> 
 
struct Complex 
{  
    float real;  
    float img;  
};  


Complex add_complex( Complex z1, Complex z2 ) 
{  
    Complex z3;  
    z3.real = z1.real + z2.real;  
    z3.img  = z1.img  + z2.img;  
    return z3;  
}  

int main() {  
    Complex z1, z2, z3;  
    printf( "Enter the first complex number \n");  
    printf( "Enter the real part " );  
    scanf( "%f", &z1.real );  
    printf( "Enter the imaginary part " );  
    scanf( "%f", &z1.img );  
    printf("The first complex number is: %f + i*%f\n",z1.real,z1.img);
    printf("nhan enter de tiep tuc");
    getch();
	printf( "\n\nEnter the second complex number \n");  
    printf( "Enter the real part " );  
    scanf( "%f", &z2.real);  
    printf( "Enter the imaginary part " );  
    scanf( "%f", &z2.img );  
    printf("The second complex number is: %f + i*%f\n",z2.real,z2.img);
    z3 = add_complex( z1, z2 );  
    printf( "\n\nSum: %f + i * %f", z3.real, z3.img );     
    return 0;     
}  
