#include"Input.h"

Input::Input() {}
Input::Input(string name, string Abs_path, string Rel_path, string Dir_path):FileName(name),absolute_path(Abs_path),relative_path(Rel_path),dir_path(Dir_path){}

string Input::get_FileName() {return FileName;}
string Input::get_absolute_path() { return absolute_path; }
string Input::get_relative_path() { return relative_path; }
string Input::get_dir_path() { return dir_path; }

void Input::set_FileName(const string& Name) { FileName = Name; }
void Input::set_absolute_path(const string& Abs_path) { absolute_path = Abs_path; }
void Input::set_relative_path(const string& Rel_path) { relative_path = Rel_path; }
void Input::set_dir_path(const string& Dir_path) { dir_path = Dir_path; }



Stdin_format::Stdin_format(){}
Stdin_format::Stdin_format(int Type, int Left, int Right) :type(Type), left(Left), right(Right) {}

int Stdin_format::get_type() {
    return type;
}
int Stdin_format::get_left() {
    return left;
}
int Stdin_format::get_right() {
    return right;
}

//prase the directory to get .cpp file in order to generate input
void generate_input() {
    DIR* curdir_dir = opendir(curdir_path.c_str());
    if (curdir_dir == NULL) {
        cout << "Fail to open current file directory!" << endl;
    }
    else {
        dirent* curfile;
        //Traverse files of CURRENT directory
        while ((curfile = readdir(curdir_dir)) != NULL) {
            curfile_name = curfile->d_name;
            if (curfile_name != "." && curfile_name != ".." && curfile_name != "stdin_format.txt")
            {
                curfile_absolute_path = curdir_path + "\\" + curfile_name;
                curfile_relative_path = "input\\" + curdir_name + "\\" + curfile_name;
                Input* curInput = new Input(curfile_name, curfile_absolute_path, curfile_relative_path, curdir_path);
                Judgement_input_vector.push_back(curInput);
            }
        }
        closedir(curdir_dir);
    }
}

//prase file stdin_format.txt and get the stdin
void generate_stdin_format() {
    curfile_absolute_path = curdir_path + "\\stdin_format.txt";
    fstream File;
    File.open(curfile_absolute_path, ios::in);
    if (!File.is_open()) {
        cout << "Fail to open stdin_format.txt!" << endl;
    }
    else {
        //prase file stdin_format.txt
        string buffer;
        while (File >> buffer) {
            int type = 0, left = 1, right = 1;
            if(buffer.substr(0,6)=="string")//string
            {
                type = 3;
                if (buffer[6] == '(') {
                    string left_num = "", right_num = "";
                    int x = 7;
                    while (buffer[x] != ',') {
                        left_num += buffer[x];
                        x++;
                    }
                    left = stoi(left_num);

                    x++;
                    while (buffer[x] != ')') {
                        right_num += buffer[x];
                        x++;
                    }
                    right = stoi(right_num);
                }
                else {
                    cout << "Format error in stdin_format.txt!" << endl;
                }
            }
            else if(buffer.substr(0, 4) == "char")//char
            {
                type = 2;
                left = 1;
                right = 1;
            }
            else if(buffer.substr(0, 3) == "int")//int
            {
                type = 1;
                if (buffer[3] == '(') {
                    string left_num = "", right_num = "";
                    int x = 4;
                    while (buffer[x] != ',') {
                        left_num += buffer[x];
                        x++;
                    }
                    left = stoi(left_num);

                    x++;
                    while (buffer[x] != ')') {
                        right_num += buffer[x];
                        x++;
                    }
                    right = stoi(right_num);
                }
                else {
                    cout << "Format error in stdin_format.txt!" << endl;
                }
            }
            else
            {
                cout << "Format error in stdin_format.txt!" << endl;
                break;
            }

            if (type!=0) {
                Stdin_format* temp = new Stdin_format(type, left, right);
                stdin_vector.push_back(temp);
            }
            else {
                cout << "Format error in stdin_format.txt!" << endl;
            }
        }
    }
    File.close();
}
