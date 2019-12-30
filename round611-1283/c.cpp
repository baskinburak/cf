#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int find_out(vector<int>& noout_list, int in) {
    if(noout_list[noout_list.size() - 1] == in) {
        swap(noout_list[noout_list.size() - 1], noout_list[noout_list.size() - 2]);
    }

    int last = noout_list[noout_list.size() - 1];
    //cout << ">> " << in << " " << last << endl;
    noout_list.pop_back();
    return last;
}

int main() {
    int n;
    cin >> n;
    vector<int> f(n+1, 0);
    vector<bool> noin(n+1, true);
    vector<bool> noout(n+1, true);
    for(int i = 1; i <= n; i++) {
        cin >> f[i];
        if(f[i] != 0) {
            noout[i] = false;
            noin[f[i]] = false;   
        }
    }

    vector<int> noin_list;
    vector<int> noout_list;
    vector<int> noin_noout_list;

    for(int i = 1;i <= n; i++) {
        if(noin[i] && !noout[i]){
            noin_list.push_back(i);
            //cout << "no in " << i << endl;
            }
            if(noin[i] && noout[i]) noin_noout_list.push_back(i);
        if(noout[i]) {
         
            noout_list.push_back(i);
            //cout << "no out " << i << endl;
        }
    }

for(int i = 0; i < noin_noout_list.size(); i++) {
        int in = noin_noout_list[i];
        int out = find_out(noout_list, in);
        f[out] = in;
    }
    for(int i = 0; i < noin_list.size(); i++) {
        int in = noin_list[i];
        int out = find_out(noout_list, in);
        f[out] = in;
    }

    for(int i = 1; i <= n; i++) {
        cout << f[i] << " ";
    }
    cout << endl;
    return 0;
}