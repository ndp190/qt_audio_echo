#include "audioWriter.h"
#include "audioFormatBuilder.h"
#include "constants.h"

AudioWriter::AudioWriter(QObject *parent)
    : QObject(parent),
      audioOutput(0){

    audioFormat = AudioFormatBuilder::getAudioFormat();
    createAudioOutput();
}

void AudioWriter::createAudioOutput(void){
    audioOutput = new QAudioOutput(audioFormat, this);
    audioOutput->setBufferSize(Constants::AudioBufferSize);

    audioDevice = audioOutput->start();
}

void AudioWriter::writeData(const char* data, int length){
    audioDevice->write(data, length);
}
