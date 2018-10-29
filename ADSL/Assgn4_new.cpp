
#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class node
{
	private :
		string name;
		float time;
		node *next;
	public :
		node()
		{
			name = "";
			time = 0.0;
			next = NULL;
		}
		node(string n,float t)
		{
			name = n;
			time = t;
			next = NULL;
		}
	friend class AdjList;
	friend class Graph;
};
class AdjList
{
	private :
		node *vertex;
	public :
		AdjList()
		{
			vertex = NULL;
		}
		void AddFlight(string d,float t)
		{
			node *q = new node(d,t);
			node *n = vertex;
			while(n->next != NULL)
				n = n->next;
			n->next = q;
		}
		void DisAdjList()
		{
			node *n = vertex;
			if(n->time == 0)
			{
				while(n->next != NULL)
				{
					n = n->next;
					cout<<setw(15)<<vertex->name<<setw(20)<<n->name<<setw(40)<<n->time<<endl;
				}
				cout<<endl;
			}
		}
		int Count()
		{
			node *n = vertex;
			int count = 0;
			while(n->next != NULL)
			{
				n = n->next;
				count++;
			}
			return count;
		}
		void del(string d)
		{
			node *n = vertex;
			node *p;
			while(n->name != d && n->next != NULL)
			{
				p = n;
				n = n->next;
			}
			p->next = n->next;
			delete n;
		}
		void NullifyRoutes()
		{
			node *n = vertex;
			n->next = NULL;
		}
	friend class Graph;

};
class Graph
{
	private :
		int vertices;
		AdjList obj[20];
	public :
		Graph()
		{
			cout<<"Enter the number of cities : ";
			cin>>vertices;
		}
		void AddCities()
		{
			int i;
			string city;
			for(i = 0; i<vertices; i++)
			{
				cout<<"Enter the name of the city "<<i+1<<" : ";
				cin>>city;
				obj[i].vertex = new node(city,0);
			}
			cout<<"The added cities are : "<<endl;
			for(i = 0; i<vertices; i++)
			{
				cout<<setw(20)<<i+1<<setw(30)<<(obj[i].vertex)->name<<endl;
			}
		}
		void AddNewCity()
		{
			string city;
			cout<<"Enter the name of the city : ";
			cin>>city;
			obj[vertices].vertex = new node(city,0);
			vertices++;
			cout<<"ADDED CITY : "<<city<<endl;
		}
		void DAddNewRoute()
		{
			string ori,dest;
			float t;
			cout<<"Enter the flight details :\n";
			cout<<"Source City : ";cin>>ori;
			cout<<"Destination : ";cin>>dest;
			cout<<"Time of Flight : ";cin>>t;
			int i = 0;
			while((obj[i].vertex)->name != ori && i != vertices)
				i++;
			/*if(i == vertices)
			{
				cout<<"Error : Source city does not exist in the graph.\n";
				return;
			}*/
			obj[i].AddFlight(dest,t);
			cout<<"Added new route as specified.\n";
		}
		void UDAddNewRoute()
		{
			string ori,dest;
			float t;
			cout<<"Enter the flight details :\n";
			cout<<"Source City : ";cin>>ori;
			cout<<"Destination : ";cin>>dest;
			cout<<"Time of Flight : ";cin>>t;
			int i = 0;
			while((obj[i].vertex)->name != ori && i != vertices)
				i++;
			obj[i].AddFlight(dest,t);
			int j = 0;
			while((obj[j].vertex)->name != dest && i != vertices)
				j++;
			obj[j].AddFlight(ori,t);
			cout<<"Added new route as specified.\n";
		}
		void Degree()
		{
			string city;
			int i=0,ind = 0,outd = 0;
			cout<<"Enter the name of the city : ";
			cin>>city;
			while((obj[i].vertex)->name != city && i != vertices)
				i++;
			outd = obj[i].Count();
			for(i=0; i<vertices; i++)
			{
				node *n = obj[i].vertex;
				while(n->next)
				{
					n = n->next;
					if(n->name == city)
						ind++;
				}
			}
			cout<<"No. of flights from "<<city<<" : "<<outd<<endl;
			cout<<"No. of flights to "<<city<<" : "<<ind<<endl;
		}
		void DAddEdges()
		{
			int i,ch,ch1;
			string dest;
			float t;
			for(i = 0; i<vertices; i++)
			{
				int count = 1;
				cout<<"\nEnter the cities having flight paths from ";
				cout<<(obj[i].vertex)->name<<" : "<<endl;
				cout<<"Press 0 if the mentioned city doesn't have any outgoing flight paths ";
				cin>>ch1;
				if(ch1 != 0)
				{
					do{
						cout<<"\nEnter city "<<count<<" : ";
						cin>>dest;
						cout<<"Enter the time of flight : ";
						cin>>t;
						obj[i].AddFlight(dest,t);
						count++;
						cout<<"\nPress 1 to add another flight path from this city\n";
						cout<<"Press 0 to change the current city\t";
						cin>>ch;
					}while(ch == 1);
				}
			}
		}
		void UDAddEdges()
		{
			int i,ch,ch1,j;
			string dest;
			float t;
			for(i = 0; i<vertices; i++)
			{
				int count = 1;
				cout<<"\nEnter the number cities having flight paths from ";
				cout<<(obj[i].vertex)->name<<" : "<<endl;
				cout<<"Press 0 if the mentioned city doesn't have any outgoing flight paths ";
				cin>>ch1;
				if(ch1 != 0)
				{
					do{
						cout<<"\nEnter city "<<count<<" : ";
						cin>>dest;
						cout<<"Enter the time of flight : ";
						cin>>t;
						obj[i].AddFlight(dest,t);
						j = 0;
						while((obj[j].vertex)->name != dest)
							j++;
						obj[j].AddFlight((obj[i].vertex)->name,t);
						count++;
						cout<<"\nPress 1 to add another flight path from this city\n";
						cout<<"Press 0 to change the current city\t";
						cin>>ch;
					}while(ch == 1);
				}
			}
		}
		void Display()
		{
			int i;
			cout<<"------- Displaying Graph -------\n";
			cout<<setw(15)<<"ORIGIN"<<setw(20)<<"DESTINATION"<<setw(40)<<"Time of Flight"<<endl;
			for(i = 0; i<vertices; i++)
				obj[i].DisAdjList();
			cout<<endl;
		}
		void DeleteCity()
		{
			string city;
			int i = 0;
			cout<<"Enter the name of the city :";
			cin>>city;
			while((obj[i].vertex)->name != city && i != vertices)
				i++;
			(obj[i].vertex)->time = -1;
			obj[i].NullifyRoutes();
			for(i=0; i<vertices; i++)
			{
				node *n = obj[i].vertex;
				while(n->next)
				{
					n = n->next;
					if(n->name == city)
						obj[i].del(city);
				}
			}
			cout<<"Removed City as specified.\n";
		}
		void DDeleteRoute()
		{
			string ori,dest;
			cout<<"Enter the flight details :\n";
			cout<<"Source City : ";cin>>ori;
			cout<<"Destination : ";cin>>dest;
			int i = 0;
			while((obj[i].vertex)->name != ori && i != vertices)
				i++;
			obj[i].del(dest);
			cout<<"The specified route is deleted.\n";
		}
		void UDDeleteRoute()
		{
			string ori,dest;
			cout<<"Enter the flight details :\n";
			cout<<"Source City : ";cin>>ori;
			cout<<"Destination : ";cin>>dest;
			int i = 0;
			while((obj[i].vertex)->name != ori && i != vertices)
				i++;
			obj[i].del(dest);
			int j = 0;
			while((obj[j].vertex)->name != dest && j != vertices)
				j++;
			obj[j].del(ori);
			cout<<"The specified route is deleted.\n";
		}
};

