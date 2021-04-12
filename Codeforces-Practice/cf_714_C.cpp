#include <bits/stdc++.h>
#include<iostream>
#include <stack>
#include <string>


using namespace std;

#define ll long long int
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,e,s) for(int i=e;i>=s;i--)
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define fs first
#define sc second
#define pb push_back
#define all(vect) (vect.begin(),vect.end())
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007

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

bool comparison(const pair<int,int> &a,const pair<int,int> &b){ 
    return a.second<b.second; 
} 

ll dp[200005+7][10];


void solvetestcases()
{
    string s;cin >> s;
    int m;cin >> m;
    ll ans = 0;
    for(auto i:s){
        ans = (ans + dp[m][i-'0'])%MOD;
    }
    cout << ans;
}


int TESTCASES=1;
int32_t main()
{
    FIO;

    memset(dp, 0, sizeof(dp));

    loop(i,0,10) dp[0][i]=1;

    for(int i=1;i<2e5+7;i++){
        for(int j=0;j<9;j++){
            dp[i][j] = dp[i-1][j+1];
        }
        dp[i][9] = (dp[i-1][0] + dp[i-1][1])%MOD;
    }

    cin >> TESTCASES;
    int total=TESTCASES;
    while(TESTCASES--){
        //cout << "Case #" << total-TESTCASES << ": ";
        solvetestcases();
        cout << "\n";
    }
    return 0;
}