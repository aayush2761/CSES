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
// minimnum queries requiered

int query(int idx, int left, int right, int start, int end, vector<int> &segment) {
    if (left > end || right < start) return INT_MAX; // Outside range
    if (left >= start && right <= end) return segment[idx]; // Fully inside range

    int mid = left + (right - left) / 2;
    return min(
        query(2 * idx + 1, left, mid, start, end, segment),
        query(2 * idx + 2, mid + 1, right, start, end, segment)
    );
}

void BuildSegmentTree(int idx, int l, int r, vector<int> &segment, vector<int> &v) {
    // Base case
    if (l == r) {
        segment[idx] = v[l];
        return;
    }

    int mid = l + (r - l) / 2;
    BuildSegmentTree(2 * idx + 1, l, mid, segment, v);
    BuildSegmentTree(2 * idx + 2, mid + 1, r, segment, v);
    segment[idx] = min(segment[2 * idx + 1], segment[2 * idx + 2]);
}

int32_t main() {
    fastio();
    auto solve = [&]() {
        int n, q;
        cin >> n >> q;

        vi v(n);
        foreach(i, 0, n, 1) cin >> v[i];

        vpi qq(q);
        foreach(i, 0, q, 1) {
            int a, b;
            cin >> a >> b;
            qq[i] = {a - 1, b - 1}; // Assuming input is 1-based indexing
        }

        // Build segment tree
        vi segment(4 * n, INT_MAX);
        BuildSegmentTree(0, 0, n - 1, segment, v);

        // Process each query
        for (auto i : qq) {
            int left = i.first;
            int right = i.second;
            cout << query(0, 0, n - 1, left, right, segment) << endl;
        }
    };

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}