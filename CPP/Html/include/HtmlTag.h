/*
 * Created by Bexx on 11/28/21.
 */
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>
#include <queue>

#ifndef HTMLTAG_H
#define HTMLTAG_H

namespace HtmlData {}
class HtmlTag {
private:
	const std::string m_Element;
	const bool m_OpenTag;

public:
	inline static const std::unordered_set<std::string> *SELF_CLOSING_TAGS =
			new std::unordered_set<std::string>
				({
					"!doctype", "!--", "?xml", "xml", "area", "base",
					 "basefont", "br", "col", "frame", "hr", "img",
					 "input", "link", "meta", "param"
				});
	inline static const std::string WHITESPACE = " \f\n\r\t";

	HtmlTag(std::string element, bool isOpenTag);
	bool matches(const HtmlTag &other);
	[[nodiscard]] bool selfClosing() const;
	[[nodiscard]] bool isOpenTag() const;
	bool operator==(const HtmlTag &other);
	friend std::ostream &operator<<(std::ostream &os, HtmlTag const &tag) {
		os << "<" << (tag.m_OpenTag ? "" : "/")
		   << ((strcmp(tag.m_Element.c_str(), "!--") == 0) ? "!-- --" : tag.m_Element)
		   << ">";
		return os;
	}

	static std::queue<HtmlTag *> tokenize(std::string *text);
	static HtmlTag *nextTag(std::string *buffer);
};


#endif