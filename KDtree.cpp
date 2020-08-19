#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	int data[2];
	struct node *left;
	struct node *right;
};
typedef struct node NODE;
NODE *newnode(int a[2]){
	NODE *p;
	p=(NODE *)malloc(sizeof(NODE));
	for (int i=0;i<2;i++){
		p->data[i]=a[i];
	}
	p->left=p->right=NULL;
	return p;
}
/*NODE *insertnode(NODE *root,int a[2],int depth){
	if (root==NULL){
		return newnode(a);
	}
	int chiso = depth % 2;
	if (a[chiso] < root->data[chiso]){
		root->left = insertnode(root->left,a,depth+1);
	}
	else {
		root->right = insertnode(root->right,a,depth+1);
	}
	return root;
}*/
void swap(int a[],int b[]){
	int n= sizeof(a)/sizeof(int);
	int tg;
	for (int i=0;i<n;i++){
		tg = a[i];
		a[i]=b[i];
		b[i]=tg;
	}
}
int **sort(int **a,int len,int s,int depth){
	int axis = depth%2;
	for (int i=s;i<len+s-1;i++){
		for (int j=i+1;j<len+s;j++){
			if (a[i][axis]<a[j][axis]) swap(a[i],a[j]);
		}
	}
	return a;
}
NODE *insertnode(NODE *root,int *a,int s,int e,int depth){
	if (root==NULL){
		return newnode(a);
	}
}
int main(){
	NODE *root=NULL;
	/*NODE *p;
	int b[2]={17,15};
	int a[7][2] = {{3, 6}, {17, 15}, {13, 15}, {6, 12}, {9, 1}, {2, 7}, {10, 19}}; 
	for (int i=0;i<7;i++){
		root = insertnode(root,a[i],0);
	//	printf("%d",root->data[0]);
	}
	printf("%d",root->data[0]);
	p=findnode(root,b,0);
	printf("%d",(p->right)->data[0]);*/
	int **a;
	a = (int **)malloc(7*sizeof(int *));
	for (int i=0;i<7;i++){
		a[i]= (int *)malloc(2*sizeof(int ));
	}
	FILE *f;
	f = fopen("D://test.txt","r+");
	for (int i=0;i<7;i++){
		for (int j=0;j<2;j++){
			fscanf(f,"%d",&a[i][j]);
		}
	}
/*	for (int i=0;i<7;i++){
		root = insertnode(root,a,7,0,0);
	}
	NODE *p=root->left;
	printf("%d",p->data[0]);*/
	return 0;
}

