#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define MULTIPLY_MACRO(a, b) ((a) * (b))

static void VectorTest() {
  std::vector<int> v = {1, 2, 3, 4, 5};
  std::transform(v.begin(), v.end(), v.begin(), [](int x) { return x * 2; });
  int sum = std::accumulate(v.begin(), v.end(), 0);
  std::cout << sum << std::endl;
}

static void ListTest() {
  std::list<std::string> ls = {"one", "two", "three"};
  ls.remove_if([](const std::string& s) { return s.size() < 4; });
  for (auto& s : ls) { std::cout << s << std::endl; }
}

static void SetTest() {
  std::set<int> si = {10, 1, 5, 2};
  si.insert(7);
  for (auto n : si) { std::cout << n << std::endl; }
}

static void MapTest() {
  std::map<int, std::string> mp;
  mp[1] = "one";
  mp[2] = "two";
  mp[3] = "three";
  auto it = mp.find(2);
  if (it != mp.end()) { std::cout << it->second << std::endl; }
}

static void UnorderedMapTest() {
  std::unordered_map<std::string, int> ump;
  ump["alpha"] = 1;
  ump["beta"] = 2;
  ump["gamma"] = 3;
  for (auto& kv : ump) { std::cout << kv.first << kv.second << std::endl; }
}

static void UnorderedSetTest() {
  std::unordered_set<int> us = {3, 1, 4, 1, 5, 9};
  us.insert(2);
  for (auto x : us) { std::cout << x << std::endl; }
}

static void DequeTest() {
  std::deque<double> dq;
  dq.push_back(1.1);
  dq.push_front(2.2);
  dq.push_back(3.3);
  std::sort(dq.begin(), dq.end());
  for (auto d : dq) std::cout << d << std::endl;
}

static void AlgorithmTest() {
  std::vector<int> nums(10);
  std::iota(nums.begin(), nums.end(), 0);
  std::random_shuffle(nums.begin(), nums.end());
  std::partial_sort(nums.begin(), nums.begin() + 5, nums.end());
  std::copy(nums.begin(), nums.end(),
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}

int main() {
  VectorTest();
  ListTest();
  SetTest();
  MapTest();
  UnorderedMapTest();
  UnorderedSetTest();
  DequeTest();
  AlgorithmTest();
  std::cout << MULTIPLY_MACRO(3, 4) << std::endl;
  return 0;
}

inline std::vector<int> CreateVectorRange(int start, int end) {
  std::vector<int> temp;
  for (int i = start; i <= end; ++i) { temp.push_back(i); }
  return temp;
}

static void AnotherRun() {
  auto v = CreateVectorRange(10, 20);
  for (auto e : v) { std::cout << e << std::endl; }
}

static void CombineContainers() {
  std::list<int> li = {1, 2, 3, 4, 5};
  std::vector<int> vec(li.begin(), li.end());
  vec.insert(vec.end(), 6);
  vec.erase(std::remove(vec.begin(), vec.end(), 2), vec.end());
  for (auto i : vec) { std::cout << i << std::endl; }
}
