#include <iostream>
#include <vector>
#include <stack>
#include<sstream>
#include<algorithm>

using namespace std;

int n;
int u[10000], v[10000];
vector<int> G[6];
bool used[1000];
vector<int> circuit; 

void doc()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin >> a >> b;
        u[i]=a; v[i]=b;
        G[a].push_back(i);
        G[b].push_back(i);
        used[i]=false;
    }
}


bool EulerCheck()
{
    for(int i=1;i<=5;i++)
    {
        if(G[i].size()%2!=0)
        {
            return false;
        }
    }
    return true;
}

void dfs(int x)
{
    while(!G[x].empty())
    {
        int g=G[x].back();
        G[x].pop_back();
        if(used[g]==true)
        {
            continue;
        }
        used[g]=true;
        int y;
        if(u[g]==x)
        {
            y=v[g];
        }
        else
        {
            y=u[g];
        }
        dfs(y);
        if(v[g]!=x)
        {
            swap(v[g],u[g]);
        }
        circuit.push_back(g);
    }
}



int main()
{
    freopen("domino.inp","r",stdin);
    doc();
    if(EulerCheck())
    {
        cout<<"1\n";
        dfs(1);
        for(int i=0;i<n;i++)
        {
            cout<<u[circuit[i]]<<" "<<v[circuit[i]]<<"\n";
        }
    }
    else
    {
        cout<<0;
    }

}