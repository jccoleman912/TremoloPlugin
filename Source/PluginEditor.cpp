/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TremoloPluginAudioProcessorEditor::TremoloPluginAudioProcessorEditor (TremoloPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (700, 600);
}

TremoloPluginAudioProcessorEditor::~TremoloPluginAudioProcessorEditor()
{
}

//==============================================================================
void TremoloPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::slategrey);

}

void TremoloPluginAudioProcessorEditor::resized()
{
    
    // Slider and Label for "Depth" parameter
    
    depthSlider.setBounds(100,100,100,100);
    depthSlider.setRange(0.f,100.f,0.1f); // (min, max, interval)
    depthSlider.setValue(100.f); // initial value
    depthSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    depthSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    depthSlider.addListener(this);
    addAndMakeVisible(depthSlider);
    
    depthLabel.setText("Depth (%)", juce::dontSendNotification);
    depthLabel.attachToComponent(&depthSlider, false);
    depthLabel.setJustificationType(juce::Justification::centredTop);
    depthLabel.setFont(juce::Font("Arial Black", 22.0, juce::Font::bold));
    addAndMakeVisible(depthLabel);
    
    // Slider and Label for "Rate (Hz)" parameter
    
    rateSlider.setBounds(500,100,100,100);
    rateSlider.setRange(0.1f,30.f,0.1f); // (min, max, interval)
    rateSlider.setValue(0.f); // initial value
    rateSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    rateSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    rateSlider.addListener(this);
    addAndMakeVisible(rateSlider);
    
    rateLabel.setText("Rate (Hz)", juce::dontSendNotification);
    rateLabel.attachToComponent(&rateSlider, false);
    rateLabel.setJustificationType(juce::Justification::centredTop);
    rateLabel.setFont(juce::Font("Arial Black", 22.0, juce::Font::bold));
    addAndMakeVisible(rateLabel);
    
    // Slider and Label for "Depth" parameter
    
    tempoSlider.setBounds(50,400,200,60);
    tempoSlider.setRange(40.f,240.f,0.1f); // (min, max, interval)
    tempoSlider.setValue(120.f); // initial value
    tempoSlider.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    tempoSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    tempoSlider.addListener(this);
    addAndMakeVisible(tempoSlider);
    
    tempoLabel.setText("Tempo (BPM)", juce::dontSendNotification);
    tempoLabel.attachToComponent(&tempoSlider, false);
    tempoLabel.setJustificationType(juce::Justification::centredTop);
    tempoLabel.setFont(juce::Font("Arial Black", 22.0, juce::Font::bold));
    addAndMakeVisible(tempoLabel);
    
    // Slider and Label for "Mix" parameter
    
    mixSlider.setBounds(500,380,100,100);
    mixSlider.setRange(0.f,100.f,0.1f); // (min, max, interval)
    mixSlider.setValue(0.f); // initial value
    mixSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    mixSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    mixSlider.addListener(this);
    addAndMakeVisible(mixSlider);
    
    mixLabel.setText("Mix (%)", juce::dontSendNotification);
    mixLabel.attachToComponent(&mixSlider, false);
    mixLabel.setJustificationType(juce::Justification::centredTop);
    mixLabel.setFont(juce::Font("Arial Black", 22.0, juce::Font::bold));
    addAndMakeVisible(mixLabel);
    
    // Slider and Label for "Gain" parameter
    
    gainSlider.setBounds(325,450,100,100);
    gainSlider.setRange(0.f,100.f,0.1f); // (min, max, interval)
    gainSlider.setValue(0.f); // initial value
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
    
    gainLabel.setText("Gain (%)", juce::dontSendNotification);
    gainLabel.attachToComponent(&gainSlider, false);
    gainLabel.setJustificationType(juce::Justification::centredTop);
    gainLabel.setFont(juce::Font("Arial Black", 22.0, juce::Font::bold));
    addAndMakeVisible(gainLabel);
    
}



void TremoloPluginAudioProcessorEditor::sliderValueChanged(juce::Slider *slider) {
    
    if(slider == &gainSlider) {
        audioProcessor.gainValue = slider->getValue()/100.f;
    }
    else if (slider == &depthSlider) {
        audioProcessor.depthValue = slider->getValue()/100.f;
    }
    else if (slider == &rateSlider) {
        audioProcessor.rateValue = slider->getValue();
    }
    else if (slider == &mixSlider) {
        audioProcessor.mixValue = slider->getValue()/100.f;
    }
    
}


void TremoloPluginAudioProcessorEditor::buttonClicked (juce::Button *button) {
    
    
}

void TremoloPluginAudioProcessorEditor::comboBoxChanged (juce::ComboBox* comboBox) {
    
}
