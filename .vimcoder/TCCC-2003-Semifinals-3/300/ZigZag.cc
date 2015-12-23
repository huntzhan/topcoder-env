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

class ZigZag {
 public:
  int longestZigZag(vector <int> sequence) {
    const int n = sequence.size();
    vector<int> counts(n, 1);
    vector<bool> signs(n, false);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        int diff = sequence[i] - sequence[j];
        if (diff == 0) {
          continue;
        }
        if (counts[j] == 1 || (diff > 0) ^ signs[j]) {
          if (counts[j] + 1 > counts[i]) {
            signs[i] = (sequence[i] - sequence[j] > 0);
            counts[i] = counts[j] + 1;
          }
        }
      }
    }
    int max_count = 1;
    for (const int count : counts) {
      max_count = max(max_count, count);
    }
    return max_count;
  }
};
