#ifndef LIST_HPP
#define LIST_HPP

#include "oop.hpp"
#include "handle.hpp"

namespace marius {
  class GCImpl;
  class List;

  class List {
    struct Node {
      OOP val;
      Node* next;

      Node(OOP v)
        : val(v)
        , next(0)
      {}
    };

    Node* head_;
    unsigned size_;

    friend class GCImpl;
  public:

    List(State& S)
      : head_(0)
      , size_(0)
    {}

    unsigned size() {
      return size_;
    }

    Node* head() {
      return head_;
    }

    static void init(State& S, Class* list);

    static List* make(State& S, OOP* fp, int size);

    OOP get(int idx);
    void push(State& S, OOP val);
  };

  typedef TypedHandle<List, OOP::eList> HList;
}

#endif
