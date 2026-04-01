#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long

struct gauss{
    bitset<60> basis[60], keep[60];
    int rk, in;
    vector<int> id;

    gauss(): rk(0), in(-1), id(60,-1) {}

    bool add(bitset<60> v){
        in++;
        bitset<60> k;
        for(int i = 59; i>=0; i--) if(v[i]){
            if(basis[i][i]) v ^= basis[i], k ^= keep[i];
            else {
                k[i] = true;
                id[i]=in, keep[i]=k;
                basis[i] = v, rk++;
                return true;
            }
        }
        return false;
    }

};


int32_t main(){ _
    int n, k; 
    while(cin >> n >> k){
        gauss g;
        int cnt = 0; bool ok = false;
        for(int i = 0; i < n; i ++){
            bitset<60> b;
            for(int j = 0; j < k; j++){
                int val; cin >> val;
                val = val & 1;
                b[j] = val;
            }
            if(g.add(b)) cnt++;
            else ok = true;
        }

        if(cnt == k and ok) cout << "N\n";
        else cout << "S\n";
    }

    exit(0);
}