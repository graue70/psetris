// Copyright 2014, University of Freiburg,
// Student, Bachelor of Science, Mathematics.
// Author: Theresa Klumpp <therry.klumpp@web.de>.

#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include "./Tetromino.h"
#include "./Tetris.h"
#include "./Structure.h"

// _____________________________________________________________________________
Structure::Structure() {
  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 12; y++) {
      if ( y == 11 || x == 9 || x == 0 || (y == 10 && x != 1 && x != 8) ) {
      _cells[x][y] = true; _elements[x][y] = ""; } else { _cells[x][y]=false; }
    }
  }
  // Initializing PSE
  {
    _elements[1][10] = "H";
    _elements[8][10] = "He";
    _elements[1][9]= "Li";
    _elements[2][9]= "Be";
    _elements[3][9]= "B";
    _elements[4][9]= "C";
    _elements[5][9]= "N";
    _elements[6][9]= "O";
    _elements[7][9]= "F";
    _elements[8][9]= "Ne";
    _elements[1][8]= "Na";
    _elements[2][8]= "Mg";
    _elements[3][8]= "Al";
    _elements[4][8]= "Si";
    _elements[5][8]= "P";
    _elements[6][8]= "S";
    _elements[7][8]= "Cl";
    _elements[8][8]= "Ar";
    _elements[1][7]= "K";
    _elements[2][7]= "Ca";
    _elements[3][7]= "Ga";
    _elements[4][7]= "Ge";
    _elements[5][7]= "As";
    _elements[6][7]= "Se";
    _elements[7][7]= "Br";
    _elements[8][7]= "Kr";
    _elements[1][6]= "Rb";
    _elements[2][6]= "Sr";
    _elements[3][6]= "In";
    _elements[4][6]= "Sn";
    _elements[5][6]= "Sb";
    _elements[6][6]= "Te";
    _elements[7][6]= "I";
    _elements[8][6]= "Xe";
    _elements[1][5]= "Cs";
    _elements[2][5]= "Ba";
    _elements[3][5]= "Tl";
    _elements[4][5]= "Pb";
    _elements[5][5]= "Bi";
    _elements[6][5]= "Po";
    _elements[7][5]= "At";
    _elements[8][5]= "Rn";
    _elements[1][4]= "Fr";
    _elements[2][4]= "Ra";
  }

  _possibleElements.push_back("H");
  _possibleElements.push_back("Be");
  _possibleElements.push_back("B");
  _possibleElements.push_back("C");
  _possibleElements.push_back("N");
  _possibleElements.push_back("O");
  _possibleElements.push_back("F");
  _possibleElements.push_back("He");
}

// _____________________________________________________________________________
void Structure::addTetromino(Tetromino tetromino) {
  int x = tetromino._x;
  int y = tetromino._y;
  // True if elements[x][y] is equal to tetromino._kind
  if ( !_elements[x][y].compare(tetromino._kind) ) {
    _cells[x][y] = true;  // Turn the cell of the Tetromino true.
    // Delete Element from possibleElements if it was in the right spot.
    for ( size_t k = 0; k < _possibleElements.size(); k++ ) {
      if ( !_possibleElements[k].compare(tetromino._kind) ) {
        _possibleElements.erase(_possibleElements.begin()+k);
        break;
      }
    }
    if (_elements[x][y-1].compare("")) {
      _possibleElements.push_back(_elements[x][y-1]);
    }
  }
}

// _____________________________________________________________________________
bool Structure::checkCollision(Tetromino tetromino) {
  int x = tetromino._x;
  int y = tetromino._y;
  // Check if Tetromino collides with another Tetromino or border.
  if (_cells[x][y]) return true;
  return false;   // No collision.
}

// _____________________________________________________________________________
bool _cells[10][12];
