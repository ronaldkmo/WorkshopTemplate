#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Add the slider to the main window
    addAndMakeVisible(freqSlider);
    // Set the range of the slider
    freqSlider.setRange(50.0, 1000.0);
    
    // Set the size of the component
    setSize (600, 100);

    // Specify the number of input and output channels that we want to open
    setAudioChannels (0, 2);
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // Update Sample Rate
    currentSampleRate = sampleRate;
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    // Define a variable for storing the amplitude of the output. Crank it up to make it louder.
    float amplitude = 0.03;
    // Get the output buffers
    float* leftBuffer = bufferToFill.buffer->getWritePointer (0, bufferToFill.startSample);
    float* rightBuffer = bufferToFill.buffer->getWritePointer (1, bufferToFill.startSample);
    
    // Calculate the change of angle and store it into a new float variable angleDelta. That is, 2 * pi * frequency / sampleRate.
    //      > You can obtain the current frequency from the slider using freqSlider.getValue().
    //      > Variable currentSampleRate stores the sample rate.
    //      > Contant M_PI stores the value of Pi
    float angleDelta = 2 * M_PI * freqSlider.getValue() / currentSampleRate;
    
    // Get the number of samples in the buffer and store it into int variable numSamples
    int numSamples = bufferToFill.buffer->getNumSamples();
    
    /*
        Your code here
     
        Main idea: Use a for loop to calculate the audio samples and send them to the output buffer. In the loop you should:
         1. Calculate y(.) for the current sample. That is amplitude * sin(angle).
             Store the value into a new float variable currentSample.
             > To calculate sin(), we can use the C++ standard function std::sin()
             > To obtain the angle for the current sample, we can refer to variable currentAngle. It is initialized as 0.
             > Variable amplitude stores the amplitude.
            
         2. Increase the value of variable currentAngle by the value of variable angleDelta as we need to get prepared for the next sample.

         3. Update the current sample in the output buffer for both channels (e.g., leftBuffer[i]). You should refer to the ith sample in the buffers.
     */
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}

void MainComponent::resized()
{
    freqSlider.setBounds(10, 10, 580, 20);
}
