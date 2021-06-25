#define CATCH_CONFIG_MAIN
#include "../node.h"

#include "../vendor/catch.hpp"

TEST_CASE("Node Data Property Functions Correcty", "[Node]") {
  Node<int, int> nodeOne(5, nullptr, nullptr);
  REQUIRE(nodeOne.data == 5);

  Node<int, int> nodeTwo(12);
  REQUIRE(nodeTwo.data == 12);

  Node<int, int>* nodeThree = new Node<int, int>(14, nullptr, nullptr);
  REQUIRE(nodeThree->data == 14);

  Node<int, int>* nodeFour = new Node<int, int>(28, nodeThree, nullptr);
  REQUIRE(nodeFour->data == 28);

  delete nodeThree;
  delete nodeFour;

  return;
}

TEST_CASE("Node Previous Property Functions Correcty", "[Node]") {
  Node<int, int> nodeOne(5, nullptr, nullptr);
  REQUIRE(nodeOne.previous == nullptr);

  Node<int, int> nodeTwo(12);
  REQUIRE(nodeOne.previous == nullptr);

  Node<int, int>* nodeThree = new Node<int, int>(14, nullptr, nullptr);
  REQUIRE(nodeThree->previous == nullptr);

  Node<int, int>* nodeFour = new Node<int, int>(28, nodeThree, nullptr);
  REQUIRE(nodeFour->previous == nodeThree);

  Node<int, int>* nodeFive = new Node<int, int>(122, nodeThree, nodeFour);
  REQUIRE(nodeFive->previous == nodeThree);

  delete nodeThree;
  delete nodeFour;
  delete nodeFive;

  return;
}

TEST_CASE("Node Next Property Functions Correcty", "[Node]") {
  Node<int, int> nodeOne(5, nullptr, nullptr);
  REQUIRE(nodeOne.next == nullptr);

  Node<int, int> nodeTwo(12);
  REQUIRE(nodeOne.next == nullptr);

  Node<int, int>* nodeThree = new Node<int, int>(14, nullptr, nullptr);
  REQUIRE(nodeThree->next == nullptr);

  Node<int, int>* nodeFour = new Node<int, int>(28, nullptr, nodeThree);
  REQUIRE(nodeFour->next == nodeThree);

  Node<int, int>* nodeFive = new Node<int, int>(122, nodeThree, nodeFour);
  REQUIRE(nodeFive->next == nodeFour);

  delete nodeThree;
  delete nodeFour;
  delete nodeFive;

  return;
}

TEST_CASE("Equality", "[Equality]") {
  Node<int, int> nodeOne(1);
  Node<int, int> nodeTwo(1);
  Node<int, int> nodeThree(2);

  REQUIRE((nodeOne == nodeTwo) == true);

  REQUIRE((nodeOne == nodeThree) == false);

  return;
}

TEST_CASE("Greather Than Comparison", "[Greather than]") {
  Node<int, int> nodeOne(1);
  Node<int, int> nodeTwo(1);
  Node<int, int> nodeThree(2);

  REQUIRE((nodeOne > nodeTwo) == false);

  bool nodeThreeGreaterThanTwo = nodeThree > nodeTwo;
  REQUIRE(nodeThreeGreaterThanTwo == true);

  return;
}

TEST_CASE("Less Than Comparison", "[Less than]") {
  Node<int, int> nodeOne(1);
  Node<int, int> nodeTwo(1);
  Node<int, int> nodeThree(2);

  REQUIRE((nodeOne < nodeTwo) == false);

  REQUIRE((nodeThree < nodeTwo) == false);

  bool nodeTwoLessThanThree = nodeTwo < nodeThree;
  REQUIRE(nodeTwoLessThanThree == true);

  return;
}