#include<iostream>
#include<vector>
#include<fstream>
#include<set>
#include<vector>
#include<sstream>
#include<string>
#include<queue>

#define FI "DUONGDIBFS.INP"
#define FO "DUONGDIBFS.OUT"

using namespace std;
vector<bool> visited;
queue<int> queued;
vector<set<int>> adjList;
vector<int> parent;
int n,x,y;


void solve_bfs()
{
    visited[x]=true;
    queued.push(x);
    while(!queued.empty())
    {
        int u= queued.front();
        queued.pop();
        if(u==y)
            {
                break;
            }
        for(set<int>::iterator it= adjList[u].begin();it!=adjList[u].end();it++)
        {
            int v=*it;
            if(visited[v]==false)
            {
                visited[v]=true;
                parent[v]=u;
                queued.push(v);
            }
        }
    }
    vector<int> path;
    if(visited[y]==false)
    {
        cout<<"khong co duong di";
    }
    else
    {
        int u=y;
        while(u!=-1)
        {
            path.push_back(u);
            u=parent[u];
        }
        //reverse(path.begin(), path.end());
        cout<<path.size()<<endl;
        for(int i=path.size()-1;i>=0;i--)
        {
            cout<<path[i]<<" ";
        }
    }
    
}
void doc()
{
    char line[10000];
    cin>>n>>x>>y;
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
            //cout<<v<<" ";
        }
        //cout<<endl;
    }
    visited.resize(n+1,false);
    parent.resize(n+1,-1);
    //open.resize(n+1);
}


int main()
{
    freopen(FI,"r",stdin);
    doc();
    solve_bfs();
    return 0;
}