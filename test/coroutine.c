#define EVIL_NO_WARN
#define EVIL_COROUTINE
#include "evil.h"


#include <stdlib.h>

int example() {
  static int i = 0;
  coroutine();
  while(1) {
    co_return(++i);
  }
  co_end();
  return i;
}

int main(int argc, char** argv) {
  if(example() != 1)
    exit(1);
  if(example() != 2)
    exit(1);
  if(example() != 3)
    exit(1);
}
