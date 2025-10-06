#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<set>

using namespace std;

#define MAX 100

vector<int> cycles((MAX*(MAX-1)/2 + 1));
int n;
int matranke[MAX][MAX];
int DEG[MAX];
int sodinhcycles=0;


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

bool EulerCheck()
{
    int deg;
    for(int i=1;i<=n;i++)
    {
        deg=0;
        for(int j=1;j<=n;j++)
        {
            if(matranke[i][j]==1)
            {
                deg+=1;
            }
        }
        if(deg%2!=0)
        {
            return false;
        }
        DEG[i]=deg;
    }
    return true;
}

int FindVertex()
{
    for(int i=1;i<=sodinhcycles;i++)
    {
        int u=cycles[i];
        for(int j=1;j<=n;j++)
        {
            if(matranke[u][j]==1)
            {
               // cout<<"dinh chua di la: "<<i;
                return i;
            }
        }
    }
    return 0;
}

void reversing(int k1,int k2)
{
    int temp;
    while(k1<=k2)
    {
        temp=cycles[k1];
        cycles[k1]=cycles[k2];
        cycles[k2]=temp;
        k1++;
        k2--;
    }
}

int gofrom(int x)

{
    int start=x;
    sodinhcycles+=1;
    cycles[sodinhcycles]=x;
    while(true)
    {
        int pos=0;
        bool found=false;
        for(int i=1;i<=n;i++)
        {
            if(matranke[x][i]>0)
            {
                found=true;
                pos=i;
                break;
            }
        }
        if(!found)
        {
            break;
        }
        matranke[x][pos]--;
        matranke[pos][x]--;
        x=pos;
        sodinhcycles+=1;
        cycles[sodinhcycles]=x;
        if(x==start)
        {
            break;
        }
    }
    //cout<<"\n cycles la: ";
    //for(int i=start;i<sodinhcycles;i++)
    //{
        //cout<<cycles[i]<<" ";
    //}
    //cout<<"\n";
    return sodinhcycles;
}

void reversecycles(int k)
{
    int sodinhdau = k;
    int sodinhgiua = sodinhcycles;
    int sodinhsau = gofrom(cycles[k]);

    //cout << "truoc khi dao: ";
    //for(int i = 1; i <= sodinhcycles; i++) cout << cycles[i] << " ";
    //cout << "\n";

    // Dao ba lần
    reversing(sodinhdau + 1, sodinhgiua);
    //cout << "dao lan 1: ";
    //for(int i = 1; i <= sodinhcycles; i++) cout << cycles[i] << " ";
    //cout << "\n";

    reversing(sodinhgiua + 1, sodinhsau);
    //cout << "dao lan 2: ";
    //for(int i = 1; i <= sodinhcycles; i++) cout << cycles[i] << " ";
    //cout << "\n";

    reversing(sodinhdau + 1, sodinhsau);
    //cout << "dao lan 3: ";
    //for(int i = 1; i <= sodinhcycles; i++) cout << cycles[i] << " ";
    //cout << "\n";
}



void FindEulerCycles()
{
    if(EulerCheck())
    {
        gofrom(1);
        while(true)
        {
            int k=FindVertex();
            if(k==0)
            {
                break;
            }
            reversecycles(k);
        }

        //cout<<"\nchu trinh euler la: ";
        cout<<"1\n";
        for(int i=1;i<=sodinhcycles;i++)
        {
            cout<<cycles[i]<<" ";
        }
    }
}


int main()
{
    freopen("chutrinheuler.inp","r",stdin);
    doc();
    FindEulerCycles();
}