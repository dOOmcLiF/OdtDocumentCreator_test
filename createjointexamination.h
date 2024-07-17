
#ifndef CREATEJOINTEXAMINATION_H
#define CREATEJOINTEXAMINATION_H

#include <QString>
#include <QTextStream>
#include <QTextDocument>
#include <QTextDocumentWriter>
#include <QTextCursor>
#include <QTextBlock>
#include <QDate>
#include <QTextTableCell>
#include <QFont>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFileDialog>
#include <QTextBrowser>
#include <QFile>
#include <QTextStream>
#include <QVBoxLayout>
#include <QTemporaryFile>
#include <QDir>




class CreateJointExamination
{
public:
    CreateJointExamination();
    bool createsOdf(const QString &fileName, const QString &dateTime, const QString &surname, const QString &complaints, const QString &anamnesisMorbi, const QString &anamnesisVitae, const QString &stLocalis, const QString &diagnosis, const QString &treatmentPlan, const QString &examinationPlan, const QString &therapisht, const QString &headOfDepartment);
    QString createPreview(const QString &dateTime, const QString &surname, const QString &complaints, const QString &anamnesisMorbi, const QString &anamnesisVitae, const QString &stLocalis, const QString &diagnosis, const QString &treatmentPlan, const QString &examinationPlan, const QString &therapisht, const QString &headOfDepartment);

private:
    QTextDocument* createDocument(const QString &dateTime, const QString &surname, const QString &complaints, const QString &anamnesisMorbi, const QString &anamnesisVitae, const QString &stLocalis, const QString &diagnosis, const QString &treatmentPlan, const QString &examinationPlan, const QString &therapisht, const QString &headOfDepartment);
};

#endif // CREATEJOINTEXAMINATION_H
