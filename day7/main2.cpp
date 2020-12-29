#include <vector>
#include <string>
#include "../utils.cpp"
#include <map>

struct BNode {
  bool counted = false;
  std::string color;
  std::vector<BNode> children;
  BNode(std::string _color): color{_color} {}
};

std::vector<std::string> input;
// std::map<std::string, BNode*> forest = {};
std::vector<BNode*> forest = {};
int totalCount = 0;

BNode* getNode(std::string name) {
  for (auto node : forest) {
    if (node->color == name) return node;
  }
  BNode *node = new BNode(name);
  forest.emplace_back(node);
  return node;
}

void count(std::vector<BNode*> nodes) {
  for (auto node : nodes) {
    if (!node->counted) {
      ++totalCount;
    }
    node->counted = true;
  }
}

void findGold(BNode* node, std::vector<BNode*> nodes) {
  if (node->color == "shiny gold") {
    count(nodes);
    return;
  }

  nodes.emplace_back(node);
  for (auto n : node->children) {
    findGold(&n, nodes);
  }
  nodes.erase(nodes.end()-1);
}

int main() {
  input = getInput("./input.prod");

  for (auto line: input) {
    std::string color = line.substr(0, line.find("bag"));
    BNode *node = getNode(color);

    if (line.find("no other bags") != -1) continue;

    std::vector<std::string> parts = split(line.substr(line.find("contain") + 8), ',');

    for (auto _line : parts) {
      std::vector<std::string> _lineParts = split(_line.substr(2, _line.find("bag")), ' ');
      std::string _color = _lineParts[0];
      if (_lineParts.size() >= 2) _color += " " + _lineParts[1];
      node->children.emplace_back(*getNode(_color));
    }
  }

  for (auto node: forest) {
    // printf("%s\n", node->color.c_str());
    // for (auto _node: node->children) {
      // printf("sub %s\n", _node.color.c_str());
    // }
    std::vector<BNode*> l = {};
    findGold(node, l);
  }
  printf("PART 1 %d\n", totalCount);
}
