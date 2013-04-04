
#include "config.h"
#include "efl_hello_world.h"

#include <Elementary.h>

EAPI_MAIN int
elm_main(int argc EINA_UNUSED, char **argv EINA_UNUSED)
{
   printf("PACKAGE\n bin: %s\n lib: %s\n data: %s\n",
          PACKAGE_BIN_DIR,
          PACKAGE_LIB_DIR,
          PACKAGE_DATA_DIR);
   return efl_hello_world();
}

ELM_MAIN()

