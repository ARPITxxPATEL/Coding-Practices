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

void solvetestcases()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    string ans1,ans2;
    int pre1=0,pre2=0;

    int cnt0=0;
    loop(i,0,n)if(s[i]=='0')cnt0++;
    if(cnt0%2==1 || s[0]=='0' || s[n-1]=='0'){
        cout << "NO";
        return;
    }

    int cnt1=0;
    loop(i,0,n)if(s[i]=='1')cnt1++;
    int temp=0;
    bool change=true;
    
    loop(i,0,n){
        if(s[i]=='1'){
            temp++;
            if(temp<=cnt1/2){
                ans1+='(';
                ans2+='(';
            }
            else{
                ans1+=')';
                ans2+=')';
            }
        }
        else{
            if(change){
                ans1+='(';
                ans2+=')';
                change = false;
            }
            else{
                ans1+=')';
                ans2+='(';
                change = true;
            }
        }
    }
    cout << "YES\n";
    cout << ans1 << "\n";
    cout << ans2;
}


int TESTCASES=1;
int32_t main()
{
    FIO;

    cin >> TESTCASES;
    int total=TESTCASES;
    while(TESTCASES--){
        //cout << "Case #" << total-TESTCASES << ": ";
        solvetestcases();
        cout << "\n";
    }
    return 0;
}