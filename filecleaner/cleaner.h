#ifndef CLEANER_H
#define CLEANER_H

#include <QObject>
#include <QDir>
#include <QDebug>

class Cleaner : public QObject
{
    Q_OBJECT
private:
    QString inputPath;
    QString outputPath;

    QString inputExt;
    QString outputExt;

    QDir inputDir;
    QDir outputDir;
public:
    explicit Cleaner(QObject *parent = nullptr);
    bool checkPath();
    void setOutputPath(QString str);
    void setInputPath(QString str);
    void setInputExt(QString str);
    void setOutputExt(QString str);
    bool checkExt();
    bool checkFolder(QString str);
    void checkFiles();
    bool clear();
signals:

public slots:
};

#endif // CLEANER_H
