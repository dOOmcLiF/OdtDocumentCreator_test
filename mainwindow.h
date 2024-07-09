#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void createsOdfWithTable();
    bool createsOdf(const QString &fileName);
    void getHwid();
    void previewHtmlFile(const QString &fileName);
};
#endif // MAINWINDOW_H
