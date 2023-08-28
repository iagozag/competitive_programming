#include<bits/stdc++.h>
using namespace std;
     
int main () {
    string str; getline(cin, str);
    vector<pair<char, int>> char_list;
     
    char c;
    for (int i = 0; i < str.size(); i++) {
        c = str[i];
        if(i > 0 && c == str[i-1]){
            for(int j = char_list.size()-1; j >= 0; j--){
                if(c == char_list[j].first){
                    char_list[j].second++;
                    break;
                }
            }
        }
        else char_list.push_back(pair<char, int> (c, 1));
    }
     
    for(auto i : char_list) cout << i.first << i.second;
    cout << "\n";
}
