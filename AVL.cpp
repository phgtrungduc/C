#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	int height;
	struct node *left,*right;
}NODE;
NODE *newnode(int data){
	NODE *p;
	p= (NODE *)malloc(sizeof(NODE));
	p->data = data;
	p->height=1;
	p->left = p->right = NULL;
	return p;
}
int height(NODE *x){
	if (x==NULL) return 0;
	int hr=height(x->right);
	int hl=height(x->left);
	return (hr>hl)?(hr+1):(hl+1);
}
NODE *xoayphai(NODE *x){
	NODE *y=x->left;
	NODE *z=y->right;
	y->right=x;
	x->left=z;
	x->height=height(x);
	y->height=height(y);
	return y;
}
void xoaytrai(NODE *x){
	NODE *y=x->right;
	NODE *z=y->left;
	y->left=x;
	x->right=z;
	x->height=height(x);
	y->height=height(y);
	return y;
}
NODE* inserttree(NODE *root,int key){
	if(root==NULL) {
		return newnode(key) ;
	}
	else if(key<root->data){
		root->left = inserttree(root->left,key);
	}
	else if(key>root->data){
		root->right = inserttree(root->right,key);
	}
	else return ;
	root->height=height(root);
	int lech=height(root->left)-height(root->right);
	if(lech<-1&&)
}

NODE *find(NODE *root,int key){
	if (root->data==key){
		return root;
	}
	if (key<root->data){
		return find(root->left,key);
	}
	else if(key>root->data){
		return find(root->right,key);
	}
	else return NULL;
}
void preoder(NODE *root){
	if (root!=NULL){
		printf("%d    ",root->data);
		preoder(root->left);
		preoder(root->right);
	}
}
int main(){
	NODE *root=NULL;
	NODE *p;
	p= newnode(13);
	inserttree(root,p);
	p= newnode(10);
	inserttree(root,p);
	p= newnode(15);
	inserttree(root,p);
	p= newnode(5);
	inserttree(root,p);
	p= newnode(11);
	inserttree(root,p);
	p= newnode(4);
	inserttree(root,p);
	p= newnode(8);
	inserttree(root,p);
	p= newnode(3);
	inserttree(root,p);
	p= newnode(16);
	inserttree(root,p);
	preoder(root);
	p=find(root,10);
	xoayphai(p);
	printf("\n");
	preoder(root);
	return 0;
}

