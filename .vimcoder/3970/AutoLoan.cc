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

class AutoLoan {
 public:

  double GetPrice(const double r, const double mp, int lt) {
    double b = 0.0;
    for (; lt > 0; --lt) {
      b = (b + mp) / (1 + r);
    }
    return b;
  }

  double interestRate(double price, double monthlyPayment, int loanTerm) {
    double lo = 0.0;
    double hi = 100.0;
    for (int i = 0; i < 100; ++i) {
      double mid = (lo + hi) / 2;
      if (GetPrice(mid, monthlyPayment, loanTerm) > price) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    return 12 * 100 * lo;
  }
};
