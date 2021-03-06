#include "sort.h"

#ifdef NON_RECURSIVE

void heapify(vector<int> &array, int root, int end) {
  int largest = root;
  int left = root * 2 + 1;
  int right = left + 1;

  while (left < end) {
    if (right < end) {
      if (array[largest] < array[right])
        largest = right;
    }

    if (array[largest] < array[left])
      largest = left;

    if (largest == root)
      break;

    swap(array[largest], array[root]);

    root = largest;
    left = root * 2 + 1;
    right = left + 1;
  }
}

#else

void heapify(vector<int> &array, int root, int end) {
  int largest = root;
  int left = root * 2 + 1;
  int right = left + 1;

  if (left < end) {
    if (right < end) {
      if (array[largest] < array[right])
        largest = right;
    }
    if (array[largest] < array[left])
      largest = left;
  }

  if (largest != root) {
    swap(array[largest], array[root]);
    heapify(array, largest, end);
  }
}

#endif

void sort(vector<int> &array) {
  for (int i = array.size() / 2; i >= 0; i--) {
    heapify(array, i, array.size());
  }
  for (int i = array.size() - 1; i > 0; i--) {
    swap(array[0], array[i]);
    heapify(array, 0, i);
  }
}
