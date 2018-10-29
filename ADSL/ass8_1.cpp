/*
 * obst.cpp
 *
 *  Created on: Feb 28, 2018
 *      Author: student
 */

#include<iostream>
using namespace std;

class X
{
	int root;
	float weight,cost;

public:
	X()
	{
		weight=0;
		cost=0;
		root=0;
	}

	friend class obst;
};

class obst
{
	int n;
	float key;
	float p[10],q[10];
	string arr;
public:
	friend class node;
	X mat[10][10];
	float min_cost;
	int min_root;
	void prob();
	void create();
	void display();
	void print();
	void print(int ,int );

};

void obst::prob()
{
	cout<<"Enter the number of keys in your Binary Search Tree :- ";
	cin>>n;
	cout<<endl;

	cout<<"Enter the name of key :-\n";
	for(int i=1;i<=n;i++)
		cin>>arr;

	cout<<"\nEnter the associated successful probability for the key :-\n";
	for(int i=1;i<=n;i++)
		cin>>p[i];

	cout<<"\nEnter the associated unsuccessful probability for the key :-\n";
	for(int i=0;i<=n;i++)
		cin>>q[i];
}

void obst::create()
{
	for(int i=0;i<=n;i++)
	{
		mat[i][i].weight=q[i];
		mat[i][i].root=0;
		mat[i][i].cost=0;

		mat[i][i+1].weight=q[i]+p[i+1]+q[i+1];
		mat[i][i+1].root=i+1;
		mat[i][i+1].cost=q[i]+p[i+1]+q[i+1];
	}

	for(int m=2;m<=n;m++)
	{
		for(int i=0;i<=n-m;i++)
		{
			int j=i+m;
			mat[i][j].weight=p[j]+q[j]+mat[i][j-1].weight;

			min_cost=1000;

			for(int k=i+1;k<=j;k++)
			{
				mat[i][j].cost=mat[i][j].weight+mat[i][k-1].cost+mat[k][j].cost;

				if(min_cost > mat[i][j].cost)
				{
					min_cost=mat[i][j].cost;
					mat[i][j].root=k;
				}
			}
		}
	}

	cout<<"The optimal cost of tree is:- "<<min_cost<<endl;
	cout<<"The root of optimal tree is:- "<<mat[0][n].root<<endl;
}

void obst::display()
{
    cout<<"The OBST table is as :-\n\n";

    for(int i=0;i<=n;i++)
    {
        cout<<"Weight :-  ";
        cout<<mat[i][i].weight<<"\t"<<mat[i][i+1].weight;

        cout<<"\nRoot   :-  ";
        cout<<mat[i][i].root<<"\t"<<mat[i][i+1].root;

        cout<<"\nCost   :-  ";
        cout<<mat[i][i].cost<<"\t"<<mat[i][i+1].cost;

        cout<<endl<<endl;
    }
}

void obst::print()
{
    cout<<"The preorder traversal of tree is :- ";
    print(0,n);
}

void obst::print(int i,int j)
{

	if(i<j)
        cout<<mat[i][j].root<<"\t";

    else
        return;

    print(i,mat[i][j].root-1);
    print(mat[i][j].root,j);
}

int main()
{
	obst o1;
	int choice;

	do
	{
		cout<<"Which operation do you want to perform?\n";

		cout<<"\n1-Enter the probabilities for successful and unsuccessful searches\n";
		cout<<"2-Calculating the optimal cost of tree\n";
		cout<<"3-Displaying the table for OBST\n";
		cout<<"4-Traversal of optimal tree\n";

		cout<<"\nEnter your choice :- ";
		cin>>choice;
		cout<<endl;

		switch(choice)
		{
			case 1: o1.prob();
					cout<<endl;
					break;

			case 2: o1.create();
					cout<<endl;
					break;

            case 3: o1.display();
					cout<<endl;
					break;

			case 4: o1.print();
					cout<<endl;
					break;

			default : cout<<"Invalid input.\n\n";
		}

	}while(choice>0  && choice<5);

	return 0;
}
/*


for(int i=0;i<=n;i++)
    {
        cout<<"Weight :-  ";
        for(int j=0;j<=n-i;j++)
        {
            cout<<mat[j][i].weight<<"\t";
        }
        cout<<endl<<"Root   :-  ";

     for(int j=0;j<=n-i;j++)
        {
            cout<<mat[j][i].root<<"\t";
        }
        cout<<endl<<"Cost   :-  ";

        for(int j=0;j<=n-i;j++)
        {
            cout<<mat[j][i].cost<<"\t";
        }
        cout<<endl<<endl;
    }
*/
