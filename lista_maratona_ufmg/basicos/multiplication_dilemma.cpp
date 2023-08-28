#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b; cin >> n;
    int mod_a, mod_b;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        mod_a = a%10; 
        mod_b = b%10;

        if(mod_a >= 5){
            cout << a+(10-mod_a) << " x " << b << " - " << (10-mod_a) << " x " << b << "\n";
        } else if(mod_a > 0){
            cout << a-(10-mod_a) << " x " << b << " + " << (10-mod_a) << " x " << b << "\n"; 
        } else if(mod_b >= 5){
            cout << a << " x " << b+(10-mod_b) << " - " << a << " x " << (10-mod_b) << "\n";
		} else{
            cout << a << " x " << b-mod_b << " + " << a << " x " << mod_b << "\n";
        }
    }
}
