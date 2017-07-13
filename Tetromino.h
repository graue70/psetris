// Copyright 2014, University of Freiburg,
// Student, Bachelor of Science, Mathematics.
// Author: Theresa Klumpp <therry.klumpp@web.de>.

#include <string>
#ifndef _HOME_THERESA_PSETRIS_TETROMINO_H_
#define _HOME_THERESA_PSETRIS_TETROMINO_H_

class Structure;

// A class for a single Tetromino.
class Tetromino {
  friend class Structure;

 public:
  // Constructor.
  explicit Tetromino(Structure structure);

  // Reset Tetromino to given kind in starting position at the top.
  void reset(int kindOfTetromino, Structure structure);

  // Show Tetromino at current position. If showNotDelete == true, draw in
  // inverse video, otherwise draw spaces to delete it. If bottomReached, draw
  // in red.
  void show(bool showNotDelete, bool bottomReached);

  // Move Tetromino according to last key. If reverse == true, do the opposite.
  void move(int key, bool reverse);

 private:
  // Absolute position of the Tetromino.
  int _x;
  int _y;

  // Kind of Element.
  std::string _kind;

  // The "stretch" of a pixel.
  static int _sx;
  static int _sy;
};
#endif  // _HOME_THERESA_PSETRIS_TETROMINO_H_
