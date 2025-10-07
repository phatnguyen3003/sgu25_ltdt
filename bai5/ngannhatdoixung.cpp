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
vector<int>pre_1;
vector<int>pre_2;
vector<bool>label_1;
vector<bool>label_2;
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

void dijkstra(vector<int>&dist,int x,vector<int>&pre,vector<bool>&label)
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

bool find_path(vector<int>&dist_1,vector<int>&dist_2)
{
    path_1.clear();
    path_2.clear();
    sum_path.clear();
    dijkstra(dist_1,dau,pre_1,label_1);
    dijkstra(dist_2,giua,pre_2,label_2);
    if(dist_1[giua]==INF||dist_2[cuoi]==INF)
    {
        return false;
    }
    for(int u=giua;u!=dau;u=pre_1[u])
    {
        path_1.push_back(u);
    }
    path_1.push_back(dau);
    reverse(path_1.begin(),path_1.end());

    for(int u=cuoi;u!=-1 && u!=giua;u=pre_2[u])
    {
        path_2.push_back(u);
    }
    path_2.push_back(giua);
    reverse(path_2.begin(),path_2.end());

    sum_path=path_1;
    sum_path.insert(sum_path.end(),path_2.begin()+1,path_2.end());

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
        cout<<sum_path.size()<<" "<<dist_1[giua]+dist_2[cuoi]<<"\n";
        for(int i=0;i<sum_path.size();i++)
        {
            cout<<sum_path[i]<<" ";
        }
    }
}