#include  "Operations.h"

string trimString(string str)
{
	size_t first = str.find_first_not_of(' ');
	if (string::npos == first)
	{
		return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

string stringToUpper(string str)
{
	for (auto& c : str) c = toupper(c);
	return str;
}

vector<num> vectorIntersect(vector<num> first, vector<num> second)
{
	size_t vSize = first.size();
	vSize += second.size();
	vector<num> res(vSize);
	if (first.size() == 0 || second.size() == 0)
	{
		cerr << endl<< "ERROR Didn't find any packs within those parameters!\n" << endl;
		return res;
	}
	
	vector<num>::iterator it;

	sort(first.begin(), first.end());
	sort(second.begin(), second.end());

	it = set_intersection(first.begin(), first.end(), second.begin(), second.end(), res.begin());

	res.resize(it - res.begin());

	return res;
}
