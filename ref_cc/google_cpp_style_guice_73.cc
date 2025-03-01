// Iterates over the contents of a GargantuanTable.
// Example:
//    std::unique_ptr&lt;GargantuanTableIterator&gt; iter = table-&gt;NewIterator();
//    for (iter-&gt;Seek("foo"); !iter-&gt;done(); iter-&gt;Next()) {
//      process(iter-&gt;key(), iter-&gt;value());
//    }
class GargantuanTableIterator {
  ...
};

