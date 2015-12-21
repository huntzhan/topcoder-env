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

class RailroadSwitchOperator {
 public:
  int minEnergy(int N, vector <int> x, vector <int> t) {
    const int n = x.size();
    int level = log2(N);
    int internal_size = pow(2, level) - 1;

    // change times of internal nodes.
    // i.e. changes[0] -> [0, 4, 7], t0 = right, t4 = left, t7 = right.
    vector<queue<int>> changes(internal_size);
    vector<int> pres(internal_size, INT_MIN);

    // fill with state of changes.
    for (int i = 0; i < n; ++i) {
      int node = internal_size + x[i] - 1;
      int time = t[i] + level - 1;
      while (node > 0) {
        int parent = (node - 1) / 2;
        bool is_left = (node == 2 * parent + 1);
        if (is_left && changes[parent].empty()) {
          pres[parent] = time;
        }
        if (is_left != (changes[parent].size() % 2 == 0)) {
          // state of change.
          changes[parent].push(time);
        }
        node = parent;
        --time;
      }
    }

    // greedy.
    int count = 0;
    while (true) {
      int min_begin = INT_MAX;
      for (int i = 0; i < internal_size; ++i) {
        if (changes[i].empty()) {
          continue;
        }
        min_begin = min(min_begin, changes[i].front());
      }
      if (min_begin == INT_MAX) {
        break;
      }
      for (int i = 0; i < internal_size; ++i) {
        if (!changes[i].empty() && pres[i] < min_begin) {
          pres[i] = changes[i].front();
          changes[i].pop();
        }
      }
      ++count;
    }
    return count;
  }
};
