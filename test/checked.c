#define EVIL_MALLOC
#include "evil.h"

Main then
  checked_malloc(msg, char*, 80 * sizeof(char), "Unable to allocate.", 1);
  free(msg);
end
