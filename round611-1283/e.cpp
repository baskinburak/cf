#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++) { cin >> x[i]; }
    sort(x.begin(), x.end());


    vector<int> x_m = x;
    x_m[0]--;
    int max_count = 1;
    for(int i = 1; i < n; i++) {
        if(x_m[i-1] < x_m[i] - 1) {
            x_m[i]--;
            max_count++;
        } else if(x_m[i-1] == x_m[i]) {
            x_m[i]++;
            max_count++;
        } else if(x_m[i] > x_m[i-1]) {
            max_count++;
        } else {
            x_m[i]++;
        }
    }

    x_m = x;
    x_m[0]++;
    int min_count = 1;
    for(int i = 1; i<n; i++) {
        if(x_m[i] == x_m[i-1]) {

        } else if (x_m[i] < x_m[i-1]) {
            x_m[i]++;
        } else if (x_m[i] == x_m[i-1] + 1) {
            x_m[i]--;
        } else {
            x_m[i]++;
            min_count++;
        }
    }


    cout << min_count << " " << max_count << endl;
    return 0;

}