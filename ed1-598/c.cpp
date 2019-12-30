#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define M_PI           3.14159265358979323846
using namespace std;

struct pt {
  int x;
  int y;
  int idx;
  long double ang;
  pt(int a, int b, int i): x(a), y(b), idx(i) {
    ang = atan2((long double)b, (long double)a);
  }
};

int main() {
  int n;
  cin >> n;

  vector<pt> vecs;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    vecs.emplace_back(x, y, i+1);
  }

  sort(vecs.begin(), vecs.end(), [](const pt& f, const pt& s) {
    return f.ang <= s.ang;
  });


  long double max_dist = 1000;
  int f_idx = 0;
  int s_idx = 0;

  for(int i = 0; i < vecs.size(); i++) {
    int j = i + 1;
    if (j==vecs.size()) j = 0;

    long double dist = abs(vecs[i].ang - vecs[j].ang);
    dist = min(dist, 2*M_PI - dist);

    if(dist < max_dist) {
      max_dist = dist;
      f_idx = i; s_idx = j;
    }
  }

  cout << vecs[f_idx].idx << " " << vecs[s_idx].idx << endl;
  return 0;
}