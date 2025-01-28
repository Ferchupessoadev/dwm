#ifndef DWM_H
#define DWM_H

typedef union {
  int i;
  unsigned int ui;
  float f;
  const void *v;
} Arg;

void quit(const Arg *arg);

#endif // !
