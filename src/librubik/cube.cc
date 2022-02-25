#include "cube.hh"

namespace rubik
{
    Cube::Cube(std::vector<Piece> p)
    {
        pieces_ = p;
    }

    Cube::Cube()
    {
        // x == -1 => blue on x
        // x == 1 => green on x
        // y == -1 => orange on y
        // y == 1 => red on y
        // z == -1 => yellow on z
        // z == 1 => white on z
        Vector3D<int> coords;
        Vector3D<Color> colors;
        for (int x = -1; x < 2; x++)
        {
            for (int y = -1; y < 2; y++)
            {
                for (int z = -1; z < 2; z++)
                {
                    coords.x = x;
                    coords.y = y;
                    coords.z = z;

                    if (x == -1)
                        colors.x = Color::BLUE;
                    if (x == 0)
                        colors.x = Color::NONE;
                    if (x == 1)
                        colors.x = Color::GREEN;

                    if (y == -1)
                        colors.y = Color::ORANGE;
                    if (y == 0)
                        colors.y = Color::NONE;
                    if (y == 1)
                        colors.y = Color::RED;

                    if (z == -1)
                        colors.z = Color::YELLOW;
                    if (z == 0)
                        colors.z = Color::NONE;
                    if (z == 1)
                        colors.z = Color::WHITE;

                    Piece p = Piece();
                    p.coords = coords;
                    p.colors = colors;
                    pieces_.push_back(p);
                }
            }
        }
    }

    bool is_valid_num(char c)
    {
        return (c == '0' || c == '1' || c == '-');
    }

    bool is_valid_color(char c)
    {
        return (c == 'B' || c == 'G' || c == 'W' || c == 'Y' || c == 'O'
                || c == 'R' || c == 'X');
    }

    Color get_color_from_letter(std::string s)
    {
        if (s == "G")
            return Color::GREEN;
        if (s == "B")
            return Color::BLUE;
        if (s == "W")
            return Color::WHITE;
        if (s == "Y")
            return Color::YELLOW;
        if (s == "O")
            return Color::ORANGE;
        if (s == "R")
            return Color::RED;
        else
            return Color::NONE;
    }
} // namespace rubik

rubik::Cube rubik::Cube::from_stream(std::istream& file_in)
{
    std::string str;
    std::string line;
    std::vector<Piece> pieces;
    // For each line in file
    while (std::getline(file_in, line))
    {
        str.clear();
        int i = 0; // Line index
        int part = 0; // Nb of slot in parenthesis
        Piece p;

        // First parenthesis
        if (line[i] == '(')
        {
            i++;
            Vector3D<int> coords;

            // While end not reached
            while (line[i] != '\n' && line[i] != ')')
            {
                while (is_valid_num(line[i]))
                {
                    str.push_back(line[i]);
                    i++;
                }

                if (line[i] != ',' && line[i] != ')')
                    throw std::invalid_argument("Building file error");
                else
                {
                    // Put number in coords
                    if (part == 0)
                        coords.x = std::atoi(str.c_str());
                    else if (part == 1)
                        coords.y = std::atoi(str.c_str());
                    else
                        coords.z = std::atoi(str.c_str());

                    if (line[i] == ',')
                        i++;
                    str.clear();
                    part++;
                }
            }
            p.coords = coords;
            i++;
        }
        else
            throw std::invalid_argument("Building file error");

        // Mid section
        if (line[i] != ' ')
            throw std::invalid_argument("Building file error");
        else
            i++;

        // second parenthesis
        if (line[i] == '(')
        {
            i++;
            part = 0;
            Vector3D<Color> colors;

            // While end not reached
            while (line[i] != '\n' && line[i] != ')')
            {
                while (is_valid_color(line[i]))
                {
                    str.push_back(line[i]);
                    i++;
                }

                if (line[i] != ',' && line[i] != ')')
                    throw std::invalid_argument("Building file error");
                else
                {
                    // Put number in coords
                    if (part == 0)
                        colors.x = get_color_from_letter(str.c_str());
                    else if (part == 1)
                        colors.y = get_color_from_letter(str.c_str());
                    else
                        colors.z = get_color_from_letter(str.c_str());

                    if (line[i] == ',')
                        i++;
                    str.clear();
                    part++;
                }
            }
            p.colors = colors;
            i++;
        }
        else
            throw std::invalid_argument("Building file error");

        if (line[i] != '\n' && line[i] != '\0')
            throw std::invalid_argument("Building file error");

        pieces.push_back(p);
    }
    return Cube(pieces);
}
