#define CATCH_CONFIG_MAIN
#include "../linkedlist.h"

#include "../vendor/catch.hpp"

TEST_CASE("List inserts Node at head element of list.", "[Push Front]") {
  LinkedList<int, int> list;

  list.PushFront(12, 12);

  REQUIRE(list.Size() == 1);

  REQUIRE(list.Head()->value == 12);
  REQUIRE(list.Head()->previous == nullptr);
  REQUIRE(list.Head()->next == nullptr);

  list.PushFront(12, 114);

  REQUIRE(list.Size() == 2);

  REQUIRE(list.Head()->value == 114);
  REQUIRE(list.Head()->previous == nullptr);
  REQUIRE(list.Head()->next->value == 12);

  list.PushFront(12, 32);

  REQUIRE(list.Size() == 3);

  REQUIRE(list.Head()->value == 32);
  REQUIRE(list.Head()->previous == nullptr);
  REQUIRE(list.Head()->next->value == 114);
}

TEST_CASE("List inserts Node at tail element of list.", "[Push Back]") {
  LinkedList<int, int> list;

  list.PushBack(12, 12);

  REQUIRE(list.Size() == 1);

  REQUIRE(list.Tail()->value == 12);
  REQUIRE(list.Tail()->previous == nullptr);
  REQUIRE(list.Tail()->next == nullptr);

  list.PushBack(12, 114);

  REQUIRE(list.Size() == 2);

  REQUIRE(list.Tail()->value == 114);
  REQUIRE(list.Tail()->previous->value == 12);
  REQUIRE(list.Tail()->next == nullptr);

  list.PushBack(12, 32);

  REQUIRE(list.Size() == 3);

  REQUIRE(list.Tail()->value == 32);
  REQUIRE(list.Tail()->previous->value == 114);
  REQUIRE(list.Tail()->next == nullptr);
}

TEST_CASE("Returns the length of the list.", "[Length]") {
  LinkedList<int, int> list;

  REQUIRE(list.Length() == 0);
  list.PushFront(12, 12);
  REQUIRE(list.Length() == 1);
  list.PushFront(12, 114);
  REQUIRE(list.Length() == 2);
  list.PushFront(12, 15);
  REQUIRE(list.Length() == 3);
  list.PushFront(12, 17);
  REQUIRE(list.Length() == 4);
  list.PopFront();
  REQUIRE(list.Length() == 3);
  list.PopBack();
  REQUIRE(list.Length() == 2);
}

TEST_CASE("Size returns the length of the list.", "[Size]") {
  LinkedList<int, int> list;

  REQUIRE(list.Size() == 0);
  list.PushFront(12, 12);
  REQUIRE(list.Size() == 1);
  list.PushFront(12, 114);
  REQUIRE(list.Size() == 2);
  list.PushFront(12, 15);
  REQUIRE(list.Size() == 3);
  list.PushFront(12, 17);
  REQUIRE(list.Size() == 4);
  list.PopFront();
  REQUIRE(list.Size() == 3);
  list.PopBack();
  REQUIRE(list.Size() == 2);
}

TEST_CASE("Appends Many Nodes to the Start Of The List",
          "[Insert Many At Start]") {
  LinkedList<int, int> list;

  list.PushFront(1, 1);
  list.PushFront(1, 5);
  list.PushFront(1, 6);
  list.PushFront(1, 2);

  REQUIRE(list.Size() == 4);

  REQUIRE(list.At(0)->value == 2);
  REQUIRE(list.At(1)->value == 6);
  REQUIRE(list.At(2)->value == 5);
  REQUIRE(list.At(3)->value == 1);

  list.PushFront(1, 4);
  list.PushFront(1, 2);
  list.PushFront(1, 5);
  list.PushFront(1, 7);

  REQUIRE(list.Size() == 8);

  REQUIRE(list.At(0)->value == 7);
  REQUIRE(list.At(1)->value == 5);
  REQUIRE(list.At(2)->value == 2);
  REQUIRE(list.At(3)->value == 4);
  REQUIRE(list.At(4)->value == 2);
  REQUIRE(list.At(5)->value == 6);
  REQUIRE(list.At(6)->value == 5);
  REQUIRE(list.At(7)->value == 1);
}

