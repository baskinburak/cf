#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        int winner = 0;
        for(int i = 0; i < k1; i++) {
            int x;
            cin >> x;
            if ( x == n) winner = 1;
        }
        for(int i = 0; i < k2; i++) {
            int x;
            cin >> x;
            if ( x == n) winner = 2;
        }
        if(winner == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}