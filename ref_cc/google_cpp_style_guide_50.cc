auto a = 42;  // a is an int
auto& b = a;  // b is an int&
auto c = b;   // c is an int
auto d{42};   // d is an int, not a std::initializer_list<int>
