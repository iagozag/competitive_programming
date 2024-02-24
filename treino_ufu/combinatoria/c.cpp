#include <bits/stdc++.h>

using namespace std;

long long fat(int a){
    long long aux=1;
    for(int i=2; i<=a; i++){
        aux*=i;
    }
    return aux;
}

int main()
{
    string palavra;
    map<char, int> vog, con;
    getline(cin, palavra);
    palavra.erase(std::remove(palavra.begin(), palavra.end(), ' '), palavra.end());

    for(int i =0; i < palavra.size(); i++){
        if(palavra[i] =='A'||palavra[i] =='E'||palavra[i] =='I'||palavra[i] =='O'||palavra[i] =='U'){
            vog[palavra[i]]++; 
        }
        else con[palavra[i]]++;
    }

    long long ans = fat(palavra.size());

    for(auto& x: vog) ans /= x.second;
    for(auto& x: con) ans /= x.second;

    cout << ans << endl;
}
