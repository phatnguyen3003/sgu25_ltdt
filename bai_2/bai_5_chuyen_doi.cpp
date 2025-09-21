#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> matran;
int sodinh, N;

struct edge {
    int u, v;
    edge(int _u, int _v) {
        u = _u;
        v = _v;
    }
};
vector<edge> danhsachcanh;

void in_file(int choice) {
    ofstream fileketqua("output/chuyendoi.out");
    fileketqua << sodinh << endl;

    switch(choice) {
        case 1: {
            vector<vector<int>> out(N);
            for(int i = 0; i < N; i++)
                for(int j = 0; j < N; j++)
                    if(matran[i][j] == 1)
                        out[i].push_back(j);

            for(int i = 0; i < N; i++) {
                for(int v : out[i]) fileketqua << v << " ";
                fileketqua << -1 << endl;
            }
            break;
        }
        case 2: {
            danhsachcanh.clear();
            for(int i = 0; i < N; i++)
                for(int j = 0; j < N; j++)
                    if(matran[i][j] == 1)
                        danhsachcanh.push_back(edge(i, j));

            for(auto &e : danhsachcanh)
                fileketqua << e.u << " " << e.v << endl;
            break;
        }
        case 3: {
            vector<vector<int>> out(N, vector<int>(N, 0));
            for(int i = 0; i < N; i++)
                for(int j : matran[i])
                    out[i][j-1] = 1;

            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++)
                    fileketqua << out[i][j] << " ";
                fileketqua << endl;
            }
            break;
        }
        case 4: {
            danhsachcanh.clear();
            for(int i = 0; i < N; i++)
                for(int j : matran[i])
                    danhsachcanh.push_back(edge(i, j));

            for(auto &e : danhsachcanh)
                fileketqua << e.u << " " << e.v << endl;
            break;
        }
        case 5: {
            vector<vector<int>> out(sodinh, vector<int>(sodinh, 0));
            for(auto &e : danhsachcanh)
                out[e.u][e.v] = 1;

            for(int i = 0; i < sodinh; i++) {
                for(int j = 0; j < sodinh; j++)
                    fileketqua << out[i][j] << " ";
                fileketqua << endl;
            }
            break;
        }
        case 6: {
            vector<vector<int>> out(sodinh);
            for(auto &e : danhsachcanh)
                out[e.u].push_back(e.v);

            for(int i = 0; i < sodinh; i++) {
                for(int v : out[i]) fileketqua << v << " ";
                fileketqua << -1 << endl;
            }
            break;
        }
    }
}

void docfile(int choice) {
    switch(choice) {
        case 1: case 2: {
            ifstream f("input/chuyendoi.inp");
            f >> N;
            sodinh = N;
            matran.resize(N, vector<int>(N, 0));
            for(int i = 0; i < N; i++)
                for(int j = 0; j < N; j++)
                    f >> matran[i][j];
            f.close();
            break;
        }
        case 3: case 4: {
            ifstream f("input/chuyendoi.inp");
            f >> N;
            sodinh = N;
            matran.resize(N);
            int x;
            for(int i = 0; i < N; i++)
                while(f >> x && x != -1)
                    matran[i].push_back(x);
            f.close();
            break;
        }
        case 5: case 6: {
            ifstream f("input/chuyendoi.inp");
            f >> sodinh >> N;
            danhsachcanh.clear();
            int a, b;
            for(int i = 0; i < N; i++) {
                f >> a >> b;
                danhsachcanh.push_back(edge(a, b));
            }
            f.close();
            break;
        }
    }
}

void chon() {
    int choice;
    cout << "Chon chuc nang:\n";
    cout << "1. ma tran ke sang danh sach ke\n";
    cout << "2. ma tran ke sang danh sach canh\n";
    cout << "3. danh sach ke sang ma tran ke\n";
    cout << "4. danh sach ke sang danh sach canh\n";
    cout << "5. danh sach canh sang ma tran ke\n";
    cout << "6. danh sach canh sang danh sach ke\n";
    cout << "Nhap lua chon: ";
    cin >> choice;

    if(choice >= 1 && choice <= 6) {
        docfile(choice);
        in_file(choice);
    } else {
        cout << "Lua chon khong hop le!" << endl;
    }
}

int main() {
    chon();
    return 0;
}
