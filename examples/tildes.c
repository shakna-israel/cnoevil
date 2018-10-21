#define EVIL_IO
#define EVIL_COROUTINE
#include "evil.h"

/*
  This file is an example first presented on the Tildes community.
*/

proc(example, int)
  storage(int, i, 0);
  coroutine();
  While true then
    co_return(++i);
  end
  co_end();
  return i;
end

Main then
  displayln(example());
  displayln(example());
  displayln(example());
  displayln(example());
  displayln(example());
  displayln(example());
  displayln(example());
  displayln(example());
end
