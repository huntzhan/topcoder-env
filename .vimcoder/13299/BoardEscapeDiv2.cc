// {{{ VimCoder 0.3.6 <-----------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// }}}

class BoardEscapeDiv2 {
 public:
  string findWinner(vector <string> s, int k) {
    const int m = s.size();
    const int n = s.front().size();

    vector<vector<bool>> cur(m, vector<bool>(n, false));
    vector<vector<bool>> next(m, vector<bool>(n, false));
    // up, down, left, right.
    const vector<int> kDirRow = {-1, 1, 0, 0};
    const vector<int> kDirCol = {0, 0, -1, 1};

    for (int round = 0; round < k; ++round) {
      for (int row = 0; row < m; ++row) {
        for (int col = 0; col < n; ++col) {
          if (s[row][col] == 'E') {
            // cannot win, skip.
            continue;
          }
          for (int dir = 0; dir < 4; ++dir) {
            auto nr = row + kDirRow[dir];
            auto nc = col + kDirCol[dir];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && s[nr][nc] != '#') {
              // find a move that next player cannot win.
              next[row][col] = next[row][col] || !cur[nr][nc];
            }
          }
        }
      }
      // move to "next" round.
      swap(cur, next);
      for (auto &line : next) {
        fill(line.begin(), line.end(), false);
      }
    }

    int tr = 0;
    int tc = 0;
    for (int row = 0; row < m; ++row) {
      for (int col = 0; col < n; ++col) {
        if (s[row][col] == 'T') {
          tr = row;
          tc = col;
          break;
        }
      }
    }

    return cur[tr][tc]? "Alice" : "Bob";
  }
};
