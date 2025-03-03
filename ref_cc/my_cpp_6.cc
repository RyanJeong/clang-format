#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Base {
 public:
  virtual ~Base() = default;
};

class Derived : public Base {
 public:
  void foo() {}
};

class Unrelated {};

struct S {
  int x;
};

int main() {
  int a = 10;
  double b = 20.5;
  float c = 30.0f;
  char d = 'd';

  int cstyle_int = (int) b;
  double cstyle_double = (double) a;
  float cstyle_float = (float) d;

  int static_int = static_cast<int>(b);
  double static_double = static_cast<double>(a);
  float static_float = static_cast<float>(d);

  Base* base_ptr = new Derived;
  Derived* derived_ptr1 = dynamic_cast<Derived*>(base_ptr);
  Base* base_ptr2 = derived_ptr1;
  Derived* derived_ptr2 = reinterpret_cast<Derived*>(base_ptr2);
  int* int_ptr = new int(100);
  const int* const_int_ptr = int_ptr;
  int* non_const_int_ptr = const_cast<int*>(const_int_ptr);

  int& ref = a;
  const int& const_ref = a;
  int&& rvalue_ref = static_cast<int&&>(a);
  const int&& const_rvalue_ref = static_cast<const int&&>(a);

  std::vector<int> vec = {1, 2, 3, 4, 5};
  auto&& fwd_ref = vec[0];
  auto&& rvalue_fwd = std::move(a);

  S s{42};
  S* s_ptr = &s;
  S* s_reinterpreted = reinterpret_cast<S*>(s_ptr);

  std::string str = "Hello";
  char* cstr = const_cast<char*>(str.c_str());

  std::cout << cstyle_int << " " << cstyle_double << " " << cstyle_float
            << "\n";
  std::cout << static_int << " " << static_double << " " << static_float
            << "\n";
  std::cout << (derived_ptr1 ? "Derived" : "Not Derived") << "\n";
  std::cout << *non_const_int_ptr << "\n";
  std::cout << ref << " " << const_ref << "\n";
  std::cout << rvalue_ref << " " << const_rvalue_ref << "\n";
  std::cout << fwd_ref << " " << rvalue_fwd << "\n";
  std::cout << s_reinterpreted->x << "\n";
  std::cout << cstr << "\n";

  delete base_ptr;
  delete int_ptr;
  return 0;
}
