#include <QDebug>
#include <QAudioDeviceInfo>
#include "audioFormatBuilder.h"
#include "io/constants.h"

QAudioFormat AudioFormatBuilder::format;
bool AudioFormatBuilder::isBuilded = false;

QAudioFormat AudioFormatBuilder::getAudioFormat(){

    if (isFormatNotBuilded()){
        buildFormat();
        checkFormat();
    }

    return format;
}

bool AudioFormatBuilder::isFormatNotBuilded(){
    return isBuilded==false;
}

void AudioFormatBuilder::buildFormat(){
    format.setFrequency(Constants::AudioFrequency);
    format.setChannels(Constants::AudioChannels);
    format.setSampleSize(Constants::AudioSampleSize);
    format.setSampleType(Constants::AudioSampleType);
    format.setByteOrder(Constants::AudioByteOrder);
    format.setCodec(Constants::AudioCodec);

    isBuilded = true;
}

void showWarningFormatNotSupperted(){
    qWarning() << "Default format not supported - trying to use nearest.";
}

void AudioFormatBuilder::checkFormat(){
    QAudioDeviceInfo info(QAudioDeviceInfo::defaultInputDevice());

    if (info.isFormatSupported(format)==false) {
        showWarningFormatNotSupperted();
        format = info.nearestFormat(format);
    }
}
