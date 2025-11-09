#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

int sodinh,socanh;
vector<vector<int>>adjList;
vector<bool>visited;
vector<pair<int,int>>caykhung;

/*

sodinh : so dinh cua do thi
socanh : so canh cua do thi
caykhung <== (u,v) chua canh cua cay khung


*/



void doc()
{
    cin>>sodinh>>socanh;
    adjList.resize(sodinh+1);
    for(int i=0;i<socanh;i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for(int i=1;i<=sodinh;i++)
    {
        sort(adjList[i].begin(),adjList[i].end());
    }
    visited.resize(sodinh+1,false);
}

/*

adjList[u] <== v
adjList[v] <== u

visited.resize(sodinh+1,false)


*/


void duyet_dfs(int u)
{
    visited[u]=true;
    for(int i=0;i<adjList[u].size();i++)
    {
        int v= adjList[u][i];
        if(!visited[v])
        {
            caykhung.push_back({u,v});
            duyet_dfs(v);
        }
    }
}

void in()
{
    cout<<caykhung.size()<<"\n";
    for(int i=0;i<caykhung.size();i++)
    {
        cout<<caykhung[i].first<<" "<<caykhung[i].second<<"\n";
    }
}


int main()
{
    freopen("input/caykhung_dfs_va_bfs.inp","r",stdin);
    doc();
    duyet_dfs(1);
    in();
}