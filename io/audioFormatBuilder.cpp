#include "audioFormatBuilder.h"
#include "io/constants.h"

QAudioFormat* AudioFormatBuilder::format;

QAudioFormat* AudioFormatBuilder::getAudioFormat(){

    if (isFormatNotBuilded()){
        buildFormat();
    }

    return format;
}

bool AudioFormatBuilder::isFormatNotBuilded(){
    return format==0;
}

void AudioFormatBuilder::buildFormat(){
    format = new QAudioFormat();

    format->setFrequency(Constants::AudioFrequency);
    format->setChannels(Constants::AudioChannels);
    format->setSampleSize(Constants::AudioSampleSize);
    format->setSampleType(Constants::AudioSampleType);
    format->setByteOrder(Constants::AudioByteOrder);
    format->setCodec(Constants::AudioCodec);
}
