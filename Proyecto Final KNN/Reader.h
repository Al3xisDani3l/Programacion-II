#include <iostream>
#include <string>
#include <fstream>
using namespace std;



class Reader
{
public:
	Reader(string path) {
		_path;
	}


	void Load() {
		_reader.open(_path, ios::out | ios::in);
		int count = 0;
		char ln[100];
		char* element;

		if (_reader.is_open())
		{
			_reader.getline(ln, 100);
			while (!_reader.eof())
			{
				element = strtok(ln, " ");
				if (count == 0)
				{

					while (element != NULL)
					{

					}
				}



			}
		}


	}


	~Reader();

private:
	ifstream _reader;
	string _path;

};

