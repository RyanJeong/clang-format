class TableInfo {
  ...
 private:
  std::string table_name_;  // OK - underscore at end.
  static Pool&lt;TableInfo&gt;* pool_;  // OK.
};