TEST_CASE("Appends Many Nodes to the End Of The List", "[Insert Many At End]") {
  LinkedList<int, int> list;

  list.PushBack(1, 1);
  list.PushBack(1, 5);
  list.PushBack(1, 6);
  list.PushBack(1, 2);

  REQUIRE(list.Size() == 4);

  REQUIRE(list.At(0)->value == 1);
  REQUIRE(list.At(1)->value == 5);
  REQUIRE(list.At(2)->value == 6);
  REQUIRE(list.At(3)->value == 2);

  list.PushBack(1, 4);
  list.PushBack(1, 2);
  list.PushBack(1, 5);
  list.PushBack(1, 7);

  REQUIRE(list.Size() == 8);

  REQUIRE(list.At(0)->value == 1);
  REQUIRE(list.At(1)->value == 5);
  REQUIRE(list.At(2)->value == 6);
  REQUIRE(list.At(3)->value == 2);
  REQUIRE(list.At(4)->value == 4);
  REQUIRE(list.At(5)->value == 2);
  REQUIRE(list.At(6)->value == 5);
  REQUIRE(list.At(7)->value == 7);
}

TEST_CASE(
    "Returns True or false depending on whether or not the element is present "
    "within the Linked List",
    "[Contains]") {
  LinkedList<int, int> list;

  list.PushFront(4, 1);
  list.PushFront(5, 2);
  list.PushFront(1, 3);
  list.PushFront(2, 4);
  list.PushFront(11, 5);

  bool containsOne = list.Contains(4);
  bool containsTwo = list.Contains(5);
  bool containsThree = list.Contains(1);
  bool containsFour = list.Contains(2);
  bool containsFive = list.Contains(11);

  bool containsTwelve = list.Contains(12);
  bool containsTwenty = list.Contains(20);
  bool containsSix = list.Contains(6);

  REQUIRE(containsOne == true);
  REQUIRE(containsTwo == true);
  REQUIRE(containsThree == true);
  REQUIRE(containsFour == true);
  REQUIRE(containsFive == true);

  REQUIRE(containsTwelve == false);
  REQUIRE(containsTwenty == false);
  REQUIRE(containsSix == false);
}

TEST_CASE("Returns the first Node of the Linked List", "[Head]") {
  LinkedList<int, int> list;

  list.PushFront(1, 1);
  list.PushFront(1, 2);
  list.PushFront(1, 3);
  list.PushFront(1, 4);
  list.PushFront(1, 5);
  list.PushFront(1, 6);

  REQUIRE(list.Head()->value == 6);

  list.PushBack(12, 5);

  REQUIRE(list.Head()->value == 6);

  list.PushFront(12, 11);

  REQUIRE(list.Head()->value == 11);
}

TEST_CASE("Returns the last Node of the Linked List", "[Tail]") {
  LinkedList<int, int> list;

  list.PushFront(1, 1);
  list.PushFront(1, 2);
  list.PushFront(1, 3);
  list.PushFront(1, 4);
  list.PushFront(1, 5);
  list.PushFront(1, 6);

  REQUIRE(list.Tail()->value == 1);

  list.PushBack(12, 5);

  REQUIRE(list.Tail()->value == 5);

  list.PushFront(12, 11);

  REQUIRE(list.Tail()->value == 5);

  list.PushBack(12, 14);

  REQUIRE(list.Tail()->value == 14);
}

TEST_CASE("Empties the Linked List", "[Clear]") {
  LinkedList<int, int> list;

  list.PushFront(1, 1);
  list.PushFront(1, 2);
  list.PushFront(1, 3);
  list.PushFront(1, 4);
  list.PushFront(1, 5);
  list.PushFront(1, 6);

  REQUIRE(list.Size() == 6);

  list.Clear();

  REQUIRE(list.Size() == 0);
}

