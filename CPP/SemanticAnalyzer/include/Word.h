//
// Created by bexx on 11/28/21.
//

#ifndef SEMANTICANALYZER_WORD_H
#define SEMANTICANALYZER_WORD_H

#include <string>
#include <iostream>
#include <utility>

class Word {
private:
	unsigned int count;
	int total;

public:
	std::string text;
	explicit Word(std::string txt);
	void increateTotal(int value);
	double score();
	bool operator==(Word const &other);
	unsigned long hash();
	int compare(Word const &other);

	friend std::ostream &operator<<(std::ostream &os, Word const &word) {
		os << word.text;
		return os;
	}
};


#endif//SEMANTICANALYZER_WORD_H
