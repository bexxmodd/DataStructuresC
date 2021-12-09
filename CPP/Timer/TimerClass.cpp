//
// Created by bexx on 12/6/21.
//

#include <cstring>
#include <ctime>
#include <iostream>

struct TimerClass {
	char *name;
	size_t length;
	std::time_t timestamp;

	TimerClass(const char *_name, size_t _length)
		: timestamp(std::time(0)), length(_length)
	{
		name = new char[_length];
		std::strncpy(name, _name, _length + 1);
		std::cout << "Created TimerClass: " << name
				  << " at: " << timestamp << std::endl;
	}

	~TimerClass()
	{
		std::time_t now = std::time(0);
		std::cout << "Lifetime of TimerClass: " << name
				  << " was " << now - timestamp << std::endl;
		delete[] name;
	}

	// copy semantics
	TimerClass(const TimerClass &rhs)
		: timestamp(rhs.timestamp),
		  length(rhs.length),
		  name(new char[rhs.length])
	{
		std::strncpy(name, rhs.name, rhs.length);
		std::cout << "  Copied " << rhs.name << "into " << name << std::endl;
	}

	TimerClass &operator=(const TimerClass &rhs)
	{
		std::cout << "  =Copied " << rhs.name <<"into "
				  << name << "using '='" << std::endl;
		if (this == &rhs)
			return *this;
		delete[] name;
		timestamp = rhs.timestamp;
		length = rhs.length;
		auto new_name = new char[rhs.length];
		name = new_name;
		std::strncpy(name, rhs.name, rhs.length);
		return *this;
	}

	TimerClass(TimerClass &&rhs) noexcept
		: timestamp(rhs.timestamp),
		  length(rhs.length),
		  name(rhs.name)
	{
		std::cout << "  Moving " << rhs.name << " into " << name << std::endl;
		rhs.timestamp = 0;
		rhs.length = 0;
		rhs.name = nullptr;
	}

	TimerClass &operator=(TimerClass &&rhs) noexcept
	{
		std::cout << "  =Moving " << rhs.name << " into " << name << std::endl;
		if (this == &rhs)
			return *this;
		name = rhs.name;
		timestamp = rhs.timestamp;
		length = rhs.length;
		rhs.timestamp = 0;
		rhs.length = 0;
		std::swap(name, rhs.name);
		return *this;
	}

	void print()
	{
		std::cout << "\tName: {" << name << "}\tBirthtime: {" << timestamp << "}\n";
	}
};
