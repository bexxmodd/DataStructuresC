//
// Created by bexx on 11/28/21.
//

#include "../include/Sentence.h"
#include <cstring>

Sentence::Sentence(int _score, std::string txt)
	: score(_score), text(std::move(txt)) {}
bool Sentence::operator==(const Sentence &other) {
	return strcmp(text.c_str(), other.text.c_str());
}
int Sentence::compare(Sentence &other) {
	return score - other.score;
}
