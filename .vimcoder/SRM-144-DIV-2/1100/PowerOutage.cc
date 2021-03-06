
// {{{ VimCoder 0.3.6 <-----------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
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
#include <utility>
#include <vector>

using namespace std;

// }}}

class PowerOutage
{
public:

  int Cost(const int duct,
           const vector<vector<int>> &edges,
           const vector<int> &ductLength) {
    int sum_of_costs = 0;
    for (int next : edges[duct]) {
      sum_of_costs += 2 * ductLength[duct] + Cost(next, edges, ductLength);
    }
    return sum_of_costs;
  }

  int LongestPath(const int duct,
                  const vector<vector<int>> &edges,
                  const vector<int> &ductLength) {
    int longest_path = 0;
    for (int next : edges[duct]) {
      longest_path = max(
          longest_path,
          ductLength[duct] + LongestPath(next, edges, ductLength));
    }
    return longest_path;
  }

	int estimateTimeOut(vector<int> fromJunction, vector<int> toJunction,
                      vector<int> ductLength) {
    const int n = ductLength.size();
    vector<vector<int>> edges(n + 1);
    for (int i = 0; i < n; ++i) {
      edges[fromJunction[i]].push_back(toJunction[i]);
    }
    return Cost(0, edges, ductLength) - LongestPath(0, edges, ductLength);
	}
};

