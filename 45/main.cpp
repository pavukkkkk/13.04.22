#include <iostream>

using namespace std;

template <typename T>
class List
{
  struct Node
  {
    T inf;
    Node* next;
    Node(T x, Node* ref = nullptr) : inf(x), next(ref) {}
  } *first = nullptr, *last = nullptr;
public:
  void add(T x)
  {
    Node *item = new Node(x);
    if (last != nullptr)
      last->next = item;
    last = item;
    if (first == nullptr)
      first = last;
  }
  void print()
  {
    for (Node* tmp = first; tmp != nullptr; tmp = tmp->next)
    {
      cout << tmp->inf << " ";
    }
    cout << '\n';
  }

  void doubleX(T x)
  {
    for (Node* tmp = first; tmp != nullptr; tmp = tmp->next)
    {
      if (tmp->inf == x)
      {
        Node* newItem = new Node(x, tmp->next);
        tmp->next = newItem;
        if (tmp == last)
          last = tmp->next;
        tmp = tmp->next;
      }
    }
  
  }
    void del(T x){
        Node* in=nullptr;
        for (Node* tmp = first; tmp != nullptr; tmp = tmp->next)
        {
            if (tmp->inf ==x){
                in = tmp;
                break;
            }
        }
        if (in !=nullptr)
        del1(first,x);
        first=in;
    }
    void del1(Node* cur, T x) {

               if (cur->inf != x) {
                   Node* i = cur->next;
                   
                   delete cur;
                   del1(i, x);
               }
    }
    List sorting( T x){
        List<T> l2;
        for (Node* tmp = first; tmp != nullptr; tmp = tmp->next)
        {
            l2.add(tmp->inf);
            if (tmp->inf==x){
                tmp=tmp->next;
            }
        }
        return l2;
    }
};

int main() {
   
  List<int> lst;
    lst.add(4);
  lst.add(5);
    lst.add(2);
  lst.add(0);
    lst.add(3);
    lst.add(2);
  lst.print();
  lst.doubleX(0);
  lst.print();
  lst.add(10);
    lst.print();
    lst.add(1);
    List<int> lst2 = lst.sorting(2);
   
  
  lst.print();
    lst2.print();
  return 0;
}
