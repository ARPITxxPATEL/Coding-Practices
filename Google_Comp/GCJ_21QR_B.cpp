#include <bits/stdc++.h>

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



void solvetestcases()
{
    int x,y;
    cin >> x >> y;
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    bool skip = true;
    for(int i=1;i<n;i++){
        if(s[i-1]!='?'){
            skip = false;
        }
        if(skip==false){
            if(s[i]=='?'){
                s[i] = s[i-1];
            }
            if(s[i-1]=='J' && s[i]=='C'){
                ans += y;
            }
            else if(s[i-1]=='C' && s[i]=='J'){
                ans += x;
            }   
        }
    }
    cout << ans;
          
}

int TESTCASES=1;
int32_t main()
{
    FIO;

    cin >> TESTCASES;
    int total=TESTCASES;
    while(TESTCASES--){
        cout << "Case #" << total-TESTCASES << ": ";
        solvetestcases();
        cout << "\n";
    }
    return 0;
}