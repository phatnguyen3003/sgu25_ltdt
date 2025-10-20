#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<queue>

using namespace std;


int dinh;

vector<vector<int>> adjList;
vector<int>visited;
queue<int>q;
vector<vector<int>>tplienthong;
int sotp=0;


void doc()
{
    cin>>dinh;
    cin.ignore();
    char line[10000];
    int v;

    adjList.resize(dinh+1);
    tplienthong.resize(dinh+1);
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
}



void bfs(int dau)
{
    visited[dau]=true;
    q.push(dau);
    tplienthong[sotp].push_back(dau);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<adjList[u].size();i++)
        {
            int v=adjList[u][i];
            if(!visited[v])
            {
                q.push(v);
                visited[v]=true;
                tplienthong[sotp].push_back(v);
            }
        }
    }
}


int main()
{
    sotp=0;
    freopen("bfs.inp","r",stdin);
    doc();
    for(int i=1;i<=dinh;i++)
    {
        if(!visited[i])
        {
            sotp+=1;
            bfs(i);
        }

    }
    for(int i=1;i<=sotp;i++)
    {
        cout<<"thanh phan thu "<<i<<" :\n";
        for(int j=0;j<tplienthong[i].size();j++)
        {
            cout<<tplienthong[i][j]<<" ";
        }
        cout<<"\n";
    }
}