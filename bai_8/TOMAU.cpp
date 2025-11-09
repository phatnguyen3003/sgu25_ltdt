#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

int n,m;
vector<vector<int>>adjList;
vector<int>Deg;
vector<int>color;
vector<bool>used;

void doc()
{
    cin>>n>>m;
    adjList.resize(n+1);
    color.resize(n+1,0);
    used.resize(n+1,false);
    Deg.resize(n+1,0);

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        Deg[i]=adjList[i].size();       // thêm bậc của từng đỉnh vào Deg 
    }
}

int timmaxdeg()
{
    int u=-1;               
    int dinhtrave;
    for(int i=1;i<Deg.size();i++)   // duyệt từng đỉnh trong đồ thị , xét từng bậc của các đỉnh với nhau tìm đỉnh có bậc cao nhất
    {
        if(u<Deg[i] && color[i]==0) // xét tìm đỉnh có bậc cao hơn nhất đang xét thêm điều kiện màu đỉnh đó chưa được tô
        {
            u=Deg[i];
            dinhtrave=i;
        }
    }
    return dinhtrave;   // trả về kết quả là đỉnh có bậc cao nhất
}

int chonmau(int dinhxet)
{
    used.assign(n+1,false);                     // gán lại mảng chứa màu đã dùng
    for(int i=0;i<adjList[dinhxet].size();i++)      // dòng 53 đến 60 => duyệt từng đỉnh kề với dinhxet đánh dấu màu đã được dùng ở các đỉnh đó vào used
    {
        int u = adjList[dinhxet][i];
        if(color[u]!=0)
        {
            used[color[u]]=true;
        }
    }
    for(int i=1;i<=n;i++)                            // dòng 61 đến 68 => duyệt từng màu trong mảng chứa màu, gặp màu đầu tiên chưa dùng (tức màu nhỏ nhất chưa dùng) thì trả về màu đó
    {
        if(!used[i])
        {
            return i;
        }
    }
    return -1;
}

bool checktomau()
{
    for(int i=1;i<=n;i++)
    {
        if(!color[i])           // kiểm tra đỉnh đó được tô màu chưa
        {
            return false;   // trả về chưa nếu phát hiện chưa tổ
        }
    }
    return true;    // nếu các đỉnh đã được tô hết thì trả về true
}


void duyet()
{
    while(!checktomau())
    {
        int u = timmaxdeg();
        color[u]=chonmau(u);
        if(color[u]==-1)
        {
            break;
        }
        for(int i=0;i<adjList[u].size();i++)
        {
            if(Deg[adjList[u][i]]>0)        // nếu bậc của các đỉnh kề u lớn hơn 0 
            {
                Deg[adjList[u][i]]-=1;      // giảm bậc đó đi 1
            }
        }
    }
}

void in()
{
    int maucaonhat = 0;
    for(int i=1;i<=n;i++)
    {
        if(maucaonhat<color[i])
        {
            maucaonhat=color[i];
        }
    }
    cout<<maucaonhat<<"\n";
    for(int i=1;i<=maucaonhat;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(color[j]==i)
            {
                cout<<j<<" ";
            }
        }
        cout<<"\n";
    }
}

int main()
{
    freopen("input/coloring.inp","r",stdin);
    doc();
    duyet();
    in();
}



