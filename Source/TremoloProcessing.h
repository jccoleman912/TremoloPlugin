/*
  ==============================================================================

    TremoloProcessing.h
    Created: 16 May 2024 11:08:29am
    Author:  Jackson Coleman

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class TremoloProcessing
{
public:
    
    float processSample(float x, const int c);
    
    void processBlock(juce::AudioBuffer<float> &buffer);
    
    void processInPlace(float * buffer, const int numSamples, const int c);
    
    void prepareToPlay(double sampleRate, int bufferSize){
        Fs = (float) sampleRate;
        hwBufferSize = bufferSize;
    }
    
    void setFrequency(float frequencyHZ);
    
    void setCurrentTime(juce::Optional<double> timeInSeconds);
    
    void setDepth(float intDepthPercentage);
    
    void setGain(float inGain);
    
    float getSampleRate();

    
private:
    
    float y = 0.f;
    // Input parameters
    float halvedDepth, rate = 2.f, gain, period, phase = 0.f, LFO;
    
    double currentTimeInSeconds;
    
    float Fs;
    float hwBufferSize;
    int i = 0;
    
};

