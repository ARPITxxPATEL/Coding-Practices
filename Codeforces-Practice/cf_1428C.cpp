#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define loop(i,s,e) for(int i=s;i<e;i++)
#define vi vector<int>
#define pb push_back
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve()
{
    string s;
    cin >> s;
    int cnta=0, cntb=0;
    int n = s.length();
    int res = 0;
    for(auto i : s){
        if(i=='A'){
            cnta++;
            res += cntb;
            cntb=0;
        }
        else cntb++;
        if(cntb>=2){
            cntb-=2;
            n-=2;
        }
        else if(cnta>=1 and cntb==1){
            cnta--;
            cntb--;
            n-=2;
        }
    }
    res += cntb;
    if(res%2==1){
        n-= res-1;
    }
    else n-=res;
    cout << n;
}
int T;
int32_t main()
{
    FIO;
    //T=1;
    cin >> T;
    while(T--){
        solve();
        cout << "\n";
    }
    return 0;
}