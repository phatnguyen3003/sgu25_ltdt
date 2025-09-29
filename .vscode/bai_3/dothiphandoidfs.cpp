#include<iostream>
#include<vector>
#include<fstream>
#include<set>
#include<vector>
#include<sstream>
#include<string>

#define FI "DOTHIPHANDOI.INP"
#define FO "DOTHIPHANDOI.OUT"

using namespace std;

int n,x,y;
vector<int> color;
vector<set<int>> adjList;

stringstream stringline;

bool dfs(int x,int status)
{
    color[x]=status;
    for(set<int>::iterator it=adjList[x].begin();it != adjList[x].end();it++)
        {
            int v=*it;
            if(color[v]==-1)
            {
                if(dfs(v,1-status)==false)
                {
                    return false;
                }
                else if(color[v]==status)
                {
                    return false;
                }
            }
        }
        return true;
}



void doc()
{
    char line[10000];
    cin>>n;
    cin.ignore();
    //cout<<n<<" "<<x;
    int v;
    adjList.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin.getline(line,10000);
        stringstream stringline(line);
        while(stringline>>v)
        {
            adjList[i].insert(v);
            //cout<<v<<" ";
        }
        //cout<<endl;
    }
    color.resize(n+1,-1);
    //open.resize(n+1);
}

void solve()
{
    bool objective=true;
    for(int i=1;i<=n;i++)
    {
        if(color[i]==-1)
        {
            if(dfs(i,0)==false)
            {
                objective=false;
                break;
            }
        }
    }
    if(!objective)
    {
        cout<<"do thi khong phan doi";
    }
    else
    {
        cout<<"do thi phan doi";
    }
}


int main()
{
    freopen(FI,"r",stdin);
    doc();
    solve();
    return 0;
}