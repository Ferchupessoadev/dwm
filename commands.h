// commands.h
#include <stdlib.h>
#include <unistd.h>

#ifndef COMMANDS_H
#define COMMANDS_H

/* commands */
/* component of dmenucmd, manipulated in spawn() */
static char dmenumon[2] = "0";

static const char *dmenucmd[] = {
    "dmenu_run",
    NULL,
};

static const char *launcher[] = {
    "dmenu_run_desktop", "-c", "-l", "10", NULL,
};

static const char *termcmd[] = {
    "st",
    NULL,
};

static const char *fileexplorer[] = {
    "file_manager.sh",
    NULL,
};

static const char *chromium[] = {
    "chromium",
    NULL,
};

static char *screenshot[] = {
    "flameshot", "screen", "--path", NULL, NULL,
};

static const char *volumeup[] = {
    "pactl", "set-sink-volume", "@DEFAULT_SINK@", "+10%", NULL,
};

static const char *volumedown[] = {
    "pactl", "set-sink-volume", "@DEFAULT_SINK@", "-10%", NULL,
};

static const char *volumemute[] = {
    "pactl", "set-sink-volume", "@DEFAULT_SINK@", "toggle", NULL,
};

#endif // COMMANDS_H
