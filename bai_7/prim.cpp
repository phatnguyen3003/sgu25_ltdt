#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;


int sodinh,socanh,tongquangduong=0;

vector<vector<int>>adjList;
vector<vector<int>>adjMatrix;
vector<tuple<int,int,int>>caykhung;
vector<tuple<int,int,int>>list;
vector<bool>visited;
stack<int>s;

/*

sodinh: so dinh trong do thi
socanh: so canh cua do thi
tongquangduong: luu tong quang duong se duoc tinh khi duyet;

adjList: chua cac ke cua do thi
adjMatrix: chua trong so cua do thi
caykhung: chua cay khung nho nhat (ket qua cua chuong trinh)
visited: danh dau dinh da co trong cay chua
list: chua cac canh trong hang doi
s: stack chua danh sach cac dinh



*/

void doc()
{
    cin>>sodinh>>socanh;
    // khoi tao
    adjList.resize(sodinh+1);
    adjMatrix.resize(sodinh+1);
    for(int i=1;i<=sodinh;i++)
    {
        adjMatrix[i].resize(sodinh+1);
    }
    visited.resize(sodinh+1,false);

    //input
    for(int i=0;i<socanh;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
    }
}

//ham xep cac canh co trong hang doi
void sorting()
{
    sort(list.begin(), list.end(), [](auto &a, auto &b){ return get<2>(a) < get<2>(b); });
}

//ham them canh vao hang doi
void adding_to_queue(int dinhxet)
{
    for(int i=1;i<=sodinh;i++)
    {
        if(adjMatrix[dinhxet][i]!=0)
        {
            list.push_back({dinhxet,i,adjMatrix[dinhxet][i]});
        }
    }
}


void duyet_prim(int dau)
{

    //khoi tao bien dau tien trong stack va them cac canh ke co trong so vao list, danh dau dinh da xet
    s.push(dau);
    adding_to_queue(dau);
    visited[dau]=true;

    //duyet den khi list rong ==> da duyet het canh co the cua do thi tu dinh bat dau
    while(!list.empty())
    {
        // lay dinh dau tien trong list de duyet
        int dinhdangxet = s.top();
        //neu dinh chua xet thi them cac canh ke vao list va danh dau da xet
        if(!visited[dinhdangxet])
        {
            adding_to_queue(dinhdangxet);
            visited[dinhdangxet]=true;
        }
        //xap xep list de lay canh dau tien la canh co trong so nho nhat
        sorting();
        // lay canh dau tien
        tuple<int,int,int> first;
        if(!list.empty())
        {
            first = list[0];
        }
        // kiem tra trong canh neu ca 2 dinh u va v cua canh da co trong cay chua
        if(!(visited[get<0>(first)] && visited[get<1>(first)]))
        {
            // neu chua co thi cho canh (u,v) vao mang caykhung ===> ket qua, dong thoi them dinh chua duoc tham trong canh vao stack
            caykhung.push_back({get<0>(first),get<1>(first),get<2>(first)});
            if(!visited[get<0>(first)])
            {
                s.push(get<0>(first));
            }
            else
            {
                s.push(get<1>(first));
            }
            // cong tong quang duong trong cay
            tongquangduong+=get<2>(first);
        }
        else
        {
            // neu khong thoa => 2 dinh trong canh da xet roi thi xoa canh khoi list
            list.erase(list.begin());
        }
    }


}

void in()
{
    cout<<caykhung.size()<<" "<<tongquangduong<<"\n";
    for(int i=0;i<caykhung.size();i++)
    {
        tuple<int,int,int>canhxet =caykhung[i];
        cout<<get<0>(canhxet)<<" "<<get<1>(canhxet)<<" "<<get<2>(canhxet)<<"\n";
    }
}

int main()
{
    freopen("input/prim.inp","r",stdin);
    doc();
    duyet_prim(1);
    in();
}