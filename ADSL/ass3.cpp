#include <iostream>
using namespace std;

class node
{
 node *leftchild,*rightchild;
 int data;
 bool rightbit,leftbit;
public:
 node()
{
  leftchild=NULL;
  rightchild=NULL;
  rightbit=leftbit=0;
}
 node(int a)
 {
  leftchild=NULL;
  rightchild=NULL;
  rightbit=leftbit=0;
  data=a;
 }
 friend class TBT;
};

class TBT
{
 node *root;
public:
 TBT()
{
  root=new node();
  root->leftchild=root;
  root->rightbit=1;
  root->leftbit=0;
  root->rightchild=root;
}
 void create();
 void insert(int data);
 node *inorder_suc(node *);
 void inorder_traversal();
 node * preorder_suc(node *c);
 void preorder_traversal();
};
//--------------------------------------------
void TBT::preorder_traversal()
{
 node *c=root->leftchild;
 while(c!=root)
 {
  cout<<" "<<c->data;
  c=preorder_suc(c);
 }
}
void TBT::inorder_traversal()
{
 node *c=root->leftchild;
 while(c->leftbit==1)
  c=c->leftchild;
 while(c!=root)
 {
  cout<<" "<<c->data;
  c=inorder_suc(c);
 }
}
node* TBT::inorder_suc(node *c)
{
 if(c->rightbit==0)
  return c->rightchild;
 else
  c=c->rightchild;
 while(c->leftbit==1)
 {
  c=c->leftchild;
 }
 return c;
}

node *TBT::preorder_suc(node *c)
{
 if(c->leftbit==1)
 {
  return c->leftchild;
 }
 while(c->rightbit==0)
 {
  c=c->rightchild;
 }
 return c->rightchild;
}

void TBT::create()
{
 int n;
 cout<<"\nEnter number of nodes:";
 cin>>n;
 for(int i=0;i<n;i++)
 {
  int info;
  cout<<"\nEnter data: ";
  cin>>info;
  this->insert(info);
 }
}
void TBT::insert(int data)
{

 if(root->leftchild==root && root->rightchild==root) //no node in tree
 {
  node *p=new node(data);
  p->leftchild=root->leftchild;
  p->leftbit=root->leftbit; //0
  p->rightbit=0;
  p->rightchild=root->rightchild;
  root->leftchild=p;
  root->leftbit=1;
  cout<<"\nInserted start"<<data;
  return;
 }
 node *cur=new node;
 cur=root->leftchild;
 while(1)
 {

  if(cur->data<data)   //insert right
  {
   node *p=new node(data);
   if(cur->rightbit==0)
   {
    p->rightchild=cur->rightchild;
    p->rightbit=cur->rightbit;
    p->leftbit=0;
    p->leftchild=cur;
    cur->rightbit=1;
    cur->rightchild=p;
    cout<<"\nInserted right "<<data;
    return;
   }
   else
    cur=cur->rightchild;
  }
  if(cur->data>data) //insert left
  {
   node *p=new node(data);
   if(cur->leftbit==0)
   {
    p->leftchild=cur->leftchild;
    p->leftbit=cur->leftbit;
    p->rightbit=0;
    p->rightchild=cur; //successor
    cur->leftbit=1;
    cur->leftchild=p;
    cout<<"\nInserted left"<<data;
    return;
   }
   else
    cur=cur->leftchild;
  }
 }

}


int main()
 {
 TBT t1;
 int value;
 int choice;
 do
 {
  cout<<"\n1.Create Tree\t2.Insert into tree\t3.Pre_order\t4.In_order\t5.Exit\nEnter your choice: ";
  cin>>choice;
  switch(choice)
  {
  case 1:
   t1.create();
   break;
  case 2:
   cout<<"\nEnter Number(data): ";
   cin>>value;
   t1.insert(value);
   break;
  case 3:
   cout<<"\nPreorder traversal of TBT\n";
   t1.preorder_traversal();
   break;
  case 4:
   cout<<"\nInoder Traversal of TBT\n";
   t1.inorder_traversal();
   break;
  default:
   cout<<"\nWrong choice";
  }

 }while(choice!=5);


 return 0;
}

