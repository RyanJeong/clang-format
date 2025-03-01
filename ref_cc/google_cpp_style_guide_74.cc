// Returns an iterator for this table, positioned at the first entry
// lexically greater than or equal to `start_word`. If there is no
// such entry, returns a null pointer. The client must not use the
// iterator after the underlying GargantuanTable has been destroyed.
//
// This method is equivalent to:
//    std::unique_ptr&lt;Iterator&gt; iter = table-&gt;NewIterator();
//    iter-&gt;Seek(start_word);
//    return iter;
std::unique_ptr&lt;Iterator&gt; GetIterator(absl::string_view start_word) const;

