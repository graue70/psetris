// Copyright 2014, University of Freiburg,
// Student, Bachelor of Science, Mathematics.
// Author: Theresa Klumpp <therry.klumpp@web.de>.

#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <iostream>
#include "./Tetris.h"
#include "./Tetromino.h"
#include "./Structure.h"

// _____________________________________________________________________________
Tetris::Tetris() {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
}

// _____________________________________________________________________________
Tetris::~Tetris() {
  fflush(stdout);
  sleep(3);        // Wait for 3 seconds.
  endwin();        // End game.
}

// _____________________________________________________________________________
void Tetris::play() {
  Structure structure;    // Create the empty structure.
  Tetromino tetromino(structure);    // Create a Tetromino.
  tetromino.show(true, false);
  int count = 0;
  int numberElements = 0;
  while (true) {
    // Get user input and definitely fall once every second.
    int key = getch();
    if (++count % 100 == 0) key = 65;  // Arrow up
    // Move up. Check if top is reached. Move down again.
    tetromino.move(65, false);
    bool topReached = structure.checkCollision(tetromino);
    tetromino.move(65, true);
    // If top is reached, add to structure.
    if (topReached) {
      tetromino.show(true, topReached);
      structure.addTetromino(tetromino);
      // If there are full rows, remove them and draw current structure.
      tetromino.reset(count, structure);    // Get a new random Tetromino.
      count = 0;
      numberElements++;
    }
    // Move Tetromino. If it collides, move back.
    tetromino.show(false, false);
    tetromino.move(key, false);
    if (structure.checkCollision(tetromino)) tetromino.move(key, true);
    tetromino.show(true, false);
    // Wait for 10 milliseconds.
    usleep(10 * 1000);
    if (numberElements > 43) {
      break;
      printf("\x1b[1m\x1b[1;1HGame Over!");
    }
  }
}
