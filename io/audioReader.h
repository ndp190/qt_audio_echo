#ifndef AUDIOREADER_H
#define AUDIOREADER_H

#include <QObject>
#include <qaudioinput.h>

class AudioReader : public QObject {
    Q_OBJECT

signals:
    void levelUpdated(qreal value);
    void dataUpdated(const char* data, int length);

private slots:
    void stateChanged(QAudio::State state);
    void onReadyRead(void);

public:
    explicit AudioReader(QObject *parent = 0);

    void setMaxLevel(qreal value);
    void setMinLevel(qreal value);

private:
    void createAudioInput();
    void onBufferFilled();
    void calculateLevel();

    qreal maxLevel;
    qreal minLevel;

    quint16 maxAmplitude;
    qreal currentLevel;

    QByteArray buffer;

    int readSizeNeeded;
    int readSizeLeft;

    QAudioDeviceInfo audioDeviceInfo;
    QIODevice* audioDevice;
    QAudioFormat audioFormat;
    QAudioInput* audioInput;
};

#endif // AUDIOREADER_H
