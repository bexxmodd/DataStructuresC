#include "../include/HtmlTag.h"
#include "../include/HtmlValidator.h"
#include <cassert>
#include <queue>
#include <stack>

static std::string tags;
std::queue<HtmlTag *> queue;
std::stack<HtmlTag *> stack;

void isValidHtmlTest() {
	tags = "<html><body><h1></h1><p>paragraph</p></body></html>";
	queue = HtmlTag::tokenize(&tags);
	assert(queue.size() == 8);
	assert(*queue.front() == HtmlTag("html", false));
	assert(*queue.back() == HtmlTag("html", true));
}

void isValidHtmlCommentTest() {
	tags = "<!-- valid -->";
	queue = HtmlTag::tokenize(&tags);
	while (!queue.empty()) {
		std::cout << *queue.front() << std::endl;
		queue.pop();
	}
}

void isValidFunctionTest() {
	tags = "<html><body><h1></h1><p>paragraph</p></body></html>";
	queue = HtmlTag::tokenize(&tags);
	assert(valid(&queue).empty());
}

void getHtmlTagsTest() {
	queue = getTagsFromHtmlFile("../test/bexxmodd.html");
	while (!queue.empty()) {
		std::cout << *queue.front() << std::endl;
		queue.pop();
	}
}

int main() {
	isValidHtmlTest();
	isValidHtmlCommentTest();
	isValidFunctionTest();
	getHtmlTagsTest();
	return 0;
}
