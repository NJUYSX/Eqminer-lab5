#ifndef INPUT_H
#define INPUT_H
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "Struct.h"
using namespace std;
class Input{
private:
    string FileName;                //name of file
    string absolute_path;           //absolute path
    string relative_path;           //relative path
    string dir_path;                //directory path
public:
    Input();
    Input(string name, string Abs_path, string Rel_path, string Dir_path);

    string get_FileName();
    string get_absolute_path();
    string get_relative_path();
    string get_dir_path();

    void set_FileName(const string& Name);
    void set_absolute_path(const string& Abs_path);
    void set_relative_path(const string& Rel_path);
    void set_dir_path(const string& Dir_path);

};

class Stdin_format {
private:
    int type;       //int = 1, char = 2, string = 3
    int left;       //左边界
    int right;      //右边界
public:
    Stdin_format();
    Stdin_format(int t, int l, int r);

    int get_type();
    int get_left();
    int get_right();
};


void generate_input();//prase the directory to get .cpp file in order to generate input
void generate_stdin_format();//prase file stdin_format.txt and get the stdin
#endif // INPUT_H
