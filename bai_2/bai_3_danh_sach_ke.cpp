#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

vector<vector<int>> matran;
int N;


void doc_file()
{
    ifstream filedauvao("input/danhsachke.inp");
    filedauvao >> N;
    matran.resize(N);
    int temp;
    for(int i=0;i<N;i++)
    {
        while(filedauvao>>temp&&temp!=-1)
        {
            matran[i].push_back(temp);
        }
    }
    filedauvao.close();
}

void in_ket_qua()
{
    ofstream fileketqua("output/danhsachke.out");
    fileketqua<<N<<endl;
    vector<vector<int>> out;
    out.resize(N,vector<int>(1,0));

    for(int i=0;i<N;i++)
    {
        out[i][0]=matran[i].size();
    }
    for(int i=0;i<N;i++)
    {
        fileketqua<<out[i][0]<<endl;
    }
}

int main()
{
    doc_file();
    in_ket_qua();
    return 0;
}
