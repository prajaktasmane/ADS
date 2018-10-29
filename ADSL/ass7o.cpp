#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

typedef class node
{
 private:
          string s;
          string t;          
          int n;
          int in;
 public:
         node()
         {
          n = 0;
          in = -1;
         }         
         friend class symbol;
}*nodeptr;


class symbol
{
 private:
               nodeptr head[100];
               int i;
  public:
               symbol()
               {
                 for(i=0;i<100;i++)
                 {
                   head[i] = NULL;
                 }
               }
               
               void insert()
               {
                 string a,b;
                 int no;
                 int j,g;
                 bool flag = 0;
                 cout<<"Enter ATTRIBUTE : ";
                 cin>>a;
                 cin.ignore();
                 cout<<"Enter its TYPE : ";
                 cin>>b;
                 cin.ignore();
                 cout<<"Enter TOTAL LINES : ";
                 cin>>no;
                 
                 int k = a.length();
                 g = k;
                 if(head[k]==NULL)
                 {
                  head[k] = new node;
                  head[k]->s = a;
                  head[k]->t = b;
                  head[k]->n = no;
                  cout<<"\n********ATTRIBUTE INSERTED********\n\n";                  
                 }
                 else
                 {
                  i = k+1;
                  while(i%100!=k)
                  {
                    if(head[i]!=NULL)
                    {
                      j = k;
                      while(head[j]->in!=-1)
                      {
                       j = head[j]->in;
                       g = j;
                      }
                    }
                    else
                    {
                      head[i] = new node;
                      head[i]->s = a;
                      head[i]->t = b;
                      head[i]->n = no;
                      head[g]->in = i;
                      cout<<"\n********ATTRIBUTE inserted********\n\n"; 
                      break;                    
                    }
                    i++;
                  }
                 }
                
               }
               
               void insertr()
               {
                 string a,b,c,d;
                 int no,nos;                 
                 int j,g;
                 bool flag = 0;
                 cout<<"Enter ATTRIBUTE : ";
                 cin>>a;
                 cin.ignore();
                 cout<<"Enter its TYPE : ";
                 cin>>b;
                 cin.ignore();
                 cout<<"Enter TOTAL LINES : ";
                 cin>>no;
                 
                 int k = a.length();
                 g = k;
                 if(head[k]==NULL)
                 {
                  head[k] = new node;
                  head[k]->s = a;
                  head[k]->t = b;
                  head[k]->n = no;
                  cout<<"\n********ATTRIBUTE INSERTED********\n\n";                  
                 }
                 else
                 {
                  c = head[k]->s;
                  d = head[k]->t;
                  nos = head[k]->n;
                  head[k]->s = a;
                  head[k]->t = b;
                  head[k]->n = no;
                  
                  i = k+1;
                  while(i%100!=k)
                  {
                    if(head[i]!=NULL)
                    {
                      j = k;
                      while(head[j]->in!=-1)
                      {
                       j = head[j]->in;
                       g = j;
                      }
                    }
                    else
                    {
                      head[i] = new node;
                      head[i]->s = c;
                      head[i]->t = d;
                      head[i]->n = nos;
                      head[g]->in = i;
                      cout<<"\n********ATTRIBUTE inserted********\n\n"; 
                      break;                    
                    }
                    i++;
                  }
                 }
               
               }
               
               void print()
               {
                cout<<"\nATRRIBUTE\tTYPE\t  N.O. OF LINES \tKEY VALUE\n";
                for(i=0;i<100;i++)
                {
                  if(head[i]!=NULL)
                  {
                   cout<<head[i]->s<<"\t\t"<<head[i]->t<<"\t\t"<<head[i]->n<<"\t\t"<<head[i]->in<<endl;
                  }
                } 
                cout<<endl;             
               }
               
               void find()
               {
                string g;
                cout<<"Enter ATTRIBUTE : ";
                cin>>g;      
                cin.ignore();          
                int k = rindex(g);
                if(k!=-1)
                {
                 cout<<"\n\n\t***REQUIRED DATA***\n";
                 cout<<head[k]->s<<"\t\t"<<head[k]->t<<"\t\t"<<head[k]->n<<endl<<endl;                 
                }
                else
                {
                 cout<<"\n\n********ATTRIBUTE NOT IN TABLE*********\n\n";
                }
               }
               
               int rindex(string f)
               {
                int k = f.length();
                i = -1;
                if(head[k]->s==f)
                {
                 return k;  
                }
                else
                { 
                  i = k;
                  while(head[i]->s!=f)
                  {
                    i = head[i]->in;
                  }
                }  
                return i;
               }
               
               void del()
               {
                string d;
                
                cout<<"Enter ATTRIBUTE : ";
                cin>>d;
                cin.ignore();
                int q = rindex(d);
                
                if(q!=-1)
                {
                 for(i=0;i<q;i++)
                 {
                   if(head[i]!=NULL)
                   {
                     if(head[i]->in==q)
                     {
                       head[i]->in = head[q]->in;
                       break;
                     }
                   }
                 } 
                 head[q] = NULL;
                 cout<<"\n\t***ATTRIBUTE DELETED***\n\n";
                }
                else
                {
                 cout<<"\n\n********ATTRIBUTE NOT IN TABLE*********\n\n";                 
                }
               } 
};

int main()
{
 int k;
 symbol s;
 while(1)
 {
  cout<<"\t1)INSERT(without replacement)\n\t2)INSERT(with replacement)\n\t3)PRINT\n\t4)FIND\n\t5)DELETE\n\t6)EXIT\nEnter CHOICE : ";
  cin>>k;
  switch(k)
  {
   case 1:
          s.insert();
          break;
   case 2:
          s.insertr();
          break;          
   case 3:
          s.print();
          break;
   case 4:
          s.find();
          break;
   case 5:
          s.del();
          break;
   case 6:       
          exit(1);
   default:
           cout<<"EnTeR ChOiCe CoRrEcTlY"<<endl;                              
  }
 }
 return 0;
}


