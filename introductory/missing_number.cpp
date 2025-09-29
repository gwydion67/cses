#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
  long long int n;
  long long int num;
  std::cin >> n;

  long long int sum = 0;
  for (int i = 0; i < n - 1; i++) {
    std::cin >> num;
    sum += num;
  }

  num = n * (n + 1) / 2 - sum;
  std::cout << num << std::endl;
  return 0;
}
