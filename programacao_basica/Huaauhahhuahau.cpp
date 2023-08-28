#include<bits/stdc++.h>
using namespace std;

bool eh_vogal(char c){
    return(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool eh_palindromo(string str){
    int j = str.size() - 1;
    for(int i = 0; i < str.size() / 2; i++){
        if(str[i] != str[j]) return false;
        j--;
    }
    return true;
}

int main(){
    string s, s2 = ""; cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(eh_vogal(s[i])) s2 += s[i];
    }
    if(eh_palindromo(s2)) cout << "S";
    else cout << "N";
}