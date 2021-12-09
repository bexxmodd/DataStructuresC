//
// Created by bexx on 12/6/21.
//

#include "TimerClass.cpp"
#include <unistd.h>

int main()
{
	TimerClass *tmp3;
	{
		auto *t1 = new TimerClass("First-Born", 11);
		sleep(1);
		TimerClass t2 = TimerClass("Nexius BIG", 11);

		auto *tmp1 = new TimerClass("I should not be here", 22);

		sleep(3);
		delete t1;

		auto *tmp2 = new TimerClass("Temporary", 10);
		sleep(1);
		std::cout << "tmp1\n";
		tmp1->print();
		std::cout << "tmp2\n";
		tmp2->print();
		tmp1 = std::move(tmp2);
//		delete tmp2;
		std::cout << "tmp1\n";
		tmp1->print();
		std::cout << "tmp2\n";
		tmp2->print();
		delete tmp1;
		tmp3 = new TimerClass("Beyonder", 9);
		sleep(2);
	}
	delete tmp3;
	return 0;
}
