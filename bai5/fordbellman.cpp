#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 1000000000

struct vertex{
    int u,v,w;
    vertex(int _u,int _v,int _w)
    {
        u=_u;
        v=_v;
        w=_w;
    }
};

vector<int>dist;
vector<int>path;
vector<int>pre;
vector<vector<vertex>> adjList;
int dinh,cung,x,y;
void doc()
{
    cin>>dinh>>cung>>x>>y;
    adjList.resize(dinh+1);
    for(int i=0;i<cung;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adjList[u].push_back(vertex(u,v,w));
    }
}


bool fordbellman()
{
    dist.resize(dinh+1,INF);
    dist[x]=0;
    pre.resize(dinh+1,-1);
    for(int k=0;k<dinh;k++)
    {
        bool checked=false;
        for(int u=1;u<=dinh;u++)
        {
            for(int j=0;j<adjList[u].size();j++)
            {
                vertex canh = adjList[u][j];
                int v=canh.v;
                int w=canh.w;
                if(dist[u]!=INF && dist[u]+w<dist[v])
                {
                    dist[v]=dist[u]+w;
                    pre[v]=u;
                    checked=true;
                }
            }
        }
        if(checked==false)
        {
            return true;
        }
    }
    for(int u=1;u<=dinh;u++)
    {
        for(int j=0;j<adjList[u].size();j++)
        {
            vertex canh=adjList[u][j];
            int v=canh.v;
            int w=canh.w;
            if(dist[u]!=INF && dist[u]+w<dist[v])
            {
                return false;
            }
        }
    }
    return true;
}