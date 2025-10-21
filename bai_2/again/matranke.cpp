#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

vector<vector<int>>adjMatrix;
vector<vector<int>>adjList;

int dinh;

struct edges
{
    int u,v;
    edges(int _u,int _v)
    {
        u=_u;
        v=_v;
    }
};

vector<edges>edgeList;

void doc()
{
    cin>>dinh;
    cin.ignore();
    adjMatrix.resize(dinh+1);
    for(int i=1;i<=dinh;i++)
    {
        adjMatrix[i].resize(dinh+1,0);
    }
    int v;
    for(int i=1;i<=dinh;i++)
    {
        for(int j=1;j<=dinh;j++)
        {
            cin>>v;
            if(v==1)
            {
                adjMatrix[i][j]=1;
                adjMatrix[j][i]=1;
            }
        }
    }
}

void chuyendoi()
{
    adjList.resize(dinh+1);
    for(int i=1;i<=dinh;i++)
    {
        for(int j=1;j<=dinh;j++)
        {
            if(adjMatrix[i][j]==1)
            {
                adjList[i].push_back(j);
                edgeList.push_back({i,j});
            }
        }
    }
}

void in()
{
    cout<<"ma tran ke:\n";
    for(int i=1;i<=dinh;i++)
    {
        for(int j=1;j<=dinh;j++)
        {
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"danh sach ke:\n";
    for(int i=1;i<=dinh;i++)
    {
        for(int j=0;j<adjList[i].size();j++)
        {
            cout<<adjList[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"danh sach canh:\n";
    for(int i=0;i<edgeList.size();i++)
    {
        cout<<"("<<edgeList[i].u<<","<<edgeList[i].v<<")\n";
    }
}


int main()
{
    freopen("input.inp","r",stdin);
    doc();
    chuyendoi();
    in();
}


