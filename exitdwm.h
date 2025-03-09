#ifndef EXITDWM_H
#define EXITDWM_H

#include "dwm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined S_LOCK || defined S_RESTART_DWM || defined S_OFFSCREEN ||          \
    defined S_EXIT || defined S_REBOOT || defined S_SHUTDOWN ||                \
    defined S_LOCK_ICON || defined S_RESTART_DWM_ICON ||                       \
    defined S_OFFSCREEN_ICON || defined S_EXIT_ICON ||                         \
    defined S_REBOOT_ICON || defined S_SHUTDOWN_ICON || defined S_FORMAT ||    \
    defined S_FORMAT_CLEAR
#error("Conflicting macro names")
#endif

#define S_LOCK "Lock"
#define S_RESTART_DWM "Restart Dwm"
#define S_OFFSCREEN "Off-screen"
#define S_EXIT "Exit"
#define S_REBOOT "Reboot"
#define S_SHUTDOWN "Shutdown"
#define S_LOCK_ICON "\uf023"
#define S_RESTART_DWM_ICON "\uf01e"
#define S_OFFSCREEN_ICON "\uf108"
#define S_EXIT_ICON "\uf2f5"
#define S_REBOOT_ICON "\uf021"
#define S_SHUTDOWN_ICON "\uf011"

#define S_FORMAT(ACTION) S_##ACTION##_ICON " " S_##ACTION
#define S_FORMAT_CLEAR "sed 's/^..//'"

void exitdwm();

#endif // EXITDWM_H
