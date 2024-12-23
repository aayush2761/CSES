#include <bits/stdc++.h>
using namespace std;

#define int long long
const int P1 = 131;       // First base for hashing
const int P2 = 137;       // Second base for hashing
const int M1 = 1e9 + 7;   // First modulus
const int M2 = 1e9 + 9;   // Second modulus

string rabinKarp(string &s) {
    if (s.empty()) return ""; 

    string res = s;
    int n = s.size();
    long long hash1 = 0, hash2 = 0; // Two hashes
    long long power1 = 1, power2 = 1;

    // Compute initial hashes and powers
    for (int i = 0; i < n; i++) {
        hash1 = (hash1 * P1 + (s[i] - 'a' + 1)) % M1;
        hash2 = (hash2 * P2 + (s[i] - 'a' + 1)) % M2;
        if (i < n - 1) {
            power1 = (power1 * P1) % M1;
            power2 = (power2 * P2) % M2;
        }
    }

    long long hashRoll1 = hash1, hashRoll2 = hash2;
    for (int j = 0; j < n - 1; j++) {
        // Update rolling hashes
        hashRoll1 = ((hashRoll1 - (s[j] - 'a' + 1) * power1 % M1 + M1) % M1 * P1 + (s[j] - 'a' + 1)) % M1;
        hashRoll2 = ((hashRoll2 - (s[j] - 'a' + 1) * power2 % M2 + M2) % M2 * P2 + (s[j] - 'a' + 1)) % M2;

        // Compare both hashes
        if (hashRoll1 < hash1 || (hashRoll1 == hash1 && hashRoll2 < hash2)) {
            res = s.substr(j + 1) + s.substr(0, j + 1);
            hash1 = hashRoll1;
            hash2 = hashRoll2;
        }
    }

    return res;
}


// ------*********************SEE THIS CODE RESOURCRE IF HAPPILY ABLE TO CODE IT *****************______????//////
// https://codeforces.com/blog/entry/79979


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto solve = [&]() {
        string s;
        cin >> s;
        cout << rabinKarp(s) << endl;
    };

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
