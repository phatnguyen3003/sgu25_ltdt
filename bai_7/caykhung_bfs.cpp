#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<stack>
#include<set>

using namespace std;

int sodinh,socanh;
vector<set<int>>adjList;
vector<bool>visited;
vector<pair<int,int>>caykhung;
//stack<int>s;


void doc()
{
    cin>>sodinh>>socanh;
    adjList.resize(sodinh+1);
    for(int i=0;i<socanh;i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
    visited.resize(sodinh+1,false);
}

void duyet_bfs(int x)
{
    visited[x]=true;
    //s.push(x);
    vector<int>hangdoi;
    hangdoi.push_back(x);
    for(int i=0;i<=hangdoi.size();i++)
    {
        int u = hangdoi[i];
        //s.pop();
        for(auto it = adjList[u].begin();it!=adjList[u].end();it++)
        {
            int v=*it;
            if(!visited[v])
            {
                visited[v]=true;
                caykhung.push_back({u,v});
                //s.push(v);
                hangdoi.push_back(v);
            }
        }
    }
}

void in()
{
    cout<<"cay khung bfs la: \n";
    for(int i=0;i<caykhung.size();i++)
    {
        cout<<caykhung[i].first<<" "<<caykhung[i].second<<"\n";
    }
}

int main()
{
    freopen("input/caykhung_dfs_va_bfs.inp","r",stdin);
    doc();
    duyet_bfs(1);
    in();
}