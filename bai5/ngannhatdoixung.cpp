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

vector<int>path_1;
vector<int>path_2;
vector<int>sum_path;
vector<int>pre;
vector<bool>label;
vector<vector<vertex>> adjList;
int dinh,cung,dau,cuoi,giua;

void doc()
{
    cin>>dinh>>cung>>dau>>cuoi>>giua;
    adjList.resize(dinh+1);
    for(int i=0;i<cung;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adjList[u].push_back(vertex(u,v,w));
    }
}

void dijkstra(vector<int>&dist,int x)
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

bool find_path(vector<int>dist_1,vector<int>dist_2)
{
    dijkstra(dist_1,dau);
    dijkstra(dist_2,giua);
    if(dist_1[giua]==INF||dist_2[cuoi]==INF)
    {
        return false;
    }
    for(int u=giua;u!=dau;u=pre[u])
    {
        path_1.push_back(u);
    }
    path_1.push_back(dau);
    reverse(path_1.begin(),path_1.end());

    for(int u=cuoi;u!=giua;u=pre[u])
    {
        path_2.push_back(u);
    }
    path_2.push_back(dau);
    reverse(path_1.begin(),path_1.end());

    sum_path.insert(path_1.end(),path_2.begin(),path_2.end());

    return true;
}

int main()
{
    vector<int>dist_1;
    vector<int>dist_2;
    freopen("input/ngannhatdoixung.inp","r",stdin);
    doc();
    if(find_path(dist_1,dist_2))
    {
        cout<<sum_path.size()<<" "<<dist_2[cuoi]<<"\n";
        for(int i=0;i<sum_path.size();i++)
        {
            cout<<sum_path[i]<<" ";
        }
    }
}