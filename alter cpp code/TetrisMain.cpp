// Copyright 2014, University of Freiburg,
// Student, Bachelor of Science, Mathematics.
// Author: Theresa Klumpp <therry.klumpp@web.de>.

#include <stdio.h>
#include <stdlib.h>
#include "./Tetris.h"

// Main function.
int main(int argc, char** argv) {
  // Parse command line arguments.
  if (argc != 1) {
    printf("Usage: ./TetrisMain\n");
    exit(1);
  }
  Tetris tetris;
  tetris.play();    // Start the game.
}
