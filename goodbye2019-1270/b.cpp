#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

pair<int, int> interesting(const vector<int>& a, int n) {
    for(int i = 0; i < n-1; i++) {
        if(abs(a[i] - a[i+1]) > 1)
            return make_pair(i, i+1);
    }
    return make_pair(-1, -1);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        auto p = interesting(a, a.size());
        if(p.first == -1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl << p.first + 1 << " " << p.second + 1 << endl;
        }
    }
    return 0;
}