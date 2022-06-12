#include"csv_reader.h"

std::vector<std::string> _split(std::string& inputs, char delimiter) {
	std::istringstream stream(inputs);
	std::string field;
	std::vector<std::string> result;

	while (std::getline(stream, field, delimiter)) {
		result.push_back(field);
	}
	return result;
}

std::int32_t count_element(std::ifstream& data) {
	int32_t counter = 0;
	std::string _line;
	while (std::getline(data, _line))
	{
		counter++;
	}

	return counter;
}