TEST_CASE("Removes the Head Node", "[Remove Head]") {
  SECTION("Removes the Head Node when the List has a size of one") {
    LinkedList<int, int> list;

    list.PushFront(12, 1);

    REQUIRE(list.Size() == 1);
    REQUIRE(list.Head()->value == 1);

    list.PopFront();

    REQUIRE(list.Size() == 0);
    REQUIRE(list.Head() == nullptr);

    list.PushFront(12, 4);
    list.PushFront(12, 3);
    list.PushBack(12, 8);

    REQUIRE(list.Size() == 3);
    REQUIRE(list.Head()->value == 3);

    list.PopFront();

    REQUIRE(list.Head()->value == 4);
  }

  SECTION("Removes the Head Node when the List has a size of three") {
    LinkedList<int, int> list;

    list.PushFront(12, 2);
    list.PushFront(12, 4);
    list.PushFront(12, 3);

    REQUIRE(list.Size() == 3);

    list.PopFront();

    REQUIRE(list.Head()->value == 4);

    list.PopFront();

    REQUIRE(list.Head()->value == 2);
  }
}

TEST_CASE("Removes the Last Node", "[Remove Last]") {
  SECTION("Remove Last does not throw an error when the list is empty.") {
    LinkedList<int, int> list;

    REQUIRE_NOTHROW(list.PopBack());
  }

  SECTION("Remove Last removes the last node when the list is of length 1.") {
    LinkedList<int, int> list;

    list.PushFront(12, 8);
    list.PopBack();

    REQUIRE(list.Head() == nullptr);
  }

  SECTION("Remove Last removes the last node when the list is of length 2.") {
    LinkedList<int, int> list;

    list.PushFront(12, 4);
    list.PushFront(12, 12);
    list.PopBack();

    REQUIRE(list.Tail()->value == 12);
  }

  SECTION("Remove Last removes the last node when the list is of length 3.") {
    LinkedList<int, int> list;

    list.PushFront(12, 3);
    list.PushFront(12, 4);
    list.PushFront(12, 8);
    list.PopBack();

    REQUIRE(list.Tail()->value == 4);
  }
}

TEST_CASE("Returns the node at the given Index", "[Get At]") {
  SECTION("Returns the node at the given index.") {
    LinkedList<int, int> list;

    list.PushFront(12, 1);
    list.PushFront(12, 4);
    list.PushFront(12, 8);
    list.PushFront(12, 2);

    REQUIRE(list.At(0)->value == 2);
    REQUIRE(list.At(1)->value == 8);
    REQUIRE(list.At(2)->value == 4);
    REQUIRE(list.At(3)->value == 1);
  }

  SECTION("Returns nullptr is the index is less than zero.") {
    LinkedList<int, int> list;

    list.PushFront(12, 1);
    list.PushFront(12, 4);
    list.PushFront(12, 8);
    list.PushFront(12, 2);

    REQUIRE(list.At(-2) == nullptr);
    REQUIRE(list.At(-24) == nullptr);
    REQUIRE(list.At(-23) == nullptr);
    REQUIRE(list.At(-123) == nullptr);
  }

  SECTION("Returns nullptr is the index is greater then N-1.") {
    LinkedList<int, int> list;

    list.PushFront(12, 1);
    list.PushFront(12, 4);
    list.PushFront(12, 8);
    list.PushFront(12, 2);

    REQUIRE(list.At(424) == nullptr);
    REQUIRE(list.At(24) == nullptr);
    REQUIRE(list.At(23) == nullptr);
    REQUIRE(list.At(123) == nullptr);
  }
}

