# dwm - dynamic window manager
This is my fork of dwm including the patches I enjoy. dwm is an extremely fast, small, and dynamic window manager for X.

## Patches and Workflow

All patches used have been found on https://dwm.suckless.org/patches/

- [centretitle](https://dwm.suckless.org/patches/centretitle/)
- [colorbar](https://dwm.suckless.org/patches/colorbar/)
- [fakefullscreen](https://dwm.suckless.org/patches/fakefullscreen/)
- [fullscreen](https://dwm.suckless.org/patches/fullscreen/)
- [swallow](https://dwm.suckless.org/patches/swallow/)
- [uselessgap](https://dwm.suckless.org/patches/uselessgap/)

### Swallow, fakefullscreen, and fullscreen

These patches provide the bulk of additional functionality in my build. I like having my terminal swallow windows it produces so there are no useless terminal windows taking up space. I use fullscreen a bit different. Fakefullscreen will prevent any window from actually going into fullscreen for example, if youtube is open in firefox, clicking the fullscreen button in the youtube player will only make the video as large as the firefox window. For the times when I want to actually go into fullscreen "mode" I use the fullscreen patch. This patch is bound to `SHIFT+ALT+F` and on press will toggle dwm's monocle layout with the focused window on top and disables the top bar. 

### The obligatory r/unixporn patches

Centretitle, colorbar, and uselessgap all provide no functionality other than additional fake internet points on r/unixporn. 

Centretitle just centers the title of the active window in dwm's top bar. Colorbar allows for more color customization in dwm's top bar. Uselessgap is exactly what the name implies, useless, wasted space between tiled windows. I do not actually think this space is wasted, it does make discerning the active window easier.

## Installation
Edit config.mk to match your local setup (dwm is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install dwm (if
necessary as root):

```bash
$ make clean install
```

## Running dwm

Add the following line to your .xinitrc to start dwm using startx:

```bash
exec dwm
```

In order to connect dwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:

```bash
DISPLAY=foo.bar:1 exec dwm
```

