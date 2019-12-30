#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using ulli = unsigned long long int;
using namespace std;


vector<ulli> make_good(const vector<ulli>& a, int n) {
    ulli sum = 0;
    ulli XOR = 0;
    for(auto number : a) {
        sum += number;
        XOR ^= number;
    }

    return vector<ulli> {XOR, sum + XOR};
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ulli> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        vector<ulli> add = make_good(a, n);
        cout << add.size() << endl;
        for(auto number : add) {
            cout << number << " ";
        }
        cout << endl;
    }
    return 0;
}