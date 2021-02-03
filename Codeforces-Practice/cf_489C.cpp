#include <bits/stdc++.h>
using namespace std;

#define int  long long int
#define loop(i,s,e) for(int i=s;i<e;i++)
#define vi vector<int>
#define pb push_back
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve()
{
    int m,s;
    cin >> m >> s;
    if(9*m<s or (m>1 and s==0)){
        cout << -1 << ' ' << -1;
        return;
    }
    vi min(m),max(m);
    loop(i,0,m){
        min[i]=0;max[i]=0;
    }
    min[0]=1;
    int val = s-1;
    for(int i=m-1;i>=0;i--){
        if(val<=9){
            min[i]+=val;
            break;
        }
        else{
            min[i]=9;
            val-=9;
        }
    }
    val = s;
    loop(i,0,m){
        if(val<=9){
            max[i]+=val;
            break;
        }
        else{
            max[i] = 9;
            val-=9;
        }
    }
    loop(i,0,m){
        cout << min[i];
    }
    cout << " ";
    loop(i,0,m){
        cout << max[i];
    }
}
int T;
int32_t main()
{
    FIO;
    T=1;
    //cin >> T;
    //int total=T;
    while(T--){
        //cout << "Case #" << total-T << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}