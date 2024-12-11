/*
  ==============================================================================

    TremoloProcessing.cpp
    Created: 16 May 2024 11:08:29am
    Author:  Jackson Coleman

  ==============================================================================
*/

#include "TremoloProcessing.h"

#include <cmath>

float TremoloProcessing::processSample(float x, const int c){
    
//    if(i > hwBufferSize) {
//        i = 0;
//    }
    
    LFO = sin(2 * M_PI * rate * currentTimeInSeconds);
    
    LFO *= halvedDepth;
    LFO += 1 - halvedDepth;
    
//    i++;
    
    y = gain * x * LFO;
    
    return y;
    
}

void TremoloProcessing::setFrequency(float frequencyHZ) {
    rate = frequencyHZ;
}

void TremoloProcessing::setCurrentTime(juce::Optional<double> timeInSeconds) {
    if(timeInSeconds.hasValue()) {
        currentTimeInSeconds = *timeInSeconds;
    } else {
        currentTimeInSeconds = 0.0;
    }
}

void TremoloProcessing::setDepth(float intDepthPercentage) {
    halvedDepth = intDepthPercentage/2.f;
}

void TremoloProcessing::setGain(float inGain) {
    gain = inGain;
}
