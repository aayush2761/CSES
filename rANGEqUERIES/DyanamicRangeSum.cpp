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
    if (lazy[idx] != 0) {
        segment[idx] += (right - left + 1) * lazy[idx];
        if (left != right) {
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if (left > end || right < start) return; // Outside range

    if (left >= start && right <= end) {
        segment[idx] += (right - left + 1) * value;
        if (left != right) {
            lazy[2 * idx + 1] += value;
            lazy[2 * idx + 2] += value;
        }
        return;
    }

    int mid = left + (right - left) / 2;
    rangeUpdate(start, end, 2 * idx + 1, left, mid, value, segment, lazy);
    rangeUpdate(start, end, 2 * idx + 2, mid + 1, right, value, segment, lazy);
    segment[idx] = segment[2 * idx + 1] + segment[2 * idx + 2];
}

long long query(long long idx, long long left, long long right, long long start, long long end, vector<long long> &segment) {
    if (left > end || right < start) return 0; // Outside range
    if (left >= start && right <= end) return segment[idx]; // Fully inside range

    long long mid = left + (right - left) / 2;
    return (
        query(2 * idx + 1, left, mid, start, end, segment) +
        query(2 * idx + 2, mid + 1, right, start, end, segment)
    );
}

void update(long long pos, long long value, long long left, long long right, long long idx, vector<long long> &segment) {
    if (left == right) {
        segment[idx] = value;
        return;
    }
    long long mid = left + (right - left) / 2;
    if (pos <= mid) update(pos, value, left, mid, 2 * idx + 1, segment);
    else update(pos, value, mid + 1, right, 2 * idx + 2, segment);
    segment[idx] = (segment[2 * idx + 1] + segment[2 * idx + 2]);
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
        BuildSegmentTree(0, 0, n - 1, segment, v);

        // Process each query
        foreach(i, 0, q, 1) {
            long long op;
            cin >> op;
            if (op == 1) {
                // Update operation: op position value
                long long pos, value;
                cin >> pos >> value;
                update(pos - 1, value, 0, n - 1, 0, segment); // Convert 1-based to 0-based
            } else if (op == 2) {
                // Query operation: op left right
                long long left, right;
                cin >> left >> right;
                cout << query(0, 0, n - 1, left - 1, right - 1, segment) << endl; // Convert 1-based to 0-based
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
