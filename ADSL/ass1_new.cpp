//erase,copy and mirror not working
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class node
{
int data;
node *left,*right;
public:
    node()
    {
        left=NULL;
        right=NULL;
        data=0;
    }
    node(int x)
    {
        left=NULL;
        right=NULL;
        data=x;
    }
    friend class tree;
    int datad()
    {
        return data;
    }
};

class tree
{
    node *root;
    public:
    tree()
    {
        root=NULL;
    }
    void create(int);
    node* insert(node*,int);
    void insert(int);
    node* rootr();
    void operator=(tree&);
    void npreorder();
    void mirror(node*);
    int height(node*);
    void BFS(node*);
    int leaf(node*);   
    //void display();
    node** ret_root_del()
    {
        node **t=&root;
        return t;
    }
    void del(node**);
    void erase();
    void reerase(node*);
    //recursive traversals
    void inorder(node*);   
    void preorder(node*);
    void postorder(node*);   
    //non-recursive traversals
    void inorder();       
    void preorder();
    void postorder();
};


void tree :: create(int x)
{
    if(root==NULL)
    {
    node *p=new node;
    p->data=x;
    root=p;
    cout<<"Root created\n";
    }
    else
    {
    insert(root,x);
    }
}

node* tree :: insert(node* t,int x)
{
if(t==NULL)
{
node *p=new node;
p->data=x;
return p;
}
else
{
char ch;
cout<<"which side ? left/right(l/r)\n";
cin>>ch;
if(ch=='l' || ch=='L')
t->left=insert(t->left,x);
else
t->right=insert(t->right,x);
return t;
}
}

void tree :: inorder(node *c)
    {

        if(c!=NULL)
        {
            inorder(c->left);
            cout<<"  "<<c->data<<"     ";
            inorder(c->right);
        }
    }

node* tree :: rootr()
{
return root;
}

void tree :: preorder(node *c)
    {

        if(c!=NULL)
        {
            cout<<"  "<<c->data<<"     ";
            preorder(c->left);
            preorder(c->right);
        }
    }

void tree :: postorder(node *c)
    {

        if(c!=NULL)
        {
            postorder(c->left);
            postorder(c->right);
            cout<<"  "<<c->data<<"     ";
        }
    }

void tree :: mirror(node *r)
{
    if(r==NULL)
    return;
    else
    {
        node *temp;
        mirror(r->left);
        mirror(r->right);
        temp=r->left;
        r->left=r->right;
        r->right=temp;
    }
}

void tree :: operator =(tree &t1)            //bfs tree assignment
{
    queue<node*> q,mq;
    node *c=t1.root;
    root= new node(c->data);
    node *mc=root;
    q.push(c);
    mq.push(mc);
    while(!q.empty())
    {
        c=q.front();
        mc=mq.front();
        if(c->left!=NULL)
        {
        mc->left=new node(c->left->data);
        q.push(c->left);
        mq.push(mc->left);
        }
        if(c->right!=NULL)
        {
        mc->right=new node(c->right->data);
        q.push(c->right);
        mq.push(mc->right);
        }
        q.pop();
        mq.pop();
    }
}

int tree :: height(node *r)
{
    //base case
    if(r==NULL)
    return 0;

    //queue to maintain current level nodes
    queue<node*> q;
    q.push(r);
    int height=0;

    //dequeue current level nodes
    //enqueue next level nodes
    while(1)
    {
        int nodecount=q.size();
        if(nodecount==0)
            return height;
        height++;
        while(nodecount>0)
        {
            node *n=q.front();
            q.pop();
            if(n->left!=NULL)
                q.push(n->left);
            if(n->right!=NULL)
                q.push(n->right);
            nodecount--;
        }
    }
}

void tree :: BFS(node *r)
{
    int nt=0;
    queue<node*> q;
    if(r==NULL)
    {
        cout<<"Tree is not created!";
        return;
    }
    q.push(r);
    while(!q.empty())
    {
        node *n=q.front();
        q.pop();
        nt++;
        cout<<n->datad()<<" ";
        if(n->left!=NULL)
            q.push(n->left);
        if(n->right!=NULL)
            q.push(n->right);
    }
    cout<<"Total nodes - "<<nt<<endl;
    cout<<"Internal nodes - "<<nt-leaf(root)<<endl;
    cout<<"Leaf nodes - "<<leaf(root)<<endl;
}

