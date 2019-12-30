#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

using lli = long long int;


class pt {
    public:
    lli x, y, idx;
    pt(lli a, lli b, lli c): x(a), y(b), idx(c) {}
};

void fix(vector<pt> a[2][2]) {
    bool something_fixed = false;

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            bool all_empty = true;
            for(int m = 0; m < 2; m++) {
                for(int n = 0; n < 2; n++) {
                    if(m == i && n == j) continue;
                    all_empty = all_empty && a[m][n].empty();
                }
            }

            if(all_empty) {
                for(int m = 0; m < a[i][j].size(); m++) {
                    a[i][j][m].x -= i;
                }

                for(int m = 0; m < a[i][j].size(); m++) {
                    a[i][j][m].y -= j;
                }

                if(i!=0 || j!=0) {
                    a[0][0] = a[i][j];
                    a[i][j].clear();
                }

                bool something_became_odd = false;
                while(!something_became_odd) {
                    for(int m = 0; m < a[0][0].size(); m++) {
                        a[0][0][m].x /= 2;
                        a[0][0][m].y /= 2;
                        if(a[0][0][m].x % 2 != 0 || a[0][0][m].y % 2 != 0) {
                            something_became_odd = true;

                            int m_dest = !(a[0][0][m].x % 2 == 0);
                            int n_dest = !(a[0][0][m].y % 2 == 0);

                            a[m_dest][n_dest].push_back(a[0][0][m]);

                            swap(a[0][0][m], a[0][0][a[0][0].size() - 1]);
                            a[0][0].pop_back();
                            m--;
                        }
                    }
                }

                something_fixed = true;
                break;
            }
        }
        if(something_fixed) break;
    }

    if(something_fixed) fix(a);
}



int main() {
    int n;
    cin >> n;
    vector<pt> a[2][2];
    for(int i = 0; i < n; i++) {
        lli x,y;
        cin >> x >> y;

        int m = !(x%2 == 0);
        int n = !(y%2 == 0);
        
        a[m][n].emplace_back(x, y, i+1);
    }

    fix(a);

    if(a[0][0].size() + a[1][1].size() > 0 && a[0][1].size() + a[1][0].size() > 0) {
        cout << a[0][0].size() + a[1][1].size() << endl;
        for(auto p : a[0][0]) {
            cout << p.idx << " ";
        }
        for(auto p : a[1][1]) {
            cout << p.idx << " ";
        }
    } else if (a[0][0].size() + a[1][1].size() == 0) {
        cout << a[1][0].size() << endl;
        for(auto p : a[1][0]) {
            cout << p.idx << " ";
        }
    } else {
        cout << a[0][0].size() << endl;
        for(auto p : a[0][0]) {
            cout << p.idx << " ";
        }
    }
    cout << endl;

    return 0;
}