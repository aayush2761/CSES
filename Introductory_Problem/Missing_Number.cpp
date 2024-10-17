#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int x = 0;

    // XOR all the given numbers
    for (int i = 1; i < n; i++) {
        int t;
        cin >> t;
        x ^= t;  // XOR with each input number
    }

    // XOR all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        x ^= i;  // XOR with each number in the range
    }

    // x now holds the missing number
    cout << x << endl;

    return 0;
}
