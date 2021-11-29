//
// Created by bexx on 11/28/21.
//
#include "../include/HtmlTag.h"
#include <regex>
#include <string>

static bool checkIfHtmlComment(unsigned int _o, const std::string &tag);
static int commentClosing(std::string *tag, unsigned int _c);
static void removeAttributes(std::string *elem);
static bool isOpen(const std::string& tag);
static bool isSelfClosing(const std::string& tag);
static bool valid(const std::string &tag);

HtmlTag::HtmlTag(std::string element, bool isOpenTag)
	: m_Element(std::move(element)), m_OpenTag(isOpenTag) {}

bool HtmlTag::matches(const HtmlTag &other) {
	return !strcasecmp(m_Element.c_str(), other.m_Element.c_str()) && m_OpenTag == other.m_OpenTag;
}

bool HtmlTag::selfClosing() const {
	return SELF_CLOSING_TAGS->count(m_Element);
}

bool HtmlTag::isOpenTag() const {
	return m_OpenTag;
}

bool HtmlTag::operator==(const HtmlTag &other) {
	return !strcmp(m_Element.c_str(), other.m_Element.c_str()) && m_OpenTag == other.m_OpenTag;
}

std::queue<HtmlTag *> HtmlTag::tokenize(std::string *text) {
	std::queue<HtmlTag *> queue;
	HtmlTag *tag;
	while ((tag = nextTag(text)) != nullptr)
		queue.push(tag);
	return queue;
}

HtmlTag *HtmlTag::nextTag(std::string *buffer) {
	if (valid(*buffer)) {
		unsigned int openBracket = buffer->find('<');
		unsigned int closeBracket = buffer->find('>');
		if (checkIfHtmlComment(openBracket, *buffer)) {
			closeBracket = commentClosing(buffer, openBracket + 4);
			if (closeBracket < 0)
				return nullptr;
		}

		std::string element = buffer->substr(openBracket + 1,
											 closeBracket - openBracket - 1);
		removeAttributes(&element);
		bool isOpenTag = isOpen(element);
		if (isOpenTag)
			element = element.substr(1, element.size());

		element = std::regex_replace(
				element, std::regex("[^A-zA-Z0-9!-]+"), "");
		buffer->erase(0, closeBracket + 1);
		if (isSelfClosing(element))
			isOpenTag = false;
		return new HtmlTag(element, isOpenTag);
	} else
		return nullptr;
}

static bool checkIfHtmlComment(unsigned int _o, const std::string &tag) {
	return _o + 4 <= tag.size()
		&& !strcmp(tag.substr(_o + 1, _o + 3).c_str(), "!--");
}

static int commentClosing(std::string *tag, unsigned int _c) {
	int closeBracket = (int)tag->find("-->", _c);
	if (closeBracket != std::string::npos) {
		tag->insert(_c, " ");
		return closeBracket + 3;// advance to the closing bracket >
	} else
		return -1;
}

static void removeAttributes(std::string *elem) {
	for (char c : HtmlTag::WHITESPACE) {
		int attributeIndex = (int)elem->find(c);
		if (attributeIndex != std::string::npos)
			*elem = elem->substr(0, attributeIndex);
	}
}

static bool isOpen(const std::string& tag) {
	return tag.find('/') == 0;
}

static bool isSelfClosing(const std::string& tag) {
	return HtmlTag::SELF_CLOSING_TAGS->count(tag) > 0;
}

static bool valid(const std::string &tag) {
	int openBracket = (int)tag.find('<');
	return openBracket != std::string::npos
		   && tag.find('>') > openBracket;
}