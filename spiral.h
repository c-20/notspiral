

// doesn't work with LONG ?

#define VK_SHIFT   0x10
#define VK_CTRL    0x11
#define VK_ALT     0x12

#define VK_LSHIFT   0xA0
#define VK_RSHIFT   0xA1
#define VK_LCONTROL 0xA2
#define VK_RCONTROL 0xA3
#define VK_LMENU    0xA4
#define VK_RMENU    0xA5

#define NUMKEYS     256

typedef long LONG;
typedef char BOOL;
typedef short int SHORT;
typedef unsigned char BYTE;

BYTE keydown[NUMKEYS];
BYTE keytoggle[NUMKEYS];

BOOL GetKeyboardState(BYTE *kbstate) {
  int ix = -1;
  while (++ix < NUMKEYS) {
    SHORT keystate = (keydown[ix] << 8) + keytoggle[ix];
    kbstate[ix] = keystate;
  }
  return 1; // TRUE
}

SHORT GetKeyState(int index) {
  SHORT keystate = (keydown[index] << 8) + keytoggle[index];
  return keystate;
}

typedef struct _POINT {
//  long x;
//  long y;
  int x;
  int y;
} POINT; // , *PPOINT;

POINT cursorposition = { 0, 0 };

BOOL GetCursorPos(POINT *point) {
  point->x = cursorposition.x;
  point->y = cursorposition.y;
  return 1; // TRUE
}

// cannot set window.mouse for GetCursorPos
void glutmousemove(int x, int y) {
  cursorposition.x = x;
  cursorposition.y = y;
  glutPostRedisplay();
}
