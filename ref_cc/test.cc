#include <algorithm>   // for std::find_if, std::sort, etc.
#include <cassert>     // for assert
#include <chrono>      // for timing-related examples
#include <cstddef>     // for size_t, nullptr_t, etc.
#include <functional>  // for std::function
#include <iostream>    // for std::cout, std::endl
#include <map>         // for std::map
#include <memory>      // for std::unique_ptr, std::shared_ptr
#include <string>      // for std::string
#include <vector>      // for std::vector

static const int kMaxBufferSize = 1024;  // Example global constant
static int g_global_counter = 0;  // Example of a global variable (discouraged)

enum class Color {
  kRed,
  kGreen,
  kBlue,
  kYellow
};

enum class Shape {
  kCircle = 100,
  kTriangle,
  kSquare,
  kRectangle
};

//------------------------------------------------------------------------------
// A forward declaration to demonstrate usage below:
class Rectangle;  // We'll define it later in the file

//------------------------------------------------------------------------------
// A struct is typically used for simple aggregate data with public members.
struct Point {
  // Google Style: public data fields are fine for simple aggregates.
  double x = 0.0;
  double y = 0.0;
};

//------------------------------------------------------------------------------
// Google Style: Classes typically use PascalCase (UpperCamelCase).
// Example: A simple base class with virtual methods and one pure virtual.
class Shape {
 public:
  // Virtual destructor for polymorphic base class.
  virtual ~Shape() {}

  // A pure virtual function to compute area.
  virtual double ComputeArea() const = 0;

  // A normal virtual function with a default implementation.
  virtual void PrintColor() const {
    std::cout << "Shape::PrintColor: Color info not available.\n";
  }
};

//------------------------------------------------------------------------------
// Google Style: Derived classes also in PascalCase.
class Circle : public Shape {
 public:
  // Constructor
  Circle(double radius, Color color) : radius_(radius), color_(color) {
    // Use member initializer list in the same line where possible
  }

  // Override function
  double ComputeArea() const override {
    // Area = π * r^2
    static const double kPi = 3.14159265358979323846;
    return kPi * radius_ * radius_;
  }

  // Override color printing
  void PrintColor() const override {
    std::cout << "Circle color: " << static_cast<int>(color_) << "\n";
  }

  // Accessor with Google style: function name in CamelCase
  double radius() const { return radius_; }

 private:
  double radius_;
  Color color_;
};

//------------------------------------------------------------------------------
// Another derived class: We declared "Rectangle" forward, now we define it.
class Rectangle : public Shape {
 public:
  Rectangle(double w, double h, Color color)
      : width_(w), height_(h), color_(color) {}

  double ComputeArea() const override { return width_ * height_; }

  void PrintColor() const override {
    std::cout << "Rectangle color: " << static_cast<int>(color_) << "\n";
  }

  double width() const { return width_; }
  double height() const { return height_; }

 private:
  double width_;
  double height_;
  Color color_;
};

//------------------------------------------------------------------------------
// Another struct with a user-defined constructor for demonstration:
struct ColoredPoint {
  double x;
  double y;
  Color color;

  ColoredPoint(double x_val, double y_val, Color c)
      : x(x_val), y(y_val), color(c) {}
};

//------------------------------------------------------------------------------
// Google Style: inline function example. Usually placed in a header, but for
// demonstration here:
inline double DistanceSquared(const Point& p1, const Point& p2) {
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  return dx * dx + dy * dy;
}

//------------------------------------------------------------------------------
// Template function example: (C++14)
template <typename T>
T AddValues(const T& a, const T& b) {
  return a + b;
}

//------------------------------------------------------------------------------
// Overloaded function templates, plus a specialization for std::string
template <typename T>
T MultiplyValues(const T& a, const T& b) {
  return a * b;
}

template <>
std::string MultiplyValues<std::string>(const std::string& a,
                                        const std::string& b) {
  // For demonstration, just concatenate
  return a + b;
}

//------------------------------------------------------------------------------
// Another template demonstration: a simple class template
template <typename T>
class MyContainer {
 public:
  MyContainer() = default;

  explicit MyContainer(std::initializer_list<T> init_list)
      : elements_(init_list) {}

  void Add(const T& value) { elements_.push_back(value); }

  const std::vector<T>& elements() const { return elements_; }

 private:
  std::vector<T> elements_;
};

