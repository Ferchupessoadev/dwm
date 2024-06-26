/* border pixel of windows */
static const unsigned int borderpx = 1;

/* gaps between windows */
static const unsigned int gappx = 10;

/* snap pixel */
static const unsigned int snap = 32;

/* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systraypinning = 0;

/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayonleft = 0;

/* systray spacing */
static const unsigned int systrayspacing = 2;
/* 1: if pinning fails, display systray on the first monitor, False:
   display systray on the last monitor*/
static const int systraypinningfailfirst = 1;

/* 0 means no systray */
static const int showsystray = 1;

/* 0 means no bar */
static const int showbar = 1;

/* 0 means bottom bar */
static const int topbar = 1;
static const char *fonts[] = {"JetBrains Mono Nerd Font:size=11"};
static const char dmenufont[] = "JetBrains Mono:size=11";
static const char col_gray1[] = "#222222";
static const char col_gray2[] = "#444444";
static const char col_gray3[] = "#bbbbbb";
static const char col_gray4[] = "#eeeeee";
static const char col_cyan[] = "#005577";

struct Theme {
  char *inactive;
  char *active;
  char *bg;
  char *focus;
};

static const struct Theme material = {
    .inactive = "#4c566a",
    .active = "#ffffff",
    .bg = "#0f101a",
    .focus = "#a151d3",
};

static const struct Theme onedark = {
    .inactive = "#4c566a",
    .active = "#ffffff",
    .bg = "#1e2127",
    .focus = "#E06C75",
};

static const struct Theme nord = {
    .inactive = "#4c566a",
    .active = "#ffffff",
    .bg = "#2e3440",
    .focus = "#81a1c1",
};

static const struct Theme monokai_pro = {
    .inactive = "#727072",
    .active = "#2d2a2e",
    .bg = "#2d2a2e",
    .focus = "#a9dc76",
};

static const char window_border[] = "#000000";

static const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {onedark.inactive, onedark.bg, window_border},
    [SchemeSel] = {onedark.active, onedark.focus, onedark.focus},
};

/* tagging */
static const char *tags[] = {"", "", "", "", "󰙯", "󰉋"};

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    {"Gimp", NULL, NULL, 0, 1, -1},
    {"Firefox", NULL, NULL, 1 << 8, 0, -1},
};

/* layout(s) */
/* factor of master area size [0.05..0.95] */
static const float mfact = 0.5;

/* number of clients in master area */
static const int nmaster = 1;

/* 1 means respect size hints in tiled resizals */
static const int resizehints = 1;

/* 1 will force focus on the fullscreen window */
static const int lockfullscreen = 1;

static const Layout layouts[] = {
    /* symbol     arrange function */
    {
        "[]=",
        tile,
    }, /* first entry is default */
    {
        "><>",
        NULL,
    }, /* no layout function means floating behavior */
    {
        "[M]",
        monocle,
    },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

#define STATUSBAR "dwmblocks"

/* commands */
/* component of dmenucmd, manipulated in spawn() */
static char dmenumon[2] = "0";

static const char *dmenucmd[] = {
    "dmenu_run",
    "-l",
    "10",
    NULL,
};

static const char *termcmd[] = {
    "st",
    NULL,
};

static const char *fileexplorer[] = {
    "pcmanfm",
    NULL,
};

static const char *chromium[] = {
    "chromium",
    NULL,
};

static const char *screenshot[] = {
    "flameshot", "screen", "--path", "~/Imágenes/screenshot", NULL,
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

#include "./exitdwm.c"
#include <X11/XF86keysym.h>
static const Key keys[] = {
    /* modifier                     key        function        argument */
    {MODKEY, XK_d, spawn, {.v = dmenucmd}},
    {MODKEY, XK_Return, spawn, {.v = termcmd}},
    {MODKEY, XK_g, spawn, {.v = chromium}},
    // volume
    {0, XF86XK_AudioRaiseVolume, spawn, {.v = volumeup}},
    {0, XF86XK_AudioLowerVolume, spawn, {.v = volumedown}},
    {0, XF86XK_AudioMute, spawn, {.v = volumemute}},
    // screenshot
    {0, XK_Print, spawn, {.v = screenshot}},
    // file explorer
    {MODKEY, XK_e, spawn, {.v = fileexplorer}},
    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY, XK_p, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY, XK_Return, zoom, {0}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY | ShiftMask, XK_q, killclient, {0}},
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
    {MODKEY, XK_minus, setgaps, {.i = -1}},
    {MODKEY, XK_equal, setgaps, {.i = +1}},
    {MODKEY | ShiftMask, XK_equal, setgaps, {.i = 0}},
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8){MODKEY | ShiftMask, XK_e, exitdwm, {0}},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkStatusText, 0, Button1, sigstatusbar, {.i = 1}},
    {ClkStatusText, 0, Button2, sigstatusbar, {.i = 2}},
    {ClkStatusText, 0, Button3, sigstatusbar, {.i = 3}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
