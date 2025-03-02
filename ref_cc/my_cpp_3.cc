#include <chrono>
#include <functional>
#include <iostream>
#include <memory>
#include <type_traits>
#include <utility>
#include <vector>

#define CHECK_MACRO(a) (a > 0)

using namespace std::chrono;  // [NOLINT]

static auto ReturnAutoLambda() {
  return [](int x) { return x * 2; };
}

template <typename T>
auto DecltypeAutoFunc(T&& val) -> decltype(auto) {
  return std::forward<T>(val);
}

static void GenericLambdaTest() {
  auto gl = [](auto t, auto u) { return t + u; };
  std::cout << gl(3, 4) << std::endl;
  std::cout << gl(1.5, 2.5) << std::endl;
}

static void ChronoTest() {
  auto start = steady_clock::now();
  for (int i = 0; i < 100; ++i) {}
  auto end = steady_clock::now();
  auto diff = duration_cast<milliseconds>(end - start).count();
  std::cout << diff << std::endl;
}

int main() {
  auto lam = ReturnAutoLambda();
  std::cout << lam(10) << std::endl;
  GenericLambdaTest();
  ChronoTest();
  int x = 10;
  std::cout << CHECK_MACRO(x) << std::endl;
  std::unique_ptr<int> ptr = std::make_unique<int>(42);
  std::cout << *ptr << std::endl;
  int&& rref = DecltypeAutoFunc(50);
  auto val = DecltypeAutoFunc(x);
  std::cout << rref << std::endl;
  std::cout << val << std::endl;
  return 0;
}

struct SimpleAgg {
  int a;
  double b;
};

static void AggInit() {
  SimpleAgg agg{1, 2.3};
  std::cout << agg.a << agg.b << std::endl;
}

static int OverloadedFunc(int a) { return a + 1; }
static double OverloadedFunc(double a) { return a + 0.1; }

template <typename X>
static X OverloadedFunc(X a, X b) {
  return a + b;
}

static void TestOverload() {
  std::cout << OverloadedFunc(5) << std::endl;
  std::cout << OverloadedFunc(3.14) << std::endl;
  std::cout << OverloadedFunc<int>(3, 4) << std::endl;
}

static void ExchangeTest() {
  int p = 10;
  int q = std::exchange(p, 20);
  std::cout << p << q << std::endl;
}

inline bool InlineBoolFunc(bool val) { return !val; }

static void SomeLoops() {
  for (int i = 0; i < 5; ++i) {}
  while (false) {}
  do { } while (false); }
