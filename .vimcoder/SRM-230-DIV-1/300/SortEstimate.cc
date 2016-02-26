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

class SortEstimate {
 public:
  double howMany(int c, int time) {
    double lo = 0.0;
    double hi = 2000000000;
    for (int i = 0; i < 100; ++i) {
      double mid = lo + (hi - lo) / 2;
      if (c * mid * log2(mid) > time) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
    return lo;
  }
};
