#include<stdio.h>
_(int __,int ___,int ____){
___/__<=1?_(__,___+1,____):!(___%__)?_(__,___+1,0):___%__==___/__&&!____?(printf("%d\t",___/__),_(__,___+1,0)) :___%__>1&&___%__<___/__?_(__,1+___,____ +!(___/__%(___%__))):___<__*__?_(__,___+1,____):0;
}
check (int a,int b,int c ){
	b/a<=1?check(a,b+1,c):!(b%a)?check(a,b+1,0):((b%a==b/a&&!c)?(printf("%d\t",b/a),check(a,b+1,0)) : (((b%a) > 1 &&(b%a)<(b/a))  ?      (check(a,1+b,c +!(b/a%(b%a))))  :   (b<a*a?check(a,b+1,c):0)));
} 
main(){
check(220,0,0);
} 



