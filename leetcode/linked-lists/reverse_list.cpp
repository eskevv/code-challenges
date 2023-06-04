struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

auto reverse_list(ListNode *head) -> ListNode * {
  ListNode *prev = nullptr;
  while (head != nullptr) {
    ListNode *temp = head->next;
    head->next = prev;
    prev = head;
    head = temp;
  }
  return prev;
}