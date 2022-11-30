#include"Judgement.h"
#include <QDebug>

string random_case(int n){
    int t = stdin_vector[n]->get_type();
    int rand_num = stdin_vector[n]->get_left() + rand() % (stdin_vector[n]->get_right() - stdin_vector[n]->get_left() + 1);
    if (t == 1) { //int
        return to_string(rand_num);
    }
    else if (t == 2||t == 3) { //char or string
        string res = "";
        char rand_char;
        for (int i = 0; i < rand_num; ++i) {
            rand_char = 'a' + rand() % 26;
            res += rand_char;
        }
        return res;
    }
    else {
        cout << "Format error in stdin_format.txt!" << endl;
        return "";
    }

}//generate single random test

Judgement::Judgement() {}
Judgement::Judgement(Input* input_1, Input* input_2, Output* _output, vector<Stdin_format*> Vector) :input1(input_1), input2(input_2), output(_output), Format_vector(Vector) {}

void Judgement::GenerateRandomCase() {
    string inputfile_path = input1->get_dir_path() + "\\input.txt";

    fstream File;
    File.open(inputfile_path, ios::out);

    for (unsigned int i = 0; i < stdin_vector.size(); i++) {
        File << random_case(i) << ' ';
    }
    File << endl;
    File.close();
}//generate random case to test
void Judgement::Judge() {
    GenerateRandomCase();
    output->set_if_equal(true);

    string inputfile_path = input1->get_dir_path() + "\\input.txt";
    string outputfile1_path = input1->get_dir_path() + "\\output1.txt";
    string outputfile2_path = input2->get_dir_path() + "\\output2.txt";

    //create file  1.out  and  2.out  representing result of file compilation
    char cmd1[1001] = "g++ -w -o 1.out ";
    strcat(cmd1, input1->get_absolute_path().c_str());
    system(cmd1);

    char cmd2[1001] = "g++ -w -o 2.out ";
    strcat(cmd2, input2->get_absolute_path().c_str());
    system(cmd2);

    for (int i = 0; i < 5; ++i) {
        //run random tests to generate outfile (containing results),then compare results

        //1.out <input.txt >output1.txt #在1.out所在目录下执行该命令
        char cmd3[1001] = ".\\1.out <";
        strcat(cmd3, inputfile_path.c_str());
        strcat(cmd3, " >");
        strcat(cmd3, outputfile1_path.c_str());
        int r1 = system(cmd3);

        //2.out <input.txt >output2.txt #在2.out所在目录下执行该命令
        char cmd4[1001] = ".\\2.out <";
        strcat(cmd4, inputfile_path.c_str());
        strcat(cmd4, " >");
        strcat(cmd4, outputfile2_path.c_str());
        int r2 = system(cmd4);

        //Error occurred while the program was running,skip this comparison
        if (r1 != 0 || r2 != 0) {
            continue;
        }

        //collect the results into vector for comparison
        fstream File1;
        vector<string> res1;
        File1.open(outputfile1_path, ios::in);
        if (!File1.is_open()) {
            cout << "Fail to open output1.txt!" << endl;
        }
        else {
            string buffer;
            while (File1 >> buffer) {
                res1.push_back(buffer);
            }
        }
        File1.close();

        fstream File2;
        vector<string> res2;
        File2.open(outputfile2_path, ios::in);
        if (!File2.is_open()) {
            cout << "Fail to open output2.txt!" << endl;
        }
        else {
            string buffer;
            while (File2 >> buffer) {
                res2.push_back(buffer);
            }
        }
        File2.close();

        //compare
        if (res1.size() != res2.size()) {
            output->set_if_equal(false);
        }
        else {
            for (unsigned int j = 0; j < res1.size(); ++j) {
                if (res1[j] != res2[j]) {
                    output->set_if_equal(false);
                }
            }
        }
    }
    remove(outputfile1_path.c_str());
    remove(outputfile2_path.c_str());
    remove("1.out");
    remove("2.out");
    remove(inputfile_path.c_str());
}//run the test to judge if the two program are equal

void runJudgement() {
    for (unsigned int i = 0; i < Judgement_input_vector.size() - 1; ++i) {
        for (unsigned int j = i + 1; j < Judgement_input_vector.size(); ++j) {
            //generate Output objects
            Output* temp_output = new Output(make_pair(Judgement_input_vector[i]->get_relative_path(), Judgement_input_vector[j]->get_relative_path()),
                                             make_pair(Judgement_input_vector[i]->get_absolute_path(), Judgement_input_vector[j]->get_absolute_path()),
                                             false);
            Judgement_output_vector.push_back(temp_output);

            //generate judgement objects
            Judgement* judgement = new Judgement(Judgement_input_vector[i], Judgement_input_vector[j], temp_output, stdin_vector);
            judgement_vector.push_back(judgement);

            //random test
            judgement->Judge();
        }
    }
}//combine functions above and run
void StartJudgement(string DirectoryPath){
    input_path=DirectoryPath;
    DIR* input_dir = opendir(DirectoryPath.c_str());
       if (input_dir == NULL) {
           cout << "Fail to open INPUT file directory!" << endl;
       }
       else {
           dirent* curdir;
           while ((curdir = readdir(input_dir)) != NULL) {
               curdir_name = curdir->d_name;
               if (curdir_name != ".vscode" && curdir_name != "." && curdir_name != "..") {

                   curdir_path = input_path + "\\" + curdir_name;
                   generate_input();
                   generate_stdin_format();

                   runJudgement();

                   Judgement_input_vector.clear();
                   stdin_vector.clear();
               }
           }
           closedir(input_dir);
       }

       //output results into inequal.csv
       Modifyfile_Judgement();
}//start Judgement
