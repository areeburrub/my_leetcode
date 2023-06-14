#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int l1Num=0,l2Num=0;
        auto* result = new ListNode(NULL);
        auto* resultCurrentPointer = result;

        while(l1!= nullptr || l2!=nullptr || carry==1){
            l1Num=0,l2Num=0;
            if(l1!=nullptr){
                l1Num = l1->val;
                l1 = l1->next;
            }
            if(l2!=nullptr){
                l2Num = l2->val;
                l2 = l2->next;
            }

            int tempResult = l1Num+l2Num+carry;
            std::cout << tempResult <<std::endl;

            if( tempResult > 9){
                resultCurrentPointer->val = tempResult%10;
                carry = 1;
            }else{
                resultCurrentPointer->val = tempResult;
                carry = 0;
            }
            if(l1!= nullptr || l2!=nullptr || carry==1){
                auto* newNode = new ListNode(NULL);
                resultCurrentPointer->next = newNode;
                resultCurrentPointer = resultCurrentPointer->next;
            }
        }

        return result;
    }
};

int main(){
    // First Linked List: 1 -> 2 -> 3
    auto* node1 = new ListNode(9);
    auto* node2 = new ListNode(9);
    auto* node3 = new ListNode(9);

    node1->next = node2;
    node2->next = node3;

    // Second Linked List: 4 -> 5 -> 6
    auto* node4 = new ListNode(9);
    auto* node5 = new ListNode(9);

    node4->next = node5;

    auto* result  = Solution::addTwoNumbers(node1,node4);

    while (result != nullptr) {
        std::cout << result->val << " -> ";
        result = result->next;
    }

    return 0;
}