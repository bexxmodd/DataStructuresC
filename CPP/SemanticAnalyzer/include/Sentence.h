//
// Created by bexx on 11/28/21.
//

#ifndef SEMANTICANALYZER_SENTENCE_H
#define SEMANTICANALYZER_SENTENCE_H

#include "../include/Word.h"


class Sentence {
private:
	int score;
	std::string text;

public:
	Sentence(int _score, std::string txt);
	bool operator==(Sentence const &other);
	int compare(Sentence &other);
	friend std::ostream &operator<<(std::ostream &os, Sentence const &sent) {
		os << sent.score << " -> " << sent.text;
		return os;
	}
};


#endif//SEMANTICANALYZER_SENTENCE_H
