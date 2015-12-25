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

class StripePainter {
 public:
  int minStrokes(string stripes) {
    const int n = stripes.size();
    vector<int> count(n, 0);
    count[0] = 1;
    for (int end = 1; end < n; ++end) {
      int begin = end - 1;
      int max_count = INT_MIN;
      while (begin >= 0 && stripes[begin] != stripes[end]) {
        max_count = max(max_count, count[begin]);
        --begin;
      }
      if (begin < 0 || count[begin] == max_count) {
        // first appear or conflict deteced.
        count[end] = count[end - 1] + 1;
      } else {
        // non-conflict strip.
        count[end] = count[end - 1];
      }
    }
    return count[n - 1];
  }
};
