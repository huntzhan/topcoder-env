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

class BadNeighbors {
 public:
  int maxDonations(vector <int> donations) {
    const int n = donations.size();
    vector<int> count(n, 0);
    int max_don = INT_MIN;
    // 1. with first.
    count[0] = donations[0];
    count[1] = max(donations[0], donations[1]);
    for (int i = 2; i < n - 1; ++i) {
      count[i] = max(donations[i] + count[i - 2], count[i - 1]);
    }
    max_don = max(max_don, count[n - 2]);

    fill(count.begin(), count.end(), 0);

    // 2. without first.
    count[1] = donations[1];
    count[2] = max(donations[1], donations[2]);
    for (int i = 3; i < n; ++i) {
      count[i] = max(donations[i] + count[i - 2], count[i - 1]);
    }
    max_don = max(max_don, count[n - 1]);

    return max_don;
  }
};
