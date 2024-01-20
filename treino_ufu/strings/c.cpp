#include <bits/stdc++.h>

using namespace std;

int main(){
    
    string frase;  vector<string> ans; 
    getline(cin, frase);
    istringstream stream(frase);
    
    string s;
    while (stream >> s) {
        if(s[0] == 'd' || s[0] == 'e') continue;
        else {
            ans.push_back(s);
        }
    }
    
    for(int i = 0; i < ans.size(); i++){
        if(i != 0 && i+1 != ans.size()){
            cout << ans[i][0] << ". ";
        }else if(i+1 != ans.size()){
            cout << ans[i] << ' ';
        } else{
            cout << ans[i];
        }
    }
    cout << endl; 

    return 0;
}