int tree :: leaf(node *n)
{
if(n==NULL)
return 0;
else if(n->right==NULL && n->left==NULL)
return 1;
else
return leaf(n->left)+leaf(n->right);
}

void tree :: erase()
{
    stack<node*> s;
    queue<node*> q;
    if(root==NULL)
        return;
    q.push(root);
    while(!q.empty())
    {
        node *n=q.front();
       
        if(n->left!=NULL)
            q.push(n->left);
        if(n->right!=NULL)
            q.push(n->right);
        delete n;
        q.pop();
    }
    root=NULL;
}

void tree :: del(node **t)
{
    reerase(*t);
    *t=NULL;
}

void tree :: reerase(node *c)
    {
        if(c!=NULL)
        {
            reerase(c->left);
            reerase(c->right);
            delete c;
            c=NULL;
        }
    }



void tree :: npreorder()
	{
		node *temp=root;
		stack<node *>s;
		if(temp==NULL)
			cout<<"Empty tree\n";
		s.push(temp);
		while(!s.empty())
		{
			temp=s.top();
			s.pop();
			cout<<temp->data<<"\t";
			if(temp->right)
				s.push(temp->right);
			if(temp->left)
				s.push(temp->left);
		}
	}
//NON RECURSIVE TRAVERSAL (not working)
    void tree :: inorder()                //non recursive inorder
{
    stack <node*> s;
    node *r=root;
    while(true)
    {
        while(r != NULL)
        {
            s.push(r);
            r = r->left;
        }
        if(!s.empty())
        {
            r = s.top();
            s.pop();
            cout << r->data << "\t";
            r = r->right;
        }
        else
            break;
    }
}

void tree :: preorder()                //non recursive preorder
{
    stack <node*> s;
    node *r=root;
    while(true)
    {
        while(r != NULL)
        {
            cout << r->data << "\t";
            s.push(r);
            r = r->left;
        }
        if(!s.empty())
        {
            r = s.top();
            s.pop();
            r = r->right;
        }
        else
            break;
    }
}

void tree :: postorder()            //non recursive postorder
{
    stack <node*> s;
    node *r=root;
    do
    {
        while(r != NULL)
        {
            if(r->right != NULL)
                s.push(r->right);
            s.push(r);
            r = r->left;
        }

        r = s.top();
        s.pop();
       
        if(!s.empty() && r->right != NULL && r->right == s.top())
        {
            node *t = s.top();
            s.pop();
            s.push(r);
            r = t;   
        }
        else
        {
            cout << r->data << "\t";
            r = NULL;
        }
    }while(!s.empty());   
}


int main()
{
tree t;
int ch,f=1;
while(f)
{
    cout<<"Which operation do you want to perform ?\n\t\t1.Insert\n\t\t2.Inorder traversal\n\t\t3.Postorder traversal\n\t\t4.Preorder traversal\n\t\t5.Mirror of tree\n\t\t6.Calculate height\n\t\t7.BFS\n\t\t8.Copy one tree to another\n\t\t9.Erase all nodes\n\t\t10.Exit\n\t\t";
    cin>>ch;
    switch(ch)
    {
    case 1:
        cout<<"Enter the number to be inserted\n";
        int n;
        cin>>n;
        t.create(n);
        break;
    case 2:
        //t.inorder(t.rootr());
        t.inorder();
        break;
    case 3:
        t.postorder(t.rootr());
        break;
    case 4:
        t.preorder(t.rootr());
        break;
    case 5:
        t.mirror(t.rootr());
        break;
    case 6:
        cout<<"Height of tree - "<<t.height(t.rootr())<<endl;
        break;
    case 7:
        t.BFS(t.rootr());
        cout<<"\n";
        break;
    case 8:
    {
        tree t1;
        t1=t;
        t1.BFS(t1.rootr());
        break;
    }
    case 9:
        t.del(t.ret_root_del());
        break;
    case 10:
       t.npreorder();
        break;
    }
}
return 0;
}

//mirror not working
