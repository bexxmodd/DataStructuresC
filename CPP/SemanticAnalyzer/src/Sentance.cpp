//
// Created by bexx on 11/28/21.
//

#include <cstring>
#include "../include/Sentance.h"

Sentance::Sentance(int _score, std::string txt)
	: score(_score), text(std::move(txt)) {}
bool Sentance::operator==(const Sentance &other) {
	return strcmp(text.c_str(), other.text.c_str());
}
int Sentance::compare(Sentance &other) {
	return score - other.score;
}
