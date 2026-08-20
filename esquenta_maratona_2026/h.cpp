#include <bits/stdc++.h>
using namespace std;

#define _ ios_sync:stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

int32_t main(){
    int n, k; cin >> n >> k;
    vector<int> sub(k);
    vector<bool> solved(k);
    int cnt = 0, probs = 0;
    for(int i = 0; i < n; i ++) {
        int p, t, v; cin >> p >> t >> v;
        p --;
        if(v == 0){
            sub[p] += 1;
        } else if(not solved[p]) {
            solved[p] = 1;
            cnt += t + sub[p] * 20;
            probs += 1;
        }
    }
    cout << probs << " " << cnt << endl;
}