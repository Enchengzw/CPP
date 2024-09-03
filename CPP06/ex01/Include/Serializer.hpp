#ifndef SERIALIZER_CLASS_HPP
# define SERIALIZER_CLASS_HPP

# include <string>
# include <iostream>
# include <stdint.h>

struct Data {
    int id;
    std::string name;
};

class Serializer
{
	public:
        Serializer();
		Serializer(const Serializer& obj);
		Serializer& operator=(const Serializer& obj);
		virtual ~Serializer();
        static uintptr_t serialize (Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif