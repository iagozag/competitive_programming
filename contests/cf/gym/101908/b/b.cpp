#include <bits/stdc++.h>

using namespace std;

#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e2+10;

int nim[MAX][MAX];
int n;

int main() { __
    for(int i = 0; i < MAX; i++) 
        for(int j = 0; j < MAX; j++) 
            nim[i][j] = -1;
    for(int i = 0; i < MAX; i++) nim[0][i] = nim[i][0] = nim[i][i] = 300; 
    for(int i = 1; i < MAX; i++) {
        for(int j = 1; j < MAX; j++) if(i != j){
            vector<bool> ss(3*MAX,false);
            for(int k = 1; k < MAX; k++) {
                if(i-k >= 0)
                    ss[nim[i-k][j]] = true;
                if(j-k >= 0)
                    ss[nim[i][j-k]] = true;
                if(i-k >= 0 and j-k >= 0)
                    ss[nim[i-k][j-k]] = true;
            }
            for(int k = 0; k < 3*MAX; k++) if(not ss[k]){
                nim[i][j] = k;
                break;
            }
        }
    }
    cin >> n;
    int ans = 0; bool can = false;
    for(int i = 0; i < n; i++) {
        int l,c;
        cin >> l >> c;
        if(nim[l][c] == 300) can = true;
        ans ^= nim[l][c];
    }
    
    cout << ((ans == 0 and !can) ? 'N' : 'Y') << endl;
	exit(0);
}

