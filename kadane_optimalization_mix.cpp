#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>


using namespace std;

vector<int> rdata() {
	vector<int> values;
	ifstream inFile("data_mix_cpp.txt");
	int temp;

	// Read the values in one at a time:
	while (inFile >> temp) {
		values.push_back(temp);
	}

	return values;
}

int find_min_positive_possition(std::vector<int> const & array) {
	for(int i=0; i<array.size()-1; i++) {
		if (array[i] > 0) {
			return i;
		}
	}
}

int find_max_positive_possition(std::vector<int> const & array) {
	for(int i=array.size()-1; i>0; i--) {
		if (array[i] > 0) {
			return i;
		}
	}
}


int sequence(std::vector<int> const & numbers, int first, int last) {
	// hack
	if (first==0) {
		first = 1;
	}
	
	int max_so_far  = numbers[0], max_ending_here = numbers[0];

	// Find sequence by looping through
	for(size_t i = first; i < last; i++) {
		// calculate max_ending_here
		if(max_ending_here < 0) {
			max_ending_here = numbers[i];

			// begin_temp = i;
		} else {
			max_ending_here += numbers[i];
		}

		// calculate max_so_far
		if(max_ending_here >= max_so_far ) {
			max_so_far  = max_ending_here;

			// begin = begin_temp;
			// end = i;
		}
	}
	return max_so_far ;
}


int main() {
	std::vector<int> numbers = rdata();
	int last_classic = numbers.size();
	
	const clock_t begin_time0 = clock();
	cout << sequence(numbers, 1, last_classic) << endl;
	cout << "classic: " << double( clock () - begin_time0 ) /  CLOCKS_PER_SEC;

	cout << endl << endl << "---------------------------------------------" << endl << endl;

	const clock_t begin_time1 = clock();
	int first = find_min_positive_possition(numbers);
	int last = find_max_positive_possition(numbers);
	cout << sequence(numbers, first, last) << endl;
	cout << "upgraded: " << double( clock () - begin_time1 ) /  CLOCKS_PER_SEC << endl;
		
	return 0;
}
