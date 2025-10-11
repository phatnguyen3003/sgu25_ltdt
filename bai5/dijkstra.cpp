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
vector<bool>label;
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

void dijkstra()
{
    dist.resize(dinh+1,INF);
    dist[x]=0;
    pre.resize(dinh+1,-1);
    label.resize(dinh+1,false);
    for(int k=0;k<dinh;k++)
    {
        int u=-1;
        int mindist=INF;
        for(int i=1;i<=dinh;i++)
        {
            if(!label[i] && dist[i]<mindist)
            {
                u=i;
                mindist=dist[i];
            }
        }
        if(u==-1)
        {
            return;
        }
        label[u]=true;
        for(int i=0;i<adjList[u].size();i++)
        {
            vertex canh= adjList[u][i];
            int v=canh.v;
            int w=canh.w;

            if(dist[v] > dist[u]+w)
            {
                dist[v]=dist[u]+w;
                pre[v]=u;
            }
        }
    }
}

bool find_path()
{
    dijkstra();
    if(dist[y]==INF)
    {
        cout<<"ko";
        return false;
    }
    for(int u=y;u!=x;u=pre[u])
    {
        path.push_back(u);
    }
    path.push_back(x);
    reverse(path.begin(),path.end());
    return true;
}

int main()
{
    freopen("input/dijktranopriorityqueue.inp","r",stdin);
    doc();
    if(find_path())
    {
        cout<<path.size()<<" "<<dist[y]<<"\n";
        for(int i=0;i<path.size();i++)
        {
            cout<<path[i]<<" ";
        }
    }
}