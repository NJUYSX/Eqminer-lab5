#include "confirmation.h"
#include "ui_confirmation.h"
#include <QFile>
#include <QMessageBox>
#include <QStringList>
#include <QTextStream>
#include <QVector>
Confirmation::Confirmation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Confirmation)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle("确认工具");
    setFixedSize(800,600);

    ShowInfo();
    connect(ui->EqualBtn,&QPushButton::clicked,[=](){
        Confirm(1);
    });
    connect(ui->InequalBtn,&QPushButton::clicked,[=](){
        Confirm(0);
    });
    connect(ui->DoubtBtn,&QPushButton::clicked,[=](){
        Confirm(2);
    });
}

Confirmation::~Confirmation()
{
    delete ui;
}

void Confirmation::ShowInfo(){
    ui->FileContent1->clear();
    ui->FileContent2->clear();
    Output *input=Confirmation_input_vector[point];

    QString filename1=QString::fromStdString(input->get_ProgramPair_relpath().first);
    QString filename2=QString::fromStdString(input->get_ProgramPair_relpath().second);
    ui->Filename1->setText(filename1);
    ui->Filename2->setText(filename2);

    QString filepath1=QString::fromStdString(input->get_ProgramPair_abspath().first);
    QString filepath2=QString::fromStdString(input->get_ProgramPair_abspath().second);

    QStringList content1=filein(filepath1);//文件1的内容
    QStringList content2=filein(filepath2);//文件2的内容

    QVector<pair<int,int>> Sameline;
    int pos = 0;
    for(int i = 0;i<content1.size();++i){
        for(int j = pos;j<content2.size();++j){
            if(content1[i] == content2[j]){
                pos = j+1;
                Sameline.push_back(make_pair(i,j));
                continue;
            }
        }
    }

    QVector<int> RedLine,GreenLine;
    if(Sameline.empty()){
        for(int i=0;i<content1.size();i++)
             RedLine.push_back(i);
        for(int i=0;i<content2.size();i++)
             GreenLine.push_back(i);
    }
    else{
        int left=0,right=0;
        int min=Sameline[0].first<Sameline[0].second?Sameline[0].first:Sameline[0].second;
        for(int i=0;i<min;i++){
            RedLine.push_back(i);
            GreenLine.push_back(i);
        }

        for(int i=0;i<Sameline.size();i++){
            pair<int,int> temp_pair=Sameline[i];
            if(temp_pair.first+left<temp_pair.second+right){
                for(int j=temp_pair.first+left;j<temp_pair.second+right;j++){
                    content1.insert(j," ");
                    GreenLine.push_back(j);
                    left++;
                }
            }
            else if(temp_pair.first+left>temp_pair.second+right){
                for(int j=temp_pair.second+right;j<temp_pair.first+left;j++){
                    content2.insert(j," ");
                    RedLine.push_back(j);
                    right++;
                }
            }
            else if(i!=0){
                pair<int,int> Last_pair=Sameline[i-1];
                for(int j=Last_pair.first+left+1;j<temp_pair.first+left;j++)
                {
                    RedLine.push_back(j);
                    GreenLine.push_back(j);
                }
            }
        }
        for(int i=Sameline.back().first+left+1;i<content1.size();i++)
        RedLine.push_back(i);
        for(int i=Sameline.back().second+right+1;i<content2.size();i++)
        GreenLine.push_back(i);
    }

    ui->FileContent1->insertItems(0,content1);
    ui->FileContent2->insertItems(0,content2);

    for(int i = 0;i<RedLine.size();i++)
        ui->FileContent1->item(RedLine[i])->setForeground(QColor("red"));
    for(int i = 0;i<GreenLine.size();++i)
        ui->FileContent2->item(GreenLine[i])->setForeground(QColor("green"));

}
void Confirmation::Confirm(int choice){
   Output *output=Confirmation_input_vector[point];
   output->set_if_equal(choice);
   Confirmation_output_vector.push_back(output);
   point++;
   if(point<Confirmation_input_vector.size())ShowInfo();
   else{
       QMessageBox::information(this,"提示","您已完成所有等价对的确认！");
       Modifyfile_Confirmation();
       this->hide();
   }
}//开始确认
QStringList filein(QString filepath){
    QStringList ans;

    QFile file(filepath);
    file.open(QIODevice::ReadWrite);
    QTextStream in(&file);
    QString line=in.readLine();
    ans.append(line);
    while(!line.isNull())//字符串有内容
    {
        line=in.readLine();//循环读取下行
        ans.append(line);
    }
    file.close();

    return ans;
}//读入文件
