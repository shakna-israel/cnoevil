#define EVIL_LAMBDA
#include "evil.h"

int main(int argc, char** argv) {
  int (*max)(int, int) = lambda (int, (int x, int y) { return x > y ? x : y; });
  return max(0, 0);
}
