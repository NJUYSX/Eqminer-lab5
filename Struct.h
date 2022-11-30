#ifndef STRUCT_H
#define STRUCT_H
#pragma once
#include <vector>
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Input;
class Output;
class Stdin_format;
class Judgement;

extern vector <Input*> Judgement_input_vector;//vector of Judgement inputs
extern vector <Output*> Judgement_output_vector;//vector of Judgement outputs
extern vector <Output*> Confirmation_input_vector;//vector of Confirmation inputs
extern vector <Output*> Confirmation_output_vector;//vector of Confirmation(final) outputs
extern vector <Stdin_format*> stdin_vector;//vector of Stdin_formats
extern vector <Judgement*> judgement_vector;//vector of Stdin_formats

extern string input_path;              //path of INPUT directory
extern string curdir_path;             //path of current directory
extern string curdir_name;             //name of current directory
extern string curfile_absolute_path;   //absolute path of current file
extern string curfile_relative_path;   //relative path of current file
extern string curfile_name;            //name of current file

#endif // STRUCT_H
