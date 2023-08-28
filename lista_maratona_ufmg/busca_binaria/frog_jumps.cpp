#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

string str;

bool is_possible(int c){
    int move = c;
    while(move <= str.size()){
        int k = 0;
        while(move > 0 && str[move-1] == 'L'){
            k++;
            if(k >= c) return false;
            move--;
        }

        move += c;
    }

    return true;
}

void solve(){
    cin >> str;

    int l = 1, r = (2*1e5)+1;
    while(l < r){
        int m = (l+r)/2;

        if(!is_possible(m)) l = m+1;
        else r = m;
    }

    cout << l << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
