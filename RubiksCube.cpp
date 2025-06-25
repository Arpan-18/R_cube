//Arpan
#include "RubiksCube.h"

char RubiksCube::getColorLetter(COLOR color) {
    switch (color) {
        case COLOR::BLUE:
            return 'B';
        case COLOR::GREEN:
            return 'G';
        case COLOR::RED:
            return 'R';
        case COLOR::YELLOW:
            return 'Y';
        case COLOR::WHITE:
            return 'W';
        case COLOR::ORANGE:
            return 'O';
    }
}

string RubiksCube::getMove(MOVE moveType) {
    switch (moveType) {
        case MOVE::L: return "L";
        case MOVE::LPRIME: return "L'";
        case MOVE::L2: return "L2";
        case MOVE::R: return "R";
        case MOVE::RPRIME: return "R'";
        case MOVE::R2: return "R2";
        case MOVE::U: return "U";
        case MOVE::UPRIME: return "U'";
        case MOVE::U2: return "U2";
        case MOVE::D: return "D";
        case MOVE::DPRIME: return "D'";
        case MOVE::D2: return "D2";
        case MOVE::F: return "F";
        case MOVE::FPRIME: return "F'";
        case MOVE::F2: return "F2";
        case MOVE::B: return "B";
        case MOVE::BPRIME: return "B'";
        case MOVE::B2: return "B2";
    }
}

RubiksCube& RubiksCube::move(MOVE moveType) {
    switch (moveType) {
        case MOVE::L: return this->l();
        case MOVE::LPRIME: return this->lPrime();
        case MOVE::L2: return this->l2();
        case MOVE::R: return this->r();
        case MOVE::RPRIME: return this->rPrime();
        case MOVE::R2: return this->r2();
        case MOVE::U: return this->u();
        case MOVE::UPRIME: return this->uPrime();
        case MOVE::U2: return this->u2();
        case MOVE::D: return this->d();
        case MOVE::DPRIME: return this->dPrime();
        case MOVE::D2: return this->d2();
        case MOVE::F: return this->f();
        case MOVE::FPRIME: return this->fPrime();
        case MOVE::F2: return this->f2();
        case MOVE::B: return this->b();
        case MOVE::BPRIME: return this->bPrime();
        case MOVE::B2: return this->b2();
    }
}

RubiksCube& RubiksCube::invert(MOVE moveType) {
    switch (moveType) {
        case MOVE::L: return this->lPrime();
        case MOVE::LPRIME: return this->l();
        case MOVE::L2: return this->l2();
        case MOVE::R: return this->rPrime();
        case MOVE::RPRIME: return this->r();
        case MOVE::R2: return this->r2();
        case MOVE::U: return this->uPrime();
        case MOVE::UPRIME: return this->u();
        case MOVE::U2: return this->u2();
        case MOVE::D: return this->dPrime();
        case MOVE::DPRIME: return this->d();
        case MOVE::D2: return this->d2();
        case MOVE::F: return this->fPrime();
        case MOVE::FPRIME: return this->f();
        case MOVE::F2: return this->f2();
        case MOVE::B: return this->bPrime();
        case MOVE::BPRIME: return this->b();
        case MOVE::B2: return this->b2();
    }
}

void RubiksCube::print() const {
    cout << "Rubik's Cube:\n\n";

    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::UP, row, col)) << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    for (int row = 0; row <= 2; row++) {
        for (int col = 0; col <= 2; col++) cout << getColorLetter(getColor(FACE::LEFT, row, col)) << " ";
        cout << " ";
        for (int col = 0; col <= 2; col++) cout << getColorLetter(getColor(FACE::FRONT, row, col)) << " ";
        cout << " ";
        for (int col = 0; col <= 2; col++) cout << getColorLetter(getColor(FACE::RIGHT, row, col)) << " ";
        cout << " ";
        for (int col = 0; col <= 2; col++) cout << getColorLetter(getColor(FACE::BACK, row, col)) << " ";
        cout << "\n";
    }

    cout << "\n";

    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::DOWN, row, col)) << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

vector<RubiksCube::MOVE> RubiksCube::randomShuffleCube(unsigned int times) {
    vector<MOVE> moveList;
    srand(time(0));
    for (unsigned int i = 0; i < times; i++) {
        unsigned int moveIndex = rand() % 18;
        moveList.push_back(static_cast<MOVE>(moveIndex));
        this->move(static_cast<MOVE>(moveIndex));
    }
    return moveList;
}

string RubiksCube::getCornerColorString(uint8_t index) const {
    string result = "";
    switch (index) {
        case 0:
            result += getColorLetter(getColor(FACE::UP, 2, 2));
            result += getColorLetter(getColor(FACE::FRONT, 0, 2));
            result += getColorLetter(getColor(FACE::RIGHT, 0, 0));
            break;
        case 1:
            result += getColorLetter(getColor(FACE::UP, 2, 0));
            result += getColorLetter(getColor(FACE::FRONT, 0, 0));
            result += getColorLetter(getColor(FACE::LEFT, 0, 2));
            break;
        case 2:
            result += getColorLetter(getColor(FACE::UP, 0, 0));
            result += getColorLetter(getColor(FACE::BACK, 0, 2));
            result += getColorLetter(getColor(FACE::LEFT, 0, 0));
            break;
        case 3:
            result += getColorLetter(getColor(FACE::UP, 0, 2));
            result += getColorLetter(getColor(FACE::BACK, 0, 0));
            result += getColorLetter(getColor(FACE::RIGHT, 0, 2));
            break;
        case 4:
            result += getColorLetter(getColor(FACE::DOWN, 0, 2));
            result += getColorLetter(getColor(FACE::FRONT, 2, 2));
            result += getColorLetter(getColor(FACE::RIGHT, 2, 0));
            break;
        case 5:
            result += getColorLetter(getColor(FACE::DOWN, 0, 0));
            result += getColorLetter(getColor(FACE::FRONT, 2, 0));
            result += getColorLetter(getColor(FACE::LEFT, 2, 2));
            break;
        case 6:
            result += getColorLetter(getColor(FACE::DOWN, 2, 2));
            result += getColorLetter(getColor(FACE::BACK, 2, 0));
            result += getColorLetter(getColor(FACE::RIGHT, 2, 2));
            break;
        case 7:
            result += getColorLetter(getColor(FACE::DOWN, 2, 0));
            result += getColorLetter(getColor(FACE::BACK, 2, 2));
            result += getColorLetter(getColor(FACE::LEFT, 2, 0));
            break;
    }
    return result;
}

uint8_t RubiksCube::getCornerIndex(uint8_t index) const {
    string corner = getCornerColorString(index);
    uint8_t result = 0;
    for (auto c : corner) {
        if (c == 'Y') result |= (1 << 2);
    }
    for (auto c : corner) {
        if (c == 'O') result |= (1 << 1);
    }
    for (auto c : corner) {
        if (c == 'G') result |= (1 << 0);
    }
    return result;
}

uint8_t RubiksCube::getCornerOrientation(uint8_t index) const {
    string corner = getCornerColorString(index);
    string filtered = "";
    for (auto c : corner) {
        if (c == 'W' || c == 'Y') filtered.push_back(c);
    }
    if (corner[1] == filtered[0]) return 1;
    else if (corner[2] == filtered[0]) return 2;
    else return 0;
}
