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
    double n; cin >> n;

    double l = 0, r = 1e8+10;
    for(int i = 0; i < 300; i++){
        double mid = (l+r)/2;

        if(mid*mid > n) r = mid;
        else l = mid;
    }

    cout << (l+r)/2 << endl;

    exit(0);
}
