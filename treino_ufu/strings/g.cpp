#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n; cin >> n;
    string ans;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        ans+=(s);
        if(i + 1 != n) ans.push_back(' ');
    }
    
    cout << ans << endl;

    return 0;
}
