/*Problem Statement-:Implement all the functions of a dictionary (ADT) using hashing.
 Data:  Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable,
 Keys must be unique Standard Operations:  Insert(key, value), Find(key), Delete(key) */

#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;

class node
{
public:
    char data[20];
    char mean[20];
    node *right;

    node(){right=NULL;
}


    friend class hash;
};

class hash
{
public:
	node *head[20];

	void initialize();
	void insert(char [], char []);
	void find(char []);
	void delet(char[]);
};

void hash::initialize()
{
	for(int i=0;i<20;i++)
	{
		head[i]=NULL;
	}
}

void hash::insert(char dat[20], char mn[20])
{
	int flag=0;
	char ch;
	node *temp=new node();
	strcpy(temp->data,dat);
	strcpy(temp->mean,mn);

	int pos=(dat[0]+dat[1]+dat[2])%20;


	if(head[pos]==NULL)
	{
		head[pos]=temp;
	}

	else
	{
		node *p=head[pos];
		node *q=head[pos];
		while(p!=NULL)
		{
			if(strcmp(p->data,dat)==0)
			{
				flag=1;
				break;
			}
			q=p;
			p=p->right;
		}

		if(flag==1)
		{
			cout<<"\nKeyword '"<<dat<<"' is already present!!";
			cout<<"\nDo you want to replace it?(y/n)";
			cin>>ch;
			if(ch=='y'||ch=='Y')
			{
				strcpy(p->data,dat);
				strcpy(p->mean,mn);
			}
		}

		else if(flag==0)
		{
		  q->right=temp;
		}
	}
}

void hash::find(char key[20])
{
	int cnt=1;
	int pos=(key[0]+key[1]+key[2])%20;
	int flag=0;
	node *p=head[pos];
	if(head[pos]==NULL)
	{
		flag=0;
	}

	else
	{

		while(p!=NULL)
		{
			if(strcmp(p->data,key)==0)
			{
				flag=1;
				break;
			}
			cnt++;
			p=p->right;
		}
	}

	if(flag==0)
	{
		cout<<"\nKeyword not found!!";
	}

	else
	{
		cout<<"\nKeyword present!!";
		cout<<"\n\tKeyword-: "<<p->data;
		cout<<"\n\tMeaning-: "<<p->mean;
		cout<<"\nNumber of searches made-: "<<cnt;
	}
}

void hash::delet(char key[20])
{
	int pos=(key[0]+key[1]+key[2])%20;
		int flag=0;

		node *q=head[pos],*p;

		if(head[pos]==NULL)
		{
			flag=0;
		}

		else if(strcmp(head[pos]->data,key)==0)
		{
			node *tem=head[pos];
			head[pos]=tem->right;
			delete tem;
			flag=1;
		}

		else
		{
			p=head[pos];
			while(p!=NULL)
			{
				if(strcmp(p->data,key)==0)
				{

					q->right=p->right;
					flag=1;
					break;
				}
				q=p;
				p=p->right;
			}
		}

		if(flag==0)
		{
			cout<<"\nKeyword not found!!";
		}
		else
		{
			cout<<"\nKeyword Deleted!!";
		}
}
int main()
{
	hash h;
	int ch;
	char dat[20],mea[20];
	h.initialize();
	while(1)
	{
		cout<<"\n1.Insert Key \n2.Find Key \n3.Delete Key \n4.Exit";
		cout<<"\nEnter your choice-: \n";
		cin>>ch;

		switch(ch)
		{
		case 1:
			cout<<"\nEnter Key to be inserted-: ";
			cin>>dat;
			cout<<"\nEnter meaning of Key-: ";
			cin>>mea;
			h.insert(dat,mea);
			break;

		case 2:
			cout<<"\nEnter Key to be searched-: ";
			cin>>dat;
			h.find(dat);
			break;

		case 3:
			cout<<"\nEnter Key to be Deleted-: ";
			cin>>dat;
			h.delet(dat);
			break;

		case 4:
			exit(1);

		default:
			cout<<"\nEnter Valid choice!!";
			break;
		}
	}

	return 0;
}
