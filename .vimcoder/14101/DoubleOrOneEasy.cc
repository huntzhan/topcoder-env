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

// TLE, with complexity O(n)
// 499999999
// 1
// 500000000
// 500000000
// 999999999
class DoubleOrOneEasy {
 public:
  int minimalSteps(int a, int b, int newA, int newB) {
    int kMaxA = newA / 2;
    int kMaxB = newB / 2;

    vector<pair<int, int>> cur, next;
    cur.push_back(make_pair(a, b));
    int count = 0;
    while (!cur.empty()) {
      for (const auto &pair : cur) {
        int cur_a = pair.first;
        int cur_b = pair.second;
        if (cur_a == newA && cur_b == newB) {
          return count;
        }
        // blue.
        if (cur_a < newA && cur_b < newB) {
          next.push_back(make_pair(cur_a + 1, cur_b + 1));
        }
        // red.
        if (cur_a <= kMaxA && cur_b <= kMaxB) {
          next.push_back(make_pair(2 * cur_a, 2 * cur_b));
        }
      }
      // move to next level.
      ++count;
      swap(cur, next);
      next.clear();
    }
    return -1;
  }
};
