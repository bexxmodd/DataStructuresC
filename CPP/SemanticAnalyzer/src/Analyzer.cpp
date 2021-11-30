//
// Created by bexx on 11/29/21.
//

#include "../include/Analyzer.h"
#include <string>
#include <iostream>
#include <fstream>

typedef std::tuple<std::string, std::string> Tuple;
static Tuple split(std::string &src, const char delim) {
	int pos = (int)src.find(delim);
	if (pos != std::string::npos) {
		std::string first = src.substr(0, pos + 1);
		std::string second = src.substr(pos, src.size() - pos - 1);
		return std::make_tuple(first, second);
	} else
		throw std::invalid_argument("Delimiter not found, can't split string");
}

namespace Analyzer {
	std::vector<Sentence *> read(const std::string& filename) {
		std::vector<Sentence *> sentences;
		std::fstream file;
		file.open(filename, std::ios::in);
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				if (Analyzer::validSentence(line)) {
					Tuple spl = split(line, ' ');
					auto *sntnc = new Sentence(std::stoi(std::get<0>(spl)),
											 std::get<1>(spl));
					sentences.push_back(sntnc);
				}
			}
			file.close();
		} else
			throw std::invalid_argument("Can't open file -- " + filename);
		return sentences;
	}

	bool validSentence(const std::string &line) {
		return (line.length() > 3
			|| !std::strcmp(&line[0], " ")
			|| !std::isalpha(line[0])
			|| !std::isalnum(line[1]))
			&& !std::strcmp(&line[0], "-");
	}

	std::unordered_set<Word *> getWords(const std::vector<Sentence *> &sentences) {
		std::unordered_set<Word *> words;
		return words;
	}

	typedef std::unordered_map<std::string, double> Map;
	 Map calculateScores(const std::unordered_set<Word *> &words) {
		;
	}

	double computeSentenceScore(const std::string &sentence,
								  const Map& wordScores) {
		return 0;
	}
}
