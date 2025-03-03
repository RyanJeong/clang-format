int x = 0;
auto x_plus_n = [&x](int n) -> int { return x + n; }
