// inputs (from globemouseupdate): HDC dc, int clientw, int clienth
// outputs (defined): double offsetx, double offsety
// outputs (global): globeceilingxy, discfloorxyz
// opens:   if (GetCursorPos(&mousep)) {

//  int screenw = GetSystemMetrics(SM_CXSCREEN);
//  int screenh = GetSystemMetrics(SM_CYSCREEN);
  BYTE kbstate[256];

// TODO: use initshift to create a kbstate array equivalent


  if (GetKeyboardState(kbstate)) {
    int kbshift = ISKEYDOWN(kbstate[VK_SHIFT]) ? 1 : 0;
//    int kbctrl = (kbstate[VK_CONTROL] > 1) ? 1 : 0;
    int kbletters = 0;
    int kbi = 'A' - 1;
    while (++kbi <= 'Z') {
      if (kbstate[kbi] > 1) { // ignore toggle
        kbletters++;
        int kbletter = kbi - 'A' + 'a';
        if (kbshift) { kbletter -= 'a' - 'A'; }
        PRESSVARLETTERKEY(kbletter);
      }
    }
    /*
    if (kbletters) {
      printf("KEYS: ");
      kbi = 'A' - 1;
      while (++kbi <= 'Z') {
        if (kbstate[kbi] > 1) { // ignore toggle
          printf(" [%d]:%d", kbi, kbstate[kbi]);
        }
      }
      printf("\n");
    }
    */
  }

  POINT mousep;
  if (GetCursorPos(&mousep)) {
    int mousex = (int)mousep.x;
    int mousey = (int)mousep.y;
//printf("%d,%d\n", mousex, mousey);
    char mousectrlkey = ISKEYDOWN(GetKeyState(VK_LCONTROL)) ? 1 : 0;
    char mouseshiftkey = ISKEYDOWN(GetKeyState(VK_LSHIFT) ) ? 1 : 0;
//    char mouseshiftkey = (GetKeyState(VK_LSHIFT) & 0x8000) ? 1 : 0;
    char swapmousekeys = mousectrlkey;
    mousectrlkey = mouseshiftkey;
    mouseshiftkey = swapmousekeys;
//    if (!mouseinshift && mouseshiftkey) {
// printf("%f,%f\n", scaleshiftx, scaleshifty);
//    scalex += scaleshiftx; // + (0.1 * scaleshift);
//    scaley += scaleshifty; // + (0.1 * scaleshift);
// moved to end of update function
    if (mousectrlkey) {
      if (!mouseinctrl) {
        mouseinctrl = 1;
        mdx[mdix] = mousex;
        mdy[mdix] = mousey;
        if (++mdix >= mdlen) { mdix = mdlen - 1; }
//        else { scalelevel++; } mdix ....
//        else { scaledivisor *= 2.0; rotatedivisor *= 10.0; }
      }
//      scaleshift += scaledivisor; //++;
    } else if (mouseinctrl && !mousectrlkey)
      { mouseinctrl = 0; }

    if (mouseshiftkey) {
      if (!mouseinshift) {
        mouseinshift = 1;
        if (--mdix < 0) { mdix = 0; }
//        else { scaledivisor *= 0.75; }
      }
//      scaleshift -= scaledivisor; // --; // -= (1.0 / scaledivisor) * scaledirection;
//      scaleshiftx = (mousex - mdx[mdix]) / scaledivisor;
//      scaleshifty = (mousey - mdy[mdix]) / scaledivisor;
    } else if (mouseinshift && !mouseshiftkey)
      { mouseinshift = 0; }



//    double dx = (double)mousex;// - mouselastx;
//    double dy = (double)mousey;// - mousethisy;
//    double offsetx = mouselastx + (dx / mousedivisor);
//    double offsety = mouselasty + (dy / mousedivisor);

    mdx[mdix] = mousex;
    mdy[mdix] = mousey;
    double offsetx = mdx[0];
    double offsety = mdy[0];
    double mdscale = 1.0;
    int mix = 0;
    while (++mix <= mdix) {
      mdscale /= 10.0;
      offsetx += mdscale * (mdx[mix] - mdx[mix - 1]);
      offsety += mdscale * (mdy[mix] - mdy[mix - 1]);
    }



