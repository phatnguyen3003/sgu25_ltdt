#include<iostream>
#include<vector>
#include<fstream>
#include<set>
#include<vector>
#include<sstream>
#include<string>
#include<queue>

#define FI "LIENTHONGBFS.INP"
#define FO "LIENTHONGBFS.OUT"

using namespace std;
vector<bool> visited;
queue<int> queued;
vector<set<int>> adjList;
int n,x;

void doc()
{
    cin>>n>>x;
    adjList.resize(n+1);
    cin.ignore();
    char line[100000];
    int v;
    for(int i=1;i<=n;i++)
    {
        cin.getline(line,1000);
        stringstream ss(line);
        while(ss>>v)
        {
            adjList[i].insert(v);
        }
    }
    visited.resize(n+1);
}



void bfs()
{
    visited[x]=true;
    queued.push(x);
    while(!queued.empty())
    {
        int u= queued.front();
        queued.pop();
        for(set<int>::iterator it= adjList[u].begin();it != adjList[u].end();it++)
        {
            int v=*it;
            if(visited[v]==false)
            {
                visited[v]=true;
                queued.push(v);
            }
        }
    }
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==true)
        count+=1;
    }
    cout<<count<<endl;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==true && i!=x)
        cout<<i<<" ";
    }
}



int main()
{
    freopen(FI,"r",stdin);
    doc();
    bfs();
    return 0;
}