#include "move.hh"

namespace rubik
{
    bool is_valid_rot(char c)
    {
        return (c == 'F' || c == 'B' || c == 'L' || c == 'R' || c == 'U'
                || c == 'D' || c == 'x' || c == 'y' || c == 'z');
    }

    bool is_valid_modif(char c)
    {
        return (c == '\'' || c == '2');
    }

    std::vector<Move> parse_moves(std::string input)
    {
        std::vector<Move> moves;
        bool is_move = false;
        Move n_move;

        if (input[0] == '\0')
            return moves;

        for (long unsigned int i = 0; i < input.size(); i++)
        {
            char c = input[i];

            if (is_valid_rot(c))
            {
                switch (c)
                {
                case ('F'):
                    n_move.mvt = Face::FRONT;
                    break;
                case ('B'):
                    n_move.mvt = Face::BACK;
                    break;
                case ('U'):
                    n_move.mvt = Face::UP;
                    break;
                case ('D'):
                    n_move.mvt = Face::DOWN;
                    break;
                case ('L'):
                    n_move.mvt = Face::LEFT;
                    break;
                case ('R'):
                    n_move.mvt = Face::RIGHT;
                    break;
                case ('x'):
                    n_move.mvt = Axis::X;
                    break;
                case ('y'):
                    n_move.mvt = Axis::Y;
                    break;
                default:
                    n_move.mvt = Axis::Z;
                    break;
                }
                is_move = true;
            }
            else if (is_move && is_valid_modif(c))
            {
                if (c == '\'')
                    n_move.dir = Direction::ANTI_CLOCKWISE;
                else
                    n_move.is_double = true;
                is_move = false;
                moves.push_back(n_move);
                n_move.is_double = false;
                n_move.dir = Direction::CLOCKWISE;
            }
            else if (c == ' ' || c == '\n')
            {
                if (is_move)
                {
                    is_move = false;
                    moves.push_back(n_move);
                    n_move.is_double = false;
                    n_move.dir = Direction::CLOCKWISE;
                }
            }
            else
            {
                throw std::invalid_argument("File parse error");
            }
        }
        if (is_move)
            moves.push_back(n_move);

        return moves;
    }
} // namespace rubik
