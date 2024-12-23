#include<iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

//Macros
#define IOtext freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PI (3.141592653589)
#define M 1000000007
#define pb push_back
#define f first
#define s second
#define foreach(i, j, k, in) for(int i=j;i<k;i+=in)
#define rforeach(i, j, k, in) for(int i=j;i>=k;i-=in)
#define rep(i,j) foreach(i,0,j,1)
#define rrep(i,j) rforeach(i,j,0,1)
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define inint(x) int x; cin>>x;
#define inll(x) long long int x; cin>>x;
#define instr(x) string x; cin>>x;
#define all(x) x.begin(), x.end()
#define out(x) cout << x << endl;
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define pm cout<<"-1"<<endl
#define ps(x,y) fixed<<setprecision(y)<<x

//Typedef
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef map<char,int> mci;
typedef set<int> st;

void zTheorem(string s, vector<int>& z) {
        int n = s.size();
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i < r) {
                z[i] = min(r - i, z[i - l]); // Corrected logic
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
    }
int32_t main()
{
    fastio()
    auto solve = [&] () {
        string s;
        cin>>s;
        int n =s.size();
          int i=0,j=n-1;
        // map<string ,int>mp;
        // unordered_set<long long>st;
        
        long long pref=0,suff=0,power=1;
        int longest=0;
        while (i < s.size()-1) {
            pref=((pref*31)%M+((s[i]-'a'+1)))%M;
            suff = (suff + (s[n - i - 1] - 'a' + 1)*power) % M;
            power = (power * 31) % M;
            if (pref == suff) cout<< i + 1<<" ";
            i++;
        }
        // i=n-1;
        // count=0;
        // string res="";
        // while(i>0){
        //     count= (count*10+(s[i]-'a'+1))%mod;
        //     if(st.find(count)!=st.end() && res.size()<=(n-i+1))res=s.substr(i);
        //      i--;
        // }
        return s.substr(0,longest);

    };

    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}