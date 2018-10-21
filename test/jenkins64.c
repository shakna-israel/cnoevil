#define EVIL_HASH
#include "evil.h"

int main(int argc, char** argv) {
  if(jenkins64("hello", 5) != 7100996278408283916)
    return 1;
}
