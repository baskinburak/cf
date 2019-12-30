#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int find(int i, vector<int>& pars) {
  return (pars[i] < 0 ? i : (pars[i] = find(pars[i], pars)));
}


void _union(int i, int j, vector<int>& pars) {
  int par_i = find(i, pars);
  int par_j = find(j, pars);

  int set_i_size = pars[par_i];
  int set_j_size = pars[par_j];

  if(set_i_size < set_j_size) {
    pars[par_i] += pars[par_j];
    pars[par_j] = par_i;
  } else {
    pars[par_j] += pars[par_j];
    pars[par_i] = par_j;
  }
}

int n, m;

int idx(int i, int j) {
  return i*m + j;
}

pair<int, int> rev_idx(int i) {
  return make_pair(i / m, i%m);
}

bool valid(const vector<vector<char>>& board, int i, int j) {
  return i >= 0 && i < board.size() && j>=0 && j < board[0].size();
}

int main() {
  int k;
  cin >> n >> m >> k;
  vector<int> pars (n*m, -1);
  vector<vector<char>> board(n, vector<char>(m));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }


  vector<bool> visited(n*m, false);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(board[i][j] == '.' && !visited[idx(i ,j)]) {
        stack<int> queue;
        queue.push(idx(i, j));
        visited[idx(i, j)] = true;
        while(!queue.empty()) {
          auto [u, v] = rev_idx(queue.top());
          queue.pop();
          if(valid(board, u+1, v) && board[u+1][v] == '.' && !visited[idx(u+1, v)]) {
            queue.push(idx(u+1, v));
            visited[idx(u+1, v)] = true;
            _union(idx(i, j), idx(u+1, v), pars);
          }
          if(valid(board, u-1, v) && board[u-1][v] == '.' && !visited[idx(u-1, v)]) {
            queue.push(idx(u-1, v));
            visited[idx(u-1, v)] = true;
            _union(idx(i, j), idx(u-1, v), pars);
          }
          if(valid(board, u, v-1) && board[u][v-1] == '.' && !visited[idx(u, v-1)]) {
            queue.push(idx(u, v-1));
            visited[idx(u, v-1)] = true;
            _union(idx(i, j), idx(u, v-1), pars);
          }
          if(valid(board, u, v+1) && board[u][v+1] == '.' && !visited[idx(u, v+1)]) {
            queue.push(idx(u, v+1));
            visited[idx(u, v+1)] = true;
            _union(idx(i, j), idx(u, v+1), pars);
          }
        }
      }
    }
  }

  vector<int> counts(n*m, 0);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(board[i][j] == '.') {
        if(valid(board, i, j+1) && board[i][j+1] == '*') {
          counts[find(idx(i, j), pars)]++;
        }
        if(valid(board, i, j-1) && board[i][j-1] == '*') {
          counts[find(idx(i, j), pars)]++;
        }
        if(valid(board, i+1, j) && board[i+1][j] == '*') {
          counts[find(idx(i, j), pars)]++;
        }
        if(valid(board, i-1, j) && board[i-1][j] == '*') {
          counts[find(idx(i, j), pars)]++;
        }
      }
    }
  }

  while(k--) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << counts[find(idx(x, y), pars)] << endl;
  }
  return 0;
}