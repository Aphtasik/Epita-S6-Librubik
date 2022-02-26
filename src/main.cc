// FIXME: You can include various files from the librubik library
#include <algorithm>
#include <fstream>
#include <iostream>
#include <librubik/color.hh>
#include <librubik/cube.hh>
#include <librubik/piece.hh>
#include <librubik/vector3D.hh>
#include <librubik/matrix3D.hh>
#include <librubik/move.hh>

int main()
{
    // FIXME: This is where you should play around with librubik.
    // Do not forget to use the 'rubik' namespace prefix (rubik::Cube,
    // rubik::Move, ...)
    //

    // rubik::Cube cube;
    // rubik::Move m;
    // m.mvt = rubik::Face::RIGHT;
    // cube.do_move(m);
    // std::cout << cube << "\n";

    rubik::Cube cube;
    cube.do_moves(rubik::parse_moves("F' D' R2 x L' U B R F U2 F2 L2 L y2 F' B2 U2 D B' z'"));
    std::cout << cube << "\n";


    return 0;
}
