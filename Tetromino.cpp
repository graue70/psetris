// Copyright 2014, University of Freiburg,
// Student, Bachelor of Science, Mathematics.
// Author: Theresa Klumpp <therry.klumpp@web.de>.

#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include "./Tetromino.h"
#include "./Structure.h"

// _____________________________________________________________________________
int Tetromino::_sx = 6;
int Tetromino::_sy = 3;

// _____________________________________________________________________________
Tetromino::Tetromino(Structure structure) {
  srand(time(0));
  reset(rand(), structure);          // Start with one kind of a Tetromino.
}

// _____________________________________________________________________________
void Tetromino::reset(int kindOfTetromino, Structure structure) {
  _x = 4;
  _y = 0;
  size_t k = structure._possibleElements.size();
  if (k == 0) {
    printf("\x1b[1m\x1b[1;1HYou won!");
  } else {
    _kind = structure._possibleElements[kindOfTetromino % k];
  }
}

// _____________________________________________________________________________
void Tetromino::show(bool showNotDelete, bool bottomReached) {
  // Draw inverse video if showNotDelete == True.
  if (showNotDelete) {
    printf("\x1b[7m");  // 7 = inverse video
//    printf("\x1b[30m");
  }
  // Draw red if bottom is reached.
  if (bottomReached) printf("\x1b[31m");  // 31 = color red
  for (int j = 0; j < _sx; j++) {
    for (int k = 0; k < _sy; k++) {
      printf("\x1b[%d;%dH ",  // n;mH: change poition to (n;m)
          (20 - _y) * _sy + k, (1 + _x) * _sx + j);
    }
  }
  if (showNotDelete) {
    printf("\x1b[40m");
//    printf("\x1b[1m");  // bold
    printf("\x1b[%d;%dH%c%c",
            (20 - _y) * _sy + 1, (1 + _x) * _sx + 1, _kind[0], _kind[1]);
  }
  printf("\x1b[0m");   // Print normal again.
  if (showNotDelete) fflush(stdout);
}

// _____________________________________________________________________________
void Tetromino::move(int key, bool reverse) {
  switch (key) {
    case 65:    // Arrow Up.
      if (reverse == false) _y++;
      if (reverse == true) _y--;
      break;
    case 67:    // Arrow Right.
      if (reverse == false) _x++;
      if (reverse == true) _x--;
      break;
    case 68:    // Arrow Left.
      if (reverse == false) _x--;
      if (reverse == true) _x++;
      break;
  }
}
