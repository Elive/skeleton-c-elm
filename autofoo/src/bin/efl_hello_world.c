
#include "config.h"
#include "efl_hello_world.h"

#include <Elementary.h>

#include <Eina.h>
#undef EINA_LOG_DOMAIN_DEFAULT
#define EINA_LOG_DOMAIN_DEFAULT _log_dom
static int _log_dom = -1;

EAPI_MAIN int
elm_main(int argc EINA_UNUSED, char **argv EINA_UNUSED)
{
   eina_log_color_disable_set(EINA_FALSE);
   _log_dom = eina_log_domain_register("mydom", EINA_COLOR_CYAN);
   EINA_LOG_ERR(" bin: %s\n lib: %s\n data: %s\n",
          PACKAGE_BIN_DIR,
          PACKAGE_LIB_DIR,
          PACKAGE_DATA_DIR);
   return efl_hello_world();
}

ELM_MAIN()

