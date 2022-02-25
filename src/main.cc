// FIXME: You can include various files from the librubik library
#include <algorithm>
#include <fstream>
#include <iostream>
#include <librubik/color.hh>
#include <librubik/cube.hh>
#include <librubik/piece.hh>
#include <librubik/vector3D.hh>

int main()
{
    // FIXME: This is where you should play around with librubik.
    // Do not forget to use the 'rubik' namespace prefix (rubik::Cube,
    // rubik::Move, ...)
    std::ifstream file("tests/cube_state_example.txt");
    auto example_cube = rubik::Cube::from_stream(file);
    std::cout << example_cube;

    std::cout << "EXIT BUG";

    return 0;
}
