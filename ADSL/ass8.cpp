#include<iostream>
using namespace std;
class node
{
	int w,r,c;
public:
	node()
{
		w=r=c=0;
}
	friend class obst;
};
class obst
{
	node a[10][10];
	string iden[10];
	int p[10],q[10];
	int n;
public:
	obst()
{
		n=0;
}
	void read();
	void create();
	int find(int,int);
	void print(int,int);
};
void obst::read()
{
	cout<<"\nEnter number of identifiers : ";
	cin>>n;
	cout<<"\nEnter the identifiers : ";
	for(int i=1;i<=n;i++)
	{
		cin>>iden[i];
	}
	cout<<"\nEnter probability of success : ";
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	cout<<"\nEnter probability of failure : ";
	for(int i=0;i<=n;i++)
	{
		cin>>q[i];
	}
}
void obst::create()
{
	int j,k,m;
	for(int i=0;i<n;i++)
	{
		a[i][i].w=q[i];
		a[i][i].r=0;
		a[i][i].c=0;
		a[i][i+1].w=q[i]+q[i+1]+p[i+1];
		a[i][i+1].c=a[i][i+1].w;
		a[i][i+1].r=i+1;
	}
	a[n][n].w=q[n];
	a[n][n].r=0;
	a[n][n].c=0;
	for(m=2;m<=n;m++)
	{
		for(int i=0;i<=n-m;i++)
		{
			j=i+m;
			a[i][j].w=a[i][j-1].w+p[j]+q[j];
			k=find(i,j);
			a[i][j].r=k;
			a[i][j].c=a[i][k-1].c+a[k][j].c+a[i][j].w;
		}
	}
	cout<<"\nOBST(Inorder Traversal) : ";
	print(0,n);
}
int obst::find(int i,int j)
{
	int min=1000;
	int p,l;
	for(p=i+1;p<=j;p++)
	{
		if((a[i][p-1].c+a[p][j].c)<min)
		{
			min=a[i][p-1].c+a[p][j].c;
			l=p;
		}
	}
	return l;
}
void obst::print(int i,int j)
{
	if(i<j)
	{
		print(i,a[i][j].r-1);
		cout<<"\n"<<iden[a[i][j].r];
		print(a[i][j].r,j);
	}
	else
		return;
}
int main()
{
	obst ob;
	ob.read();
	ob.create();

	return 0;
}
