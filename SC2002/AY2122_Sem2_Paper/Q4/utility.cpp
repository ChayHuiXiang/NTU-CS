#include "utility.h"

using namespace std;

ArrayList::ArrayList(int size) {
  this->size = size;
  items = (string*)malloc(sizeof(string)*size);
  for (int i = 0; i<size; i++) {
    items[i] = "";
  }
}

string ArrayList::get(int index) {
  return items[index];
}

void ArrayList::add(string s) {
  for (int i = 0; i<size; i++) {
    if (items[i] == "") {
      items[i] = s;
      return;
    }
  }
}

class Statement {
  private:
    List* words;
  public:
    Statement(int length) {
      words = new ArrayList(length);
    }

    void put(string word) {
      ArrayList* arraylistWords = dynamic_cast<ArrayList*>(words);
      arraylistWords->add(word);
    }
};

int main() {
  Statement s(3);
  s.put("fuck");
}
