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

ll gcd(ll a,ll b){
    if(b==0)return a;
    if(a<b)return gcd(b,a);
    return gcd(b,a%b);
}

bool comparison(const pair<int,int> &a,const pair<int,int> &b){ 
    return a.second<b.second; 
} 

bool palind(string s){
    for(int i=0;i<s.length()/2;i++){
        if(s[i]!=s[s.length()-1-i])return false;
    }
    return true;
}

void solvetestcases()
{
    string s;
    cin >> s;
    int n = s.length();
    string ans;
    if(palind(s)){
        int cnt=0;
        loop(i,0,n){
            if(s[i]=='a')cnt++;
        }
        if(cnt==n){
            cout << "NO";
            return;
        }
        else{
            ans = s;
            ans += 'a';
            cout << "YES\n";
            cout << ans;
            return;
        }
    }
    else{
        int cnt1=0,cnt2=0;
        loop(i,0,n){
            if(s[i]=='a')cnt1++;
            else break;
        }
        loopr(i,n-1,0){
            if(s[i]=='a')cnt2++;
            else break;
        }
        if(cnt1<=cnt2){
            ans = s;
            ans += 'a';
            cout << "YES\n";
            cout << ans;
            return;
        }
        else{
            ans = "a";
            ans += s;
            cout << "YES\n";
            cout << ans;
            return;
        }
    }
}

int TESTCASES=1;
int32_t main()
{
    FIO;

    cin >> TESTCASES;
    //int total=TESTCASES;
    while(TESTCASES--){
        //cout << "Case #" << total-TESTCASES << ": ";
        solvetestcases();
        cout << "\n";
    }
    return 0;
}