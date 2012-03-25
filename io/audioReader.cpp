#include <QDebug>
#include <QtCore/qendian.h>

#include "audioReader.h"
#include "audioFormatBuilder.h"
#include "constants.h"

AudioReader::AudioReader(QObject *parent)
    : QObject(parent),
      maxLevel(Constants::InputMaxLevel),
      minLevel(Constants::InputMinLevel),
      maxAmplitude(Constants::InputMaxAmplitude),
      audioDeviceInfo(QAudioDeviceInfo::defaultInputDevice()),
      audioInput(0) {

    audioFormat = AudioFormatBuilder::getAudioFormat();
    createAudioInput();
}

void AudioReader::createAudioInput(){
    audioInput = new QAudioInput(audioDeviceInfo, audioFormat, this);
    audioInput->setBufferSize(Constants::AudioBufferSize);

    connect(audioInput, SIGNAL(stateChanged(QAudio::State)),
            this, SLOT(stateChanged(QAudio::State)));

    audioDevice = audioInput->start();

    connect(audioDevice, SIGNAL(readyRead()),
            this, SLOT(onReadyRead()));
}

void AudioReader::onReadyRead(void){
    buffer = audioDevice->read(Constants::AudioBufferSize);

    onBufferFilled();
}

void AudioReader::onBufferFilled(){
    calculateLevel();

    if ((currentLevel>=minLevel)
     && (currentLevel<=maxLevel)){

        emit levelUpdated(currentLevel);
        emit dataUpdated(buffer.data(), buffer.size());
    } else {
        if (currentLevel>maxLevel){
            emit levelUpdated(maxLevel);
        } else {
            emit levelUpdated(0.0);
        }
    }
}

void AudioReader::calculateLevel(){
    Q_ASSERT(audioFormat.sampleSize() % 8 == 0);

    const int channelBytes = audioFormat.sampleSize() / 8;
    const int sampleBytes = audioFormat.channels() * channelBytes;

    Q_ASSERT(len % sampleBytes == 0);

    const int numSamples = buffer.size() / sampleBytes;

    quint16 currentMaxAmplitude = 0;
    const unsigned char *ptr = reinterpret_cast<const unsigned char *>(buffer.data());

    for (int i = 0; i < numSamples; ++i) {
        for(int j = 0; j < audioFormat.channels(); ++j) {
            quint16 currentValue = qAbs(qFromLittleEndian<qint16>(ptr));
            currentMaxAmplitude = qMax(currentValue, currentMaxAmplitude);
            ptr += channelBytes;
        }
    }

    currentMaxAmplitude = qMin(currentMaxAmplitude, maxAmplitude);
    currentLevel = qreal(currentMaxAmplitude)/maxAmplitude;
}

void AudioReader::stateChanged(QAudio::State state){
    qWarning() << "AudioReader: state = " << state;
}

void AudioReader::setMaxLevel(qreal value){
    this->maxLevel = value;
}

void AudioReader::setMinLevel(qreal value){
    this->minLevel = value;
}
