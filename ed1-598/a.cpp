#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    long long int n;
    cin >> n;
    long long int sum = (n * (n+1)) / 2;
    int sub  = 1;
    while(n) {
      sum -= 2*sub;
      n = n >> 1;
      sub *= 2;
    }
    cout << sum << endl;
  }
  return 0;
}