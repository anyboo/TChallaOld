#ifndef FORMDOWNLOADFILE_H
#define FORMDOWNLOADFILE_H

#include <QWidget>
#include <videoserver.h>
#include "listview.h"

namespace Ui {
class FormDownloadFile;
}

class FormDownloadFile : public ListViewItem
{
    Q_OBJECT

public:
    explicit FormDownloadFile(QWidget *parent = 0);
    ~FormDownloadFile();
    void init(pRecordFile_t pFile, std::shared_ptr<videoserver> pServer);
    pRecordFile_t getData()
    {
        return mpFile;
    }
    void setChecked(bool b);
    bool isChecked();
protected:
    pRecordFile_t mpFile;
    std::shared_ptr<videoserver> mpServer;
private slots:
    void on_pushButtonPlay_clicked();

private:
    Ui::FormDownloadFile *ui;
};

#endif // FORMDOWNLOADFILE_H
