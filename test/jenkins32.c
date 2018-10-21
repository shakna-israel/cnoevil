#define EVIL_HASH
#include "evil.h"

int main(int argc, char** argv) {
  if(jenkins32("hello", 5) != 4172743612)
    return 1;
}
