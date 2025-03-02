#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define SQUARE_MACRO(x) ((x) * (x))

struct BaseStructA {
  int x;
  explicit BaseStructA(int v) : x(v) {}
  BaseStructA() : x(0) {}
};

struct DerivedStructA : public BaseStructA {
  DerivedStructA() : BaseStructA(100) {}
};

class BaseClass {
 protected:
  int base_value;

 public:
  BaseClass() : base_value(10) {}
  explicit BaseClass(int v) : base_value(v) {}
  int GetBase() const { return base_value; }
  virtual ~BaseClass() {}
};

class SubClass : public BaseClass {
 public:
  SubClass() : BaseClass(99) {}
  int TwiceBase() const { return base_value * 2; }
};

class ComplexClass {
  int data;
  double another;

 public:
  ComplexClass() : data(0), another(0.0) {}
  ComplexClass(int x, double y) : data(x), another(y) {}
  ComplexClass(const ComplexClass& rhs) = default;
  ComplexClass(ComplexClass&& rhs) noexcept
      : data(rhs.data), another(rhs.another) {
    rhs.data = 0;
    rhs.another = 0.0;
  }
  ComplexClass& operator=(const ComplexClass&) = default;
  ComplexClass& operator=(ComplexClass&& rhs) noexcept {
    if (this != &rhs) {
      data = rhs.data;
      another = rhs.another;
      rhs.data = 0;
      rhs.another = 0.0;
    }
    return *this;
  }
  ~ComplexClass() = default;
  int GetData() const { return data; }
  double GetAnother() const { return another; }
  bool operator<(const ComplexClass& other) const { return data < other.data; }
  ComplexClass operator+(const ComplexClass& other) const {
    return ComplexClass(data + other.data, another + other.another);
  }
};

struct StructWithOperator {
  int value;
  bool operator==(const StructWithOperator& rhs) const {
    return value == rhs.value;
  }
};

static ComplexClass CreateComplex(int a, double b) {
  return ComplexClass(a, b);
}

int main() {
  DerivedStructA da;
  SubClass sc;
  std::cout << da.x << std::endl;
  std::cout << sc.GetBase() << std::endl;
  std::cout << sc.TwiceBase() << std::endl;
  ComplexClass c1(10, 2.5);
  ComplexClass c2 = CreateComplex(5, 3.3);
  ComplexClass c3 = c1 + c2;
  if (c1 < c2) {}  // [NOLINT]
  StructWithOperator swo1{10};
  StructWithOperator swo2{20};
  if (swo1 == swo2) {}  // [NOLINT]
  std::vector<ComplexClass> vc;
  vc.push_back(c1);
  vc.push_back(std::move(c2));
  return 0;
}

class AnotherLevelClass : public SubClass {
 public:
  AnotherLevelClass() : SubClass() {}
  int AdditionalFunc() const { return GetBase() + 10; }
};

inline ComplexClass InlineCreateComplex(int x, double y) {
  return ComplexClass(x, y);
}

struct MultiConstructor {
  int a;
  double b;
  MultiConstructor() : a(0), b(0.0) {}
  explicit MultiConstructor(int v) : a(v), b(0.0) {}
  explicit MultiConstructor(double w) : a(0), b(w) {}
  MultiConstructor(int v, double w) : a(v), b(w) {}
};

static void TestMultiConstructor() {
  MultiConstructor m1;
  MultiConstructor m2(5);
  MultiConstructor m3(3.14);
  MultiConstructor m4(10, 2.71);
}

inline int OverloadedOperatorLike(int z) { return SQUARE_MACRO(z); }

class OpClass {
 public:
  int operator()(int x, int y) { return x + y; }
};

