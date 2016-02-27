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

class Mortgage {
 public:

  int GetTerm(long long loan, const int interest,
              const int monthly_payment) {
    int term = 0;
    const int base = 12000;

    while (loan > 0) {
      ++term;

      loan -= monthly_payment;
      if (loan <= 0) {
        break;
      }

      long long p = loan * interest;
      if (p % base != 0) {
        p = p / base + 1;
      } else {
        p = p / base;
      }
      if (p >= monthly_payment) {
        return INT_MAX;
      }

      loan += p;
    }

    return (term + 11) / 12;
  }

  int monthlyPayment(int loan, int interest, int term) {
    int lo = 1;
    int hi = 2000000000;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (GetTerm(loan, interest, mid) <= term) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    return lo;
  }
};
