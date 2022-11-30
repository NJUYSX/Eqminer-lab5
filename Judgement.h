#ifndef JUDGEMENT_H
#define JUDGEMENT_H
#pragma once
#include "Input.h"
#include "Output.h"
#include <stdio.h>
using namespace std;
class Judgement {
private:
    Input* input1;
    Input* input2;
    Output* output;
    vector<Stdin_format*> Format_vector;
public:
    Judgement();
    Judgement(Input* input_1, Input* input_2, Output* _output, vector<Stdin_format*> Vector);
    void GenerateRandomCase();//generate random cases into casefile for test
    void Judge();//run the test to judge if the two program are equal

};
string random_case(int n);//generate single random test

void runJudgement();//combine functions above and run
void StartJudgement(string DirectoryPath);//start Judgement
#endif // JUDGEMENT_H
