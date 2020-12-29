#include <vector>
#include <string>
#include "../utils.cpp"
#include <map>

std::vector<std::string> input;
int totalCount = 0;
std::string target = "shiny gold";

struct BNode {
  bool counted = false;
  std::string color;
  std::vector<BNode> children;
  BNode(std::string _color): color{_color} {}
};

std::map<std::string, BNode*> forest;

BNode getNode(std::string name) {
  if (forest.find(name) == forest.end()) {
    forest.insert(std::make_pair(name, new BNode(name)));
  }
  return *forest[name];
}

void count(std::vector<BNode> l) {
  for (int i = 0; i < l.size(); ++i) {
    if (!l[i].counted) {
      totalCount++;
    }
    l[i].counted = true;
  }
}

void findGold(BNode n, std::vector<BNode> l) {
  if (n.color == target) {
    count(l);
  } else {
    l.emplace_back(n);
    for (int i = 0; i < n.children.size(); ++i) {
      findGold(n.children[i], l);
    }
    l.erase(l.end()-1);
  }
}

int main() {
  input = getInput("./input.prod");
  printf("%d\n", (int) input.size());

  for (int i = 0; i < input.size(); ++i) {
    std::string line = input[i];
    std::vector<std::string> lineComponents = split(line, ' ');

    if (lineComponents.size() == 0) continue;

    std::string name = "";
    for (int j = 0; j < 2; j++) {
      name += lineComponents[j];
    }

    BNode node = getNode(name);

    if (line.find("no other bags") == -1) continue;

    std::vector<std::string> tmp = lineComponents;
    lineComponents = {};
    for (int j = 4; j < tmp.size(); ++j) lineComponents.emplace_back(tmp[j]);

    do {
      std::string bag = "";
      for (int j = 1; j < 3; ++j) bag += lineComponents[j] + " ";
      bag = bag.substr(0, bag.length()-1);

      std::vector<std::string> tmp = lineComponents;
      lineComponents = {};
      for (int j = 4; j < tmp.size(); ++j) lineComponents.emplace_back(tmp[j]);

      node.children.emplace_back(getNode(bag));
    } while (lineComponents.size() >= 4);
  }

  std::map<std::string, BNode*>::iterator it = forest.begin();
  while (it != forest.end()) {
    std::vector<BNode> l = {};
    findGold(*forest[it->first], l);
    it++;
  }

  printf("%d\n", totalCount);

  return 0;
}
