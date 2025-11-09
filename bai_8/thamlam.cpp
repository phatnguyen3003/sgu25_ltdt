#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

int n,m;
vector<vector<int>>adjList;
vector<pair<int,int>>Deg;
vector<int>color;
vector<bool>used;

void doc()
{
    cin>>n>>m;
    adjList.resize(n+1);
    color.resize(n+1,0);
    used.resize(n+1,false);

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        Deg.push_back({i,adjList[i].size()});       // thêm bậc của từng đỉnh vào Deg 
    }
}


int chonmau(int dinhxet)
{
    used.assign(n+1,false);                     // gán lại mảng chứa màu đã dùng
    for(int i=0;i<adjList[dinhxet].size();i++)      // dòng 39 đến 46 => duyệt từng đỉnh kề với dinhxet đánh dấu màu đã được dùng ở các đỉnh đó vào used
    {
        int u = adjList[dinhxet][i];
        if(color[u]!=0)
        {
            used[color[u]]=true;
        }
    }
    for(int i=1;i<=n;i++)                            
    {
        if(!used[i])
        {
            return i;
        }
    }
    return -1;
}

void sorting()
{
    sort(Deg.begin(),Deg.end(),[](const pair<int,int>&a , const pair<int,int>&b)
    {
        return a.second<b.second;
    });
}


void duyet()
{
    for(int i=0;i<Deg.size();i++)
    {
        pair<int,int> u_pair =Deg[i];

        int u = u_pair.first;
        color[u]=chonmau(u);
        if(color[u]==-1)
        {
            break;
        }
    }
}

void in()
{
    int maucaonhat = 0;
    for(int i=1;i<=n;i++)
    {
        if(maucaonhat<color[i])
        {
            maucaonhat=color[i];
        }
    }
    cout<<maucaonhat<<"\n";
    for(int i=1;i<=maucaonhat;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(color[j]==i)
            {
                cout<<j<<" ";
            }
        }
        cout<<"\n";
    }
}

int main()
{
    freopen("input/thamlam.inp","r",stdin);
    doc();
    duyet();
    in();
}



