/* border pixel of windows */
static const unsigned int borderpx = 1; /* border pixel of windows */
static const unsigned int gappx = 1;    /* gaps between windows */
static const unsigned int snap = 1;     /* snap pixel */

/* systray */
static const unsigned int systraypinning =
    0; // 0: sloppy systray follows selected monitor, >0: pin systray to monitor
       // X
static const unsigned int systrayonleft =
    0; // 0: systray in the right corner, >0: systray on left of status text
static const unsigned int systrayspacing = 2; // systray spacing
static const int systraypinningfailfirst =
    1; // 1: if pinning fails, display systray on the first monitor, False:
       // display systray on the last monitor
static const int showsystray = 1; // 0 means no systray

static const int showbar = 1; // 0 means no bar
static const int topbar = 1;  // 0 means bottom bar

static const char *fonts[] = {"JetBrains Mono Nerd Font:size=11"}; // fonts
static const char dmenufont[] = "JetBrains Mono:size=11";          // dmenu font

// colors
static const char col_gray1[] = "#222222";
static const char col_gray2[] = "#444444";
static const char col_gray3[] = "#bbbbbb";
static const char col_gray4[] = "#eeeeee";
static const char col_cyan[] = "#005577";

// themes
struct Theme {
  const char *inactive;
  const char *active;
  const char *bg;
  const char *focus;
};

static const struct Theme material = {
    .inactive = "#4c566a",
    .active = "#ffffff",
    .bg = "#0f101a",
    .focus = "#0f101a",
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

static const struct Theme gruvbox = {
    .inactive = "#928374",
    .active = "#fbf1c7",
    .bg = "#282828",
    .focus = "#83a598",
};

static const struct Theme solarized_dark = {
    .inactive = "#657b83",
    .active = "#93a1a1",
    .bg = "#002b36",
    .focus = "#b58900",
};

static const struct Theme dracula = {
    .inactive = "#6272a4",
    .active = "#f8f8f2",
    .bg = "#282a36",
    .focus = "#ff79c6",
};

static const struct Theme tomorrow_night = {
    .inactive = "#4d4d4c",
    .active = "#ffffff",
    .bg = "#1d1f21",
    .focus = "#cc6666",
};

static const char window_border[] = "#000000";

// colors
static const char *colors[][3] = {
    // fg                 bg             border
    // Tema Nord
    {nord.inactive, nord.bg, window_border},
    {nord.active, nord.focus, nord.focus},

    // Tema Onedark
    {onedark.inactive, onedark.bg, window_border},
    {onedark.active, onedark.focus, onedark.focus},

    // Tema Material
    {material.inactive, material.bg, window_border},
    {material.active, material.focus, material.focus},

    // Tema Monokai Pro
    {monokai_pro.inactive, monokai_pro.bg, window_border},
    {monokai_pro.active, monokai_pro.focus, monokai_pro.focus},

    // Tema Gruvbox
    {gruvbox.inactive, gruvbox.bg, window_border},
    {gruvbox.active, gruvbox.focus, gruvbox.focus},

    // Tema Solarized Dark
    {solarized_dark.inactive, solarized_dark.bg, window_border},
    {solarized_dark.active, solarized_dark.focus, solarized_dark.focus},

    // Tema Dracula
    {dracula.inactive, dracula.bg, window_border},
    {dracula.active, dracula.focus, dracula.focus},

    // Tema Tomorrow Night
    {tomorrow_night.inactive, tomorrow_night.bg, window_border},
    {tomorrow_night.active, tomorrow_night.focus, tomorrow_night.focus},
};

static const char *tags[] = {"󰖟", "", "", "󰙯", "",
                             "",  "", "", " "}; // tags

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

static const float mfact = 0.5; // factor of master area size [0.05..0.95]
static const int nmaster = 1;   // number of clients in master area */
static const int resizehints =
    1; // 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; // 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    {
        " ",
        tile,
    }, /* first entry is default */
    {
        " ",
        NULL,
    }, /* no layout function means floating behavior */
    {
        "",
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

#include "./exitdwm.c"
#include "commands.h"
#include <X11/XF86keysym.h>
static const Key keys[] = {
    /* modifier                     key        function        argument */
    {MODKEY, XK_d, spawn, {.v = dmenucmd}},
    {MODKEY, XK_r, spawn, {.v = launcher}},
    {MODKEY, XK_Return, spawn, {.v = termcmd}},
    {MODKEY, XK_g, spawn, {.v = chromium}},

    /* volume control */
    {0, XF86XK_AudioRaiseVolume, spawn, {.v = volumeup}},   // volume up
    {0, XF86XK_AudioLowerVolume, spawn, {.v = volumedown}}, // volume down
    {0, XF86XK_AudioMute, spawn, {.v = volumemute}},        // mute
    {0, XK_Print, spawn, {.v = screenshot}},                // screenshot

    {MODKEY, XK_e, spawn, {.v = fileexplorer}}, // file explorer

    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY | ShiftMask, XK_t, schemeToggle, {0}},
    {MODKEY | ShiftMask, XK_z, schemeCycle, {0}},
    {MODKEY, XK_p, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY | ShiftMask, XK_Return, zoom, {0}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY | ShiftMask, XK_q, killclient, {0}},
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_s, togglesticky, {0}}, // toggle sticky
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
    {ClkWinTitle, 0, Button2, zoom, {0}},
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
