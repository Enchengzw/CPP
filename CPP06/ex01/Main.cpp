#include "./Include/Serializer.hpp"

int main() 
{
	Data *data;
	uintptr_t rawdata;
    Data *retdata;
	data = new Data;

	std::cout << "Data             : " << data << std::endl;
	rawdata = Serializer::serialize(data);
	std::cout << "Raw data         : " << rawdata << std::endl;
	retdata = Serializer::deserialize(rawdata);
	std::cout << "Deserialized data: " << retdata << std::endl;

	delete data;

	return 0;
}