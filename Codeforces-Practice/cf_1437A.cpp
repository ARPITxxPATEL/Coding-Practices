#include <bits/stdc++.h>
using namespace std;

#define int  long long int
#define loop(i,s,e) for(int i=s;i<e;i++)
#define vi vector<int>
#define pb push_back
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve()
{
    int l,r;
    cin >> l >> r;
    if(float(l%(r+1)>=(r+1)/2.0))cout << "YES";
    else cout << "NO";
}
int T;
int32_t main()
{
    FIO;
    //T=1;
    cin >> T;
    //int total=T;
    while(T--){
        //cout << "Case #" << total-T << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}