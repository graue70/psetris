// Copyright 2014, University of Freiburg,
// Student, Bachelor of Science, Mathematics.
// Author: Theresa Klumpp <therry.klumpp@web.de>.

#include <string>
#include <vector>
#include "./Tetromino.h"
#ifndef _HOME_THERESA_PSETRIS_STRUCTURE_H_
#define _HOME_THERESA_PSETRIS_STRUCTURE_H_

// Class for the Structure.
class Structure {
  friend class Tetromino;

 public:
  // Create empty structure.
  Structure();

  // Add Tetromino to structure.
  void addTetromino(Tetromino tetromino);

  // Check if Tetromino collides with structure or border.
  bool checkCollision(Tetromino tetromino);

 private:
  // One bool for each of the 10 x 20 possible cells.
  bool _cells[10][12];

  // Element structure
  std::string _elements[10][12];

  // Vector with possible Elements.
  std::vector<std::string> _possibleElements;
};
#endif  // _HOME_THERESA_PSETRIS_STRUCTURE_H_
