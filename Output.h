#ifndef OUTPUT_H
#define OUTPUT_H
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>

#include "Struct.h"
using namespace std;
class Output {
private:
    pair <string, string> ProgramPair_relpath;//存相对路径，文件输出要用
    pair <string, string> ProgramPair_abspath;//存绝对路径，打开文件要用
    int if_equal;//0不相等 1相等 2存疑
public:
    Output();
    Output(pair<string, string>ProPair_relpath, pair<string, string>ProPair_abspath,int flag);
    void set_ProgramPair_relpath(const string& ProgramA, const string& ProgramB);
    void set_ProgramPair_abspath(const string& ProgramA, const string& ProgramB);
    void set_if_equal(const int& flag);

    int get_if_equal();
    pair<string, string> get_ProgramPair_relpath();
    pair<string, string> get_ProgramPair_abspath();

};

void Modifyfile_Judgement();//等价判断工具的输出结果
void Modifyfile_Confirmation();//等价判断工具的输出结果
#endif // OUTPUT_H
