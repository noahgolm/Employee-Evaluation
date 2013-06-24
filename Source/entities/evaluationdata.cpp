#include "evaluationdata.h"
#include <QString>
#include <QMap>

EvaluationData::EvaluationData()
{

}

EvaluationData::EvaluationData(int number)
{
    this->setInfo(evalNumber, number);
}

EvaluationData EvaluationData::setDate(DateFields field, QDate date)
{
    dateMap.insert(field, date);
    return *this;
}


EvaluationData EvaluationData::setScore(MainFields field, int score)
{
    scoreMap.insert(field, score);
    return *this;
}

EvaluationData EvaluationData::setComment(MainFields field, QString comment)
{
    commentsMap.insert(field, comment);
    return *this;
}

EvaluationData EvaluationData::setInfo(InfoFields field, int data)
{
    infoMap.insert(field, data);
    return *this;
}

EvaluationData EvaluationData::setAverageScore(float score)
{
    this->averageScore = score;
    return *this;
}

EvaluationData EvaluationData::setRecommend(bool b)
{
    this->doRecommend = b;
    return *this;
}

QDate EvaluationData::getDate(DateFields field)
{
    return dateMap.value(field);
}

int EvaluationData::getInfo(InfoFields field)
{
    return infoMap.value(field);
}

int EvaluationData::getScore(EvaluationData::MainFields field)
{
    return scoreMap.value(field);
}

float EvaluationData::getAverageScore()
{
    return this->averageScore;
}

QString EvaluationData::getComment(EvaluationData::MainFields field)
{
    return commentsMap.value(field);
}

bool EvaluationData::getRecommend()
{
    return this->doRecommend;
}
