#include <stdlib.h>
#include <stdio.h>
#include "x11ew.h"
#include <string.h>

static void openTestWindow(void) {
  Display *display;
  Window window;
  int screen;
  display = XOpenDisplay(NULL);
  if (display == NULL) {
    fprintf(stderr, "Cannot open display\n");
    exit(1);
  }
  screen = DefaultScreen(display);
  window = XCreateSimpleWindow(display,
                               RootWindow(display, screen),
                               10, 10,
                               100, 100,
                               1,
                               BlackPixel(display, screen),
                               WhitePixel(display, screen));
  XSelectInput(display, window, ExposureMask | KeyPressMask);
  XMapWindow(display, window);
  while (1) {
    XEvent event;
    XNextEvent(display, &event);
    if (event.type == Expose) {
      const char* message = "Hello, World!";
      GC gc = DefaultGC(display, screen);
      XFillRectangle(display, window, gc, 20, 20, 10, 10);
      XDrawString(display, window, gc, 10, 50, message, strlen(message));
    }
    if (event.type == KeyPress) {
      break;
    }
  }
  XCloseDisplay(display);
}

int main(int argc, char* argv[]) {
  (void) argc;  // Ignored.
  (void) argv;  // Ignored.
  if (x11ewInit() == X11EW_SUCCESS) {
    printf("X11 found\n");
    openTestWindow();
  }
  else {
    printf("X11 not found\n");
  }
  return EXIT_SUCCESS;
}
