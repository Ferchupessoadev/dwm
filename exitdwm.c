#include "dwm.h"
#include "exitdwm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exitdwm() {
  FILE *exit_menu = popen(
      "echo \"" S_FORMAT(LOCK) "\n" S_FORMAT(RESTART_DWM) "\n" S_FORMAT(OFFSCREEN) "\n" S_FORMAT(
          EXIT) "\n" S_FORMAT(REBOOT) "\n" S_FORMAT(SHUTDOWN) "\" | dmenu "
                                                              "|"
                                                              " " S_FORMAT_CLEAR,
      "r");

  char exit_action[16];

  if (exit_menu == NULL ||
      fscanf(exit_menu, "%15[a-zA-Z -]", exit_action) == EOF) {
    fputs("Error. Failure in exit_dwm.", stderr);
    goto close_streams;
  }

  if (strcmp(exit_action, S_LOCK) == 0)
    system("slock & sleep .5; xset dpms force off");
  else if (strcmp(exit_action, S_RESTART_DWM) == 0)
    quit(&(const Arg){1});
  else if (strcmp(exit_action, S_OFFSCREEN) == 0)
    system("sleep .5; xset dpms force off");
  else if (strcmp(exit_action, S_EXIT) == 0)
    quit(&(const Arg){0});
  else if (strcmp(exit_action, S_REBOOT) == 0)
    system("systemctl reboot");
  else if (strcmp(exit_action, S_SHUTDOWN) == 0)
    system("systemctl poweroff -i");

close_streams:
  pclose(exit_menu);
}
