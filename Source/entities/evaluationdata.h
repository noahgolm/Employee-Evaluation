#ifndef EVALUATIONDATA_H
#define EVALUATIONDATA_H

#include <QMap>
#include <QDate>

//Forward declarations
class QString;

class EvaluationData
{

public:
    //--------------------------
    // Enums for the maps
    //--------------------------
    enum InfoFields {
        evalNumber,
        employeeID,
        employerID
    };

    enum DateFields {
        nextDate,
        currentDate
    };

    enum MainFields {
        workQuality,
        workHabits,
        jobKnowledge,
        behavior,
        overall
    };

    EvaluationData();
    EvaluationData(int number);

    EvaluationData setDate(DateFields field, QDate date);
    EvaluationData setScore(MainFields field, int score);
    EvaluationData setComment(MainFields field, QString comment);
    EvaluationData setInfo(InfoFields field, int data);
    EvaluationData setAverageScore(float score);
    EvaluationData setRecommend(bool b);

    QDate   getDate(DateFields field);
    int     getScore(MainFields field);
    float   getAverageScore();
    QString getComment(MainFields field);
    int     getInfo(InfoFields field);
    bool    getRecommend();

private:
    QMap<InfoFields, int>      infoMap;
    QMap<DateFields, QDate>    dateMap;
    QMap<MainFields, QString>  commentsMap;
    QMap<MainFields, int>      scoreMap;

    //Whether or not to recommend the individual
    float averageScore;
    bool  doRecommend;


};

#endif // EVALUATIONDATA_H