//------------------------------------------------------------------------------
// A function that uses MyContainer
void DemoContainerUsage() {
  MyContainer<int> int_container = {1, 2, 3, 4};
  int_container.Add(5);

  MyContainer<std::string> string_container = {"Hello", "World"};
  string_container.Add("!");

  std::cout << "int_container has " << int_container.elements().size()
            << " elements.\n";
  std::cout << "string_container has " << string_container.elements().size()
            << " elements.\n";
}

//------------------------------------------------------------------------------
// Example of a lambda usage. We can test capturing variables, etc.
void DemoLambda() {
  std::vector<int> values = {3, 1, 4, 1, 5, 9};

  // Google style suggests short lambdas can be inline like this:
  auto is_even = [](int x) { return x % 2 == 0; };

  // Remove even numbers:
  values.erase(std::remove_if(values.begin(), values.end(), is_even),
               values.end());

  std::cout << "After removing evens, size=" << values.size() << "\n";

  // Another lambda that captures by reference:
  int sum = 0;
  std::for_each(values.begin(), values.end(), [&](int x) { sum += x; });
  std::cout << "Sum of remaining elements: " << sum << "\n";
}

//------------------------------------------------------------------------------
// Demonstration of if-else, else-if, switch, for, while, do-while in one place:
void DemoControlFlow(int input) {
  // if-else
  if (input < 0)
    std::cout << "Negative input.\n";
  else if (input == 0)
    std::cout << "Zero input.\n";
  else
    std::cout << "Positive input.\n";

  // if-else with braces
  if (input < 0) {
    std::cout << "  Negative input.\n";
  } else if (input == 0) {
    std::cout << "  Zero input.\n";
  } else {
    std::cout << "  Positive input.\n";
  }

  // switch
  switch (input) {
    case 0:
      std::cout << "Switch case: Zero.\n";
      break;
    case 1:
      std::cout << "Switch case: One.\n";
      break;
    default:
      std::cout << "Switch case: Others.\n";
      break;
  }

  // for
  std::cout << "For loop from 0 to input (exclusive): ";
  for (int i = 0; i < input; ++i) std::cout << i << " ";
  std::cout << std::endl;

  // for with braces
  std::cout << "For loop from 0 to input (exclusive): ";
  for (int i = 0; i < input; ++i) { std::cout << i << "-"; }
  std::cout << std::endl;

  // while
  int w = input;
  while (w > 0) {
    std::cout << "While loop: w=" << w << std::endl;
    --w;
  }

  // while without braces
  w = input;
  while (w-- > 0) {}

  // do-while
  int dw = 0;
  do {
    std::cout << "Do-while loop, iteration: " << dw << std::endl;
    ++dw;
  } while (dw < 3);
}

//------------------------------------------------------------------------------
// A demonstration function that manipulates static/global variables:
void IncrementGlobalCounter() { ++g_global_counter; }

//------------------------------------------------------------------------------
// Show usage of objects, polymorphism, etc.
void DemoPolymorphism() {
  // Create shapes
  std::unique_ptr<Shape> circle = std::make_unique<Circle>(5.0, Color::kGreen);
  std::unique_ptr<Shape> rect =
      std::make_unique<Rectangle>(4.0, 6.0, Color::kBlue);

  // Polymorphic calls
  std::cout << "Circle area: " << circle->ComputeArea() << "\n";
  circle->PrintColor();

  std::cout << "Rectangle area: " << rect->ComputeArea() << "\n";
  rect->PrintColor();
}

//------------------------------------------------------------------------------
// Demonstrate usage of struct with designated initializers (C++14 doesn't
// have full designated init like C, but we can do aggregate initialization).
// We'll do partial, just for style demonstration:
void DemoStructInitialization() {
  Point p{1.0, 2.0};
  std::cout << "Point p = (" << p.x << ", " << p.y << ")\n";
}

//------------------------------------------------------------------------------
// Using <map> and <string> to show typical usage.
void DemoMapUsage() {
  std::map<std::string, int> word_count;
  word_count["apple"] = 3;
  word_count["banana"] = 2;

  // Check existence
  if (word_count.find("apple") != word_count.end())
    std::cout << "Found apple with count: " << word_count["apple"] << "\n";

  // Iterate
  for (const auto& entry : word_count)
    std::cout << "Word: " << entry.first << ", count: " << entry.second << "\n";
}

//------------------------------------------------------------------------------
// Some demonstration of chrono from C++14, measuring a small code's runtime.
void DemoChrono() {
  auto start = std::chrono::steady_clock::now();
  // Just a dummy loop
  long sum = 0;
  for (int i = 0; i < 1000000; ++i) sum += i;
  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;

  std::cout
      << "DemoChrono: sum=" << sum << ", took="
      << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
      << " ms\n";
}

