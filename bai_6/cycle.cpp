#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cmath>

using namespace std;
/*
chuong trinh se duyet qua tat ca hinh tron bang thuat toan dijkstra
sau do xet xem co duong di tu hinh tron dau tien den hinh tron cuoi cung khong
neu co thi in ra duong di va so buoc nhau, dong thoi them loai buoc nhay voi moi duong tron di qua no (-1,0,1) voi -1 la khong the di qua hoac la dinh bat dau,
0 la buoc qua binh thuong, 1 la buoc nhay

ham doc()
{
    doc tu input cac hinh tron va luu vao dshtron(danh sach cac hinh tron)
    sau do khoi tao danh sach ke adjList va ma tran buoc nhay step_jump de luu dinh dang di chuyen giua cac hinh tron trong do moi [i] la so cua hinh tron
    xet tung hinh tron i va j cho tat ca hinh tron de tinh khoang cach, xet dieu kien de danh dau vao step_jump qua bien khoang_cach
}

ham duyet() thuc chat la dijkstra
{
    trong do khoi tao cac mang visited,parent,dist
    dat hinh tron dau tien co khoang cach la 0
    sau do duyet dijkstra nhu binh thuong voi tat ca cac dinh ke cua hinh tron hien tai
    chi chinh sua dieu kien cap nhat so voi dijkstra binh thuong de uu tien khoang cach sau do moi den xet buoc nhay de co the cap nhat dist va parent}


*/
#define INF 1000000000
int sohtron,dau,cuoi;

struct cycle
{
    int x,y,r;
    cycle(int _x,int _y,int _r)
    {
        x=_x;
        y=_y;
        r=_r;
    }
};

vector<cycle> dshtron;
vector<vector<int>> adjList;
vector<vector<int>> step_jump;
vector<bool> visited;
vector<pair<int,int>> parent; // first la dinh truoc do cua dinh dang xet, second la loai buoc nhay tu dinh truoc den no
vector<pair<int,int>> dist; // first la so buoc nhay/buoc cua dinh dau den dinh do, second la tong so buoc di chuyen den dinh do

void doc()
{
    cin>>sohtron>>dau>>cuoi;
    for(int i=0;i<sohtron;i++)
    {
        int x,y,r;
        cin>>x>>y>>r;
        dshtron.push_back(cycle(x,y,r));
    }

    adjList.resize(sohtron+1);
    step_jump.resize(sohtron+1);
    for(int i=0;i<=sohtron;i++)
    {
        step_jump[i].resize(sohtron+1,-1);
    }

    for(int i=1;i<=sohtron;i++)
    {
        for(int j=1;j<=sohtron;j++)
        {
            if(i!=j)
            {
                int x1=dshtron[i-1].x;
                int y1=dshtron[i-1].y;
                int r1=dshtron[i-1].r;
                int x2=dshtron[j-1].x;
                int y2=dshtron[j-1].y;
                int r2=dshtron[j-1].r;

                int khoang_cach=sqrt((pow(x2-x1,2) + pow(y2-y1,2))) - (r1 + r2);
                // tinh khoang cach giua 2 hinh tron bang cong thuc khoang cach giua 2 diem trong khong gian, tru di ban binh cac hinh vi dang tim diem gan nhat
                if(khoang_cach<0) khoang_cach=0;//sau khi tru 2 ban kinh neu khoang cach am(tuc 2 hinh tron giao nhau) thi khoang cach la 0

                else if(khoang_cach<=60)
                {
                    adjList[i].push_back(j);
                    step_jump[i][j]=(khoang_cach<=50?0:1);
                }
                else
                {
                    step_jump[i][j]=-1;
                }
            }
        }
    }
}


void duyet()
{
    visited.resize(sohtron+1,false);
    parent.resize(sohtron+1,{-1,-1});
    dist.resize(sohtron+1,{INF,0});
    dist[dau].first=0;
    
    for(int i=1;i<=sohtron;i++)
    {
        int u=-1;
        int min_dist=INF;
        for(int j=1;j<=sohtron;j++)
        //tim dinh chua tham va co khoang cach nho nhat nhu dijkstra thong thuong
        {
            if(!visited[j] && dist[j].first<min_dist)
            {
                min_dist=dist[j].first;
                u=j;
            }
        }
        if(u==-1)
        {
            break;
        }
        visited[u]=true;
        for(int g=0;g<adjList[u].size();g++)
        {
            int v = adjList[u][g];
            int step = step_jump[u][v];

            if(step==-1) // kiem tra lan 2 neu khong di duoc tu u den v ( step = -1 tuc la khong ton tai duong di den v) thi bo qua
            continue;
            if(dist[v].first > dist[u].first + step || (dist[v].first == dist[u].first + step && dist[v].second > dist[u].second + 1)) 
            // so sanh theo 2 tieu chi: dau tien so khoang cach nhu dijkstra thuong de uu tien, neu duong di bang nhau thi so theo tieu chi cua de bai
            // so sanh so buoc di chuyen de uu tien tuyen duong co it so buoc hon
            {
                dist[v].first = dist[u].first+step;
                dist[v].second = dist[u].second + 1;
                parent[v].first = u; // cap nhat dinh truoc do cua v la u
                parent[v].second = step;// cap nhat loai buoc di chuyen tu u den v
            }
        }
    }

}

void solve()
{
    doc();
    duyet();
    vector<int>path;
    if(dist[cuoi].first!=INF) //neu ton tai duong di den cuoi
    {
        cout<<"1\n";
        for(int u=cuoi;u!=-1;u=parent[u].first) //bat dau truy nguoc theo parent vi trong do luu duong di ngan nhat tu dinh truoc den v
        {
            path.push_back(u);
        }
        reverse(path.begin(),path.end()); // dao duong de co duoc duong di tu dau den cuoi
        //cout<<dist[cuoi].first<<" "<<dist[cuoi].second+1<<"\n";
        for(int i=0;i<path.size();i++)
        {
            cout<<path[i]<<" "<<parent[path[i]].second<<"\n"; // in ra dinh di qua va loai buoc dinh theo yeu cau
        }
    }
}

int main()
{
    freopen("input/cycle.inp","r",stdin);
    solve();
    return 0;
}