#include <stdio.h>
#include <stdlib.h>

struct TNode {
	int data;
	struct TNode *left;
	struct TNode *right;
};
typedef struct TNode NODE;
NODE* newnode (int data){
	NODE *p = (NODE*)malloc(sizeof(NODE));
	p->data = data;
	p->left =NULL;
	p->right=NULL;
	return p;
}
void creatnode(NODE *&root,int x){
	if (root==NULL){
		root = newnode(x);
		return ;
	}
	else if (x<root->data) creatnode(root->left,x);
	else if (x>root->data) creatnode(root->right,x);
	else return;
}
void thutugiua(NODE *root){
	if (root!=NULL) {
	    thutugiua(root->left);
	    printf("%d  ",root->data);
	    thutugiua(root->right);
	}
	return;
} 
void thututruoc(NODE *root){
	if (root!=NULL){
		printf("%d  ",root->data);
		thututruoc(root->left);
		thututruoc(root->right);
	}
	return;
}
void thutusau(NODE *root){
	if (root!=NULL){
		thutusau(root->left);
		thutusau(root->right);
		printf("%d  ",root->data);
	}
	return;
}
int countnode(NODE *root){
	if (root==NULL||root->data%2!=0) return -99999;
	
	else {
		int max=-9999999;
		if (root->data%2==0) max=root->data;
		int left = countnode(root->left);
		int right = countnode(root->right);
		max = (max>left)?max:left;
		max = (max>right)?max:right;
		return max;
	}
}
int countnodethank(NODE *root,int k){
	int dem=0;
	if (root==NULL) return 0;
	
	else {
		if (root->data>k) dem++;
		return dem+countnodethank(root->left,k)+countnodethank(root->right,k);
	}
}
int high(NODE *root){
	if (root==NULL) return 0;
	int hl=high(root->left);
	int hr=high(root->right);
	return (hr>hl)?(1+hr):(1+hl);
}
NODE *findnode(NODE *root,int x){
	if (root->data==NULL) return NULL;
	if (root->data==x) return root;
	else if (x<root->data) return findnode(root->left,x);
	else if (x>root->data) return findnode(root->right,x);
}
void delnode(NODE *&node){
	node=NULL;
}
int remove_node(NODE *&root){
	if(root == NULL) return -1; //remove null
	NODE *ptr = root; //remember this node for delete later
	if(root->left == NULL) root=root->right;
	else if(root->right == NULL) root=root->left;
	else {
		NODE *preP = root;
		ptr = root->left;
		while(ptr->right != NULL){
			preP = ptr;
			ptr = ptr->right;
		}
	root->data = ptr->data;
	if(preP == root) root->left = ptr->left;
	else preP->right = ptr->left;
	}//find the rightmost node on the left sub tree
	free(ptr);
}
int remove(NODE *&root, int key){
	if(root==NULL || key==root->data) return remove_node(root);
	else if(key < root->data) return remove(root->left,key);
	else return remove(root->right,key);
}
int evenleaf(NODE *root){
	if (root==NULL) return 0;
	else {
		if (root->left==NULL&&root->right==NULL) return 1;
		else return evenleaf(root->left)+evenleaf(root->right);
	}
}
int tongle(NODE *root){
	int tong=0;
	if (root==NULL) return 0;
	else {
		if (root->data%2!=0) tong=tong+root->data;
		return tong+tongle(root->left)+tongle(root->right);
	}
}

int tongcacnut(NODE *root){
	if (root==NULL) return 0;
	else {
		return root->data+tongcacnut(root->left)+tongcacnut(root->right);
	}
}
NODE *quay(NODE *root){
	if (root!=NULL){
		quay(root->left);
		quay(root->right);
		NODE *tmp=root->left;
		root->left=root->right;
		root->right=tmp;
	}
//	else return root;
}
int isleaf(NODE *p){
	if (p->left==NULL&&p->right==NULL) return 1;
	return 0;
}
int demnut(NODE *root){
	if (root==NULL) return 0;
	else {
		int dem=0;
		if (root->left!=NULL&&root->right!=NULL)  dem=1;
		return dem+ demnut(root->left)+demnut(root->right);
	}
}
NODE *delnode(NODE *&root,int key){
	if (root==NULL) printf("deo tim thay");
	if (key<root->data){
		root->left=delnode(root->left,key);
	}
	else if (key>root->data){
		root->right=delnode(root->right,key);
	}
	else {
		if (root->left!=NULL&&root->right!=NULL){
			NODE *p=root->right;
			while (p->left!=NULL){
				p=p->left;
			}
			root->data=p->data;
			root->right=delnode(root->right,root->data);
		}
		else {
			NODE *p=root;
			if (root->left==NULL) root=root->right;
			else if (root->right==NULL) root=root->left;
			//free(p);
		}
	}
	return root;
	
}
int max=-99999;
int findmax(NODE *&root){
	if (root==NULL) return -999999;
	else {
		int maxl=findmax(root->left);
		int maxr=findmax(root->right);
		max = (root->data>maxl)?root->data:maxl;
		max = (max>maxr)?max:maxr;
	}
	return max;
}
NODE **array=(NODE **)malloc(100*sizeof(NODE **));
int out=-1,in=-1;
void enqueue(NODE *p){
		in++;
	array[in]=p;
}
NODE  *dequeue(){
	if (in==out) printf("\nQueue rong");
	else {
		out++;
		return array[out];
	}
}
int sizeofqueue(){
	return in-out;
}
int main(){
    NODE *root=NULL;
    int n;
   /*printf("Nhap so phan tu cua cay ban dau: ");
    scanf("%d",&n);*/
    int a[]={20,8,50,15,7,25,60,21,55,70,51,57,27};
    /*for (int i=0;i<n;i++){
	    printf("\nNhap phan tu thu %d: ",i);	
	    scanf("%d",&a[i]);
	}*/
	for (int i=0;i<13;i++){
	    creatnode(root,a[i]);
	}
	enqueue(root);
	do {
		NODE *p=dequeue();
		if (p->left!=NULL) enqueue(p->left);
		if (p->right!=NULL) enqueue(p->right);
		
	} while (sizeofqueue()!=1);
	NODE *p=dequeue();
	printf("%d",p->data);
	thututruoc(root);
	printf("\n");
	printf("%d",countnode(root));
	return 0;
 }














