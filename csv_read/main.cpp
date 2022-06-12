#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include"csv_reader.h"

int32_t main(int argc, char** argv) {

	std::ifstream tmp_read(argv[1]);
	std::ifstream ans_read(argv[2]);
	
	std::ifstream tmp(argv[1]);
	std::ifstream ans(argv[2]);

	std::string line_tmp;
	std::string line_ans;
	std::vector<std::string> num_tmp;
	std::vector<std::string> num_ans;

	std::int32_t tmp_i = 0;
	std::int32_t counter = 0;
	std::int32_t score_counter = 0;

	std::vector<bool> judge(200);

	int32_t tmp_height = count_element(tmp_read);
	int32_t ans_height = count_element(ans_read);

	std::vector<std::vector<std::int32_t>>
		tmp_data(
			tmp_height,
			std::vector<std::int32_t>(20)
		);
	if (tmp_height != ans_height) {
		std::cout << "HEHGHT ERROR" << std::endl;
		system("pause");
		exit(1);
	}



	for (int32_t i = 0; i < tmp_height; ++i) {
		std::getline(tmp, line_tmp);
		std::getline(ans, line_ans);

		num_tmp = _split(line_tmp, ',');
		num_ans = _split(line_ans, ',');

		for (int32_t j = 0; j < num_tmp.size(); ++j) {			

			if (std::stoi(num_tmp.at(j)) == std::stoi(num_ans.at(j))) {
				counter++;
			}
		}

		if (counter == num_tmp.size()) { 
			judge[i] = true; 
			score_counter++;
		}
		else{
			judge[i] = false;
		}

		counter = 0;
	}

	std::cout << "SCORE : " << std::endl;
	std::cout << score_counter << " / " << tmp_height << std::endl;
	std::cout << (double(score_counter) / double(tmp_height))*100 << "%"<< std::endl;

	
	 system("pause");


}