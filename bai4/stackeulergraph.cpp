#include <iostream>
#include <vector>
#include <stack>
#include<sstream>
#include<algorithm>

using namespace std;

#define MAX 100

int n;
int matranke[MAX][MAX];

bool EulerCheck() {
    for(int i = 1; i <= n; i++){
        int deg = 0;
        for(int j = 1; j <= n; j++)
            deg += matranke[i][j];
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
        for(int i=1;i<=n;i++)
        {
            if(matranke[v][i]>0)
            {
                found=true;
                s.push(i);
                matranke[v][i]--;
                matranke[i][v]--;
                break;
            }
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
    cin>>n;
    cin.ignore(1000,'\n');
    int v;
    //cout<<"input:\n";
    string line;
    for(int i=1;i<=n;i++)
    {
        getline(cin,line);
        stringstream stringline(line);
        for(int j=1;j<=n;j++)
        {
            stringline>>v;
            matranke[i][j]=v;
            //cout<<matranke[i][j]<<" ";

        }
        //cout<<"\n";
    }
}


int main()
{
    freopen("chutrinheuler.inp","r",stdin);
    doc();
    solve();
}