#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

vector<vector<int>> matran;
int N;


void doc_file()
{
    ifstream filedauvao("input/bacrabacvao.inp");
    filedauvao >> N;
    matran.resize(N,vector<int>(N));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            filedauvao>>matran[i][j];
        }
    }
    filedauvao.close();
}

void in_ket_qua()
{
    ofstream fileketqua("output/bacrabacvao.out");
    fileketqua<<N<<endl;
    vector<vector<int>> io;
    io.resize(N,vector<int>(2,0));

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(matran[i][j]==1)
            {
                io[i][0]+=1;
                io[j][1]+=1;
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<2;j++)
        {
            fileketqua<<io[i][j]<<" ";
        }
        fileketqua<<endl;
    }
}

int main()
{
    doc_file();
    in_ket_qua();
    return 0;
}
