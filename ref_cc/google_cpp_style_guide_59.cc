switch (var) {
  case 0: {
    ...
    break;
  }
  case 1: {
    ...
    break;
  }
  default: {
    LOG(FATAL) &lt;&lt; "Invalid value in switch statement: " &lt;&lt; var;
  }
}

