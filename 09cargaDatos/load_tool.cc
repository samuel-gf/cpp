#ifndef _LOAD_TOOL
#define _LOAD_TOOL

#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>

namespace load_tool{

	using namespace std;

	// Devuelve true si el carácter c es un separador
	bool inline is_a_separator(char const c)
	{
		switch (c) {
			case ' ':
				return true;
			case '\t':
				return true;
			default:
				return false;
		}
		return false;
	}

	// Devuelve true si el carácter c es un comentario
	bool inline is_a_comment(char const c){
		return (c=='#');
	}

	// Devuelve un vector de strings, donde cada elemento es una palabra de la línea
	vector<string> split_line(string const sLine)
	{
		vector<string> vLine;
		int i{0};
		while (i < sLine.size()) {
			string sWord;
			while (is_a_separator(sLine[i])) // Salta espacios al principio de línea
				++i;

			if (is_a_comment(sLine[i])){	// Lo que queda de línea es un comentario. Termina bucle y función
				break;
			} else {			// Lo que queda de línea es una palabra
				while (i < sLine.size() && !is_a_separator(sLine[i])) {
					sWord += sLine[i++];
				}
				vLine.push_back(sWord);
			}
		}
		return vLine;
	}

	// Devuelve la estructura vector<vector<string>> sin líneas en blanco
	vector<vector<string>> remove_null(vector<vector<string>> &vLines){
		for (vector<string> vLine : vLines){
			for(string word: vLine){
				cout<<word<<" ";
				// @TODO Acabar esta función
			}
			cout<<endl;
		}
	}

	// Vector de vector<string>, cada item es un vector que contiene items que son
	// a su vez palabras
	vector<vector<string>> split_file(string const file_name)
	{
		ifstream finput(file_name);
		vector<vector<string>> vLines; // Vector de vector<string>
		string sLine;
		while (getline(finput, sLine)) { vLines.push_back(split_line(sLine)); }	
		remove_null(vLines);
		return vLines;
	}
}
#endif
