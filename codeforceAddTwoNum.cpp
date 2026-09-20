// во первых для удобства можно использовать уже предложенную структуру связного спика
// т.к. цифры уде лежат в обратном порядке, то можно просто складывать их и переносить остаток
// остаток carry считается при каждом проходе и реализует перенос остатка
// для разной длины чисел val1 и val2 приравнивается к 0
// в конце собираем по порядку результат 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;
        int sum = 0;

        while (l1 != nullptr || l2 != nullptr) {
            int val1 = 0;
            int val2 = 0;

            if (l1 != nullptr) {
                val1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                val2 = l2->val;
                l2 = l2->next;
            }

            sum = val1 + val2 + carry;
            carry = 0;

            if (sum >= 10) {
                carry = 1;
                sum = sum - 10;
            }

            ListNode* node = new ListNode(sum);

            if (head == nullptr) {
                head = node;
                tail = node;
            }
            else {
                tail->next = node;
                tail = node;
            }
        }

        if (carry == 1) {
            ListNode* lastNode = new ListNode(1);
            tail->next = lastNode;
        }

        return head;
    }
};