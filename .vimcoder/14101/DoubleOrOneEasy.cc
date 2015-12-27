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

class DoubleOrOneEasy {
 public:
  int minimalSteps(int a, int b, int newA, int newB) {
    if (a > newA || b > newB) {
      return -1;
    }
    int global_cnt = INT_MAX;
    // 2^29 = 536870912 < 1,000,000,000
    // 2^30 = 1073741824 > 1,000,000,000
    for (int i = 0; i < 30; ++i) {
      long long diff_a = newA - 1LL * a * (1 << i);
      long long diff_b = newB - 1LL * b * (1 << i);
      if (diff_a != diff_b || diff_a < 0) {
        continue;
      }

      int diff = static_cast<int>(diff_a);
      int local_cnt = i;
      for (int j = i; j >= 0; --j) {
        int rj = diff / (1 << j);
        local_cnt += rj;
        diff -= rj * (1 << j);
      }

      global_cnt = min(global_cnt, local_cnt);
    }
    return global_cnt == INT_MAX? -1 : global_cnt;
  }
};
