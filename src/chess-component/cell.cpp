#include "chess-component/cell.h"

Cell::Cell(unsigned int row, unsigned int column, bool empty)
    : m_row(row), m_column(column), m_empty(empty) {
    m_positionNotation[0] = 'a' + m_column;
    m_positionNotation[1] = '8' - m_row;
}
Cell::Cell(unsigned int row, unsigned int column, bool empty, Piece *piece) 
    : m_row(row), m_column(column), m_empty(empty), mp_piece(piece) {
    m_positionNotation[0] = 'a' + m_column;
    m_positionNotation[1] = '8' - m_row;
}

unsigned int Cell::getRow() {
    return m_row;
}
unsigned int Cell::getColumn() {
    return m_column;
}
std::string Cell::getPositionNotation() {
    std::string notation = "";
    notation += m_positionNotation[0];
    notation += m_positionNotation[1];
    return notation;
}
std::string Cell::getRowNotation() {
    std::string notation = "";
    notation += m_positionNotation[0];
    return notation;
}
std::string Cell::getColumnNotation() {
    std::string notation = "";
    notation += m_positionNotation[1];
    return notation;
}
void Cell::setEmpty() {
    if(!m_empty) {
        delete mp_piece;
        mp_piece = nullptr;
        m_empty = true;
    };
}
bool Cell::isEmpty() {
    return m_empty;
}

Piece &Cell::getPiece() {
    return *mp_piece;
}
void Cell::setPiece(Piece *piece) {
    mp_piece = piece;
}