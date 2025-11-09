#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;


struct edges{
    int u,v,w;
    edges(int _u,int _v,int _w)
    {
        u=_u;
        v=_v;
        w=_w;
    }
};



int sodinh,socanh;
vector<edges>dscanh;
vector<edges>caykhung;
vector<vector<int>>adjList;
vector<bool>visited;

void doc()
{
    cin>>sodinh>>socanh;
    adjList.resize(sodinh+1);
    for(int i=0;i<socanh;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dscanh.push_back(edges(u,v,w));
        //adjList[u].push_back(v);
        //adjList[v].push_back(u);
    }
    visited.resize(sodinh+1,false);
}

void xep_ds()
{
    for(int i=0;i<dscanh.size();i++)
    {
        for(int j=i+1;j<dscanh.size();j++)
        {
            if(dscanh[i].w>dscanh[j].w)
            {
                edges temp(dscanh[i]);
                dscanh[i]=dscanh[j];
                dscanh[j]=temp;
            }
        }
    }
}


/*

dinhxet: dinh u cua canh truyen vao
muctieu: dinh v cua canh truyen vao

bool dfs : kiem tra xem co duong di tu dinhxet(u) den muctieu(v)
neu co duong di thi tra ve true => loai bo trong ham check

*/


bool dfs(int dinhxet,int muctieu)
{
    if(dinhxet==muctieu)
    {
        return true;
    }
    visited[dinhxet]=true;
    for(int i=0;i<adjList[dinhxet].size();i++)
    {
        if(!visited[adjList[dinhxet][i]])
        {
            if(dfs(adjList[dinhxet][i],muctieu))
            {
                return true;
            }
        }
    }
    return false;
}

bool check(int dinhxet,int muctieu)
{
    visited.assign(sodinh+1,false);
    if(dfs(dinhxet,muctieu))
    {
        return true;
    }
    else
    {
        return false;
    }
}



void duyet_kruskal()
{
    xep_ds();
    for(int i=0;i<dscanh.size();i++)
    {
        edges canhxet = dscanh[i];
        if(!check(canhxet.u,canhxet.v))
        {
            caykhung.push_back({canhxet.u,canhxet.v,canhxet.w});
            adjList[canhxet.u].push_back(canhxet.v);
            adjList[canhxet.v].push_back(canhxet.u);
        }
    }
}




void in()
{
    int tong=0;
    for(int i=0;i<caykhung.size();i++)
    {
        tong+=caykhung[i].w;
    }
    cout<<caykhung.size()<<" "<<tong<<"\n";
    for(int i=0;i<caykhung.size();i++)
    {
        cout<<caykhung[i].u<<" "<<caykhung[i].v<<" "<<caykhung[i].w<<"\n";
    }
}




int main()
{
    freopen("input/kruskal.inp","r",stdin);
    doc();
    duyet_kruskal();
    in();
}