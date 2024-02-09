#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	string w, word;
	
	for(int i = 0; i < n; i++){
		cin >> w >> word;
		word += word;
		string w1 = word;
		reverse(w1.begin(), w1.end());
		if(word.find(w) != string::npos || w1.find(w) != string::npos) cout << "S" << endl;
		else cout << "N" << endl;
	}
	
	exit(0);
}
