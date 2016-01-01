// {{{ VimCoder 0.3.6 <-----------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

class DiameterOfRandomTree {
 public:

  vector<vector<int>> edges_;

  void BuildTree(const int x, const int parent,
                 const vector<int> &a, const vector<int> &b) {
    const int n = a.size();
    for (int i = 0; i < n; ++i) {
      int child = -1;
      if (a[i] == x && b[i] != parent) {
        child = b[i];
      }
      if (b[i] == x && a[i] != parent) {
        child = a[i];
      }
      if (child != -1) {
        edges_[x].push_back(child);
        BuildTree(child, x, a, b);
      }
    }
  }

  // memorization of CountPaths.
  long long cache_[51][101][201];

  long long CountPaths(const int x,
                       const int ub_depth, const int ub_diameter) {
    auto &ret = cache_[x][ub_depth][ub_diameter];
    const auto &children = edges_[x];
    // stop conditions.
    if (ret != -1) {
      return ret;
    }
    if (children.empty()) {
      ret = 1;
      return ret;
    }

    ret = 0;
    for (int m = 1; m <= ub_depth && m <= ub_diameter; ++m) {
      for (int i = 0; i < children.size(); ++i) {
        for (int wi = 1; wi <= 2 && wi <= m; ++wi) {
          // count the number of path rooted by children[i] with depth m.
          auto count_i = CountPaths(children[i], m - wi, ub_diameter);
          if (m - wi > 0) {
            count_i -= CountPaths(children[i], m - wi - 1, ub_diameter);
          }

          // count the number of ways with fixed i.
          for (int j = 0; j < children.size(); ++j) {
            if (i == j) {
              continue;
            }
            int j_ub_depth = i < j? m - 1 : m;
            j_ub_depth = min(j_ub_depth, ub_diameter - m);

            long long count_j = 0;
            for (int wj = 1; wj <= 2 && wj <= j_ub_depth; ++wj) {
              count_j += CountPaths(children[j], j_ub_depth - wj, ub_diameter);
            }
            // production.
            count_i *= count_j;
          }
          ret += count_i;
        }
      }
    }
    return ret;
  }

  double getExpectation(vector <int> a, vector <int> b) {
    const int n = a.size();

    edges_ = vector<vector<int>>(n + 1);
    memset(cache_, -1, sizeof(cache_));

    BuildTree(0, -1, a, b);

    double ret = 0.0;
    long long pre = 0;
    for (int d = 1; d <= 100; ++d) {
      auto cur = CountPaths(0, 100, d);
      ret += d * (cur - pre) / static_cast<double>(1LL << n);
      pre = cur;
    }
    return ret;
  }
};
