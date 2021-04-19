/*
 Given a singly linked list of integers, sort it using 'Merge Sort.'
*/

#include <bits/stdc++.h>

class Node {
  public:
    int data;
  Node * next;
  Node(int data) {
    this -> data = data;
    this -> next = NULL;
  }
};

using namespace std;

Node * takeinput() {
  int data;
  cin >> data;
  Node * head = NULL, * tail = NULL;
  while (data != -1) {
    Node * newnode = new Node(data);
    if (head == NULL) {
      head = newnode;
      tail = newnode;
    } else {
      tail -> next = newnode;
      tail = newnode;
    }
    cin >> data;
  }
  return head;
}

void print(Node * head) {
  Node * temp = head;
  while (temp != NULL) {
    cout << temp -> data << " ";
    temp = temp -> next;
  }
  cout << endl;
}

Node * midPoint(Node * head) {
  if (head == NULL || head -> next == NULL) {
    return head;
  }
  Node * slow = head;
  Node * fast = head -> next;
  while (fast != NULL && fast -> next != NULL) {
    slow = slow -> next;
    fast = fast -> next -> next;
  }
  return slow;
}

Node * merge(Node * head1, Node * head2) {
  Node * headnew = NULL;
  Node * tailnew = NULL;
  if (head1 == NULL)
    return head2;
  if (head2 == NULL)
    return head1;
  if (head1 -> data < head2 -> data) {
    headnew = head1;
    tailnew = head1;
    head1 = head1 -> next;
  } else {
    headnew = head2;
    tailnew = head2;
    head2 = head2 -> next;
  }
  while (head1 != NULL && head2 != NULL) {
    if (head1 -> data < head2 -> data) {
      tailnew -> next = head1;
      tailnew = head1;
      head1 = head1 -> next;
    } else {
      tailnew -> next = head2;
      tailnew = head2;
      head2 = head2 -> next;
    }
  }
  if (head1 == NULL) {
    tailnew -> next = head2;
  } else if (head2 == NULL) {
    tailnew -> next = head1;
  }
  return headnew;
}

Node * mergeSort(Node * head) {
  if (head == NULL || head -> next == NULL)
    return head;
  //find mid element of the origial LL
  Node * mid = midPoint(head);
  Node * temp = mid -> next;
  mid -> next = NULL;
  //sort the two halves
  Node * head1 = mergeSort(head);
  Node * head2 = mergeSort(temp);
  //merge the two sorted halves
  Node * finalhead = merge(head1, head2);
  return finalhead;
}

int main() {
  Node * head = takeinput();
  head = mergeSort(head);
  print(head);
  return 0;
}

/*
Time Complexity: O(nlogn)
Space Complexity: O(logn)
where 'n' is the size of the singly linked list

Sample Input:
10 9 8 7 6 5 4 3 -1
Sample Output:
3 4 5 6 7 8 9 10 
*/
