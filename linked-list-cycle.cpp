#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Create Linked list given a vector of int values
// returns pointer to head of lined list
ListNode* createLinkedListWithCycle(vector<int> values, int pos = -1) {
  vector<ListNode*> nodes;
  ListNode* head;
  ListNode* node = new ListNode();
  head = node;
  for (int value : values) {
    node->next = new ListNode(value);
    node = node->next;
    nodes.push_back(node);
  }
  head = head->next;

  if (pos >= 0) {
    node->next = nodes[pos];
  }

  return head;
}

// Prints Linked List
// e.g. 5->8->3->NULL
void printLinkedList(ListNode* head, int limit = -1) {
  ListNode* node = head;
  int i = 0;

  if (limit == -1) {
    for (node = head; (node != nullptr); node = node->next) {
      cout << node->val << "=>";
    }
  } else {
    for (node = head; ((node != nullptr) && (i < limit)); node = node->next, i++) {
      cout << node->val << "=>";
    }
  }

  cout << "NULL\n";
}

int main(int argc, char const* argv[]) {
  ListNode* list1 = createLinkedListWithCycle({3, 2, 0, -4}, 1);
  printLinkedList(list1, 8);
  return 0;
}
