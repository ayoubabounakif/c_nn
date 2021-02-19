#include "try_catch.h"
extern jmp_buf * __TRY_CATCH_LIB__raise_env;
extern jmp_buf * __TRY_CATCH_LIB__retry_env;

void * rmalloc(size_t const nbytes)
{
  void * const mem = malloc(nbytes);
  if (mem == NULL) {
    RAISE(MALLOC_EXCEPTION);
  }
  return mem;
}

