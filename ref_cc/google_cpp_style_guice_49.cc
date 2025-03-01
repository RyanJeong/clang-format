std::sort(v.begin(), v.end(), [](int x, int y) {
  return Weight(x) &lt; Weight(y);
});

