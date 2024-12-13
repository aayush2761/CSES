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
void rangeUpdate(int start, int end, int idx, int left, int right, int value, vector<ll> &segment, vector<ll> &lazy) {
    // Apply pending updates
    if (lazy[idx] != 0) {
        segment[idx] += (right - left + 1) * lazy[idx];
        if (left != right) { // Propagate to children if not a leaf
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }
        lazy[idx] = 0; // Clear current node's lazy value
    }

    // Completely outside the range
    if (left > end || right < start) return;

    // Completely inside the range
    if (left >= start && right <= end) {
        segment[idx] += (right - left + 1) * value;
        if (left != right) { // Propagate to children
            lazy[2 * idx + 1] += value;
            lazy[2 * idx + 2] += value;
        }
        return;
    }

    // Partially in the range, split further
    int mid = left + (right - left) / 2;
    rangeUpdate(start, end, 2 * idx + 1, left, mid, value, segment, lazy);
    rangeUpdate(start, end, 2 * idx + 2, mid + 1, right, value, segment, lazy);
    segment[idx] = segment[2 * idx + 1] + segment[2 * idx + 2]; // Update parent
}

long long query(long long idx, long long left, long long right, long long start, long long end, vector<long long> &segment, vector<long long> &lazy) {
    // Apply pending updates (Fix added here)
    if (lazy[idx] != 0) {
        segment[idx] += (right - left + 1) * lazy[idx];
        if (left != right) { // Propagate to children
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }
        lazy[idx] = 0; // Clear current node's lazy value
    }

    // Completely outside the range
    if (left > end || right < start) return 0;

    // Completely inside the range
    if (left >= start && right <= end) return segment[idx];

    // Partially in the range, split further
    long long mid = left + (right - left) / 2;
    return (
        query(2 * idx + 1, left, mid, start, end, segment, lazy) +
        query(2 * idx + 2, mid + 1, right, start, end, segment, lazy)
    );
}

void BuildSegmentTree(long long idx, long long l, long long r, vector<long long> &segment, vector<long long> &v) {
    if (l == r) {
        segment[idx] = v[l];
        return;
    }

    long long mid = l + (r - l) / 2;
    BuildSegmentTree(2 * idx + 1, l, mid, segment, v);
    BuildSegmentTree(2 * idx + 2, mid + 1, r, segment, v);
    segment[idx] = (segment[2 * idx + 1] + segment[2 * idx + 2]);
}

int32_t main() {
    fastio();
    auto solve = [&]() {
        long long n, q;
        cin >> n >> q;

        vector<long long> v(n);
        foreach(i, 0, n, 1) cin >> v[i];

        // Build segment tree
        vector<long long> segment(4 * n, 0);
        vector<long long> lazy(4 * n, 0);
        BuildSegmentTree(0, 0, n - 1, segment, v);

        // Process each query
        foreach(i, 0, q, 1) {
            long long op;
            cin >> op;
            if (op == 1) {
                // Range Update operation: 1 start end value
                long long start, end, value;
                cin >> start >> end >> value;
                rangeUpdate(start - 1, end - 1, 0, 0, n - 1, value, segment, lazy);
            } else if (op == 2) {
                // Point Query operation: 2 pos
                long long pos;
                cin >> pos;
                cout << query(0, 0, n - 1, pos - 1, pos - 1, segment, lazy) << endl;
            }
        }
    };

    long long t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
