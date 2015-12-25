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

class QuickSums {
 public:
  int minSums(string numbers, int sum) {
    const int n = numbers.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, INT_MAX));
    for (int end = 0; end < n; ++end) {
      for (int begin = end; begin >= 0; --begin) {
        int num = stoi(numbers.substr(begin, end - begin + 1));
        if (num > sum) {
          break;
        }
        if (begin == 0) {
          dp[end][num] = 0;
          break;
        }
        for (int s = num; s <= sum; ++s) {
          if (dp[begin - 1][s - num] != INT_MAX) {
            dp[end][s] = min(dp[end][s], dp[begin - 1][s - num] + 1);
          }
        }
      }
    }
    return dp[n - 1][sum] == INT_MAX? -1 : dp[n - 1][sum];
  }
};
