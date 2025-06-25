#include "RubiksCube.h"

class RubiksCube3dArray : public RubiksCube {
private:
    void rotateFace(int f) {
        char tmp[3][3];
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                tmp[i][j] = cube[f][i][j];

        for (int i = 0; i < 3; ++i) cube[f][0][i] = tmp[2 - i][0];
        for (int i = 0; i < 3; ++i) cube[f][i][2] = tmp[0][i];
        for (int i = 0; i < 3; ++i) cube[f][2][2 - i] = tmp[i][2];
        for (int i = 0; i < 3; ++i) cube[f][2 - i][0] = tmp[2][2 - i];
    }

public:
    char cube[6][3][3]{};

    RubiksCube3dArray() {
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    cube[i][j][k] = getColorLetter(COLOR(i));
    }

    COLOR getColor(FACE f, unsigned r, unsigned c) const override {
        char clr = cube[int(f)][r][c];
        switch (clr) {
            case 'B': return COLOR::BLUE;
            case 'R': return COLOR::RED;
            case 'G': return COLOR::GREEN;
            case 'O': return COLOR::ORANGE;
            case 'Y': return COLOR::YELLOW;
            default: return COLOR::WHITE;
        }
    }

    bool isSolved() const override {
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    if (cube[i][j][k] != getColorLetter(COLOR(i))) return false;
        return true;
    }

    RubiksCube &u() override {
        rotateFace(0);
        char temp[3];
        for (int i = 0; i < 3; ++i) temp[i] = cube[4][0][2 - i];
        for (int i = 0; i < 3; ++i) cube[4][0][2 - i] = cube[1][0][2 - i];
        for (int i = 0; i < 3; ++i) cube[1][0][2 - i] = cube[2][0][2 - i];
        for (int i = 0; i < 3; ++i) cube[2][0][2 - i] = cube[3][0][2 - i];
        for (int i = 0; i < 3; ++i) cube[3][0][2 - i] = temp[i];
        return *this;
    }

    RubiksCube &uPrime() override {
        return u().u().u();
    }

    RubiksCube &u2() override {
        return u().u();
    }

    RubiksCube &l() override {
        rotateFace(1);
        char temp[3];
        for (int i = 0; i < 3; ++i) temp[i] = cube[0][i][0];
        for (int i = 0; i < 3; ++i) cube[0][i][0] = cube[4][2 - i][2];
        for (int i = 0; i < 3; ++i) cube[4][2 - i][2] = cube[5][i][0];
        for (int i = 0; i < 3; ++i) cube[5][i][0] = cube[2][i][0];
        for (int i = 0; i < 3; ++i) cube[2][i][0] = temp[i];
        return *this;
    }

    RubiksCube &lPrime() override {
        return l().l().l();
    }

    RubiksCube &l2() override {
        return l().l();
    }

    RubiksCube &f() override {
        rotateFace(2);
        char temp[3];
        for (int i = 0; i < 3; ++i) temp[i] = cube[0][2][i];
        for (int i = 0; i < 3; ++i) cube[0][2][i] = cube[1][2 - i][2];
        for (int i = 0; i < 3; ++i) cube[1][2 - i][2] = cube[5][0][2 - i];
        for (int i = 0; i < 3; ++i) cube[5][0][2 - i] = cube[3][i][0];
        for (int i = 0; i < 3; ++i) cube[3][i][0] = temp[i];
        return *this;
    }

    RubiksCube &fPrime() override {
        return f().f().f();
    }

    RubiksCube &f2() override {
        return f().f();
    }

    RubiksCube &r() override {
        rotateFace(3);
        char temp[3];
        for (int i = 0; i < 3; ++i) temp[i] = cube[0][2 - i][2];
        for (int i = 0; i < 3; ++i) cube[0][2 - i][2] = cube[2][2 - i][2];
        for (int i = 0; i < 3; ++i) cube[2][2 - i][2] = cube[5][2 - i][2];
        for (int i = 0; i < 3; ++i) cube[5][2 - i][2] = cube[4][i][0];
        for (int i = 0; i < 3; ++i) cube[4][i][0] = temp[i];
        return *this;
    }

    RubiksCube &rPrime() override {
        return r().r().r();
    }

    RubiksCube &r2() override {
        return r().r();
    }

    RubiksCube &b() override {
        rotateFace(4);
        char temp[3];
        for (int i = 0; i < 3; ++i) temp[i] = cube[0][0][2 - i];
        for (int i = 0; i < 3; ++i) cube[0][0][2 - i] = cube[3][2 - i][2];
        for (int i = 0; i < 3; ++i) cube[3][2 - i][2] = cube[5][2][i];
        for (int i = 0; i < 3; ++i) cube[5][2][i] = cube[1][i][0];
        for (int i = 0; i < 3; ++i) cube[1][i][0] = temp[i];
        return *this;
    }

    RubiksCube &bPrime() override {
        return b().b().b();
    }

    RubiksCube &b2() override {
        return b().b();
    }

    RubiksCube &d() override {
        rotateFace(5);
        char temp[3];
        for (int i = 0; i < 3; ++i) temp[i] = cube[2][2][i];
        for (int i = 0; i < 3; ++i) cube[2][2][i] = cube[1][2][i];
        for (int i = 0; i < 3; ++i) cube[1][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; ++i) cube[4][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; ++i) cube[3][2][i] = temp[i];
        return *this;
    }

    RubiksCube &dPrime() override {
        return d().d().d();
    }

    RubiksCube &d2() override {
        return d().d();
    }

    bool operator==(const RubiksCube3dArray &rhs) const {
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    if (cube[i][j][k] != rhs.cube[i][j][k]) return false;
        return true;
    }

    RubiksCube3dArray &operator=(const RubiksCube3dArray &rhs) {
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    cube[i][j][k] = rhs.cube[i][j][k];
        return *this;
    }
};

struct Hash3d {
    size_t operator()(const RubiksCube3dArray &r) const {
        string str = "";
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    str += r.cube[i][j][k];
        return hash<string>()(str);
    }
};
