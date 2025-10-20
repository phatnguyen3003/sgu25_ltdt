#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<queue>
#include<algorithm>

using namespace std;
vector<vector<int>> adjList;
vector<int>visited;
vector<vector<int>> tplienthong;
vector<int>pre;
vector<int>path;
int sotp=0;
int dinh,dau,cuoi;

void doc()
{
    cin>>dinh>>dau>>cuoi;
    cin.ignore();
    char line[10000];
    int v;

    adjList.resize(dinh+1);
    for(int i=1;i<=dinh;i++)
    {
        cin.getline(line,10000);
        stringstream ss(line);
        while(ss>>v)
        {
            adjList[i].push_back(v);
        }
    }
    /*for(int i=1;i<=dinh;i++)
    {
        for(int j=0;j<adjList[i].size();j++)
        {
            cout<<adjList[i][j]<<" ";
        }
        cout<<"\n";
    }*/
   visited.resize(dinh+1,false);
   tplienthong.resize(dinh+1);
   pre.resize(dinh+1,-1);
}

void dfs(int x)
{
    visited[x]=true;
    tplienthong[sotp].push_back(x);
    for(int i=0;i<adjList[x].size();i++)
    {
        int v=adjList[x][i];
        if(!visited[v])
        {
            pre[v]=x;
            dfs(v);
        }
    }
}


bool check()
{
    for(int i=1;i<=sotp;i++)
    {
        if(find(tplienthong[i].begin(),tplienthong[i].end(),dau) != tplienthong[i].end() && find(tplienthong[i].begin(),tplienthong[i].end(),cuoi) != tplienthong[i].end())
        {
            return true;
        }
    }
    return false;
}


void in()
{
    for(int i=1;i<=sotp;i++)
    {
        cout<<"thanh phan thu "<<i<<" :\n";
        for(int j=0;j<tplienthong[i].size();j++)
        {
            cout<<tplienthong[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    if(pre[cuoi]!=-1 && check())
    {
        cout<<"duong di tu "<<dau<<" den "<<cuoi<<" la: \n";
        pre[dau]=-1;
        for(int u=cuoi;u!=-1;u=pre[u])
        {
            path.push_back(u);
        }
        reverse(path.begin(),path.end());
        for(int i=0;i<path.size();i++)
        {
            cout<<path[i]<<" ";
        }
    }
    else
    {
        cout<<"khong co duong di tu "<<dau<<" den "<<cuoi;
    }
}

int main()
{
    freopen("dfs.inp","r",stdin);
    doc();
    for(int i=1;i<=dinh;i++)
    {
        if(!visited[i])
        {
            sotp+=1;
            dfs(i);
        }
    }
    in();
}