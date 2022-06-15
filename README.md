# notspiral

This is not spiral

. spiral.cc to compile
./spiral.exe to run (Windows) - works Native/in Wine
./spiral.e to run (Linux X11) - uses GLUT to simplify

rle integration needs shadow drawing because neither buffer
 is really accessible anyway

This is an early upload because it compiles in Windows XP
using mingw32 (and also msys2) and also in Linux (Mint)
Linux version spiral.e has no functional keyboard yet
Windows version spiral.exe can't read key/mouse at the same time
 and seems to have lost CTRL/SHIFT zoom but it all needs a rework
Next release will be notspiraltoo, and it will be an aggregator

Perspective drawing of lat/log sphere with rotating disc

rotating disc has linear actuators to be configured for inverse kinematics

(resolving the lengths from the angles from the target position)

remove return; in update() for broken auto-centreing

Z-X rotate, C-V actuator1, B-N actuator2
