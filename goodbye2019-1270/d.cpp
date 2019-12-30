#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

pair<int, int> question(const vector<int>& x) {
    cout << "? ";
    for(int i = 0; i < x.size()-1; i++) {
        cout << x[i] << " ";
    }
    cout << x[x.size() - 1] << endl;
    cout.flush();

    int pos, apos;
    cin >> pos;
    if(pos == -1)
        return make_pair(-1, -1);
    cin >> apos;
    return make_pair(pos, apos);
}

void answer(int ans) {
    cout << "! " << ans << endl;
    cout.flush();
}

int main() {
    int n, k;
    cin >> n >> k;

    if(k == 1) {
        answer(1);
        return 0;
    }

    vector<int> query(k);
    for(int i = 1; i<=k; i++) query[i-1] = i;

    auto pivot = question(query);
    query[pivot.first-1] = k+1;
    auto pivot2 = question(query);

    int same_side = 0;
    //query[pivot.first-1] = pivot.first;

    for(int i = 0; i < k; i++) {
        if(query[i] == pivot2.first) continue;
        int qi = query[i];
        query[i] = pivot.first;
        auto res = question(query);
        if(res.first == pivot2.first) same_side++;
        query[i] = qi;
    }

    if(pivot.second < pivot2.second) {
        answer(same_side + 1);
    } else {
        answer(k - same_side);
    }
    return 0;
}