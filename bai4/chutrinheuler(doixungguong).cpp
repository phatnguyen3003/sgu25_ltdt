#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<set>

using namespace std;

#define MAX 100

vector<int> cycles((MAX*(MAX-1)/2 + 1));
int n;
int deg[MAX];
vector<set<int>> adjList;
int dinh=0;


void doc()
{
    char line[10000];
    cin>>n;
    cin.ignore();
    int v;
    adjList.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin.getline(line,10000);
        stringstream stringline(line);
        while(stringline>>v)
        {
            adjList[i].insert(v);
        }
    }
}


void gofrom(int x)
{
    int start=x;
    dinh+=1;
    cycles[dinh]=x;
    while(true)
    {
        if(adjList[x].empty())
        {
            break;
        }
        int v=*adjList[x].begin();
        adjList[x].erase(v);
        adjList[v].erase(x);
        x=v;
        dinh++;
        cycles[dinh]=x;
        if(x==start)
        {
            break;
        }
    }
}

int FindVertex()
{
    for(int i=1;i<=dinh;i++)
    {
        if(!adjList[cycles[i]].empty())
        {
            return i;
        }
    }
    return 0;
}

void ReverseCycle(int k)
{
    
}