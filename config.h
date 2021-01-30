/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx 		= 4;        /* border pixel of windows */
static const unsigned int gappx     	= 15;       /* gaps between windows */
static const unsigned int snap      	= 32;       /* snap pixel */
static const int swallowfloating    	= 0;        /* 1 means swallow floating windows by default */
static const int showbar            	= 1;        /* 0 means no bar */
static const int topbar             	= 1;        /* 0 means bottom bar */
static const char *fonts[]  	        = { "DejaVu Sans Mono Nerd Font:size=18", "DejaVu Sans Mono Nerd Font:size=24" };

/* // gruvbox blue */ 
/* static const char col_normalbg[]      = "#076678"; */
/* static const char col_normalfg[]      = "#ebdbb2"; */
/* static const char col_normalbd[]      = "#282828"; */
/* static const char col_selectbg[]      = "#076678"; */
/* static const char col_selectfg[]      = "#282828"; */
/* static const char col_selectbd[]      = "#076678"; */

// monochrome dark
/* static const char col_normalbg[]      = "#0a0a0a"; */
/* static const char col_normalfg[]      = "#c9c9c9"; */
/* static const char col_normalbd[]      = "#0a0a0a"; */
/* static const char col_selectbg[]      = "#c9c9c9"; */
/* static const char col_selectfg[]      = "#0a0a0a"; */
/* static const char col_selectbd[]      = "#c9c9c9"; */

// monochrome light 
static const char col_normalbg[]      = "#f1f1f1"; 
static const char col_normalfg[]      = "#212121"; 
static const char col_normalbd[]      = "#f1f1f1"; 
static const char col_selectbg[]      = "#212121"; 
static const char col_selectfg[]      = "#f1f1f1"; 
static const char col_selectbd[]      = "#f0544c"; 

// fav wal 
/* static const char col_normalbg[]      = "#060815"; */
/* static const char col_normalfg[]      = "#9fb9c1"; */
/* static const char col_normalbd[]      = "#060815"; */
/* static const char col_selectbg[]      = "#9fb9c1"; */
/* static const char col_selectfg[]      = "#060815"; */
/* static const char col_selectbd[]      = "#9fb9c1"; */

static const char *colors[][3] = {
        /*                  fg,           bg,            border   */
	[SchemeNorm]    = { col_normalfg, col_normalbg,  col_normalbd},
	[SchemeSel]     = { col_selectfg, col_selectbg,  col_selectbd},
	[SchemeStatus]  = { col_normalfg, col_normalbg,  "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel] = { col_selectfg, col_selectbg,  "#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
        [SchemeTagsNorm]= { col_normalfg, col_normalbg,  "#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
        [SchemeInfoSel] = { col_normalfg, col_normalbg,  "#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
        [SchemeInfoNorm]= { col_normalfg, col_normalbg,  "#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};


/* tagging */
static const char *tags[] = { "I", "II", "III", "IV", "V", "VI"};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class            instance  title           tags mask  isfloating  isterminal   noswallow  monitor */
	{ "Gimp",           NULL,     NULL,           0,         1,          0,           0,        -1 },
	{ "Alacritty",      NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ "kitty",          NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ "St",             NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ NULL,             NULL,     "Event Tester", 0,         1,          0,           1,        -1 }, /* xev */
	{ NULL,             NULL,     "Picture-in-Picture",           0,         1,          0,           0,        -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol   arrange function */
	{ "﩯",      tile },    /* first entry is default */
	{ "缾",      NULL },    /* no layout function means floating behavior */
	{ "",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] 		= { "dmenu_run", "-c","-m", dmenumon, NULL };
static const char *termcmd[]  		= { "alacritty", NULL };
static const char *webcmd[] 		= {"librewolf", NULL};
static const char *webprivatecmd[] 	= {"librewolf", "--private-window", NULL};
static const char *volup[] 		= {"dwm_volup", NULL};
static const char *voldn[] 		= {"dwm_voldown", NULL};
static const char *briup[]		= {"dwm_brightnessup", NULL};
static const char *bridn[] 		= {"ddwm_brightnessdown", NULL};
static const char *audio[] 		= {"audio", NULL};
static const char *net[] 		= {"networkmanager_dmenu", NULL};
static const char *ss[] 		= {"screenshot", NULL};
static const char *clipmenu[] 		= {"clipmenu", NULL};
static const char *passmenu[] 		= {"passmenu", NULL};
static const char *mount[] 		= {"dmenumount", NULL};
static const char *dmenuexit[] 		= {"dmenuexit", NULL};
static const char *emoji[] 		= {"emojenu", NULL};

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_space,  spawn,          {.v = clipmenu } },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
    { MODKEY|ShiftMask,             XK_w,      spawn,          {.v = webcmd} },
    { MODKEY|ShiftMask,             XK_n,      spawn,          {.v = webprivatecmd} },
	{ MODKEY,                       XK_F12,    spawn,          {.v = volup } },
	{ MODKEY,                       XK_F11,    spawn,          {.v = voldn } },
	{ MODKEY,                       XK_F1,     spawn,          {.v = bridn } },
	{ MODKEY,                       XK_F2,     spawn,          {.v = briup } },
	{ MODKEY|ShiftMask,             XK_o,      spawn,          {.v = audio } },
	{ MODKEY|ShiftMask,             XK_i,      spawn,          {.v = net } },
	{ MODKEY|ShiftMask,             XK_k,      spawn,          {.v = passmenu } },
	{ MODKEY|ShiftMask,             XK_m,      spawn,          {.v = mount } },
	{ MODKEY|ShiftMask,             XK_q,      spawn,          {.v = dmenuexit } },
	{ MODKEY|ShiftMask,             XK_e,      spawn,          {.v = emoji } },
	{ MODKEY,                       XK_F10,    spawn,          {.v = ss } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_f,      fullscreen,     {0} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
