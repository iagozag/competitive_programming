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
 
string retorna_vencedor(string first, string second){
    if(first == "rock"){
        if(second == "scissors") return first;
        else if(second == "paper") return second;
    } else if(first == "paper"){
        if(second == "scissors") return second;
        else if(second == "rock") return first;
    }
    else if(first == "scissors"){
        if(second == "paper") return first;
        else if(second == "rock") return second;
    }

    return "?";
}

int main(){ // _
    vector<string> lista;
    string entrada, anterior;
    string ans = "?";

    for(int i = 0; i < 3; i++){
        cin >> entrada;
        lista.pb(entrada);
    }

    if(lista[0] != lista[1] && lista[0] != lista[2] && lista[1] != lista[2]){
        cout << "?" << endl;
        return(0);
    }

    if(retorna_vencedor(lista[0], lista[1]) == lista[0]) ans = "F";
    else if(retorna_vencedor(lista[0], lista[1]) == lista[1]) ans = "M";

    if(ans == "F"){
        if(lista[0] == lista[2]) ans = "?";
        else if(retorna_vencedor(lista[0], lista[2]) == lista[0]) ans = "F";
        else if(retorna_vencedor(lista[0], lista[2]) == lista[2]) ans = "S";
    } else if(ans == "M"){
        if(lista[1] == lista[2]) ans = "?";
        else if(retorna_vencedor(lista[1], lista[2]) == lista[1]) ans = "M";
        else if(retorna_vencedor(lista[1], lista[2]) == lista[2]) ans = "S";
    } else{
        if(lista[0] == lista[2]) ans = "?";
        else if(retorna_vencedor(lista[0], lista[2]) == lista[2]) ans = "S";
        else ans = "?";
    }

    cout << ans << endl;
    return(0);
}
