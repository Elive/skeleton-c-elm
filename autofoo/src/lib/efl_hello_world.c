
#include "config.h"
#include "efl_hello_world.h"

#include <Elementary.h>

static Eina_Bool sigint_handler(void *data, int ev_type, void *ev)
{
    EINA_LOG_DBG("Ctrl-C hit");
    elm_exit();
    return EINA_TRUE;
}

static void
on_done(void *data EINA_UNUSED,
        Evas_Object *obj EINA_UNUSED,
        void *event_info EINA_UNUSED)
{
   elm_exit();
}

int
efl_hello_world(const char *edje_file_path,
                Eina_Bool fullscreen,
                Eina_Rectangle geometry)
{
   ecore_event_handler_add(ECORE_EVENT_SIGNAL_EXIT, sigint_handler, NULL);

   Evas_Object *win, *box, *lab, *btn;

   win = elm_win_util_standard_add("hello", "Hello Title");
   evas_object_smart_callback_add(win, "delete,request", on_done, NULL);

   // add a vertical box as a resize object for the window
   // (controls window minimum size and gets resized if window is resized)
   box = elm_box_add(win);
   elm_box_horizontal_set(box, EINA_TRUE);
   elm_win_resize_object_add(win, box);
   evas_object_show(box);

   // add a label widget, set the text
   // pack it at the end of the box
   lab = elm_label_add(win);
   elm_object_text_set(lab, "Hello out there world!");
   elm_box_pack_end(box, lab);
   evas_object_show(lab);

   // add a button widget, set the text
   // pack it at the end of the box
   // call on_done when it is clicked
   btn = elm_button_add(win);
   elm_object_text_set(btn, "OK");
   elm_box_pack_end(box, btn);
   evas_object_show(btn);
   evas_object_smart_callback_add(btn, "clicked", on_done, NULL);

   evas_object_show(win);

   if (fullscreen)
     elm_win_fullscreen_set(win, fullscreen);
   else
     {
        if (geometry.w > -1 && geometry.h > -1)
          evas_object_resize(win, geometry.w, geometry.h);
        if (geometry.x > -1 && geometry.y > -1)
          evas_object_move(win, geometry.x, geometry.y);
     }

   elm_run();
   elm_shutdown();
   return 0;
}

