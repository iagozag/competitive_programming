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

int main(){ _
    vector<int> actual_move;
    vector<int> inverse;
    int x, y, p_x, p_y;
    string d;

    int n, sum; cin >> n;
    for(int i = 0; i < n; i++){
        set<vector<int>> moves;
        sum = 0;
        cin >> d;
        
        x = 0, y = 0, p_x = 0, p_y = 0;
        actual_move = {x,y,p_x,p_y};
        inverse = actual_move;
        moves.insert(actual_move);
        for(auto c: d){
            if(c == 'N') y++;
            if(c == 'S') y--;
            if(c == 'W') x--;
            if(c == 'E') x++;
            actual_move = {x,y,p_x,p_y};
            inverse = {p_x,p_y,x,y};

            if(moves.count(actual_move) == 0 && moves.count(inverse) == 0) sum += 5;
            else sum++;

            moves.insert(actual_move);
            p_x = x; 
            p_y = y; 
        }
        
        cout << sum << endl;
    }

    exit(0);
}