TEST_CASE("Works as an alias for Get At", "[At]") {
  SECTION("Returns the node at the given index.") {
    LinkedList<int, int> list;

    list.PushFront(12, 1);
    list.PushFront(12, 4);
    list.PushFront(12, 8);
    list.PushFront(12, 2);

    REQUIRE(list.At(0)->value == 2);
    REQUIRE(list.At(1)->value == 8);
    REQUIRE(list.At(2)->value == 4);
    REQUIRE(list.At(3)->value == 1);
  }

  SECTION("Returns nullptr is the index is less than zero.") {
    LinkedList<int, int> list;

    list.PushFront(12, 1);
    list.PushFront(12, 4);
    list.PushFront(12, 8);
    list.PushFront(12, 2);

    REQUIRE(list.At(-2) == nullptr);
    REQUIRE(list.At(-24) == nullptr);
    REQUIRE(list.At(-23) == nullptr);
    REQUIRE(list.At(-123) == nullptr);
  }

  SECTION("Returns nullptr is the index is greater then N-1.") {
    LinkedList<int, int> list;

    list.PushFront(12, 1);
    list.PushFront(12, 4);
    list.PushFront(12, 8);
    list.PushFront(12, 2);

    REQUIRE(list.At(424) == nullptr);
    REQUIRE(list.At(24) == nullptr);
    REQUIRE(list.At(23) == nullptr);
    REQUIRE(list.At(123) == nullptr);
  }
}

TEST_CASE("Removes the node at the specified Index.", "[Remove At]") {
  SECTION("Remove At does not crash on an empty list") {
    LinkedList<int, int> list;

    REQUIRE_NOTHROW(list.PopAt(2));
  }

  SECTION("Remove At does not crash on an out of bounds index.") {
    LinkedList<int, int> list;

    list.PushFront(12, 2);

    REQUIRE_NOTHROW(list.PopAt(5));
  }

  SECTION("Remove At deletes the first node.") {
    LinkedList<int, int> list;

    list.PushBack(12, 1);
    list.PushBack(12, 2);
    list.PushBack(12, 3);
    list.PushBack(12, 4);

    REQUIRE(list.At(0)->value == 1);

    list.PopAt(0);

    REQUIRE(list.At(0)->value == 2);
  }

  SECTION("Remove At deletes the node at the specified index.") {
    LinkedList<int, int> list;

    list.PushBack(12, 1);
    list.PushBack(12, 2);
    list.PushBack(12, 3);
    list.PushBack(12, 4);

    REQUIRE(list.At(1)->value == 2);

    list.PopAt(1);

    REQUIRE(list.At(1)->value == 3);
  }

  SECTION("Remove At deletes the last node of the linked list.") {
    LinkedList<int, int> list;

    list.PushBack(12, 1);
    list.PushBack(12, 2);
    list.PushBack(12, 3);
    list.PushBack(12, 4);

    REQUIRE(list.At(3)->value == 4);

    list.PopAt(3);

    REQUIRE(list.Tail()->value == 3);
  }
}

TEST_CASE("Inserts a New Node at the Specified Index.", "[Insert At]") {
  SECTION(
      "Inserts a new node with value at the 0 index when the list is empty.") {
    LinkedList<int, int> list;

    list.PushAt(1, 5, 0);

    REQUIRE(list.Head()->value == 5);
  }

  SECTION(
      "Inserts a new node with value at the 0 index when the list has "
      "elements.") {
    LinkedList<int, int> list;

    list.PushFront(12, 2);
    list.PushFront(12, 4);
    list.PushFront(12, 7);

    list.PushAt(1, 5, 0);

    REQUIRE(list.At(0)->value == 5);
    REQUIRE(list.At(1)->value == 7);
    REQUIRE(list.At(2)->value == 4);
    REQUIRE(list.At(3)->value == 2);
  }

  SECTION("Inserts a new node at the middle index of the list.") {
    LinkedList<int, int> list;

    list.PushBack(12, 2);
    list.PushBack(12, 7);
    list.PushBack(12, 3);
    list.PushBack(12, 4);

    list.PushAt(1, 9, 2);

    REQUIRE(list.At(0)->value == 2);
    REQUIRE(list.At(1)->value == 7);
    REQUIRE(list.At(2)->value == 9);
    REQUIRE(list.At(3)->value == 3);
    REQUIRE(list.At(4)->value == 4);
  }

  SECTION("Inserts a new node with value at the last index.") {
    LinkedList<int, int> list;

    list.PushBack(12, 2);
    list.PushBack(12, 7);

    list.PushAt(1, 3, 2);

    REQUIRE(list.At(0)->value == 2);
    REQUIRE(list.At(1)->value == 7);
    REQUIRE(list.At(2)->value == 3);
  }

  SECTION(
      "Inserts a new node at index 0 with value when the index less than "
      "zero.") {
    LinkedList<int, int> list;

    list.PushBack(12, 2);
    list.PushBack(12, 7);

    list.PushAt(1, 5, -4);

    REQUIRE(list.At(0)->value == 5);
    REQUIRE(list.At(1)->value == 2);
    REQUIRE(list.At(2)->value == 7);
  }

  SECTION(
      "Inserts a new node at last index with value when the index is greater "
      "than N-1") {
    LinkedList<int, int> list;

    list.PushBack(12, 2);
    list.PushBack(12, 7);

    list.PushAt(1, 5, 12);

    REQUIRE(list.At(0)->value == 2);
    REQUIRE(list.At(1)->value == 7);
    REQUIRE(list.At(2)->value == 5);
  }
}

