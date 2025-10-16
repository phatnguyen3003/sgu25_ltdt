#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cmath>

using namespace std;

#define INF 1000000000
int sohtron,dau,cuoi;

struct cycle
{
    int x,y,r;
    cycle(int _x,int _y,int _r)
    {
        x=_x;
        y=_y;
        r=_r;
    }
};

vector<cycle> dshtron;
vector<vector<int>> adjList;
vector<vector<int>> step_jump;
vector<bool> visited;
vector<pair<int,int>> parent;
vector<pair<int,int>> dist;

void doc()
{
    cin>>sohtron>>dau>>cuoi;
    for(int i=0;i<sohtron;i++)
    {
        int x,y,r;
        cin>>x>>y>>r;
        dshtron.push_back(cycle(x,y,r));
    }

    adjList.resize(sohtron+1);
    step_jump.resize(sohtron+1);
    for(int i=0;i<=sohtron;i++)
    {
        step_jump[i].resize(sohtron+1,-1);
    }

    for(int i=1;i<=sohtron;i++)
    {
        for(int j=1;j<=sohtron;j++)
        {
            if(i!=j)
            {
                int x1=dshtron[i-1].x;
                int y1=dshtron[i-1].y;
                int r1=dshtron[i-1].r;
                int x2=dshtron[j-1].x;
                int y2=dshtron[j-1].y;
                int r2=dshtron[j-1].r;

                int khoang_cach=sqrt((pow(x2-x1,2) + pow(y2-y1,2))) - (r1 + r2);
                if(khoang_cach<0) khoang_cach=0;

                if(khoang_cach<=60)
                {
                    adjList[i].push_back(j);
                    step_jump[i][j]=(khoang_cach<=50?0:1);
                }
            }
        }
    }
}


void duyet()
{
    visited.resize(sohtron+1,false);
    parent.resize(sohtron+1,{-1,-1});
    dist.resize(sohtron+1,{INF,0});
    dist[dau].first=0;
    
    for(int i=1;i<=sohtron;i++)
    {
        int u=-1;
        int min_dist=INF;
        for(int j=1;j<=sohtron;j++)
        {
            if(!visited[j] && dist[j].first<min_dist)
            {
                min_dist=dist[j].first;
                u=j;
            }
        }
        if(u==-1)
        {
            break;
        }
        visited[u]=true;
        for(int g=0;g<adjList[u].size();g++)
        {
            int v = adjList[u][g];
            int step = step_jump[u][v];

            if(step==-1)
            continue;
            if(dist[v].first > dist[u].first + step || (dist[v].first == dist[u].first + step && dist[v].second > dist[u].second + 1))
            {
                dist[v].first = dist[u].first+step;
                dist[v].second = dist[u].second + 1;
                parent[v].first = u;
                parent[v].second = step;
            }
        }
    }

}

void solve()
{
    doc();
    duyet();
    vector<int>path;
    if(dist[cuoi].first!=INF)
    {
        cout<<"1\n";
        for(int u=cuoi;u!=-1;u=parent[u].first)
        {
            path.push_back(u);
        }
        reverse(path.begin(),path.end());
        cout<<dist[cuoi].first<<" "<<dist[cuoi].second+1<<"\n";
        for(int i=0;i<path.size();i++)
        {
            cout<<path[i]<<" "<<parent[path[i]].second<<"\n";
        }
    }
}

int main()
{
    freopen("input/cycle.inp","r",stdin);
    solve();
    return 0;
}