#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n,m;

queue<int>hangdoi;
vector<vector<int>>adjList;
vector<int>color;


void doc()
{
    cin>>n>>m;
    adjList.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    color.resize(n+1,0);
}

bool duyet(int dau)
{
    hangdoi.push(dau);
    color[dau]=1;
    while(!hangdoi.empty())
    {
        int u=hangdoi.front();
        hangdoi.pop();
        int maucanto = 3 - color[u];

        for(int i=0;i<adjList[u].size();i++)
        {
            int v = adjList[u][i];

            if(color[v]==0)
            {
                color[v]=maucanto;
                hangdoi.push(v);
            }
            else if(color[u]==color[v])
            {
                return false;
            }
        }
    }
    return true;
}

void giai()
{
    bool possible = true;

    for(int i=1;i<=n;i++)
    {
        if(color[i]==0)
        {
            if(!duyet(i))
            {
                possible=false;
                break;
            }
        }
    }
    if(!possible)
    {
        cout<<"IMPOSSIBLE";
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            cout<<color[i]<<" ";
        }
    }
}

int main()
{
    freopen("input/TEAMBUILDING.inp","r",stdin);
    doc();
    giai();
}