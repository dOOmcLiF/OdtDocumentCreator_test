#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "createjointexamination.h"

#include <QMainWindow>
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

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_createButton_clicked();

    void on_aboutAction_triggered();

    void on_openButton_clicked();

    void on_previewButton_clicked();

private:
    Ui::MainWindow *ui;
    void getHwid();
    CreateJointExamination cje;
};
#endif // MAINWINDOW_H
