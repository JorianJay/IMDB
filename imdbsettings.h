#ifndef IMDBSETTINGS_H
#define IMDBSETTINGS_H

#include <QDialog>
#include <QAbstractButton>
#include <QListView>
#include <QListIterator>

namespace Ui {
class ImDbSettings;
}

class ImDbSettings : public QDialog
{
    Q_OBJECT

public:
    explicit ImDbSettings(QWidget *parent = 0);
    ~ImDbSettings();



private slots:
    void on_buttonBox_accepted();
    void ScrapeIntervalChanged(int value);

    void on_btnSelFolder_clicked();
    void on_btnAddFolder_clicked();
    void on_buttonBox_2_clicked(QAbstractButton *button);
    void on_lstFoldersToScan_clicked(const QModelIndex &index);

    void on_buttonBox_3_clicked(QAbstractButton *button);


    void on_pushButton_clicked();

    void on_lstRegExp_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();



    void on_btnAddDelFileFilter_clicked();

    void on_lstDeleteFileTypes_clicked(const QModelIndex &index);

    void on_buttonBox_4_clicked(QAbstractButton *button);


    void on_btnAddDelFileFilter_2_clicked();

    void on_buttonBox_5_clicked(QAbstractButton *button);

    void on_lstChoppers_clicked(const QModelIndex &index);

private:
    Ui::ImDbSettings *ui;
    QAction *actCloseApp;
    void saveini(const QString &name, const QVariant &value);
    QVariant ini(const QString &key, const QVariant &defaultValue) const;

    void addDefaultDeleteMasks();
    void addDefaultRegExp();
    void addDefaultChoppers();
};

#endif // IMDBSETTINGS_H
