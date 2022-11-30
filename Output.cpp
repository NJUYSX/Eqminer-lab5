#include"Output.h"

Output::Output(){}
Output::Output(pair<string, string>ProPair_relpath, pair<string, string>ProPair_abspath,int flag):
    ProgramPair_relpath(ProPair_relpath),ProgramPair_abspath(ProPair_abspath),if_equal(flag) {}
void Output::set_ProgramPair_relpath(const string &ProgramA, const string &ProgramB){
    ProgramPair_relpath = make_pair(ProgramA, ProgramB);
}
void Output::set_ProgramPair_abspath(const string &ProgramA, const string &ProgramB){
    ProgramPair_abspath = make_pair(ProgramA, ProgramB);
}
void Output::set_if_equal(const int& flag) {
    if_equal = flag;
}

int Output::get_if_equal() { return if_equal; }
pair<string, string> Output::get_ProgramPair_abspath() { return ProgramPair_abspath; }
pair<string, string> Output::get_ProgramPair_relpath() { return ProgramPair_relpath; }
void Modifyfile_Judgement() {
    //inequal
    fstream File_inequal;
    File_inequal.open("inequal.csv", ios::out);
    File_inequal << "file1" << ',' << "file2" << endl;

    for (unsigned int i = 0; i < Judgement_output_vector.size(); ++i) {
        if (Judgement_output_vector[i]->get_if_equal() == 0) {
            //inequal,直接写入文件
            File_inequal << Judgement_output_vector[i]->get_ProgramPair_relpath().first << ',' << Judgement_output_vector[i]->get_ProgramPair_relpath().second << endl;
        }
        else if (Judgement_output_vector[i]->get_if_equal() == 1) {
            //equal，交给等价确认工具确认
            Confirmation_input_vector.push_back(Judgement_output_vector[i]);
        }
    }
    File_inequal.close();
}
void Modifyfile_Confirmation(){
    fstream File_inequal;
    File_inequal.open("inequal.csv", ios::app);//已追加模式写
    File_inequal << "file1" << ',' << "file2" << endl;

    fstream File_equal;
    File_equal.open("equal.csv",ios::out);
    File_equal << "file1" << ',' << "file2" << endl;

    fstream File_doubt;
    File_doubt.open("doubt.csv",ios::out);
    File_doubt << "file1" << ',' << "file2" << endl;

    for (unsigned int i = 0; i < Confirmation_output_vector.size(); ++i) {
        if (Confirmation_output_vector[i]->get_if_equal() == 0) {
            //inequal
            File_inequal << Confirmation_output_vector[i]->get_ProgramPair_relpath().first << ',' << Confirmation_output_vector[i]->get_ProgramPair_relpath().second << endl;
        }
        else if (Confirmation_output_vector[i]->get_if_equal() == 1) {
            //equal
             File_equal << Confirmation_output_vector[i]->get_ProgramPair_relpath().first << ',' << Confirmation_output_vector[i]->get_ProgramPair_relpath().second << endl;
        }
        else if(Confirmation_output_vector[i]->get_if_equal() == 2){
            //doubt
            File_doubt << Confirmation_output_vector[i]->get_ProgramPair_relpath().first << ',' << Confirmation_output_vector[i]->get_ProgramPair_relpath().second << endl;
        }
    }
    File_inequal.close();
}
