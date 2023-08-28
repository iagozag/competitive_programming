#include<bits/stdc++.h>
using namespace std;
    
#define endl '\n'
#define f first
#define s second
#define pb push_back
    
typedef long long ll;
    
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
    
int main(){
    int n; cin >> n;
    float hit_points;
    int void_abs, light_strike;

    for(int i = 0; i < n; i++){
        cin >> hit_points >> void_abs >> light_strike;

        while(hit_points > 20 && void_abs > 0){
            hit_points = floor(hit_points/2) + 10;
            void_abs--;
        }

        while(hit_points > 0 && light_strike > 0){
            hit_points -= 10;
            light_strike--;
        }
       
        if(hit_points > 0){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    
    exit(0);
}
