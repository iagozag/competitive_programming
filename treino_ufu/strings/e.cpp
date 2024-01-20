#include <bits/stdc++.h>

using namespace std;

int main(){
    
    string s; cin >> s;
    int l; l = s.size();
    string ans;
    for(int i = 0; i < l; i++){
        int count = 1; char c = s[i];
        int j;
        for(j = i + 1; j < l; j++){
            if(s[i] == s[j]) count++;
            else {
                break;
            }
        }
        if(count > 1) {
            ans.push_back(c);
            ans+=to_string(count);
        } else {
            ans.push_back(c);
        }
        i = j -1 ;
    }
    
    if(ans.size() >= l){
        cout << s << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
