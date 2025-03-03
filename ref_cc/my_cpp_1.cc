#include <algorithm>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <string>
#include <utility>
#include <vector>

#define MACRO_ONE(x) (x + 10)
#define MACRO_TWO(a, b) ((a) + (b))
#define CONDITIONAL_MACRO

#ifdef CONDITIONAL_MACRO
inline int InlineAdd(int x, int y) { return x + y; }
#endif

#ifndef ANOTHER_MACRO
#define ANOTHER_MACRO(z) (z * 2)
#endif

static int VeryLongFunctionNameWithManyParametersAndComplexLogic(int a, int b,
                                                                 int c, int d,
                                                                 int e, int f,
                                                                 int g, int h) {
  return a + b + c + d + e + f + g + h;
}

template <typename T>
T GenericAdd(T x, T y) {
  return x + y;
}

template <typename X, typename Y, typename Z>
auto TripleCombine(X x, Y y, Z z) {
  return x + y + z;
}

struct SingleStructA {
  int x;
  int y;
  SingleStructA(int a, int b) : x(a), y(b) {}
};

struct SingleStructB {
  int m;
  int n;
  SingleStructB(int a, int b) : m(a), n(b) {}
};

class SingleClassA {
 public:
  int val;
  SingleClassA() : val(0) {}
  explicit SingleClassA(int v) : val(v) {}
  int GetVal() const { return val; }
};

class SingleClassB {
  int data;

 public:
  explicit SingleClassB(int d) : data(d) {}
  int Data() const { return data; }
};

inline int SimpleInlineFunc(int a) { return a * 3; }
auto GenericLambda = [](auto x, auto y) { return x * y; };

static void FooFunction(const std::vector<int>& v) {
  for (auto w : v) {
    if (w > 10) {}  // [NOLINT]
  }
}

static std::string ConcatLongIdentifiersWithMoreParameters(
    const std::string& a, const std::string& b, const std::string& c,
    const std::string& d, const std::string& e) {
  return a + b + c + d + e;
}

static void ProcessValues() {
  int x = 0;
  if (x < 5) {
    x += 1;
  } else if (x == 5) {
    x += 2;
  } else {
    x += 3;
  }
  switch (x) {
    case 1:
      x += 10;
      break;
    case 2:
      x += 20;
      break;
    default:
      x += 30;
      break;
  }
  for (int i = 0; i < 5; ++i) { x += i; }
  while (x < 50) { ++x; }
  // Munseong: Not actually using this expression; just testing
  do { x -= 2; } while (x > 10);  // [NOLINT]
}

static void BigParameterFunction(int a1, int a2, int a3, int a4, int a5, int a6,
                                 int a7, int a8, int a9) {
  (void) a1;
  (void) a2;
  (void) a3;
  (void) a4;
  (void) a5;
  (void) a6;
  (void) a7;
  (void) a8;
  (void) a9;
}

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};
  v.erase(std::remove_if(v.begin(), v.end(), [](int n) { return n > 3; }),
          v.end());
  std::cout << MACRO_ONE(5) << std::endl;
  std::cout << ANOTHER_MACRO(4) << std::endl;
  SingleStructA sa(1, 2);
  SingleStructB sb(3, 4);
  SingleClassA ca(42);
  SingleClassB cb(7);
  std::cout << InlineAdd(3, 4) << std::endl;
  std::cout << GenericAdd<int>(5, 6) << std::endl;
  std::cout << TripleCombine<int, int, int>(1, 2, 3) << std::endl;
  std::cout << GenericLambda(2, 5) << std::endl;
  FooFunction(v);
  ProcessValues();
  BigParameterFunction(1, 2, 3, 4, 5, 6, 7, 8, 9);
  auto str = ConcatLongIdentifiersWithMoreParameters("abcdef", "ghijkl",
                                                     "mnopqr", "stuvwx", "yz");
  std::cout << str << std::endl;
  std::unique_ptr<int> uptr(new int(10));
  std::unique_ptr<int> uptr2 = std::move(uptr);
  if (uptr2) { *uptr2 = 55; }
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(1, 100);
  int r = dist(gen);
  std::cout << r << std::endl;
  return 0;
}

inline int AnotherInline(int p) { return p * p; }

static void RepeatedFunction1() {
  int x = 0;
  if (x < 10) {
    x += 5;
  } else {
    x -= 5;
  }
  switch (x) {
    case 5:
      x += 1;
      break;
    default:
      x += 2;
      break;
  }
  for (int i = 0; i < 3; ++i) { x++; }
}

static void RepeatedFunction2() {
  std::string s = "test";
  while (s.size() < 10) { s += "x"; }
  // Munseong: Not actually using this expression; just testing
  do { s.pop_back(); } while (s.size() > 5);  // [NOLINT]
}

template <typename T>
struct LongStructNameForTesting {
  T data;
  explicit LongStructNameForTesting(T v) : data(v) {}
  T GetData() const { return data; }
};

template <typename T>
T MoveExample(T&& val) {
  T temp = std::move(val);
  return temp;
}

class InheritedClassA : public SingleClassA {
 public:
  InheritedClassA() : SingleClassA(100) {}
};

class InheritedClassB : public InheritedClassA {
 public:
  InheritedClassB() : InheritedClassA() {}
};

static void AnotherSeriesOfStatements() {
  std::vector<std::string> list;
  list.push_back("alpha");
  list.push_back("beta");
  list.push_back("gamma");
  std::sort(list.begin(), list.end());
}

static void LambdaTests() {
  auto l = [](int a, int b) { return a + b; };
  l(1, 2);
}

inline double InlineDouble(double x) { return x + 0.5; }

int DummyFunction(int p1, int p2, int p3, int p4, int p5, int p6) {
  return p1 + p2 + p3 + p4 + p5 + p6;
}

int AnotherMainLikeFunc() {
  int a = 0;
  for (int i = 0; i < 10; ++i) { a += i; }
  return a;
}

static void VeryLongParamNamesFunction(
    int alphaBetaGammaDeltaEpsilonZetaEtaThetaIotaKappa) {
  (void) alphaBetaGammaDeltaEpsilonZetaEtaThetaIotaKappa;
}
