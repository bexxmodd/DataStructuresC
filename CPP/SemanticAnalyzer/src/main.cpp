#include "../include/Sentence.h"
#include "../include/Analyzer.h"
#include <iostream>

int main(int argc, char **argv) {
	if (argc < 2)
		throw std::invalid_argument("Please specify the name of the input file");
	std::string filename = argv[1];
	std::cout << "Please enter a sentence:" << std::endl;
	std::string sent;
	std::getline(std::cin, sent);

	auto sentences = Analyzer::read(filename);
	auto words = Analyzer::getWords(sentences);
	auto wordScores = Analyzer::calculateScores(words);
	double score = Analyzer::computeSentenceScore(&sent, wordScores);
	std::cout << "The sentiment score is " << score << std::endl;

	return 0;
}
