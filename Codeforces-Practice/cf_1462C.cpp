#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define loop(i,s,e) for(int i=s;i<e;i++)
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define pb push_back
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD1 1000000007
#define MOD 4294967296 //2^32

bool isprime(int n){
    for(int i=2;i*i<=n;i++) if(n%i==0) return false;
    return true;
}
vi SieveOfEratosthenes(int n){
    bool prime[n+1];
    vi v;
    memset(prime,true,sizeof(prime));
    for(int p=2;p*p<=n;p++){
        if(prime[p]){
            for(int i=p*p;i<=n;i+=p) prime[i] = false;
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]) v.pb(i);
    }
    return v;
}

string reversestr(string sub){
    reverse(sub.begin(),sub.end());
    return sub;
}

void solve()
{
    int n;
    cin >> n;
    if(n>45){
        cout << -1;
    }
    else if(n<10){
        cout << n;
    }
    else{
        string ans = "";
        int var = 9;
        while(n>0){
            if(n>=var){
                n -= var;
                ans = ans + char(var+48);
                var--;
            }
            else{
                var = n;
                n -= var;
                ans = ans + char(var+48);
            }
            
        }
        reverse(ans.begin(),ans.end());
        cout << ans;
    }

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