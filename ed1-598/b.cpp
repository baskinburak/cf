#include <iostream>

using namespace std;
int main() {
  string inp;
  int m;
  cin >> inp >> m;

  while(m--) {
    int l, r, k;
    cin >> l >> r >> k;
    l--; r--;
    int len = r - l + 1;
    k %= len;
    string substr(len, '0');
    for(int i = l; i <= r; i++) {
      int w = i - k;
      if(w < l) {
        w += len;
      }


      substr[i-l] = inp[w]; 
    }

    for(int i = l; i <= r; i++) {
      inp[i] = substr[i-l];
    }
  }

  cout << inp << endl;
  return 0;
}