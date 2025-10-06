#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<stack>

using namespace std;

#define MAX 100
vector<int> trail;
int n;
int matranke[MAX][MAX];
vector<int>oddvertex;
stack<int>s;

void doc()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>matranke[i][j];
            //cout<<matranke[i][j]<<" ";
        }
        //cout<<"\n";
    }
}

bool checkeulertrail()
{
    int sobacle=0,dem=0;
    for(int i=1;i<=n;i++)
    {
        dem=0;
        for(int j=1;j<=n;j++)
        {
            if(matranke[i][j]==1)
            {
                dem+=1;
            }
        }
        if(dem%2!=0)
        {
            sobacle+=1;
            oddvertex.push_back(i);
        }
        if(oddvertex.size()>2)
        {
            return false;
        }
    }
    if(oddvertex.size()!=2)
    {
        return false;
    }
    return true;
}


void EulerTrail(int start)
{
    s.push(start);
    while(!s.empty())
    {
        int u=s.top();
        int v;
        bool found=false;
        for(int i=1;i<=n;i++)
        {
            if(matranke[u][i]==1)
            {
                v=i;
                found=true;
                break;
            }
        }
        if(!found)
        {
            s.pop();
            trail.push_back(u);
        }
        else
        {
            matranke[u][v]--;
            matranke[v][u]--;
            s.push(v);
        }

    }
}


void solve()
{
    if(checkeulertrail())
    {
        cout<<"1"<<"\n";
        EulerTrail(oddvertex[0]);
        reverse(trail.begin(),trail.end());
        for(int i=0;i<trail.size();i++)
        {
            cout<<trail[i]<<" ";
        }
    }
    else
    {
        cout<<"0";
    }
}


int main()
{
    freopen("nuaeuler.inp","r",stdin);
    doc();
    solve();
}