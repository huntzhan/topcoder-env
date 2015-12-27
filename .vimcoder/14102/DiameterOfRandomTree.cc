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

class DiameterOfRandomTree {
 public:
  // pairs of (length, possibility).
  unordered_map<int, double> GetExpectedValueOfPath(
      const int parent,
      const vector<vector<int>> &children) {
    if (children[parent].empty()) {
      return {make_pair(0, 1.0)};
    }
    unordered_map<int, double> length_possibility;
    for (const int child : children[parent]) {
      for (const auto &lp_pair : GetExpectedValueOfPath(child, children)) {
        length_possibility[lp_pair.first + 1] += lp_pair.second;
        length_possibility[lp_pair.first + 2] += lp_pair.second;
      }
    }
    return length_possibility;
  }

  double getExpectation(vector <int> a, vector <int> b) {
    const int n = a.size() + 1;
    vector<vector<int>> children(n);
    for (int i = 0; i < n - 1; ++i) {
      int p = a[i];
      int c = b[i];
      if (p > c) {
        swap(p, c);
      }
      children[p].push_back(c);
    }

  }
};
