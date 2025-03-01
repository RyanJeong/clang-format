class Copyable {
 public:
  Copyable(const Copyable&amp; other) = default;
  Copyable&amp; operator=(const Copyable&amp; other) = default;

  // The implicit move operations are suppressed by the declarations above.
  // You may explicitly declare move operations to support efficient moves.
};

class MoveOnly {
 public:
  MoveOnly(MoveOnly&amp;&amp; other) = default;
  MoveOnly&amp; operator=(MoveOnly&amp;&amp; other) = default;

  // The copy operations are implicitly deleted, but you can
  // spell that out explicitly if you want:
  MoveOnly(const MoveOnly&amp;) = delete;
  MoveOnly&amp; operator=(const MoveOnly&amp;) = delete;
};

class NotCopyableOrMovable {
 public:
  // Not copyable or movable
  NotCopyableOrMovable(const NotCopyableOrMovable&amp;) = delete;
  NotCopyableOrMovable&amp; operator=(const NotCopyableOrMovable&amp;)
      = delete;

  // The move operations are implicitly disabled, but you can
  // spell that out explicitly if you want:
  NotCopyableOrMovable(NotCopyableOrMovable&amp;&amp;) = delete;
  NotCopyableOrMovable&amp; operator=(NotCopyableOrMovable&amp;&amp;)
      = delete;
};

