#define EVIL_LAMBDA
#include "evil.h"



int main(int argc, char** argv) {
  int (*max)(int, int) = lambda (int, (int x, int y) { return x > y ? x : y; });
  // Takes max as an argument!
  int (*passed)(int (*max)(int, int), int) = lambda(int, (int (*max)(int, int), int y) { return max(y, y); });
  return passed(max, 0);
}
