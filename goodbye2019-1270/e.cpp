// not solved yet

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int dist(const pair<int, int>& p1, const pair<int, int>& p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) 
            + (p1.second - p2.second) * (p1.second - p2.second);
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        a[i] = make_pair(x, y);
    }


    return 0;
}