#include<bits/stdc++.h>
#include <cctype>
#include <iterator>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string st; cin >> st;
    set<char> vowel = {'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y'};

    for(size_t i = 0; i < st.size(); i++){
        if(vowel.count(st[i])) st.erase(i, 1), i--;
        else if(st[i] >= 'A' && st[i] <= 'Z' && !vowel.count(st[i]+32)) st[i]+=32, i--;
        else if(st[i] >= 'a' && st[i] <= 'z' && !vowel.count(st[i])) st.insert(i, "."), i++;
    }

    cout << st << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
