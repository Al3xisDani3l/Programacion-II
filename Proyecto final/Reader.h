// Proyecto Final Equipo 5
// Alexis Daniel Hernandez Gamez  - 180263
// Genesis Erizel Arteaga Rangel - 182129
// Francisco Antonio Hernandez Mena - 180233

#include <iostream>
#include <string>
#include <fstream>
#include "Point.h"
#include "Dataset.h"
using namespace std;



class Reader
{
public:
	Reader(string path) {
		_path;
	}
	Reader() {
		
	}



	Dataset * Load() {
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

	Dataset* Load(string path) {
		_reader.open(path, ios::out | ios::in);
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
	Dataset* _internalSet;

};
