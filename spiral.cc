#if 0 // compile using . spiral.cc
# optimise="-O2" # or -g for debug
# static="-s -static-libstdc++ -static-libgcc -static"
# standard="-std=c++11"
mingw="$(uname | grep -o MINGW)"
msys="$(uname | grep -o MSYS)"
standard=""
crosslibs="-lm -lpthread"
linlibs="-lGL -lGLU -lglut $crosslibs"
xplibs="-lgdi32 -luser32 -lkernel32 -lcomctl32"
winlibs="-mwindows $xplibs $crosslibs"
src=spiral.cc
# $gcc $optimise $static -o $out $src $libs
if [ "$mingw$msys" != "" ] ; then
  gcc=/mingw33/bin/g++.exe
  standard="-DXPEXE"
  if [ "$msys" != "" ] ; then
    gitpath="/c/Program Files/Git"
    gcc="$gitpath$gcc"
  fi # source /mingw33 from Git
  out=spiral.exe
  $gcc $standard -o $out $src $winlibs
else
  gcc=g++
  out=spiral.e
  $gcc $standard -o $out $src $linlibs
fi
return
#else // run ./spiral.e for linux or ./spiral.exe for windows
// include keyboard program -- might need to override globe2d main,
// otherwise insert extra code

// spiral.h needs glutPostRedisplay()

// common macros defined here
//#define ISKEYDOWN(kbstateval) \
//  (kbstateval > 1)
#define ISKEYDOWN(kbstateval) \
  ((kbstateval >> 8) == 1)
#define ISKEYTOGGLE(kbstateval) \
  ((kbstateval & 1) == 1)

#include "rle.h"
// rle shadow bitmap drawing in both win and lin
// rle packets sent by hoof to server sock
// server builds scaled drawing with bars or stretched
// keyboard in zhutou/pighead?


#ifdef XPEXE
#include "main.cpp"
#else
#include <GL/freeglut.h>
#include <GL/gl.h>
#include "spiral.h"
#include "main.cc"
#endif // !XPEXE

#endif // !0
