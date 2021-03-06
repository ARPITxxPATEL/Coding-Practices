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

char mirror(int i){
    if(i==1)return '1';
    else if(i==0) return '0';
    else if(i==2) return '5';
    else if(i==5) return '2';
    else if(i==8) return '8';
    else return 'a';
}

string check(string s,int i,int h,int m){
    string temp="";
    int hr = int(s[0]-48)*10+int(s[1]-48);
    int mn = int(s[3]-48)*10+int(s[4]-48);
    
    mn += i;
    hr += mn/m;

    hr%=h;
    mn%=m;
    
    if(mirror(mn%10)=='a'){
        return "";
    }
    else{
        temp += mirror(mn%10);
    }

    if(mirror(mn/10)=='a'){
        return "";
    }
    else{
        temp += mirror(mn/10);
    }
    temp += ':';
    if(mirror(hr%10)=='a'){
        return "";
    }
    else{
        temp += mirror(hr%10);
    }

    if(mirror(hr/10)=='a'){
        return "";
    }
    else{
        temp += mirror(hr/10);
    }
    return temp;
}

void solvetestcases()
{
    int h,m;
    string s;
    cin >> h >> m;
    cin >> s;

    loop(i,0,h*m){
        
            string temp=check(s,i,h,m);
            if(     temp!="" && ((int(temp[0])-48)*10+(int(temp[1])-48)<h) &&   ((int(temp[3])-48)*10+(int(temp[4])-48)<m)  ){
                string ans="";
                reverse(temp.begin(),temp.end());
                loop(k,0,5){
                    if(k==2){
                        ans += ':';
                        continue;
                    }
                    ans += mirror(int(temp[k])-48);
                }
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