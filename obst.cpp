#include <bits/stdc++.h>
using namespace std;

class x{
    int c,r,w;
public:
    x(){
        c=r=w=0;
    }
    friend class obst;
};
class obst{
    int n;
    int *q,*p;
    x x1[10][10];
public:
    obst(){
        n=0;
        cout<<"Enter the total no. of elements: \n";
            cin>>n;

            p=new int(n+1);
            q=new int(n+1);

        for(int i=0;i<=n;i++)
            p[i]=q[i]=0;
    }
    void input();
    void display();
    void create();
    void mincost();
    friend class x;

};
void obst::input(){

    cout<<"Enter the probabilities for successful search for each node starting from 1: \n";
    for(int i=1;i<=n;i++)
        cin>>p[i];
    cout<<"Enter the probabilities for unsuccessful search for each node starting from 0: \n";
        for(int i=0;i<=n;i++)
            cin>>q[i];

}
void obst::create(){
    for(int i=0;i<=n;i++){
        x1[i][i].c=0;
        x1[i][i].r=0;
        x1[i][i].w=q[i];
    }

    for(int i=0;i<=n-1;i++){
        x1[i][i+1].w= q[i]+q[i+1]+p[i+1];
        x1[i][i+1].r= i+1;
        x1[i][i+1].c= x1[i][i+1].w;
    }
    int j;
    for(int m=2;m<=n;m++){
        for(int i=0;i<=n-m;i++)
        { j=i+m;
            x1[i][j].w=x1[i][j-1].w+p[j]+q[j];

            //..........cost..........

            int min=99,mink=n,c1;
            for(int k=i+1;k<=j;k++){
                c1 = x1[i][k-1].c + x1[k][j].c;
                if(c1<min){
                    min=c1;
                    mink=k;
                }

            }

            x1[i][j].c= min + x1[i][j].w;
            x1[i][j].r=mink;


        }
    }
}
void obst::mincost(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<"w"<<i<<j<<":"<<x1[i][j].w<<"\n";
            cout<<"c"<<i<<j<<":"<<x1[i][j].c<<"\n";
            cout<<"r"<<i<<j<<":"<<x1[i][j].r<<"\n";

            cout<<"\n \n";
        }
    }

    cout<<"Minimum cost of tree is: \n"<<x1[0][n].c;
    cout<<"\n Root of tree is: \n "<<x1[0][n].r;
}

int main() {
//    cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
    obst o;
    o.input();
    o.create();
    o.mincost();
    return 0;
}
