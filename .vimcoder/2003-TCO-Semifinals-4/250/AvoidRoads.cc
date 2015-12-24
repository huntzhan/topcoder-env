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

class AvoidRoads {
 public:
  long long numWays(int width, int height, vector <string> bad) {
    // transform bad.
    vector<vector<bool>> blocked(width + 1, vector<bool>(height + 1, false));
    for (const auto &line : bad) {
      istringstream strm(line);
      int x = 0;
      int y = 0;
      // first point.
      strm >> x >> y;
      blocked[x][y] = true;
      // second point.
      strm >> x >> y;
      blocked[x][y] = true;
    }

    // dp.
    vector<vector<long long>> dp(width + 1, vector<long long>(height + 1, 0));
    dp[0][0] = 1;
    for (int row = 0; row <= width; ++row) {
      for (int col = 0; col <= height; ++col) {
        // on left.
        if (col > 0 && !(blocked[row][col - 1] && blocked[row][col])) {
          dp[row][col] += dp[row][col - 1];
        }
        // on top.
        if (row > 0 && !(blocked[row - 1][col] && blocked[row][col])) {
          dp[row][col] += dp[row - 1][col];
        }
      }
    }

    return dp[width][height];
  }
};
