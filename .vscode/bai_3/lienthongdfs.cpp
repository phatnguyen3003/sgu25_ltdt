#include<iostream>
#include<vector>
#include<fstream>
#include<set>
#include<vector>
#include<sstream>
#include<string>

#define FI "LIENTHONGDFS.INP"
#define FO "LIENTHONGDFS.OUT"

using namespace std;

int n,x;
vector<bool> visited;
vector<set<int>> adjList;
vector<int> near;
stringstream stringline;

void dfs(int x)
{
    visited[x]=true;
        near.push_back(x);
        for(set<int>::iterator it=adjList[x].begin();it != adjList[x].end();it++)
        {
            int v=*it;
            if(!visited[v])
            {
                visited[v]=true;
                dfs(v);
                //cout<<v<<" ";
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

void solve()
{
    dfs(x);
    cout<<near.size()<<endl;
    for(int i=0;i<near.size();i++)
    {
        cout<<near[i]<<" ";
    }
}

int main()
{
    freopen(FI,"r",stdin);
    doc();
    solve();
    return 0;
}