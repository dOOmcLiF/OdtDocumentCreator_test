
#ifndef CREATEODF_H
#define CREATEODF_H

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

#include <QtCore>
#include <QtGui>


class CreateOdf
{
public:
    CreateOdf();
    void createsOdfWithTable();
    bool createsOdf(const QString &fileName, const QString &name, const QString &surname);
};
#endif // CREATEODF_H
