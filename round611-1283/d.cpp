#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
    long long int n, m;
    cin >> n >> m;
    vector<long long int> x(n);
    for(long long int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    

    map<long long int, vector<pair<long long int, long long int>>> valid_intervals;
    for(long long int i = 1; i < n; i++) {
        if(x[i] - x[i-1] - 1 > 0)
            valid_intervals[x[i] - x[i-1] - 1].push_back(make_pair(x[i-1], x[i]));
    }

    long long int res = 0;
    vector<long long int> y;
    for(long long int dist = 1; ; dist++) {
        y.push_back(x[0] - dist);
        res+=dist;
        if(y.size() == m) break;
        y.push_back(x[n-1] + dist);
        res+=dist;
        if(y.size() == m) break;

        bool done = false;
        for(auto it = valid_intervals.begin(); it!=valid_intervals.end(); it++) {
            long long int sep = it->first;
            vector<pair<long long int, long long int>>& vec = it->second;
            for(long long int i = 0; i < vec.size(); i++) {
                y.push_back(vec[i].first + dist);
                res+=dist;
                if(y.size() == m) {
                    done = true;
                    break;
                }
                if(sep / 2 >= dist) {
                    y.push_back(vec[i].second - dist);
                    res+=dist;
                    if(y.size() == m) {
                        done = true;
                        break;
                    }
                }
            }
            if(done)
                break;
        }
        if(done)
            break;

        valid_intervals.erase(dist * 2);
        valid_intervals.erase(dist * 2 - 1);
    }

    cout << res << endl;
    for(long long int i = 0; i < y.size(); i++)
        cout << y[i] << " ";
    cout << endl;
    return 0;
}