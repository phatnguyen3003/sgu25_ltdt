#include<iostream>
#include<vector>
#include<fstream>
#include<set>
#include<vector>
#include<sstream>
#include<string>

#define FI "DUONGDIDFS.INP"
#define FO "DUONGDIDFS.OUT"

using namespace std;

int n,x,y;
vector<bool> visited;
vector<set<int>> adjList;
vector<int>parrent;

stringstream stringline;

void duong_di_dfs(int x)
{
    visited[x]=true;
    for(set<int>::iterator it=adjList[x].begin();it != adjList[x].end();it++)
    {
        int v=*it;
        if(!visited[v])
        {
            visited[v]=true;
            parrent[v]=x;
            duong_di_dfs(v);
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
    parrent.resize(n+1,-1);
    //open.resize(n+1);
}

int main()
{
    freopen(FI,"r",stdin);
    doc();
    duong_di_dfs(x);
    if (!visited[y]) {
        cout << "khong co duong di tu " << x << " den " << y;
    } else {
        vector<int> path;
        for (int u = y; u != -1; u = parrent[u]) {
            path.push_back(u);
        }
        cout << path.size() << endl;
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
    }
    return 0;
}