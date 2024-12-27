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
typedef vector<char> vc;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef map<char,int> mci;
typedef set<int> st;

// Operator overloads
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
template<typename T, typename V> // cout << map<T,V>
ostream& operator<<(ostream &ostream, const map<T,V> &c) { for (auto &it : c) cout << it.first << " " << it.second<<endl; return ostream; }
template<typename T, typename V> // cout << vector<pair<T,V>>
ostream& operator<<(ostream &ostream, const vector<pair<T,V>> &c) { for (auto &it : c) cout << it.first << " " << it.second<<endl; return ostream; }

int gridPaths(int  n,vector<vc>&grid){
     vvi dp(n,vi(n,0));
     if(grid[0][0]=='*')return 0;
    //  else dp[0][0]=1;
     
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0)dp[i][j]=1;
            else if(grid[i][j]=='*')dp[i][j]=0;
            else{
                if(i==0 && j>0){
                    dp[i][j]= dp[i][j-1];
                }
                else if(i!=0 && j==0){
                     dp[i][j]= dp[i-1][j];
                }
                else{
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1])%M;
                }
            }
        }
     }
    //   for(int i=0;i<n;i++){
    //     cout<<dp[i]<<endl;
    // }
   
     return dp[n-1][n-1]%M;
}
int32_t main()
{
    fastio()
    auto solve = [&] () {
        inint(n);
        vector<vc> grid(n,vc(n));
        foreach(i,0,n,1){
            foreach(j,0,n,1){
                cin>>grid[i][j];
            }
        }
        int res=gridPaths(n,grid);
        out(res)
    };

    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}