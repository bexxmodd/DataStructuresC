//
// Created by bexx on 11/28/21.
//

#ifndef SEMANTICANALYZER_SENTANCE_H
#define SEMANTICANALYZER_SENTANCE_H

#include "../include/Word.h"


class Sentance {
private:
	int score;
	std::string text;
	Sentance(int _score, std::string txt);
	bool operator==(Sentance const &other);
	int compare(Sentance &other);
	friend std::ostream &operator<<(std::ostream &os, Sentance const &sent) {
		os << sent.score << " -> " << sent.text;
		return os;
	}
};


#endif//SEMANTICANALYZER_SENTANCE_H
