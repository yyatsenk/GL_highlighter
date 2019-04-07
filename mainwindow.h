#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class SearchHighLight;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void onSearchText();
    Ui::MainWindow *ui;
    SearchHighLight* searchHighLight;
};

#endif // MAINWINDOW_H
