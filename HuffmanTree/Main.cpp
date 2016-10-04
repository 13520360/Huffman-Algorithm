#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <numeric>
#include <random>

using namespace std;

template <typename T>
vector<size_t> sort_indexes(const vector<T> &v) {

	// initialize original index locations
	vector<size_t> idx(v.size());
	iota(idx.begin(), idx.end(), 0);

	// sort indexes based on comparing values in v
	sort(idx.begin(), idx.end(),
		[&v](size_t i1, size_t i2) {return v[i1] < v[i2]; });

	return idx;
}
int main() {
	char array[5] = { 'a','b','c','d','e' };
	ifstream myfile;
	string line;

	myfile.open("E:\\Original_File.txt");
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			int i;
			int counts[5];
			cout << line << endl;
			for (i = 0; i < 5; ++i)
			{
				int j = 0, count = 0;
				for (j = 0; line[j] != '\0'; ++j)
				{
					if (array[i] == line[j])
						++count;
				}
				// Add count to parallel array of character
				counts[i] = count;
			}
			// Sort by frequencies
			std::vector<int> v(counts, counts + sizeof counts / sizeof counts[0]);
			for (auto i : sort_indexes(v)) {
				cout << array[i] << " -- " << v[i] << endl;
			}

		}

		myfile.close();
	}

	return 0;
}