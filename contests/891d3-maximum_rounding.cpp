#include<bits/stdc++.h>
#include <exception>
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

void solve(){
    string n; cin >> n;
    n = "0" + n;
    int N = int(n.size());
    int index = N;
    for(int i = N-1; i >= 0; i--)
        if(n[i] >= '5'){
            n[i] = '0';
            index = i;

            int j = i-1;
            while(n[j] == '9'){
                n[j] = '0';
                j--;
            }

            n[j]++;
        }

    for(int i = index; i < N; i++)
        n[i] = '0';

    if(n.front() == '0')
        n = n.substr(1);

    cout << n << endl; 
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
