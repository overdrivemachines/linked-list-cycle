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

// Method 1
// Iterate through the nodes
// Check if the node is in the set
// If not, add it to the set
// Runtime 24 ms Beats 11.67%
// Memory 11.2 MB Beats 8.19%
bool hasCycle1(ListNode* head) {
  ListNode* node;
  set<ListNode*> s;

  for (node = head; node != nullptr; node = node->next) {
    // does node exist in the set?
    if (s.find(node) != s.end())
      return true;

    // add the node in the set
    s.insert(node);
  }

  return false;
}

// Method 2
// move slow by one
// move fast by two
// if they both meet there is a cycle
// Runtime 7 ms Beats 95.77%
// Memory 8.2 MB Beats 48.85%
bool hasCycle(ListNode* head) {
  ListNode *slow = head, *fast;

  if ((head == nullptr) || (head->next == nullptr) || (head->next->next == nullptr))
    return false;

  fast = slow->next->next;
  while (fast != nullptr) {
    if (slow == fast) {
      cout << "slow: " << slow->val << " fast: " << fast->val << endl;
      return true;
    }

    slow = slow->next;
    if (fast->next != nullptr)
      fast = fast->next->next;
    else
      return false;
  }

  return false;
}

int main(int argc, char const* argv[]) {
  ListNode* list1 = createLinkedListWithCycle({2, 4, 5, 8}, -1);
  printLinkedList(list1, 8);
  if (hasCycle(list1))
    cout << "Has cycle" << endl;
  else
    cout << "Does not have cycle" << endl;
  return 0;
}
