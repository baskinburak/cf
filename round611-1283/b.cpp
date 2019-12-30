#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        cout << n - ((n%k) - min(n%k, k/2)) << endl;
    }
    return 0;
}