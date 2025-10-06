#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

#define MAX 100
int n;
int matranke[MAX][MAX];
vector<int>path;
bool foundhamiltoncycles=false;


void doc()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>matranke[i][j];
        }
    }
}


bool check(int current)
{
    for(int i=0;i<path.size();i++)
    {
        if(current==path[i])
        {
            return false;
        }
    }
    return true;
}

void HamiltonCycles(int x)
{
    if(foundhamiltoncycles)
    {
        return;
    }
    
    path.push_back(x);
    if(path.size()==n)
    {
        if(matranke[x][path[0]]==1)
        {
            cout<<"1"<<"\n";
            for(int i=0;i<path.size();i++)
            {
                cout<<path[i]<<" ";
            }
            cout<<path[0]<<"\n";
            foundhamiltoncycles=true;
        }
        path.pop_back();
        return;
    }

    for(int i=1;i<=n;i++)
    {
        if(matranke[x][i]==1 && check(i))
        {
            HamiltonCycles(i);
        }
    }
    path.pop_back();
}

int main()
{
    freopen("chutrinhhamilton.inp","r",stdin);
    doc();
    HamiltonCycles(1);
    if(!foundhamiltoncycles)
    {
        cout<<"0";
    }
}