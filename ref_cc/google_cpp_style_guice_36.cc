bool Base::Equal(Base* other) = 0;
bool Derived::Equal(Base* other) {
  Derived* that = dynamic_cast&lt;Derived*&gt;(other);
  if (that == nullptr)
    return false;
  ...
}

