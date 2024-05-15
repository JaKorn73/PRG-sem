/*
 * filename: keyboard.c
 * author: Jan Faigl
*/
#include <stdio.h>
#include <stdlib.h>

#include "keyboard.h"

#include "utils.h"
#include "event_queue.h"

void* keyboard_thread(void*)
{
  return NULL;
  call_termios(0);
  char c;
  event ev;
  while((c = getchar()) != 'q') {
    ev.type = EV_TYPE_NUM;
    switch(c) {
      case 'g': //get version
        ev.type = EV_GET_VERSION;
        break;
      case 'a':
        ev.type = EV_ABORT;
        break;
      case 's':
        ev.type = EV_SET_COMPUTE;
        break;
      case 'c':
        ev.type = EV_COMPUTE;
        break;
      default:
        break;
    } //end switch
    if (ev.type != EV_TYPE_NUM)
      queue_push(ev);

  } //end while
  set_quit();
  ev.type = EV_QUIT;
  queue_push(ev);
  call_termios(1); // restore terminal settings

  return NULL;
}