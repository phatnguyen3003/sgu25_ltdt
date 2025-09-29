#include<iostream>
#include<vector>
#include<fstream>
#include<set>
#include<vector>
#include<sstream>
#include<string>
#include<queue>

#define FI "CANHCAUDINHKHOPBFS.INP"
#define FO "CANHCAUDINHKHOPBFS.OUT"

using namespace std;

vector<bool> visited;
queue<int> queued;
vector<set<int>> adjList;
int n,x,y,z,sotp=0;

void bfs(int x)
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
    sotp+=1;
}

void doc()
{
    char line[10000];
    cin>>n>>x>>y>>z;
    cin.ignore();
    //cout<<n<<" "<<x;
    int v;
    adjList.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin.getline(line,10000);
        stringstream stringline(line);
        while(stringline>>v)
        {
            adjList[i].insert(v);
            //adjList[v].insert(i);
            //cout<<v<<" ";
        }
        //cout<<endl;
    }
    visited.resize(n+1,false);
}

void solve_cau()
{
    if(adjList[x].find(y)==adjList[x].end())
    {
        cout<<"khong la canh cau";
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false)
        {
            bfs(i);
        }
    }
    int temp=sotp;
    fill(visited.begin(),visited.end(),false);
    sotp=0;
    adjList[x].erase(y);
    adjList[y].erase(x);
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false)
        {
            bfs(i);
        }
    }
    if(temp<sotp)
    {
        cout<<"la canh cau";
    }
    else
    {
        cout<<"khong la canh cau";
    }
    adjList[x].insert(y);
    adjList[y].insert(x);
}


void solve_khop()
{
    if(adjList[z].size()==0)
    {
        cout<<"khong la dinh khop";
        return;
    }
    fill(visited.begin(),visited.end(),false);
    sotp=0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false)
        {
            bfs(i);
        }
    }
    int temp=sotp;
    sotp=0;
    fill(visited.begin(),visited.end(),false);
    visited[z]=true;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false)
        {
            bfs(i);
        }
    }
    if(temp<sotp)
    {
        cout<<"la dinh khop";
    }
    else
    {
        cout<<"khong la dinh khop";
    }
}

int main()
{
    freopen(FI,"r",stdin);
    doc();
    solve_cau();
    cout<<endl;
    solve_khop();
    return 0;
}