#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<stack>
#include<set>
#include<queue>

using namespace std;

int sodinh,socanh;
vector<set<int>>adjList;
vector<bool>visited;
vector<pair<int,int>>caykhung;
queue<int>queued;
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

/*

sodinh : so dinh cua do thi
socanh : so canh co trong do thi de doc dau vao

vector<int> hangdoi gia lap 1 hang doi ma khong dung stack, vi ket qua duoc in theo huong tang dan tu nho den lon
visited.resize(sodinh+1,false)
adjList.resize(Sodinh+1)



*/



void duyet_bfs(int x)
{
    visited[x]=true;
    //s.push(x);
    
    queued.push(x);
    for(int i=0;i<=queued.size();i++)
    {
        int u = queued.front();
        queued.pop();
        //s.pop();
        for(auto it = adjList[u].begin();it!=adjList[u].end();it++)
        {
            int v=*it;
            if(!visited[v])
            {
                visited[v]=true;
                caykhung.push_back({u,v}); // push cap dinh u va v vao caykhung chua cac canh cua cay khung dang tim
                //s.push(v);
                queued.push(v);
            }
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
    duyet_bfs(1);
    in();
}