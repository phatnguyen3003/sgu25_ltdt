#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<sstream>

using namespace std;

#define INF 10000000

int dinh,canh;
vector<vector<pair<int,int>>> adjList;
vector<bool>visited;
vector<vector<int>>pre;
vector<int>dist;

vector<vector<int>>disttoall;

void doc()
{
    cin>>dinh>>canh;
    adjList.resize(dinh+1);
    for(int i=0;i<canh;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adjList[u].push_back({v,w});
    }
    visited.resize(dinh+1,false);
    pre.resize(dinh+1);
    disttoall.resize(dinh+1);
    for(int i=1;i<=dinh;i++)
    {
        disttoall[i].resize(dinh+1,INF);
    }
    for(int i=1;i<=dinh;i++)
    {
        pre[i].resize(dinh+1,-1);
    }
}

void dijkstra(int dau)
{
    visited.assign(dinh+1,false);

    for(int i=1;i<=dinh;i++)
    {
        disttoall[dau][i]=INF;
        pre[dau][i]=-1;
    }

    disttoall[dau][dau]=0;
    for(int k=0;k<dinh;k++)
    {
        int u=-1;
        int mindist=INF;
        for(int i=1;i<=dinh;i++)
        {
            if(!visited[i] && mindist>disttoall[dau][i])
            {
                u=i;
                mindist=disttoall[dau][i];
            }
        }
        if(u==-1)
        {
            return;
        }
        else
        {
            visited[u]=true;
        }
        for(int i=0;i<adjList[u].size();i++)
        {
            if(disttoall[dau][adjList[u][i].first]>disttoall[dau][u]+adjList[u][i].second)
            {
                disttoall[dau][adjList[u][i].first]=disttoall[dau][u]+adjList[u][i].second;
                pre[dau][adjList[u][i].first]=u;
            }
        }
    }
}

void in()
{
    cout<<"ma tran dist: \n";
    for(int i=1;i<=dinh;i++)
    {
        for(int j=1;j<=dinh;j++)
        {
            if(disttoall[i][j]==INF)
            {
                cout<<"INF ";
            }
            else
            {
                cout<<disttoall[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
    cout<<"\nma tran pre: \n";
    for(int i=1;i<=dinh;i++)
    {
        for(int j=1;j<=dinh;j++)
        {
            cout<<pre[i][j]<<" ";
        }
        cout<<"\n";
    }
}


int main()
{
    freopen("input_doc.inp","r",stdin);
    doc();
    for(int i=1;i<=dinh;i++)
    {
        dijkstra(i);
    }
    in();
}