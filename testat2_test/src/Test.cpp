#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "Word.h"
#include <string>
#include <sstream>
#include <vector>

void wordInputTest() {
	std::istringstream input{"compl33tely ~ weird !!??!! 4matted in_put"};
	std::vector<std::string> words{};
	for (Word w{}; (input >> w).good(); words.push_back(w.to_str()))	{ }
	std::vector<std::string> expected{"compl", "tely", "weird", "matted", "in", "put"};
	ASSERT_EQUAL(expected, words);
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(wordInputTest));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner { cute::makeRunner(lis, argc, argv) };
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}