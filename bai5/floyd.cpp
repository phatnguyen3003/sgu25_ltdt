#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 1000000000

vector<vector<int>>dist;
vector<vector<int>>path;
int dinh,cung;

void doc()
{
    cin>>dinh>>cung;
    dist.resize(dinh+1);
    for(int i=0;i<dinh+1;i++)
    {
        dist[i].resize(dinh+1,INF);
    }

    path.resize(dinh+1);
    for(int i=0;i<dinh+1;i++)
    {
        path[i].resize(dinh+1,-1);
    }


    for(int i=1;i<=dinh;i++)
    {
        dist[i][i]=0;
    }

    for(int i=0;i<cung;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        if(dist[u][v]>w)
        {
            dist[u][v]=w;
            path[u][v]=v;
            //dist[v][u]=w;
            //path[v][u]=u;
        }
    }
}

void floyd()
{
    for(int k=1;k<=dinh;k++)
    {
        for(int i=1;i<=dinh;i++)
        {
            for(int j=1;j<=dinh;j++)
            {
                if(dist[i][k]<INF && dist[k][j]<INF && dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    path[i][j]=path[i][k];
                }
            }
        }
    }
}


void solve()
{
    doc();
    floyd();
    for(int i=1;i<=dinh;i++)
    {
        for(int j=1;j<=dinh;j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
}


int main()
{
    freopen("input/floyd.inp","r",stdin);
    solve();
}