TEST_CASE("Returns true if the list is empty, false otherwise", "[Is Empty]") {
  SECTION("Returns true if the list is empty") {
    LinkedList<int, int> list;

    REQUIRE(list.Size() == 0);

    REQUIRE(list.Empty() == true);
  }

  SECTION("Returns true if the list is empty") {
    LinkedList<int, int> list;
    list.PushFront(12, 1);
    list.PushBack(12, 2);
    list.PushBack(12, 3);
    list.PushBack(12, 4);
    list.PushBack(12, 5);

    REQUIRE(list.Size() == 5);

    REQUIRE(list.Empty() == false);
  }
}

TEST_CASE("Updates the specified index with the provided value.",
          "[Update Index]") {
  SECTION("Returns false if the list is empty.") {
    LinkedList<int, int> list;

    bool updateIndex = list.UpdateIndex(25, 5);

    REQUIRE(updateIndex == false);
  }

  SECTION("Returns false if the index is less than zero.") {
    LinkedList<int, int> list;

    list.PushFront(12, 1);
    list.PushFront(12, 2);
    list.PushFront(12, 3);
    list.PushFront(12, 4);
    list.PushFront(12, 5);

    bool updateIndex = list.UpdateIndex(25, -5);

    REQUIRE(updateIndex == false);
  }

  SECTION("Returns false if the index is greater than N-1.") {
    LinkedList<int, int> list;

    list.PushFront(12, 1);
    list.PushFront(12, 2);
    list.PushFront(12, 3);
    list.PushFront(12, 4);
    list.PushFront(12, 5);

    bool updateIndex = list.UpdateIndex(25, 223);

    REQUIRE(updateIndex == false);
  }

  SECTION("Returns true and updates the index with the supplied value.") {
    LinkedList<int, int> list;

    list.PushFront(12, 5);
    list.PushFront(12, 3);
    list.PushFront(12, 6);
    list.PushFront(12, 11);

    bool updateIndexZero = list.UpdateIndex(22, 0);
    bool updateIndexOne = list.UpdateIndex(5, 1);
    bool updateIndexTwo = list.UpdateIndex(8, 2);
    bool updateIndexThree = list.UpdateIndex(19, 3);

    REQUIRE(updateIndexZero == true);
    REQUIRE(updateIndexOne == true);
    REQUIRE(updateIndexTwo == true);
    REQUIRE(updateIndexThree == true);

    REQUIRE(list.At(0)->value == 22);
    REQUIRE(list.At(1)->value == 5);
    REQUIRE(list.At(2)->value == 8);
    REQUIRE(list.At(3)->value == 19);
  }
}

