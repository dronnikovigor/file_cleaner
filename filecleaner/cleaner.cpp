#include "cleaner.h"

Cleaner::Cleaner(QObject *parent) : QObject(parent)
{
    inputPath = "";
    outputPath = "";
    inputExt = "";
    outputExt = "";
}

void Cleaner::setInputPath(QString str)
{
    inputPath = str;
}

void Cleaner::setOutputPath(QString str)
{
    outputPath = str;
}

bool Cleaner::checkPath()
{
    return ((inputPath != "") && (outputPath != ""));
}

void Cleaner::setInputExt(QString str)
{
    inputExt = str;
}

void Cleaner::setOutputExt(QString str)
{
    outputExt = str;
}

bool Cleaner::checkExt()
{
    return ((inputExt != "") && (outputExt != ""));
}

bool Cleaner::checkFolder(QString str)
{
    if (QDir(str).exists())
        return 1;
    else
        return 0;
}

void Cleaner::checkFiles()
{
    QStringList filters;
    filters << "*."+inputExt;
    inputDir.setNameFilters(filters);
    QStringList inputFiles = inputDir.entryList(filters, QDir::Files);

    filters.clear();
    filters << "*."+outputExt;
    outputDir.setNameFilters(filters);
    QStringList outputFiles = outputDir.entryList(filters, QDir::Files);

    for (int i = 0; i < outputFiles.size(); i++){
        QString filename = outputFiles.at(i);
        QString temp = filename;
        if(filename.endsWith("."+outputExt)){
            filename.replace("."+outputExt, "."+inputExt);
            if(!inputFiles.contains(filename)){
                QFile::remove(outputDir.absolutePath() + "/" + temp);
            }
        }
    }
}

bool Cleaner::clear()
{
    if(checkFolder(inputPath)){
        inputDir.setPath(inputPath);
        if(checkFolder(outputPath)){
            outputDir.setPath(outputPath);
            checkFiles();
        }
        else return 0;
    }
    else return 0;
    return 1;
}
