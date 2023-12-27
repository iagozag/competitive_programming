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

int main(){ _
    int n, prev_sum, sum = 0, pieces = 0; cin >> n;
    vector<int> diff;
    for(int i = 0; i < n; i++){
        int number; cin >> number;
        diff.pb(number);
    }

    for(int i = 0; i < n; i++)
        diff.pb(diff.at(i));

    for(int i = 0; i < n+i; i++){
        if(n+1 >= diff.size()) break;
    }

    (prev_sum > 0) ? cout << prev_sum << '\n' : cout << 0 << '\n';
    
    exit(0);
}
