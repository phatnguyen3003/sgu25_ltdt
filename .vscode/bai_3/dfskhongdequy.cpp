#include<iostream>
#include<vector>
#include<fstream>
#include<set>
#include<vector>
#include<sstream>
#include<string>

#define FI "DFSKHONGDEQUY.INP"
#define FO "DFSKHONGDEQUY.OUT"

using namespace std;

int n,x;
vector<bool> visited;
vector<set<int>> adjList;
vector<int> open;
stringstream stringline;

void dfs()
{
    visited[x]=true;
    open.push_back(x);
    while(!open.empty())
    {
        int u=open.back();
        open.pop_back();
        cout<<u<<" ";
        for(set<int>::iterator it=adjList[u].begin();it != adjList[u].end();it++)
        {
            int v=*it;
            if(!visited[v])
            {
                visited[v]=true;
                open.push_back(v);
                //cout<<v<<" ";
            }
        }
    }
}



void doc()
{
    char line[10000];
    cin>>n>>x;
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
    //open.resize(n+1);
}


int main()
{
    freopen(FI,"r",stdin);
    doc();
    dfs();
    return 0;
}