TEST_CASE("Updates the first element and returns true, otherwise returns false",
          "[Update Head]") {
  SECTION("Returns false if the list is empty.") {
    LinkedList<int, int> list;
    bool updateFirst = list.UpdateFirst(14);
    REQUIRE(updateFirst == false);
  }

  SECTION("Returns true and updates the head node with the supplied value.") {
    LinkedList<int, int> list;

    list.PushFront(12, 5);
    list.PushFront(12, 3);
    list.PushFront(12, 6);
    list.PushFront(12, 11);

    REQUIRE(list.Head()->value == 11);

    bool updateFirst = list.UpdateFirst(32);

    REQUIRE(updateFirst == true);

    REQUIRE(list.Head()->value == 32);
  }
}

TEST_CASE("Updates the last element and returns true, otherwise returns false",
          "[Update Last]") {
  SECTION("Returns false if the list is empty.") {
    LinkedList<int, int> list;
    bool updateLast = list.UpdateLast(14);
    REQUIRE(updateLast == false);
  }

  SECTION("Returns true and updates the tail node with the supplied value.") {
    LinkedList<int, int> list;

    list.PushFront(12, 5);
    list.PushFront(12, 3);
    list.PushFront(12, 6);
    list.PushFront(12, 11);

    REQUIRE(list.Tail()->value == 5);

    bool updateLast = list.UpdateLast(32);

    REQUIRE(updateLast == true);

    REQUIRE(list.Tail()->value == 32);
  }
}

TEST_CASE("Returns the amount of times the value occurs within the list",
          "[Count]") {
  SECTION("Returns Zero id the list is empty.") {
    LinkedList<int, int> list;
    int count = list.Count(34);
    REQUIRE(count == 0);
  }

  SECTION(
      "Returns the number of times the specifies value appears in the list.") {
    LinkedList<int, int> list;

    list.PushFront(12, 5);
    list.PushFront(12, 5);
    list.PushFront(12, 5);
    list.PushFront(12, 5);
    list.PushFront(12, 3);
    list.PushFront(12, 6);
    list.PushFront(12, 6);
    list.PushFront(12, 6);
    list.PushFront(12, 11);
    list.PushFront(12, 11);
    list.PushFront(12, 22);

    int countFive = list.Count(5);
    int countThree = list.Count(3);
    int countSix = list.Count(6);
    int countEleven = list.Count(11);
    int countTwentyTwo = list.Count(22);

    REQUIRE(countFive == 4);
    REQUIRE(countThree == 1);
    REQUIRE(countSix == 3);
    REQUIRE(countEleven == 2);
    REQUIRE(countTwentyTwo == 1);

    list.PushFront(12, 5);
    list.PushFront(12, 3);
    list.PushFront(12, 11);
    list.PushFront(12, 22);
    list.PushFront(12, 6);
    list.PushFront(12, 6);

    countFive = list.Count(5);
    countThree = list.Count(3);
    countSix = list.Count(6);
    countEleven = list.Count(11);
    countTwentyTwo = list.Count(22);

    REQUIRE(countFive == 5);
    REQUIRE(countThree == 2);
    REQUIRE(countSix == 5);
    REQUIRE(countEleven == 3);
    REQUIRE(countTwentyTwo == 2);
  }
}

TEST_CASE("Operator[] Returns the node at the specifed index", "[operator[]]") {
  SECTION("Returns nullptr when the list is empty.") {
    LinkedList<int, int> list;
    REQUIRE(list[3] == nullptr);
  }

  SECTION("Returns nullptr when the provided index is less than zero.") {
    LinkedList<int, int> list;
    list.PushFront(12, 5);
    list.PushFront(12, 3);
    list.PushFront(12, 2);

    REQUIRE(list[-2] == nullptr);
  }

  SECTION("Returns nullptr when the provided index is greater than N-1.") {
    LinkedList<int, int> list;
    list.PushFront(12, 5);
    list.PushFront(12, 3);
    list.PushFront(12, 2);

    REQUIRE(list[5] == nullptr);
  }

  SECTION("Returns the node at the specified index.") {
    LinkedList<int, int> list;
    list.PushFront(12, 5);
    list.PushFront(12, 3);
    list.PushFront(12, 2);

    REQUIRE(list[0]->value == 2);
    REQUIRE(list[1]->value == 3);
    REQUIRE(list[2]->value == 5);
  }
}

