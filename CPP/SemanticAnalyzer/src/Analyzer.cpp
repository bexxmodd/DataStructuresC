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
		std::string second = src.substr(pos + 1, src.size() - pos - 1);
		return std::make_tuple(first, second);
	} else
		throw std::invalid_argument("Delimiter not found, can't split string");
}

static std::vector<std::string> split(std::string *src, const std::string &delim) {
	std::vector<std::string> result;
	size_t pos;
	std::string token;
	while ((pos = src->find(delim)) != std::string::npos) {
		token = src->substr(0, pos);
		result.push_back(token);
		src->erase(0, pos + delim.length());
	}
	result.push_back(*src);
	return result;
}

namespace Analyzer {
	std::vector<Sentence *> read(const std::string& filename) {
		std::vector<Sentence *> sentences;
		std::fstream file;
		file.open(filename, std::ios::in);
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				if (Analyzer::validSentence(&line)) {
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

	bool validSentence(std::string *line) {
		if (line->length() < 3 || !std::strcmp(&(*line)[0], " ") || std::isalpha((*line)[0]))
			return false;
		if (!std::strcmp(&(*line)[0], "-") && !std::isdigit((*line)[1]))
			return false;

		Tuple spl = split(*line, ' ');
		int score = stoi(std::get<0>(spl));
		char c = std::get<1>(spl)[0];
		c += 32; // convert to lower case
		return (score >= -2 && score <= 2) && (c >= 'a' && c <= 'z');
	}

	std::unordered_set<Word *> getWords(const std::vector<Sentence *> &sentences) {
		std::unordered_set<Word *> words;
		if (sentences.empty())
			return words;
		std::unordered_map<std::string, std::vector<int>> map;
		for (auto& sentence : sentences) {
			if (sentence->empty())
				continue;
			auto splits = split(&(sentence->text), " ");
			for (auto& s : splits) {
				std::transform(s.begin(), s.end(), s.begin(), ::tolower);
				if (std::isalpha(s[0])) {
					if (map.count(s) < 1)
						map.insert((std::make_pair(s, 1)));
					map[s].push_back(sentence->score);
				}
			}
		}
		for (auto& entry : map) {
			Word *w = new Word{entry.first};
			for (int score : map[entry.first])
				w->increateTotal(score);
			words.insert(w);
		}
		return words;
	}

	typedef std::unordered_map<std::string, double> Map;
	 Map calculateScores(const std::unordered_set<Word *> &words) {
		 Map map;
		 if (words.empty())
			 return map;
		 for (auto& word : words) {
			 if (!word->text.empty() || std::isalpha(word->text[0])) {
				 std::transform(word->text.begin(), word->text.end(),
								word->text.begin(), tolower);
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
		auto splits = split(sentence, " ");
		for (auto& s : splits) {
			std::transform(s.begin(), s.end(), s.begin(), ::tolower);
			if (std::isalpha(s[0]) != 0) {
				if (wordScores.count(s) > 0)
					score += wordScores.at(s);
				size++;
			}
		}
		return size > 0 ? score / size : 0.0;
	}
}
