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

class MoveStones {
 public:
  long long get(vector <int> a, vector <int> b) {
    const int n = a.size();

    vector<int> diff(n, 0);
    long long diff_sum = 0;
    for (int i = 0; i < n; ++i) {
      diff[i] = b[i] - a[i];
      diff_sum += diff[i];
    }
    if (diff_sum != 0) {
      return -1;
    }

    long long count = 0;
    for (int i = 0; i < n; ++i) {
      if (diff[i] >= 0) {
        continue;
      }

      int l = i, r = i;
      int cl = 0, cr = 0;
      while (diff[i] < 0) {

        while (diff[l] <= 0) {
          l = (l - 1 + n) % n;
          ++cl;
        }
        while (diff[r] <= 0) {
          r = (r + 1) % n;
          ++cr;
        }

        int t = 0;
        long long tc = 0;
        if (cl <= cr) {
          t = l;
          tc = cl;
        } else {
          t = r;
          tc = cr;
        }

        if (diff[t] >= -diff[i]) {
          diff[t] += diff[i];
          count += tc * -diff[i]; 
          diff[i] = 0;
        } else {
          diff[i] += diff[t];
          count += tc * diff[t]; 
          diff[t] = 0;
        }
      }
    }
    return count;
  }
};
