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

class FiringEmployees {
 public:

  int fire(vector <int> manager, vector <int> salary, vector <int> productivity) {
    const int N = manager.size();
    vector<int> total_profits(N + 1, 0);
    for (int i = N - 1; i >= 0; --i) {
      total_profits[i + 1] += productivity[i] - salary[i];
      if (total_profits[i + 1] > 0) {
        total_profits[manager[i]] += total_profits[i + 1];
      }
    }
    return total_profits[0];
  }
};
