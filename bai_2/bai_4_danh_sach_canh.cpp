#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int N,sodinh;

struct edge {
    int u, v;
    edge(int _u,int _v){
        u = _u;
        v = _v;
    }
};
vector<edge> matran;


void doc_file()
{
    ifstream filedauvao("input/danhsachcanh.inp");
    filedauvao >> sodinh >> N;
    int a,b;
    for(int i=0;i<N;i++)
    {
        filedauvao >> a >> b;
        matran.push_back(edge(a,b));
    }
    filedauvao.close();
}

void in_ket_qua()
{
    ofstream fileketqua("output/danhsachcanh.out");
    fileketqua<<sodinh<<endl;
    vector<int> socanh(sodinh+1,0);
    int a,b;
    for(int i=0;i<N;i++)
    {
        a=matran[i].u;
        b=matran[i].v;
        if(a==b)
        {
            socanh[a]+=1;
        }
        else{
            socanh[a]+=1;
            socanh[b]+=1;
        }
    }
    for(int i=1;i<=sodinh;i++)
    {
        fileketqua<<socanh[i]<<endl;
    }
    fileketqua.close();
}

int main()
{
    doc_file();
    in_ket_qua();
    return 0;
}