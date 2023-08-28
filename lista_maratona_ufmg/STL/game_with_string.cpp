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
    string s; cin >> s;
    map<char,int> mp;
    for(auto c: s) mp.insert({c,1});

    int k = 0;
    for(unsigned i = 0; i < s.size()-1; i++){
        if(s[i] == s[i+1]){
            s.erase(s.begin()+i, s.begin()+i+2);
            k++;
            (i == 0) ? i-- : i -= 2;

            if(s.empty()) break;
        }
    }

    (k % 2 == 0) ? cout << "No" : cout << "Yes";
    cout << endl;

    exit(0);
}
