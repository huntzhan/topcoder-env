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

class UnionOfIntervals {
 public:

  long long CountPos(const vector<int> &lowerBound,
                     const vector<int> &upperBound,
                     const int value) {
    const int n = lowerBound.size();
    long long pos = 0;
    for (int i = 0; i < n; ++i) {
      if (value < lowerBound[i]) {
        continue;
      }
      if (upperBound[i] < value) {
        pos += 1LL + upperBound[i] - lowerBound[i];
      } else {
        // value in range [lo, hi].
        pos += 0LL + value - lowerBound[i];
      }
    }
    return pos;
  }

  int nthElement(vector <int> lowerBound, vector <int> upperBound, int n) {
    long long lo = -2000000000;
    long long hi = 2000000000;
    while (lo < hi) {
      long long mid = lo + (hi - lo + 1) / 2;
      if (CountPos(lowerBound, upperBound, mid) <= n) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    return lo;
  }
};