TEST_CASE("Iterator Works with the Linked List.", "[Iterator]") {
  SECTION("begin can be used to get hold of the first element.") {
    LinkedList<int, int> list;

    list.PushFront(12, 1);
    list.PushFront(12, 5);
    list.PushFront(12, 1);
    list.PushFront(12, 3);
    list.PushFront(12, 5);
    list.PushFront(12, 6);

    LinkedList<int, int>::Iterator begin = list.begin();

    REQUIRE(begin->value == 6);
  }

  SECTION("A Range based for loop can be used on the linked list.") {
    LinkedList<int, int> list;

    list.PushBack(12, 1);
    list.PushBack(12, 2);
    list.PushBack(12, 3);
    list.PushBack(12, 4);
    list.PushBack(12, 5);
    list.PushBack(12, 6);
    list.PushBack(12, 7);

    for (Node<int, int> node : list) {
      ;
    }
  }

  SECTION("A For loop with iterators is possible.") {
    LinkedList<int, int> list;

    list.PushBack(12, 1);
    list.PushBack(12, 2);
    list.PushBack(12, 3);
    list.PushBack(12, 4);
    list.PushBack(12, 5);
    list.PushBack(12, 6);
    list.PushBack(12, 7);

    for (LinkedList<int, int>::Iterator it = list.begin(); it != list.end();
         it++) {
      ;
    }
  }

  SECTION("A For loop with const iterators is possible.") {
    LinkedList<int, int> list;

    list.PushBack(12, 1);
    list.PushBack(12, 2);
    list.PushBack(12, 3);
    list.PushBack(12, 4);
    list.PushBack(12, 5);
    list.PushBack(12, 6);
    list.PushBack(12, 7);

    for (LinkedList<int, int>::ConstIterator it = list.cbegin();
         it != list.cend(); it++) {
      ;
    }
  }

  SECTION("A Reverse For loop with iterators is possible.") {
    LinkedList<int, int> list;

    list.PushBack(12, 1);
    list.PushBack(12, 2);
    list.PushBack(12, 3);
    list.PushBack(12, 4);
    list.PushBack(12, 5);
    list.PushBack(12, 6);
    list.PushBack(12, 7);

    for (LinkedList<int, int>::ReverseIterator it = list.rbegin();
         it != list.rend(); it++) {
      ;
    }
  }

  SECTION("A Reverse For loop with iterators is possible.") {
    LinkedList<int, int> list;

    list.PushBack(12, 1);
    list.PushBack(12, 2);
    list.PushBack(12, 3);
    list.PushBack(12, 4);
    list.PushBack(12, 5);
    list.PushBack(12, 6);
    list.PushBack(12, 7);

    for (LinkedList<int, int>::ConstReverseIterator it = list.crbegin();
         it != list.crend(); it++) {
      ;
    }
  }
}

TEST_CASE("Returns the element at the head position,nullptr otherwise.",
          "[Head]") {
  SECTION("Returns nullptr when the list is empty.") {
    LinkedList<int, int> list;

    REQUIRE(list.Head() == nullptr);
  }

  SECTION("Returns the element in the head position.") {
    LinkedList<int, int> list;
    list.PushFront(12, 4);

    REQUIRE(list.Head()->value == 4);

    list.PushFront(12, 1);
    list.PushFront(12, 2);
    list.PushFront(12, 3);
    list.PushFront(12, 4);
    list.PushFront(12, 5);
    list.PushFront(12, 6);
    list.PushFront(12, 7);

    REQUIRE(list.Head()->value == 7);
  }
}

TEST_CASE("Returns the element at the tail position,nullptr otherwise.",
          "[Tail]") {
  SECTION("Returns nullptr when the list is empty.") {
    LinkedList<int, int> list;

    REQUIRE(list.Tail() == nullptr);
  }

  SECTION("Returns the element in the tail position.") {
    LinkedList<int, int> list;
    list.PushFront(12, 4);

    REQUIRE(list.Tail()->value == 4);

    list.PushFront(12, 1);
    list.PushFront(12, 2);
    list.PushFront(12, 3);
    list.PushFront(12, 4);
    list.PushFront(12, 5);

    REQUIRE(list.Tail()->value == 4);
  }
}

