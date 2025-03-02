std::sort(v.begin(), v.end(), [](int x, int y) {
  return Weight(x) < Weight(y);
});

