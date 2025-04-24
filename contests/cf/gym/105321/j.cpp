#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main() { _
    ll n, x; cin >> n >> x;
    map<ll,ll> m;
    for(ll i=0;i<n;i++) {
        ll a;
        cin >> a;
        m[a]++;
    }

    list<ll> l;
    
    for(auto i = m.begin();i!=m.end();) {
        if(not m.count(x-i->ff)) {
            for(int a=0;a<i->ss;a++) l.push_back(i->ff);
            int xx = i->ff;
            i++;
            m.erase(xx);
            continue; 
        }
        i++;
    }
    int q=0;
    if((x%2==0) and m.count(x>>1)) {
        q=m.at(x>>1);
        m.erase(x>>1);
    }

    if(l.empty() and m.size()==2ULL) {
        auto it = m.begin();
        for(int i=0;i<it->ss;i++) l.push_back(it->ff);
        if(q) {
            l.push_back(x>>1);
            q--;
        } else {
            //cout << n << ' ' << x << endl;
            cout << "*\n";
            return 0;
        }
        int d = it->ff;
        it++;
        m.erase(d);
        for(int i=0;i<it->ss;i++) l.push_back(it->ff);
        
        for(auto it = l.begin();it!=l.end() and q;it++) {
            if(it!=l.begin() and (*it==(x>>1) or *prev(it)==(x>>1))) 
                continue;
            
            q--;
            l.insert(it,x>>1);
        }
        if(q>1) {
            //cout << n << ' ' << x << endl;
            cout << "*\n";
            return 0;
        }
        if(q) l.push_back(x>>1);
        // cout << n << ' ' << x << endl;
        for(int i:l) cout << i << ' ';
        cout << '\n';
        return 0;
    } else if(l.empty() and m.size()>2ULL) {
        auto it = m.begin();
        auto it2 = prev(prev(m.end()));

        for(int i=0;i<it->ss;i++) l.push_back(it->ff);
        for(int i=0;i<it2->ss;i++) l.push_back(it2->ff);
        auto a = it;
        it = m.lower_bound(x-it->ff);
        m.erase(a);
        a = it2;
        it2 = m.lower_bound(x-it2->ff);
        m.erase(a);
        for(int i=0;i<it->ss;i++) l.push_back(it->ff);
        for(int i=0;i<it2->ss;i++) l.push_back(it2->ff);
        m.erase(it);
        m.erase(it2);
    }

    while(m.size()) {
        auto it = m.begin();
        for(int i=0;i<it->ss;i++) l.push_front(it->ff);
        int xx = it->ff;
        it = m.lower_bound(x-xx);
        m.erase(xx);
        for(int i=0;i<it->ss;i++) l.push_back(it->ff);
        m.erase(it);
    }
    
    if(q) {
        for(auto it = l.begin();it!=l.end() and q;it++) {
            if(*it==(x>>1)) continue;
            if(it!=l.begin() and *prev(it)==(x>>1)) continue;
            q--;
            l.insert(it,x>>1);
        }
        if(q>1) {
            //cout << n << ' ' << x << endl;
            cout << "*\n";
            return 0;
        }
        if(q) l.push_back(x>>1);
    }

    //cout << n << ' ' << x << endl;
    for(int i:l) cout << i << ' ';
    cout << '\n';
    return 0;
}