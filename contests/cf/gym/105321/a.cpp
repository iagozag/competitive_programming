#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

map<pair<int,int>,int> pos;
map<int,pair<int,int>> pos2;
map<int,set<int>> ret;

int tab[4][4];

int check() {
    for(int i=1;i<=3;i++) {
        if(tab[i][1] == tab[i][2] and tab[i][2]==tab[i][3] and tab[i][1]) return tab[i][1];
        if(tab[1][i] == tab[2][i] and tab[2][i]==tab[3][i] and tab[1][i]) return tab[1][i];
    }

    if(tab[1][1] and tab[1][1]==tab[2][2] and tab[2][2]==tab[3][3]) return tab[1][1];
    if(tab[1][3] and tab[1][3]==tab[2][2] and tab[2][2]==tab[3][1]) return tab[3][1];
    return 0;
}
int bruteO();

int bruteX() {
    bool jj = false;
    bool emp=false;
    for(int i=1;i<=3;i++) {
        for(int j=1;j<=3;j++) {
            if(tab[i][j]==0) {
                bool inv=false;
                for(int x:ret[pos[{i,j}]]) {
                    auto p = pos2[x];
                    if(tab[p.ff][p.ss]==0) {
                        inv = true;
                        break;
                    }
                }
                if(inv) continue;
                jj = true;
                tab[i][j] = 1;
                int g = check();
                tab[i][j] = 0;
                if(g==1) return g;
                tab[i][j] = 1;
                int sla = bruteO();
                tab[i][j] = 0;
                if(sla==1) return 1;
                if(sla==0) emp = true;
            }
        }
    }
    if(jj==false) return check();
    if(emp) return 0;
    else return 2;
}

int bruteO() {
    bool jj = false;
    bool emp=false;
    for(int i=1;i<=3;i++) {
        for(int j=1;j<=3;j++) {
            if(tab[i][j]==0) {
                bool inv=false;
                for(int x:ret[pos[{i,j}]]) {
                    auto p = pos2[x];
                    if(tab[p.ff][p.ss]==0) {
                        inv = true;
                        break;
                    }
                }
                if(inv) continue;
                jj=true;
                tab[i][j] = 2;
                int g = check();
                tab[i][j] = 0;
                if(g==2) return g;
                tab[i][j] = 2;
                int sla = bruteX();
                tab[i][j] = 0;

                if(sla==2) return 2;
                if(sla==0) emp = true;
            }
        }
    }
    if(jj==false) return check();
    if(emp) return 0;
    else return 1;
}

int32_t main() { _
    for(int i=1;i<=3;i++) {
        for(int j=1;j<=3;j++) {
            pos.insert({{i,j},pos.size()+1});
            pos2.insert({pos.size(),{i,j}});
            tab[i][j] = 0;
        }
    }
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        int a,b;
        cin >> a >> b;
        ret[b].insert(a);
    }

    int r = bruteX();
    if(r==1) cout << "X\n";
    else if(r==2) cout << "O\n";
    else cout << "E\n";

}