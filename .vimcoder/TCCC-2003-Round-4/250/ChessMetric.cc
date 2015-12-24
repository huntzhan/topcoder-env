// {{{ VimCoder 0.3.6 <-----------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <climits>
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

class ChessMetric {
 public:
  long long howMany(int size,
                    vector<int> start, vector<int> end, int numMoves) {
    vector<vector<long long>> pre(size, vector<long long>(size, 0));
    auto cur = pre;
    pre[start[0]][start[1]] = 1;

    const vector<pair<int, int>> kDirs = {
      // one spaces.
      {-1, -1},
      {-1, 0},
      {-1, 1},
      {0, -1},
      {0, 1},
      {1, -1},
      {1, 0},
      {1, 1},
      // "L" shape.
      {-1, -2},
      {-1, 2},
      {1, -2},
      {1, 2},
      {-2, -1},
      {-2, 1},
      {2, -1},
      {2, 1},
    };

    // dp: construct cur from pre.
    for (int i = 0; i < numMoves; ++i) {
      for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
          for (const auto &dir : kDirs) {
            int pr = row + dir.first;
            int pc = col + dir.second;
            if (pr < 0 || pr >= size || pc < 0 || pc >= size) {
              continue;
            }
            cur[row][col] += pre[pr][pc];
          }
        }
      }
      // move to next state.
      swap(cur, pre);
      for (auto &line : cur) {
        fill(line.begin(), line.end(), 0);
      }
    }

    return pre[end[0]][end[1]];
  }
};
