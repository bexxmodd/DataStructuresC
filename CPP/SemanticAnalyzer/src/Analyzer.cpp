//
// Created by bexx on 11/29/21.
//

#include "../include/Analyzer.h"
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

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
		 Map map;
		 if (words.empty())
			 return map;
		 for (auto& word : words) {
			 if (!word->text.empty() || std::isalpha(word->text[0])) {
				 std::transform(word->text.begin(), word->text.end(), word->text.begin(), tolower);
				 map.insert({ word->text, word->score() });
			 }
		 }
		 return map;
	}

	double computeSentenceScore(std::string *sentence,
								  const Map& wordScores) {
		double score = 0;
		int size = 0;
		if (wordScores.empty() || sentence->empty())
			return score;

		// overload split to return all the strings split on delimiter
		auto splits = split(*sentence, ' ');
		return 0;
	}
}
