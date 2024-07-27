#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "config.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(Config::applicationName);
    getHwid();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_createButton_clicked()
{
    QString dateTime = ui->dateTimeEdit->text();
    QString surname = ui->surnameEdit->text();
    QString complaints = ui->complaintsEdit->toPlainText();
    QString anamnesisMorbi = ui->anamnesisMorbiEdit->toPlainText();
    QString anamnesisVitae = ui->anamnesisVitaeEdit->toPlainText();
    QString stLocalis = ui->stLocalisEdit->toPlainText();
    QString diagnosis = ui->diagnosisEdit->toPlainText();
    QString treatmentPlan = ui->treatmentPlanEdit->toPlainText();
    QString examinationPlan = ui->examinationPlanEdit->toPlainText();
    QString therapist = ui->therapistEdit->text();
    QString headOfDepartment = ui->headOfDepartmentEdit->text();

    QString nameOfFile = QFileDialog::getSaveFileName(this,
        tr("Сохранить файл"),
        "",
        tr("ODT файлы (*.odt);;Все файлы (*)"));

    if (nameOfFile.isEmpty())
        return;

    if (!nameOfFile.endsWith(".odt", Qt::CaseInsensitive))
        nameOfFile += ".odt";

    bool createSuccess = cje.createsOdf(nameOfFile, dateTime, surname, complaints, anamnesisMorbi, anamnesisVitae, stLocalis, diagnosis, treatmentPlan, examinationPlan, therapist, headOfDepartment);

    if (createSuccess) {
        QMessageBox::information(this, "Успех!", "Файл успешно сохранён!");
    }

}



void MainWindow::on_aboutAction_triggered()
{
    QMessageBox aboutDlg(this);
    aboutDlg.setTextFormat(Qt::RichText);
    aboutDlg.setWindowTitle(tr("О программе %1").arg(Config::applicationName));
    aboutDlg.setIcon(QMessageBox::Information);
    aboutDlg.setText(tr("%1 %2<br>"
                        "Автор: <a href=\"https://t.me/dOOmcLiF_tg\">dOOmcLiF</a>, 2024.<br>"
                        "This application is dynamically linked against the "
                        "<a href=\"https://www.qt.io/developers/\">Qt Library</a> "
                        "v. %3, which is under the LGPLv3 license.<br>")
                         .arg(Config::applicationName, Config::applicationVersion, qVersion()));
    aboutDlg.exec();
}

void MainWindow::getHwid()
{
    QString hwid = QSysInfo::machineUniqueId();

    QEventLoop loop;
    QNetworkAccessManager nam;
    QNetworkRequest req(QUrl("https://raw.githubusercontent.com/dOOmcLiF/Mods/main/files/hwid's"));
    QNetworkReply *reply = nam.get(req);
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    QByteArray buffer = reply->readAll();

    qDebug() << "what did i get" << buffer.trimmed();

    QString ips = buffer;
    QStringList lines = ips.split("\n");
    qDebug() << lines;

    bool found = false;
    for (const QString& line : lines) {
        if (line.trimmed() == hwid) {
            found = true;
            break;
        }
    }

    if (found) {
        qDebug() << "HWID found in the list";
    } else {
        qDebug() << "HWID not found in the list";
    }
}


void MainWindow::on_openButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Выберите файл"),
        "",
        tr("HTML файлы (*.html *.htm);;Все файлы (*.*)"));

    if (!fileName.isEmpty())
    {
        qDebug() << "Выбранный файл:" << fileName;
        //previewHtmlFile(fileName);
    }
}

void MainWindow::on_previewButton_clicked()
{
    QString dateTime = ui->dateTimeEdit->text();
    QString surname = ui->surnameEdit->text();
    QString complaints = ui->complaintsEdit->toPlainText();
    QString anamnesisMorbi = ui->anamnesisMorbiEdit->toPlainText();
    QString anamnesisVitae = ui->anamnesisVitaeEdit->toPlainText();
    QString stLocalis = ui->stLocalisEdit->toPlainText();
    QString diagnosis = ui->diagnosisEdit->toPlainText();
    QString treatmentPlan = ui->treatmentPlanEdit->toPlainText();
    QString examinationPlan = ui->examinationPlanEdit->toPlainText();
    QString therapist = ui->therapistEdit->text();
    QString headOfDepartment = ui->headOfDepartmentEdit->text();

    QString tempFileName = cje.createPreview(dateTime, surname, complaints, anamnesisMorbi, anamnesisVitae, stLocalis, diagnosis, treatmentPlan, examinationPlan, therapist, headOfDepartment);

    if (!tempFileName.isEmpty()) {
        QFile file(tempFileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString htmlContent = in.readAll();
            file.close();

            QTextBrowser *previewWidget = new QTextBrowser(this);
            previewWidget->setOpenExternalLinks(false);
            previewWidget->setHtml(htmlContent);

            QDialog *previewDialog = new QDialog(this);
            QVBoxLayout *layout = new QVBoxLayout(previewDialog);
            layout->addWidget(previewWidget);
            previewDialog->setLayout(layout);
            previewDialog->setWindowTitle(tr("Предпросмотр"));
            previewDialog->resize(800, 600);
            previewDialog->show();
        } else {
            QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось открыть файл для предпросмотра."));
        }
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось создать файл для предпросмотра."));
    }
}


void MainWindow::on_nextButton_clicked()
{
    int currentIndex = ui->stackedWidget->currentIndex();
    int pageCount = ui->stackedWidget->count();

    int nextIndex = (currentIndex + 1) % pageCount;
    ui->stackedWidget->setCurrentIndex(nextIndex);
}


void MainWindow::on_prevButton_clicked()
{
    int currentIndex = ui->stackedWidget->currentIndex();
    int pageCount = ui->stackedWidget->count();

    int nextIndex = (currentIndex - 1) % pageCount;
    ui->stackedWidget->setCurrentIndex(nextIndex);
}