//------------------------------------------------------------------------------
// A function returning multiple results using struct:
struct PairInt {
  int first_value;
  int second_value;
};

PairInt MakePair(int a, int b) {
  PairInt p;
  p.first_value = a;
  p.second_value = b;
  return p;
}

//------------------------------------------------------------------------------
// Show usage of that pair-struct:
void DemoPairUsage() {
  PairInt pi = MakePair(10, 20);
  std::cout << "Pair: (" << pi.first_value << ", " << pi.second_value << ")\n";
}

//------------------------------------------------------------------------------
// Another example: a function pointer or std::function usage (C++14).
void DemoFunctionPointer() {
  // Normal function
  auto times_two = [](int x) { return x * 2; };

  // Store in std::function
  std::function<int(int)> func = times_two;

  std::cout << "func(10) = " << func(10) << "\n";
}

//------------------------------------------------------------------------------
// Demo of references, pointers, dynamic memory:
void DemoPointers() {
  int local_var = 100;
  int& ref_var = local_var;

  std::cout << "local_var=" << local_var << ", ref_var=" << ref_var << "\n";

  ref_var = 200;
  std::cout << "After modifying ref_var, local_var=" << local_var << "\n";

  // dynamic allocation (avoid raw new in real code, but demonstration)
  int* dynamic_int = new int(500);
  std::cout << "*dynamic_int=" << *dynamic_int << "\n";
  delete dynamic_int;  // free memory

  // better: use smart pointers
  auto smart_int = std::make_unique<int>(999);
  std::cout << "*smart_int=" << *smart_int << "\n";
}

//------------------------------------------------------------------------------
// Show inline variable usage: (C++17 feature) - not allowed in C++14, so skip.

//------------------------------------------------------------------------------
// We'll define a simple namespace to group some utilities:
namespace myproject {
namespace internal {

// A simple helper
int InternalCompute(int x, int y) { return x * y + 42; }
}  // namespace internal

int PublicCompute(int x) {
  // Use something from internal
  return internal::InternalCompute(x, x) - 10;
}
}  // namespace myproject

//------------------------------------------------------------------------------
// Another demonstration: an interface-like abstract class (for reference):
class Logger {
 public:
  virtual ~Logger() {}
  virtual void Log(const std::string& message) = 0;
};

class ConsoleLogger : public Logger {
 public:
  void Log(const std::string& message) override {
    std::cout << "[ConsoleLogger] " << message << "\n";
  }
};

//------------------------------------------------------------------------------
// Show how to pass a Logger interface around:
void DemoLogger(Logger* logger) {
  if (logger) logger->Log("DemoLogger started.");
}

//------------------------------------------------------------------------------
// We can define a small test scenario inside a separate function:
void RunAllDemos() {
  std::cout << "Running all demos...\n";
  DemoContainerUsage();
  DemoLambda();
  DemoControlFlow(3);
  DemoPolymorphism();
  DemoStructInitialization();
  DemoMapUsage();
  DemoChrono();
  DemoPairUsage();
  DemoFunctionPointer();
  DemoPointers();

  // Logger usage
  ConsoleLogger console_logger;
  DemoLogger(&console_logger);

  // Accessing namespace function
  std::cout << "myproject::PublicCompute(5)=" << myproject::PublicCompute(5)
            << "\n";
}

//------------------------------------------------------------------------------
// main() function
int main() {
  std::cout << "Google C++ Style Example - Start\n";

  // Increment global counter a few times
  IncrementGlobalCounter();
  IncrementGlobalCounter();
  std::cout << "Global counter = " << g_global_counter << "\n";

  // Basic usage of templated functions
  int result_int = AddValues<int>(10, 20);
  double result_double = AddValues<double>(3.14, 2.71);
  std::cout << "AddValues<int>(10, 20) = " << result_int << "\n";
  std::cout << "AddValues<double>(3.14, 2.71) = " << result_double << "\n";

  // Multiply strings
  std::string concat = MultiplyValues<std::string>("Hello", "World");
  std::cout << "MultiplyValues<std::string>(\"Hello\", \"World\") = " << concat
            << "\n";

  // Run demonstration of shape usage, containers, etc.
  RunAllDemos();

  std::cout << "Google C++ Style Example - End\n";
  return 0;
}
