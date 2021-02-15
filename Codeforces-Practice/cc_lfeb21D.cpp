#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define loop(i,s,e) for(int i=s;i<e;i++)
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define pb push_back
#define fs first
#define sc second
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define MOD1 4294967296 //2^32

int countall[1000007];


bool isprime(int n){
    for(int i=2;i*i<=n;i++) if(n%i==0) return false;
    return true;
}
void SieveOfEratosthenes(int n){
    bool prime[n];
    vi v;
    memset(prime,true,sizeof(prime));
    for(int p=2;p*p<n;p++){
        if(prime[p]){
            for(int i=p*p;i<n;i+=p) prime[i] = false;
        }
    }
    for(int i=2;i<n;i++){
        countall[i] = countall[i-1];
        if(prime[i]) countall[i] = countall[i] + 1;
    }
    return;
}

bool comparison(const pair<int,int> &a,const pair<int,int> &b){ 
    return a.second<b.second; 
} 

void solve()
{
    int a,b;
    cin >> a >> b;

    if(countall[a]<=b) cout << "Chef";
    else cout << "Divyam";
    
}
int T;


int32_t main()
{
    FIO;
    //T=1;
    cin >> T;
    //int total=T;
    loop(i,0,1000007)countall[i] = 0;
    SieveOfEratosthenes(1000007);
    
    while(T--){
        //cout << "Case #" << total-T << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}