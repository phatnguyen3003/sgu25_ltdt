#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cmath>

using namespace std;

#define INF 1000000000

vector<vector<int>> dist;//luu khoang cach ngan nhat tu u den v
vector<vector<pair<int,int>>> pre; //luu duong di tu dinh u den v
vector<vector<int>> List; //danh sach trong so (se chu yeu lam viec trong day)
vector<vector<bool>> visited;
int n,m,xi,yi,xj,yj;


void doc()
{
    cin>>n>>m>>xi>>yi>>xj>>yj;
    dist.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        dist[i].resize(m+1,INF);
    }
    List.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        List[i].resize(m+1,0);
    }
    pre.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        pre[i].resize(m+1,{-1,-1});
    }

    visited.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        visited[i].resize(m+1,false);
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>List[i][j];
        }
    }

}

void dijkstra()
{
    dist[xi][yi]=0;
    for(int k=0;k<n*m;k++)
    {
        int xt=-1,yt=-1;
        int min_dist=INF;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(min_dist>dist[i][j] && visited[i][j]==false)
                {
                    min_dist=dist[i][j];
                    xt=i;
                    yt=j;
                }
            }
        }
        if(xt==-1 && yt==-1)
        {
            break;
        }
        visited[xt][yt]=true;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if(abs(i)+abs(j)==1)
                {
                    int x_moi=xt+i;
                    int y_moi=yt+j;
                    if(x_moi<=n && y_moi<=m && x_moi>=1 && y_moi>=1)
                    {
                        if(List[x_moi][y_moi]==0)
                        {
                            continue;
                        }
                        if(dist[x_moi][y_moi]>dist[xt][yt]+List[x_moi][y_moi])
                        {
                            dist[x_moi][y_moi]=dist[xt][yt]+List[x_moi][y_moi];
                            pre[x_moi][y_moi]={xt,yt};
                        }
                    }
                }
            }
        }
    }
}


void solve()
{
    doc();
    if(List[xi][yi]==0 || List[xj][yj]==0)
    {
        cout<<"0";
    }
    dijkstra();
    if(dist[xj][yj]!=INF)
    {
        cout<<"1\n";
        cout<<dist[xj][yj]-List[xj][yj]<<"\n";
        vector<pair<int,int>>path;
        int i=xj;
        int j=yj;
        while(i!=xi || j !=yi)
        {
            path.push_back({i,j});
            i=pre[i][j].first;
            j=pre[i][j].second;
        }
        path.push_back({i,j});
        reverse(path.begin(),path.end());
        for(int i=0;i<path.size();i++)
        {
            cout<<path[i].first<<" "<<path[i].second<<"\n";
        }
    }

}


int main()
{
    freopen("input/mintable.inp","r",stdin);
    solve();
    return 0;
}