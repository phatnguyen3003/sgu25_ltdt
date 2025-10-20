#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

vector<vector<int>> adjList;
vector<bool>visited;
vector<int>path;
stack<int>s;
int dinh,canh;

void doc()
{
    cin>>dinh>>canh;
    adjList.resize(dinh+1);
    visited.resize(dinh+1,false);
    for(int i=0;i<canh;i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}


void hamilton_ko_dequy(int x)
{
    while(!s.empty())
    {
        s.pop();
    }
    visited.assign(dinh+1,false);
    path.clear();
    path.push_back(x);
    s.push(x);
    visited[x]=true;
    stack<int>pos;
    pos.push(0);
    while(!s.empty())
    {
        int u=s.top();
        int position=pos.top();
        bool found=false;
        if(path.size()==dinh && find(adjList[u].begin(),adjList[u].end(),x)!=adjList[u].end())
        {
            for(int i=0;i<path.size();i++)
            {
                cout<<path[i]<<" ";
            }
            cout<<x<<"\n";
        }
        for(int i=position;i<adjList[u].size();i++)
        {
            int v=adjList[u][i];
            if(!visited[v])
            {
                pos.top()=i+1;
                s.push(v);
                pos.push(0);
                visited[v]=true;
                path.push_back(v);
                found=true;
                break;
            }
        }
        if(found==false)
        {
            s.pop();
            visited[u]=false;
            if(!path.empty())
            {
                path.pop_back();
            }
            pos.pop();
        }
    }
}

void hamilton(int x,int start)
{
    path.push_back(x);
    visited[x]=true;
    if(path.size()==dinh)
    {
        if(find(adjList[x].begin(),adjList[x].end(),start) != adjList[x].end())
        {
            for(int i=0;i<path.size();i++)
            {
                cout<<path[i]<<" ";
            }
            cout<<start<<"\n";
        }
    }
    else
    {
        for(int i=0;i<adjList[x].size();i++)
        {
            int v=adjList[x][i];
            if(!visited[v])
            {
                hamilton(v,start);
            }
        }
    }
    visited[x]=false;
    path.pop_back();
}

int main()
{
    freopen("hamilton.inp","r",stdin);
    doc();
    for(int i=1;i<=dinh;i++)
    {
        //hamilton(i,i);
        hamilton_ko_dequy(i);
    }
}