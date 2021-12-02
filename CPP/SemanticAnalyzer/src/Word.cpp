// Created by bexx on 11/28/21.

#include "../include/Word.h"
#include <cstring>

Word::Word(std::string txt)
	: text(std::move(txt)), count(0), total(0) {}

void Word::increateTotal(int value) {
	total += value;
	count++;
}

double Word::score() {
	if (count == 0)
		return 0;
	return (double)total / count;
}

bool Word::operator==(Word const &other) {
	return !strcmp(text.c_str(), other.text.c_str())
		   && count == other.count
		   && total == other.total;
}

unsigned long Word::hash() {
	std::hash<std::string> hash_string;
	return hash_string(text);
}

int Word::compare(Word const &other) {
	return total - other.total;
}
