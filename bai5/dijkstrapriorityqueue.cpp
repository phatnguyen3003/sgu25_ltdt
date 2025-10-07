#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>


using namespace std;

#define INF 1000000000

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pqueue;
vector<vector<pair<int,int>>> adjList;
vector<int>dist;
vector<int>pre;
vector<int>path;
int dinh,cung,dau,cuoi;

void doc()
{
    cin>>dinh>>cung>>dau>>cuoi;
    adjList.resize(dinh+1);
    dist.resize(dinh+1,INF);
    pre.resize(dinh+1,-1);
    for(int i=0;i<cung;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adjList[u].push_back({v,w});
    }
}

bool dijkstrapriority()
{
    dist[dau]=0;
    pqueue.push({0,dau});
    while(!pqueue.empty())
    {
        pair<int,int>top=pqueue.top();
        int distu=top.first;
        int u=top.second;
        pqueue.pop();
        if(distu!=dist[u])
        {
            continue;
        }
        for(int i=0;i<adjList[u].size();i++)
        {
            pair<int,int>component=adjList[u][i];
            int v=component.first;
            int w=component.second;
            if(dist[v]>distu+w)
            {
                dist[v]=distu+w;
                pre[v]=u;
                pqueue.push({dist[v],v});
            }
        }
    }
    if(dist[cuoi]!=INF)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void pathing()
{
    doc();
    if(dijkstrapriority())
    {
        for(int u=cuoi;u!=dau;u=pre[u])
        {
            path.push_back(u);
        }
        path.push_back(dau);
        reverse(path.begin(),path.end());
    }
    cout<<path.size()<<" "<<dist[cuoi]<<"\n";
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<" ";
    }
}


int main()
{
    freopen("input/dijkstrapriority.inp","r",stdin);
    pathing();
}