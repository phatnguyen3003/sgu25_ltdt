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

void doc()
{
    cin>>sodinh>>socanh;
    for(int i=0;i<socanh;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dscanh.push_back(edges(u,v,w));
    }
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

bool tim_trongkhung(edges input)
{
    if(find(caykhung.begin(),caykhung.end(),input)!=caykhung.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

void duyet_kruskal()
{
    xep_ds();

}