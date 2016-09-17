#include <QFile>
#include <QTextStream>
#include "findcrap.h"
#include "ui_findcrap.h"

FindCrap::FindCrap(QWidget *parent) :QWidget(parent),ui(new Ui::FindCrap)
{
    ui->setupUi(this);
    getTextFile();
}

FindCrap::~FindCrap()
{
    delete ui;
}

void FindCrap::on_SearchButton_clicked()
{
    QString word = ui->lineEdit->text();
    ui->textEdit->find(word,QTextDocument::FindWholeWords);
}

void FindCrap::getTextFile()
{
    QFile myfile("C:/Users/Mun Kit/Documents/Qt Projects/FindCrap/text.txt");
    myfile.open(QIODevice::ReadOnly);
    QTextStream textStream(&myfile);
    QString line = textStream.readAll();
    myfile.close();

    ui->textEdit->setPlainText(line);
    QTextCursor textCursor = ui->textEdit->textCursor();
    textCursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor,1);
}
