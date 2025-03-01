

<p>Dynamic initialization of nonlocal variables is discouraged, and in general
it is forbidden. However, we do permit it if no aspect of the program depends
on the sequencing of this initialization with respect to all other
initializations. Under those restrictions, the ordering of the initialization
does not make an observable difference. For example:</p>

