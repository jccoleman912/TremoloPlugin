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
    }
    
    void setFrequency(float frequencyHZ);
    
    void setCurrentSample(int intCurrentSample);
    
    float getSampleRate();

    
private:
    
    float Fs;
    
};

