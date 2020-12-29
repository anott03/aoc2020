#include <vector>
#include <string>
#include <algorithm>
#include "../utils.cpp"

// std::string input = "523764819";
std::string input = "389125467";

int main() {
  int current = std::stoi(input.substr(0, 1));
  int current_idx = 0;
  std::string pickup;

  for (int _ = 0; _ < 10; ++_) {
    if (input.length() - current_idx - 1 >= 3) {
      pickup = input.substr(current_idx + 1, 3);
    } else {
      pickup = input.substr(current_idx);
      pickup += input.substr(0, 3-pickup.length());
    }
    for (char c : pickup)
      input.erase(remove(input.begin(), input.end(), c), input.end());
    
    int destination = current - 1;
    int destination_idx = input.find(std::to_string(destination));
    while (destination_idx == -1) {
      --destination;
      if (destination < 1) {
        int max = destination;
        for (char c : input) {
          max = max < std::stoi(&c) ? std::stoi(&c) : max;
        }
        destination = max;
      }
      destination_idx = input.find(std::to_string(destination));
    }

    printf("%s\n", input.c_str());
    input = input.substr(0, destination_idx + 1) + pickup + input.substr(destination_idx + 1);
    printf("%s\n", input.c_str());
    current_idx = current_idx + 1 >= input.size() ? 0 : current_idx + 1;
  }

  printf("%s\n", input.c_str());

  return 0;
}
