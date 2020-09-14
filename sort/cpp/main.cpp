#include <iostream>
#include <iomanip>
#include <string.h>

#include "sort.h"

void dump(vector<int> &array) {
  bool comma = false;

  cout << "[";
  for (auto n : array) {
    if (comma) cout << ", ";
    else comma = true;
    cout << n;
  }
  cout << "]" << endl;
}

bool isSorted(vector<int> &array) {
  for (int i = 1; i < array.size(); i++) {
    if (array[i] < array[i - 1])
      return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  int n;
  vector<int> array;

  /* Read input from standard input. */
  while (cin >> n) {
    array.push_back(n);
  }

  /* Run sort algorithm */
  sort(array);

  if (argc == 2) {
    /* Verify the result of test. */
    if (strncmp("--test", argv[1], 6) == 0) {
      cout << std::left << setw(25) << argv[0] << (isSorted(array) ? " [PASS]" : " [FAIL]") << setw(50) << endl;
    }
  }

  return 0;
}
