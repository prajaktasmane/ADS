/*
Name:-Shubham Maheshwari
Roll Number-2274
Division-SE-II
Problem Statement:-	
Department maintains a student information. The file contains roll number, name, division and address.
Allow user to add, delete information of student. Display information of particular employee.If record 
of student does not exist an appropriate message is displayed. If it is, then the system displays the 
student details. Use sequential file to main the data.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool call;
class student
{
	public:
	int div;
        int flag;
	int roll;
	string name;
	string city;
	void add();
	void del();
	void display(string );
	friend istream &operator >>(istream &in,student &s);	
  	friend ostream &operator <<(ostream &out,student &s);  
};
istream &operator >>(istream &in,student &s)
{	
        in>>s.name;
	in>>s.div;
	in>>s.roll;
	in>>s.city;
	return in;
}
ostream &operator <<(ostream &out,student &s)
{
        out<<s.name<<"\t";
	out<<s.div<<"\t";
	out<<s.roll<<"\t";
	out<<s.city<<endl;
	return out;
}
void student::add()
{
	student s;
	fstream file;
	file.open("student.txt",ios::app);
	cout<<"Enter the Student Details (Name,Division,Roll Number,Resdience City):-\n";
	cin>>s;
	file<<s;
	file.close();
	cout<<"Record Added Succesfully.\n";
}
void student::display(string a)
{
	fstream file;
	student s;
	flag=0;
	file.open("student.txt",ios::in);
	while(!file.eof())
	{
		file>>s;
		if(s.name==a)
		{
			flag=1;
			break;
		}
	}
	if(flag==1 && call==false)
	{
		cout<<"Record is:-\n";
		cout<<s;
	}
	if(!flag)
	{
		cout<<"Record not Found.\n";
		return;
	}
	file.close();
}
void student::del()
{
  	fstream file1,file2;
	student s;
	string n;	
        cout<<"Enter the name of Student for which you want to delete record:-\n";
	cin>>n;
	call=true;
	display(n);
        if(!flag)
        {
	  cout<<"Record not Found.\n";
	  return;
	}
	call=false;
	file1.open("student.txt",ios::in);
	file2.open("temp.txt",ios::out);
	while(!file1.eof())
	{
	  file1>>s;
	  if(s.name==n)
		{
		  continue;
		}
	 if(file1.eof())
	  {
	  	break;
	  }	
	  file2<<s;
	  file2<<endl;
	}
	file1.close();
	file2.close();	
	cout<<"Record Deleted Successfully.\n";
	remove("student.txt");
	rename("temp.txt","student.txt");
}
int main()
{
  string k;
  student s;
  int l;
  do
  {
  	cout<<"Enter your choice:-\n";
  	cout<<"1.Add a Record to File\n";
  	cout<<"2.Search and Display Records\n";
  	cout<<"3.Delete a Record from File\n";
  	cout<<"4.Exit\n";
  	cin>>l;
  	switch(l)
  	{
  	 case 1:
	 s.add();
	 break;
	 case 2:
         cout<<"Enter the student you want to search:-\n";
         cin>>k;
         s.display(k);
	 break;
	 case 3:
	 s.del();
	 break;
	 case 4:
	 break;
	 default:
	 cout<<"!!Invalid Choice!!\n";
	 break;	
	}
  }while(l!=4);
  return 0;
}

