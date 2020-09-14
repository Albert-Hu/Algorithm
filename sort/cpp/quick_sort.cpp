#include "sort.h"

#ifdef NON_RECURSIVE

#include <queue>

void sort(vector<int> &array) {
  queue<pair<int, int> > ranges;

  ranges.push(make_pair(0, array.size() - 1));
  while (ranges.size() > 0) {
    pair<int, int> r = ranges.front();
    ranges.pop();
    if (r.first < r.second) {
      int start = r.first + 1, end = r.second;
      int middle = array[r.first];
      while (start < end) {
        while (start < end && array[start] < middle) start++;
        while (start < end && middle <= array[end]) end--;
        swap(array[start], array[end]);
      }
      if (array[r.first] > array[start])
        swap(array[r.first], array[start]);
      ranges.push(make_pair(r.first, end - 1));
      ranges.push(make_pair(start, r.second));
    }
  }
}

#else

void sort(vector<int> &array, int start, int end) {
  if (start < end) {
    int middle = array[start], s = start + 1, e = end;
    while (s < e) {
      while (s < e && array[s] < middle) s++;
      while (s < e && middle <= array[e]) e--;
      swap(array[s], array[e]);
    }
    if (array[start] > array[s])
      swap(array[start], array[s]);
    sort(array, start, e - 1);
    sort(array, s, end);
  }
}

void sort(vector<int> &array) {
  sort(array, 0, array.size() - 1);
}

#endif
