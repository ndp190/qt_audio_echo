#ifndef AUDIOWRITER_H
#define AUDIOWRITER_H

#include <QObject>
#include <QAudioOutput>

class AudioWriter : public QObject{
    Q_OBJECT

public slots:
    void writeData(const char* data, int length);

public:
    explicit AudioWriter(QObject *parent = 0);

private:
    void createAudioOutput(void);

    QAudioFormat audioFormat;
    QAudioOutput* audioOutput;
    QIODevice* audioDevice;
};

#endif // AUDIOWRITER_H
