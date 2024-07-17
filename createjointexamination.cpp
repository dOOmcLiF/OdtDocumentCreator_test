
#include "createjointexamination.h"

CreateJointExamination::CreateJointExamination()
{

}

bool CreateJointExamination::createsOdf(const QString &fileName, const QString &dateTime, const QString &surname, const QString &complaints, const QString &anamnesisMorbi, const QString &anamnesisVitae, const QString &stLocalis, const QString &diagnosis, const QString &treatmentPlan, const QString &examinationPlan, const QString &therapisht, const QString &headOfDepartment)
{
    QTextDocument *doc = createDocument(dateTime, surname, complaints, anamnesisMorbi, anamnesisVitae, stLocalis, diagnosis, treatmentPlan, examinationPlan, therapisht, headOfDepartment);

    QTextDocumentWriter writer(fileName);
    writer.setFormat("odf");
    bool createSuccess = writer.write(doc);

    delete doc;
    return createSuccess;
}

QString CreateJointExamination::createPreview(const QString &dateTime, const QString &surname, const QString &complaints, const QString &anamnesisMorbi, const QString &anamnesisVitae, const QString &stLocalis, const QString &diagnosis, const QString &treatmentPlan, const QString &examinationPlan, const QString &therapisht, const QString &headOfDepartment)
{
    QTemporaryFile tempFile(QDir::tempPath() + "/preview_XXXXXX.html");
    tempFile.setAutoRemove(false);
    if (tempFile.open()) {
        QString tempFileName = tempFile.fileName();
        tempFile.close();

        QTextDocument *doc = createDocument(dateTime, surname, complaints, anamnesisMorbi, anamnesisVitae, stLocalis, diagnosis, treatmentPlan, examinationPlan, therapisht, headOfDepartment);

        QTextDocumentWriter writer(tempFileName);
        writer.setFormat("html");
        if (writer.write(doc)) {
            delete doc;
            return tempFileName;
        }
        delete doc;
    }
    return QString();
}

QTextDocument* CreateJointExamination::createDocument(const QString &dateTime, const QString &surname, const QString &complaints, const QString &anamnesisMorbi, const QString &anamnesisVitae, const QString &stLocalis, const QString &diagnosis, const QString &treatmentPlan, const QString &examinationPlan, const QString &therapisht, const QString &headOfDepartment)
{
    QTextDocument *doc = new QTextDocument;
    doc->setDocumentMargin(10);

    QTextCursor cursor(doc);
    cursor.movePosition(QTextCursor::Start);

    QTextCharFormat textFormat;
    textFormat.setFont(QFont("Times New Roman", 10));
    doc->setDefaultFont(textFormat.font());

    QTextCharFormat boldFormat;
    boldFormat.setFont(QFont("Times New Roman", 15, QFont::Bold));

    //HEADERS
    QTextCharFormat header1Format = textFormat;
    header1Format.setFont(QFont("Times"));
    header1Format.setFontPointSize(10);
    //header1Format.setFontUnderline(true);
    header1Format.setForeground(QBrush(QColor(Qt::black)));

    QTextCharFormat header2Format = textFormat;
    header2Format.setFont(QFont("Times"));
    header2Format.setFontPointSize(10);
    //header2Format.setFontUnderline(true);
    header2Format.setForeground(QBrush(QColor(Qt::red)));

    QTextCharFormat title1Format = boldFormat;
    title1Format.setFontPointSize(10);
    //titleFormat.setFontUnderline(true);
    title1Format.setForeground(QBrush(QColor(Qt::black)));

    QTextCharFormat title2Format = boldFormat;
    title2Format.setFontPointSize(10);
    //titleFormat.setFontUnderline(true);
    title2Format.setForeground(QBrush(QColor(Qt::red)));

    QTextBlockFormat titleBlockFormat = cursor.block().blockFormat();
    titleBlockFormat.setAlignment(Qt::AlignHCenter);
    QTextBlockFormat blockFormat = cursor.block().blockFormat();

    //Title of the document
    //cursor.insertBlock();
    cursor.insertText(dateTime, title1Format);
    cursor.insertText(QObject::tr("\t\t"));
    cursor.insertText(QObject::tr("Совместный осмотр с зав/отд колопроктологии"), title1Format);
    cursor.insertBlock(); //new line

    cursor.setBlockFormat(blockFormat);
    cursor.insertText(QObject::tr("Жалобы: "), title2Format);
    cursor.insertText(complaints,header2Format);
    cursor.insertBlock();
    cursor.insertText(QObject::tr("Anamnesis morbi: "), title2Format);
    cursor.insertText(anamnesisMorbi, header2Format);
    cursor.insertBlock();
    cursor.insertText(QObject::tr("Anamnesis vitae: "), title1Format);
    cursor.insertText(anamnesisVitae, header1Format);
    cursor.insertBlock();
    cursor.insertText(QObject::tr("St. localis: "), title2Format);
    cursor.insertText(stLocalis, header2Format);
    cursor.insertBlock();
    cursor.insertText(QObject::tr("Диагноз: "), title1Format);
    cursor.insertText(diagnosis, title1Format);
    cursor.insertBlock();
    cursor.insertText(QObject::tr("План обследования: "), title1Format);
    cursor.insertBlock();
    cursor.insertText(examinationPlan, header1Format);
    cursor.insertBlock();
    cursor.insertText(QObject::tr("План лечения: "), title1Format);
    cursor.insertBlock();
    cursor.insertText(treatmentPlan, header1Format);
    cursor.insertBlock();
    cursor.insertBlock();
    cursor.insertText(QObject::tr("\t\t\t\t\t\t"));
    cursor.insertText(QObject::tr("Леч. врач: "), header1Format);
    cursor.insertText(QObject::tr("______________________"), header1Format);
    cursor.insertText(therapisht, header1Format);
    cursor.insertBlock();
    cursor.insertText(QObject::tr("\t\t\t\t\t\t"));
    cursor.insertText(QObject::tr("Зав. отделением: "), header1Format);
    cursor.insertText(QObject::tr("______________________"), header1Format);
    cursor.insertText(headOfDepartment, header1Format);

    cursor.movePosition(QTextCursor::End);




    return doc;
}
