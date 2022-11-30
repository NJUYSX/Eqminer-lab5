#include"Struct.h"

vector <Input*> Judgement_input_vector;//vector of Judgement inputs
vector <Output*> Judgement_output_vector;//vector of Judgement outputs
vector <Output*> Confirmation_input_vector;//vector of Confirmation inputs
vector <Output*> Confirmation_output_vector;//vector of Confirmation(final) outputs
vector <Stdin_format*> stdin_vector;//vector of Stdin_formats
vector <Judgement*> judgement_vector;//vector of Stdin_formats

string input_path;              //path of input directory
string curdir_path;             //path of current directory
string curdir_name;             //name of current directory
string curfile_absolute_path;   //absolute path of current file
string curfile_relative_path;   //relative path of current file
string curfile_name;            //name of current file