void DirectedGraph()
{
	int menu,choice;
	cout<<" :: Creating new DIRECTED GRAPH :: \n";
	Graph obj;
	obj.AddCities();
	obj.DAddEdges();
	obj.Display();
	do{
		cout<<"\nMENU : DIRECTED GRAPH\n";
		cout<<"Press 0 to display the graph in desired format.\n";
	    	cout<<"Press 1 to add new city to the graph.\nPress 2 to add new route to the graph.\n";
		cout<<"Press 3 to remove a city from the graph.\nPress 4 to delete a route from the graph.\n";
		cout<<"Press 5 to display the number of flights to and from a particular city.\t";
		cin>>menu;
		switch(menu)
		{
			case 0 :
			{
				obj.Display();
				break;
			}
			case 1 :
			{
				obj.AddNewCity();
				break;
			}
			case 2 :
			{
				obj.DAddNewRoute();
				break;
			}
			case 3 :
			{
				obj.DeleteCity();
				break;
			}
			case 4 :
			{
				obj.DDeleteRoute();
				break;
			}
			case 5 :
			{
				obj.Degree();
				break;
			}
			default :
			{
				cout<<"ERROR : Invalid Choice!\n";
				break;
			}
		}
		cout<<"Press 1 to CONTINUE with the current graph. \t Press 0 to EXIT from the current graph. \t";
		cin>>choice;
	}while(choice == 1);
}
void UndirectedGraph()
{
	int menu,choice;
	cout<<" :: Creating new UNDIRECTED GRAPH :: \n";
	Graph obj;
	obj.AddCities();
	obj.UDAddEdges();
	obj.Display();
	do{
		cout<<"\nMENU : UNDIRECTED GRAPH\n";
		cout<<"Press 0 to display the graph in desired format.\n";
		cout<<"Press 1 to add new city to the graph.\nPress 2 to add new route to the graph.\n";
		cout<<"Press 3 to remove a city from the graph.\nPress 4 to delete a route from the graph.\n";
		cout<<"Press 5 to display the number of flights to and from a particular city.\t";
		cin>>menu;
		switch(menu)
		{
			case 0 :
			{
				obj.Display();
				break;
			}
			case 1 :
			{
				obj.AddNewCity();
				break;
			}
			case 2 :
			{
				obj.UDAddNewRoute();
				break;
			}
			case 3 :
			{
				obj.DeleteCity();
				break;
			}
			case 4 :
			{
				obj.UDDeleteRoute();
				break;
			}
			case 5 :
			{
				obj.Degree();
				break;
			}
			default :
			{
				cout<<"ERROR : Invalid Choice!\n";
				break;
			}
		}
		cout<<"Press 1 to CONTINUE with the current graph. \t Press 0 to EXIT from the current graph. \t";
		cin>>choice;
	}while(choice == 1);
}

int main()
{
	int m;
	while(1)
	{
		cout<<"\n\nPress 1 if the graph is directed graph\nPress 2 if the graph is undirected graph\n";
		cout<<"Press 0 to EXIT.\t";
		cin>>m;
		if(m == 1)
		{
			DirectedGraph();
		}
		else if (m == 2)
		{
			UndirectedGraph();
		}
		else if (m == 0)
		{
			cout<<"\n\nExiting from the program\n";
			return 0;
		}
		else
			cout<<"ERROR : Invalid Choice!\n";
	}
}
