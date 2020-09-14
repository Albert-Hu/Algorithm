#include "sort.h"

void merge(vector<int>::iterator target, vector<int> &a, vector<int> &b) {
  int a_index = 0, b_index = 0;

  while (a_index < a.size() && b_index < b.size()) {
    if (a[a_index] < b[b_index]) {
      *target++ = a[a_index++];
    } else {
      *target++ = b[b_index++];
    }
  }

  while (a_index < a.size()) {
    *target++ = a[a_index++];
  }

  while (b_index < b.size()) {
    *target++ = b[b_index++];
  }
}

#ifdef NON_RECURSIVE

void sort(vector<int> &array) {
  int length = array.size();
  int amount = 1;

  while (amount < length) {
    for (int next = 0; next < length; next += amount * 2) {
      int left_start = next;
      int left_end = min(left_start + amount, length);
      vector<int> left(array.begin() + left_start, array.begin() + left_end);
      if (left_end < length) {
        int right_start = left_end;
        int right_end = min(right_start + amount, length);
        vector<int> right(array.begin() + right_start, array.begin() + right_end);
        merge(array.begin() + left_start, left, right);
      } else {
        int merged_start = left_start - amount * 2;
        int merged_end = left_start;
        vector<int> merged(array.begin() + merged_start, array.begin() + merged_end);
        merge(array.begin() + merged_start, left, merged);
      }
    }
    amount *= 2;
  }
}

#else

void sort(vector<int> &array) {
  if (array.size() > 1) {
    int size = array.size() / 2;
    vector<int> left(array.begin(), array.begin() + size);
    vector<int> right(array.begin() + size, array.end());
    sort(left);
    sort(right);
    merge(array.begin(), left, right);
  }
}

#endif
