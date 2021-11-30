//
// Created by bexx on 11/28/21.
//
#include "../include/HtmlTag.h"
#include "../include/HtmlValidator.h"
#include <fstream>

std::stack<HtmlTag *> valid(std::queue<HtmlTag *> *tags) {
	std::stack<HtmlTag *> stack;
	if (tags->empty())
		return stack;

	while (!tags->empty()) {
		auto& tag = tags->front();
		tags->pop();

		if (tag->isOpenTag())
			stack.push(tag);
		else if (tag->selfClosing())
			continue;
		else {
			if (tag->matches(*tags->front()))
				stack.pop();
			else
				return stack;
		}
	}
	return stack;
}

std::queue<HtmlTag *> getTagsFromHtmlFile(const std::string &filename) {
	char byte;
	std::ifstream file(filename);
	std::string buffer;
	if (!file.is_open())
		throw std::invalid_argument("Can't open file -- " + filename);

	while (file.get(byte))
		buffer += byte;

	file.close();
	return HtmlTag::tokenize(&buffer);
}