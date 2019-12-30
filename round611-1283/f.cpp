#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> main(n-1);
    vector<int> aux(n-1, -1);
    vector<int> sc(n, 0); // successor counts
    for(int i = 0; i < n-1; i++) {
        cin >> main[i];
        main[i]--;
        sc[main[i]]++;
    }

    set<int> leaves;
    for(int i = 0; i < n; i++) {
        if(sc[i] == 0) leaves.insert(i);
    }

    for(int i = n-2; i >= 0; i--) {
        if(leaves.empty()) {
            cout << "-1" << endl;
            return 0;
        }

        int a = *leaves.begin();
        leaves.erase(a);

        aux[i] = a;
        sc[main[i]]--;
        if(sc[main[i]] == 0)
            leaves.insert(main[i]);
    }

    vector<bool> visited(n, false);
    for(auto i : aux) {
        visited[i] = true;
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i])
            cout << i+1 << endl;
    }

    for(int i = 0; i < n-1; i++)
        cout << main[i]+1 << " " << aux[i]+1 << endl;

    return 0;
}