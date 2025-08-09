#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<vector<int>> con;

bool has01(vector<int> aux){
    bool zero = false, um = false;
    for(auto e: aux){
        if(e) zero = true;
        else um = true;
    }
    return zero and um;
}

int32_t main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int tam; cin >> tam;
        vector<int> aux(tam);
        for(int j=0; j<tam; j++) {cin >> aux[j]; aux[j]--;}
        con.push_back(aux);

    }
    if(n==2){
		bool has01 = false, has10 = false;
		for(int i = 0; i < (int)con[0].size()-1; i++) if(con[0][i] == 1 and con[0][i+1] == 0) has10 = true;
		for(int i = 0; i < (int)con[1].size()-1; i++) if(con[1][i] == 0 and con[1][i+1] == 1) has01 = true;

        if((find(con[0].begin(), con[0].end(), 1) != con[0].end() and find(con[1].begin(), con[1].end(), 0) != con[1].end()) or
		   has01 or has10)
			cout << "N" << endl;
        else cout << "S" << endl;
    }else{
        cout << "S" << endl;
    }
}
