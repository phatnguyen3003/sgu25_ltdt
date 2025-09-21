#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

vector<vector<int>> matran;
int N,sodinh;


void doc_file()
{
    ifstream filedauvao("input/matranke.inp");
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
    ofstream fileketqua("output/matranke.out");
    fileketqua<<N<<endl;
    vector<int> ke(N,0);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(matran[i][j]==1)
            {
                ke[i]+=1;
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        fileketqua<<ke[i]<<endl;
    }
}

int main()
{
    doc_file();
    in_ket_qua();
    return 0;
}
