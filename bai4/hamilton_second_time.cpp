#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<stack>

using namespace std;

int dinh,canh;
vector<vector<int>>adjList;
vector<int>visited;
vector<int>path;


bool hamiltoncheck()
{
    for(int i=1;i<=dinh;i++)
    {
        int deg=adjList[i].size();
        if(deg<dinh/2)
        {
            return false;
        }
    }
    return true;
}

void doc()
{
    cin>>dinh>>canh;
    cin.ignore();
    adjList.resize(dinh+1);
    int u,v;
    for(int i=1;i<=canh;i++)
    {
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    } 
    visited.resize(dinh+1,false);
}

void hamilton(int dau,int start)
{
    path.push_back(dau);
    visited[dau]=true;
    if(path.size()==dinh)
    {
        for(int i=0;i<path.size();i++)
        {
            cout<<path[i]<<" ";
        }
        cout<<start<<"\n";
    }
    else
    {
        for(int i=0;i<adjList[dau].size();i++)
        {
            int v=adjList[dau][i];
            if(!visited[v])
            {
                hamilton(v,start);
            }
        }
    }
    visited[dau]=false;
    path.pop_back();
}

int main()
{
    freopen("hamilton.inp","r",stdin);
    doc();
    if(!hamiltoncheck())
    {
        cout<<"do thi co the khong co chu trinh hamilton\n";
    }
    for(int i=1;i<=dinh;i++)
    {
        hamilton(i,i);
    }
}