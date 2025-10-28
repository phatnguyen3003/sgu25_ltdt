#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<stack>
#include<set>
#include<sstream>


using namespace std;

int dinh,dau;
vector<set<int>>adjList;
stack<int>s;
vector<int>cycle;

bool eulercheck()
{
    for(int i=1;i<=dinh;i++)
    {
        int deg=adjList[i].size();
        if(deg%2!=0)
        {
            return false;
        }
    }
    return true;
}


void doc()
{
    cin>>dinh>>dau;
    cin.ignore();
    adjList.resize(dinh+1);
    int v;
    char line[10000];
    for(int i=1;i<=dinh;i++)
    {
        cin.getline(line,10000);
        stringstream ss(line);
        while(ss>>v)
        {
            adjList[i].insert(v);
            adjList[v].insert(i);
        }
    }
}

void euler()
{
    s.push(dau);
    while(!s.empty())
    {
        int v=s.top();
        bool found=false;
        if(adjList[v].size()>0)
        {
            found=true;
            int first=*adjList[v].begin();
            s.push(first);
            adjList[v].erase(first);
            adjList[first].erase(v);
        }
        if(!found)
        {
            cycle.push_back(v);
            s.pop();
        }
    }
}


void in()
{
    if(eulercheck())
    {
        reverse(cycle.begin(),cycle.end());
        for(int i=0;i<cycle.size();i++)
        {
            cout<<cycle[i]<<" ";
        }
    }
    else
    {
        cout<<"khong co do thi euler";
    }
}

int main()
{
    freopen("input_euler.inp","r",stdin);
    doc();
    euler();
    in();
}