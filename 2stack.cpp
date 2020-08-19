struct node{
	int data;
	struct node *next;
};
typedef struct node NODE;
struct list{
	NODE *head;
	int top;
};
typedef struct list LIST;
void init(LIST &l){
	l.head=NULL;
	l.top=-1;
}
NODE *initnode(int x){
	NODE *p;
	p = (NODE *)malloc(sizeof(NODE));
	p->data=x;
	p->next=NULL;
	return p;
}
void push(LIST &l,NODE *p){
	if(l.top==-1){
		l.head=p;
		l.top++;
	}
	else {
		p->next=l.head;
		l.head=p;
		l.top++;
	}
}
void pop(list &l,int &x){
	if (l.top==-1) printf("\nStack rong");
	else {
		x=l.head->data;
		l.head=l.head->next;
		l.top--;
	}
}
LIST xuoi,nguoc;
void dequeue(LIST &l,int x){
	push(xuoi,x)
}
int main(){
	list xuoi,nguoc,q;
	push();
}
