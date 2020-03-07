#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include "stack.hpp"

class Bracket
{
public:
	Bracket(char c=' ', size_t pos=0 )
		: _c(c), _pos(pos)
	{
	}

	bool match_with(char o) const
	{
		return ( (_c == '{' && o== '}') ||
				 (_c == '[' && o== ']') ||
				 (_c == '(' && o== ')'));
	}
	size_t pos() const
	{
		return _pos;
	}
protected:
	char _c;
	size_t _pos;
};

int
main(int argc, const char* argv[])
{
	int exit_code = EXIT_SUCCESS;
	try
	{
		if (argc != 2)
		{
			std::cerr << "Usage: check_brackets filename" << std::endl;
			return EXIT_FAILURE;
		}
		std::string filename = argv[1];

		std::ifstream input (argv[1]);
		if (!input)
		{
			std::cerr << "Error: could not open input filename '" << argv[1] << "'." << std::endl;
			std::cerr << "Usage: check_brackets filename" << std::endl;
			return EXIT_FAILURE;
		}
		size_t pos = 0;
		bool unbalanced_found = false;
		Stack<Bracket> brakets;
		char next_c;
		while(input && !unbalanced_found)
		{
			++pos;
			input >> next_c;
			if (input)
			{
				if (next_c == '(' || next_c == '{' || next_c == '[')
				{
					/* process a opening bracket. */

					//TODO
					brakets.push(Bracket(next_c, pos));
				}
				else if (next_c == ')' || next_c == '}' || next_c == ']')
				{
					/* process a closing bracket. */

					//TODO
					if (brakets.is_empty()) unbalanced_found = true;
					else if (brakets.top().match_with(next_c)) brakets.pop();
				}
			}
		}

		/* write the result. */

		//TODO
		if (!unbalanced_found) std::cout << pos << std::endl;
		else std::cout << "Success" << std::endl;

	}
	catch(std::runtime_error &e)
	{
		std::cerr << "Run time exception: " << e.what() << std::endl;
		exit_code = EXIT_FAILURE;
	}
	catch(...)
	{
		std::cerr << "Catched unknown exception!." << std::endl;
		exit_code = EXIT_FAILURE;
	}
	return exit_code;
}

