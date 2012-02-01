#ifndef AUDIOFORMATBUILDER_H
#define AUDIOFORMATBUILDER_H

#include <QAudioFormat>

class AudioFormatBuilder {

public:
    static QAudioFormat getAudioFormat();

private:
    AudioFormatBuilder(){}

    static bool isFormatNotBuilded();
    static void buildFormat();
    static void checkFormat();

    static bool isBuilded;
    static QAudioFormat format;
};

#endif // AUDIOFORMATBUILDER_H
