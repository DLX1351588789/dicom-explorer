#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QTableWidget;
class CReadDcmFile;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void wheelEvent(QWheelEvent* evt);
    void SetFileName(const char* fileName);

protected:
    virtual void closeEvent(QCloseEvent *event);

private slots:
    void on_OpenImg_pushButton_clicked();
    void on_MultiFrame_verticalSlider_valueChanged(int value);

    void on_actionDicomTags_triggered();
    void on_Close_pushButton_clicked();
    void on_About_pushButton_clicked();

private:
    void OpenImg();
    void ShowAnnotations();
    void ClearAnnotations();
    void CloseImg();
    void InitToolBar();

private:
    Ui::MainWindow *ui;

    CReadDcmFile* m_pReadDcmFile;
    QTableWidget *m_pTagsInfoTable;
    QString m_strFileName;
};


#endif // MAINWINDOW_H
