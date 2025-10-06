#include<iostream>
#include<vector>
#include<fstream>
#include<set>
#include<vector>
#include<sstream>
#include<string>
#include<queue>

#define FI "THANHPHANLIENTHONGBFS.INP"
#define FO "THANHPHANLIENTHONGBFS.OUT"

using namespace std;

vector<bool> visited;
queue<int> queued;
vector<set<int>> adjList;
vector<vector<int>> box;
int n,sotp=0;


void bfs(int x)
{
    visited[x]=true;
    queued.push(x);
    while(!queued.empty())
    {
        int u= queued.front();
        queued.pop();
        box[sotp].push_back(u);
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
    cin>>n;
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

void solve()
{
    box.resize(n);
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false)
        {
            bfs(i);
        }
    }
    cout<<sotp<<endl;
    for(int i=0;i<sotp;i++)
    {
        for(int j=0;j<box[i].size();j++)
        {
            cout<<box[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    freopen(FI,"r",stdin);
    doc();
    solve();
    return 0;
}