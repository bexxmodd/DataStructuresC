//
// Created by bexx on 11/29/21.
//

#ifndef HTML_HTMLVALIDATOR_H
#define HTML_HTMLVALIDATOR_H

#include "HtmlTag.h"
#include <queue>
#include <stack>

std::stack<HtmlTag *> valid(std::queue<HtmlTag *> *tags);
std::queue<HtmlTag *> getTagsFromHtmlFile(const std::string &filename);

#endif//HTML_HTMLVALIDATOR_H
