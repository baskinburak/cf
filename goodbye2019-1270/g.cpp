// solved from editorial
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


void cycle(const vector<int>& a, int n, vector<int>& cyc) {
    vector<bool> v(n, false);
    int i = 0;
    while(!v[i]) { v[i] = true; i = i - a[i]; }
    int ii = i;
    cyc.push_back(ii); i = i - a[i];
    while(i != ii) { cyc.push_back(i); i = i - a[i]; }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) { cin >> a[i]; }
        
        vector<int> cyc; cycle(a, n, cyc);

        cout << cyc.size() << '\n';
        for(auto i : cyc) {
            cout << i + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}