TEST_CASE("Returns true if the lists have exactly the same value & length.",
          "[Operator==]") {
  SECTION("Returns true when comparing the same list.") {
    LinkedList<int, int> list;

    list.PushFront(12, 4);
    list.PushFront(12, 2);

    bool listEquals = list == list;
    REQUIRE(listEquals == true);
  }

  SECTION("Returns false if the sizes of the two lists differ.") {
    LinkedList<int, int> list;
    list.PushBack(12, 1);
    list.PushBack(12, 2);
    list.PushBack(12, 3);

    LinkedList<int, int> otherList;

    otherList.PushBack(12, 1);
    otherList.PushBack(12, 2);
    otherList.PushBack(12, 3);
    otherList.PushBack(12, 4);
    otherList.PushBack(12, 5);
    otherList.PushBack(12, 6);
    otherList.PushBack(12, 7);

    bool listEquals = list == otherList;
    REQUIRE(listEquals == false);
  }

  SECTION(
      "Returns false if the sizes of the list are the same but the value is "
      "different.") {
    LinkedList<int, int> list;
    list.PushBack(12, 1);
    list.PushBack(12, 2);
    list.PushBack(12, 3);

    LinkedList<int, int> otherList;
    otherList.PushBack(12, 1);
    otherList.PushBack(12, 2);
    otherList.PushBack(12, 4);

    bool listEquals = list == otherList;
    REQUIRE(listEquals == false);
  }

  SECTION(
      "Returns true if the sizes of the list are the same and the value is the "
      "same.") {
    LinkedList<int, int> list;
    list.PushBack(12, 1);
    list.PushBack(12, 2);
    list.PushBack(12, 3);

    LinkedList<int, int> otherList;
    otherList.PushBack(12, 1);
    otherList.PushBack(12, 2);
    otherList.PushBack(12, 3);

    bool listEquals = list == otherList;
    REQUIRE(listEquals == true);
  }
}

TEST_CASE("Returns true if the lists are different.", "[Operator!=]") {
  SECTION("Returns false when comparing the same list.") {
    LinkedList<int, int> list;

    list.PushFront(12, 4);
    list.PushFront(12, 2);

    bool listEquals = list != list;
    REQUIRE(listEquals == false);
  }

  SECTION("Returns true if the sizes of the two lists differ.") {
    LinkedList<int, int> list;
    list.PushBack(12, 1);
    list.PushBack(12, 2);
    list.PushBack(12, 3);

    LinkedList<int, int> otherList;

    list.PushBack(12, 1);
    list.PushBack(12, 2);
    list.PushBack(12, 3);
    list.PushBack(12, 4);
    list.PushBack(12, 5);
    list.PushBack(12, 6);
    list.PushBack(12, 7);

    bool listEquals = list != otherList;
    REQUIRE(listEquals == true);
  }

  SECTION(
      "Returns true if the sizes of the list are the same but the value is "
      "different.") {
    LinkedList<int, int> list;
    list.PushBack(12, 1);
    list.PushBack(12, 2);
    list.PushBack(12, 3);

    LinkedList<int, int> otherList;
    otherList.PushBack(12, 1);
    otherList.PushBack(12, 2);
    otherList.PushBack(12, 4);

    bool listEquals = list != otherList;
    REQUIRE(listEquals == true);
  }

  SECTION(
      "Returns false if the sizes of the list are the same and the value is "
      "the "
      "same.") {
    LinkedList<int, int> list;
    list.PushBack(12, 1);
    list.PushBack(12, 2);
    list.PushBack(12, 3);

    LinkedList<int, int> otherList;
    otherList.PushBack(12, 1);
    otherList.PushBack(12, 2);
    otherList.PushBack(12, 3);

    bool listEquals = list != otherList;
    REQUIRE(listEquals == false);
  }
}
