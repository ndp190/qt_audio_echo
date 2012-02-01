#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Constants {

#include <QAudioFormat>

const int InputMaxAmplitude  = 32767;

const qreal InputMaxLevel = 1.0;
const qreal InputMinLevel = 0.1;

const QAudioFormat::SampleType AudioSampleType = QAudioFormat::SignedInt;
const QAudioFormat::Endian     AudioByteOrder  = QAudioFormat::LittleEndian;

const int AudioBufferSize = 16384;
const int AudioFrequency  = 44100;
const int AudioChannels   = 2;
const int AudioSampleSize = 16;
const QString AudioCodec  = "audio/pcm";

}

#endif // CONSTANTS_H
