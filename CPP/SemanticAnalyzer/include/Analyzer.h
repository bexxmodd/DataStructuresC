//
// Created by bexx on 11/29/21.
//

#ifndef SEMANTICANALYZER_ANALYZER_H
#define SEMANTICANALYZER_ANALYZER_H

#include "Sentence.h"
#include "Word.h"
#include <cstring>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace Analyzer {
	typedef std::unordered_map<std::string, double> Map;

	std::vector<Sentence *> read(const std::string& filename);
	bool validSentence(const std::string &line);
	std::unordered_set<Word *> getWords(const std::vector<Sentence *> &sentences);
	Map calculateScores(const std::unordered_set<Word *> &words);
	double computeSentenceScore(const std::string &sentence, const Map& wordScores);
}

#endif//SEMANTICANALYZER_ANALYZER_H
