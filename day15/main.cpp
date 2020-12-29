#include <vector>
#include <string>
#include "../utils.cpp"
#include <map>

std::vector<int> starting = { 14, 8, 16, 0, 1, 17 };

int findMove(int move) {
  std::map<int, int> spokenNums = {{14, 0}, {8, 1}, {16, 2},
    {0, 3}, {1, 4}, {17, 5}};
  int n = 0;
  for (int i = starting.size(); i <= move - 2; ++i) {
    if (spokenNums.find(n) != spokenNums.end()) {
      int age = spokenNums[n];
      spokenNums[n] = i;
      n = i - age;
    } else {
      spokenNums[n] = i;
      n = 0;
    }
  }
  return n;
}

int main() {
  printf("PART 1 %d\nPART 2 %d\n", findMove(2020), findMove(30000000));
  return 0;
}
