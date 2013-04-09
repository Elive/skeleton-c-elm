
#include "config.h"
#include "efl_hello_world.h"

#include <Eina.h>
#include <Elementary.h>
#include <Ecore_Getopt.h>

#define THEME_FILE_BUF_SIZE   128

#undef EINA_LOG_DOMAIN_DEFAULT
#define EINA_LOG_DOMAIN_DEFAULT _log_dom
static int _log_dom = -1;

static const Ecore_Getopt options =
{
   PACKAGE_NAME,
   "%prog [options]",
   VERSION,
   "(C) 2013 Jérémy Zurcher",
   "this code is … ASIS",
   "FIXME",
   1,
   {
      ECORE_GETOPT_LICENSE('L', "license"),
      ECORE_GETOPT_COPYRIGHT('C', "copyright"),
      ECORE_GETOPT_VERSION('V', "version"),
      ECORE_GETOPT_HELP('H', "help"),
      ECORE_GETOPT_CALLBACK_NOARGS('E', "list-engines",
                                   "list ecore-evas engines",
                                   ecore_getopt_callback_ecore_evas_list_engines,
                                   NULL),
      ECORE_GETOPT_STORE_TRUE('f', "fullscreen", "set f"),
      ECORE_GETOPT_CALLBACK_ARGS('g', "geometry",
                                 "geometry to use in x:y:w:h form.",
                                 "X:Y:W:H",
                                 ecore_getopt_callback_geometry_parse,
                                 NULL),
      ECORE_GETOPT_COUNT('v', "verbose",
                         "increase log verbosity"),
      ECORE_GETOPT_STORE_DEF_STR('t', "theme",
                                 "path to read the theme file from",
                                 "default"),
      ECORE_GETOPT_STORE_STR('e', "engine",
                             "ecore-evas engine to use"),
      ECORE_GETOPT_SENTINEL
   }
};

EAPI_MAIN int
elm_main(int argc, char **argv)
{
   Eina_Bool exit = EINA_FALSE;
   int args;
   char *engine = NULL;
   char *theme = "default.edj";
   int verbosity = 0;
   Eina_Bool fullscreen = EINA_FALSE;
   Eina_Rectangle geometry = {-1, -1, -1, -1};
   char edje_file_path[THEME_FILE_BUF_SIZE];
   int eina_log_level = EINA_LOG_LEVEL_ERR;

   Ecore_Getopt_Value values[] =
     {
        ECORE_GETOPT_VALUE_BOOL(exit),
        ECORE_GETOPT_VALUE_BOOL(exit),
        ECORE_GETOPT_VALUE_BOOL(exit),
        ECORE_GETOPT_VALUE_BOOL(exit),
        ECORE_GETOPT_VALUE_BOOL(exit),
        ECORE_GETOPT_VALUE_BOOL(fullscreen),
        ECORE_GETOPT_VALUE_PTR_CAST(geometry),
        ECORE_GETOPT_VALUE_INT(verbosity),
        ECORE_GETOPT_VALUE_STR(theme),
        ECORE_GETOPT_VALUE_STR(engine),
        ECORE_GETOPT_VALUE_NONE
     };

   elm_policy_set(ELM_POLICY_QUIT, ELM_POLICY_QUIT_LAST_WINDOW_CLOSED);
   elm_app_compile_bin_dir_set(PACKAGE_BIN_DIR);
   elm_app_compile_lib_dir_set(PACKAGE_LIB_DIR);
   elm_app_compile_data_dir_set(PACKAGE_DATA_DIR);
   elm_app_info_set(elm_main, PACKAGE_NAME, "themes/default.edj");

   args = ecore_getopt_parse(&options, values, argc, argv);

   if (args < 0)
     {
        fprintf(stderr, "ERROR: could not parse command line options.\n");
        return EXIT_FAILURE;
     }

   if (exit) return EXIT_SUCCESS;

   /* if (geometry.x <= 0) geometry.x = 0; */
   /* if (geometry.y <= 0) geometry.y = 0; */

   eina_log_level += verbosity;
   if (eina_log_level > EINA_LOG_LEVEL_DBG)
     eina_log_level = EINA_LOG_LEVEL_DBG;
   eina_log_level_set(eina_log_level);

   snprintf(edje_file_path, sizeof(edje_file_path),
            "%s/themes/%s", elm_app_data_dir_get(), theme);

   if (engine) elm_config_preferred_engine_set(engine);

   eina_log_color_disable_set(EINA_FALSE);
   _log_dom = eina_log_domain_register(PACKAGE_NAME, EINA_COLOR_CYAN);
   EINA_LOG_ERR("\n bin    : %s\n lib    : %s\n data   : %s\n",
          elm_app_bin_dir_get(),
          elm_app_lib_dir_get(),
          elm_app_data_dir_get());

   return efl_hello_world(edje_file_path, fullscreen, geometry);
}

ELM_MAIN()

