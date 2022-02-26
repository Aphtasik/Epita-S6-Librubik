#include "parse-csv.hh"

namespace rubik::solver
{
    std::vector<std::vector<std::string>> parse_csv(const std::string& f)
    {
        std::ifstream file_in;
        std::string line;
        std::vector<std::vector<std::string>> res;

        file_in.open(f);

        int ref = 0;
        int count = 0;
        int line_nb = 1;

        if (!file_in.is_open())
        {
            throw std::ios_base::failure("Error opening file");
        }

        while (getline(file_in, line))
        {
            std::stringstream ss;
            ss.str(line);
            std::string token;
            std::vector<std::string> word;

            count = 0;
            while (getline(ss, token, ','))
            {
                if (line_nb == 1)
                {
                    ref++;
                }
                else
                {
                    count++;
                }
                word.push_back(token);
            }

            if (line[line.length() - 1] == ',')
            {
                if (line_nb == 1)
                {
                    ref++;
                }
                else
                {
                    count++;
                }
                word.push_back("");
            }

            if (count != ref && line_nb != 1)
                throw std::ios_base::failure(
                    "Non consistent number of columns at line "
                    + std::to_string(line_nb));

            res.push_back(word);
            line_nb++;
        }

        return res;
    }

} // namespace rubik::solver
