#include <iostream>
#include <vector>
#include <stack>
#include<sstream>
#include<algorithm>
#include<set>

using namespace std;

#define MAX 100

int n;
vector<set<int>> adjList;

bool EulerCheck() {
    for(int i = 1; i <= n; i++){
        int deg = 0;
        deg = adjList[i].size();
        if(deg % 2 != 0) return false;
    }
    return true;
}


void FindEulerGraph(int start)
{
    stack<int>s;
    vector<int>cycles;

    s.push(start);

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
            cycles.push_back(v);
            s.pop();
        }
    }
    reverse(cycles.begin(), cycles.end());
    for(int i=0;i<cycles.size();i++)
    {
        cout<<cycles[i]<<" ";
    }
}

void solve()
{
    if(EulerCheck())
    {
        cout<<"1\n";
        FindEulerGraph(1);
    }
    else
    {
        cout<<"0";
    }
}

void doc()
{
    char line[10000];
    cin>>n;
    cin.ignore();
    adjList.resize(n+1);
    int v;
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


int main()
{
    freopen("chutrinheulerdske.inp","r",stdin);
    doc();
    solve();
}