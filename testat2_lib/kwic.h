
#ifndef MWIC_H_
#define KWIC_H_

#include "word.h"

#include <set>
#include <istream>
#include <vector>
#include <ostream>

std::vector<Word> read_words(std::istream &input);

std::set<std::vector<Word>> kwic(const std::vector<Word> &words);

std::vector<std::vector<Word>> sort_combinations(std::set<std::vector<Word>> &combinations);

void write_combinations(const std::vector<std::vector<Word>> &combinations, std::ostream &output);

void kwic_io(std::istream &input, std::ostream &output);

#endif /* KWIC_H_ */