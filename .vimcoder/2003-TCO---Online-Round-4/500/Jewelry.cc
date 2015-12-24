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

class Jewelry {
 public:
  int Choose(int n, int k) {
    if (k * 2 > n) {
      k = n - k;
    }
    if (k == 0) {
      return 1;
    }

    int ret = n;
    for (int i = 2; i <= k; ++i) {
      ret *= (n + 1 - i);
      ret /= i;
    }
    return ret;
  }

  long long howMany(vector <int> values) {
    sort(values.begin(), values.end());
    const int n = values.size();
    const long long max_sum = accumulate(values.begin(), values.end(), 0LL);

    long long count = 0;
    int begin = 0;
    while (begin < n) {
      int end = begin + 1;
      while (end < n && values[end - 1] == values[end]) {
        ++end;
      }
      int G = end - begin;
      for (int g = 1; g <= G; ++g) {
        // construct lways[0, begin - 1] and rways[begin + g, n - 1].
        vector<long long> lways(max_sum + 1, 0);
        lways[0] = 1;
        for (int i = 0; i < begin; ++i) {
          for (auto s = max_sum; s >= values[i]; --s) {
            lways[s] += lways[s - values[i]];
          }
        }

        vector<long long> rways(max_sum + 1, 0);
        rways[0] = 1;
        for (int i = n - 1; i >= begin + g; --i) {
          for (auto s = max_sum; s >= values[i]; --s) {
            rways[s] += rways[s - values[i]];
          }
        }

        for (auto s = max_sum; s >= g * values[begin]; --s) {
          count += Choose(G, g) * lways[s - g * values[begin]] * rways[s];
        }
      }
      begin = end;
    }
    return count;
  }
};
