/*
  ==============================================================================

   This file is part of the JUCE framework.
   Copyright (c) Raw Material Software Limited

   JUCE is an open source framework subject to commercial or open source
   licensing.

   By downloading, installing, or using the JUCE framework, or combining the
   JUCE framework with any other source code, object code, content or any other
   copyrightable work, you agree to the terms of the JUCE End User Licence
   Agreement, and all incorporated terms including the JUCE Privacy Policy and
   the JUCE Website Terms of Service, as applicable, which will bind you. If you
   do not agree to the terms of these agreements, we will not license the JUCE
   framework to you, and you must discontinue the installation or download
   process and cease use of the JUCE framework.

   JUCE End User Licence Agreement: https://juce.com/legal/juce-8-licence/
   JUCE Privacy Policy: https://juce.com/juce-privacy-policy
   JUCE Website Terms of Service: https://juce.com/juce-website-terms-of-service/

   Or:

   You may also use this code under the terms of the AGPLv3:
   https://www.gnu.org/licenses/agpl-3.0.en.html

   THE JUCE FRAMEWORK IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL
   WARRANTIES, WHETHER EXPRESSED OR IMPLIED, INCLUDING WARRANTY OF
   MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, ARE DISCLAIMED.

  ==============================================================================
*/

/**
    Classes for IIR filter processing.
*/
namespace juce::dsp::IIR
{
    /** A set of coefficients for use in an Filter object.

        @tags{DSP}
    */
    template <typename NumericType>
    struct ArrayCoefficients
    {
        /** Returns the coefficients for a first order low-pass filter. */
        static std::array<NumericType, 4> makeFirstOrderLowPass (double sampleRate, NumericType frequency);

        /** Returns the coefficients for a first order high-pass filter. */
        static std::array<NumericType, 4> makeFirstOrderHighPass (double sampleRate, NumericType frequency);

        /** Returns the coefficients for a first order all-pass filter. */
        static std::array<NumericType, 4> makeFirstOrderAllPass (double sampleRate, NumericType frequency);

        /** Returns the coefficients for a low-pass filter. */
        static std::array<NumericType, 6> makeLowPass (double sampleRate, NumericType frequency);

        /** Returns the coefficients for a low-pass filter with variable Q. */
        static std::array<NumericType, 6> makeLowPass (double sampleRate, NumericType frequency, NumericType Q);

        /** Returns the coefficients for a high-pass filter. */
        static std::array<NumericType, 6> makeHighPass (double sampleRate, NumericType frequency);

        /** Returns the coefficients for a high-pass filter with variable Q. */
        static std::array<NumericType, 6> makeHighPass (double sampleRate, NumericType frequency, NumericType Q);

        /** Returns the coefficients for a band-pass filter. */
        static std::array<NumericType, 6> makeBandPass (double sampleRate, NumericType frequency);

        /** Returns the coefficients for a band-pass filter with variable Q. */
        static std::array<NumericType, 6> makeBandPass (double sampleRate, NumericType frequency, NumericType Q);

        /** Returns the coefficients for a notch filter. */
        static std::array<NumericType, 6> makeNotch (double sampleRate, NumericType frequency);

        /** Returns the coefficients for a notch filter with variable Q. */
        static std::array<NumericType, 6> makeNotch (double sampleRate, NumericType frequency, NumericType Q);

        /** Returns the coefficients for an all-pass filter. */
        static std::array<NumericType, 6> makeAllPass (double sampleRate, NumericType frequency);

        /** Returns the coefficients for an all-pass filter with variable Q. */
        static std::array<NumericType, 6> makeAllPass (double sampleRate, NumericType frequency, NumericType Q);

        /** Returns the coefficients for a low-pass shelf filter with variable Q and gain.

            The gain is a scale factor that the low frequencies are multiplied by, so values
            greater than 1.0 will boost the low frequencies, values less than 1.0 will
            attenuate them.
        */
        static std::array<NumericType, 6> makeLowShelf (double sampleRate,
                                                        NumericType cutOffFrequency,
                                                        NumericType Q,
                                                        NumericType gainFactor);

        /** Returns the coefficients for a high-pass shelf filter with variable Q and gain.

            The gain is a scale factor that the high frequencies are multiplied by, so values
            greater than 1.0 will boost the high frequencies, values less than 1.0 will
            attenuate them.
        */
        static std::array<NumericType, 6> makeHighShelf (double sampleRate,
                                                         NumericType cutOffFrequency,
                                                         NumericType Q,
                                                         NumericType gainFactor);

        /** Returns the coefficients for a peak filter centred around a
            given frequency, with a variable Q and gain.

            The gain is a scale factor that the centre frequencies are multiplied by, so
            values greater than 1.0 will boost the centre frequencies, values less than
            1.0 will attenuate them.
        */
        static std::array<NumericType, 6> makePeakFilter (double sampleRate,
                                                          NumericType centreFrequency,
                                                          NumericType Q,
                                                          NumericType gainFactor);

    private:
        // Unfortunately, std::sqrt is not marked as constexpr just yet in all compilers
        static constexpr NumericType inverseRootTwo = static_cast<NumericType> (0.70710678118654752440L);
    };

    //==============================================================================
    /** A set of coefficients for use in an Filter object.
        @see IIR::Filter

        @tags{DSP}
    */
    template <typename NumericType>
    struct Coefficients  : public ProcessorState
    {
        /** Creates a null set of coefficients (which will produce silence). */
        Coefficients();

        /** Directly constructs an object from the raw coefficients.
            Most people will want to use the static methods instead of this, but the
            constructor is public to allow tinkerers to create their own custom filters!
        */
        Coefficients (NumericType b0, NumericType b1,
                      NumericType a0, NumericType a1);

        Coefficients (NumericType b0, NumericType b1, NumericType b2,
                      NumericType a0, NumericType a1, NumericType a2);

        Coefficients (NumericType b0, NumericType b1, NumericType b2, NumericType b3,
                      NumericType a0, NumericType a1, NumericType a2, NumericType a3);

        Coefficients (const Coefficients&) = default;
        Coefficients (Coefficients&&) = default;
        Coefficients& operator= (const Coefficients&) = default;
        Coefficients& operator= (Coefficients&&) = default;

        /** Constructs from an array. */
        template <size_t Num>
        explicit Coefficients (const std::array<NumericType, Num>& values) { assignImpl<Num> (values.data()); }

        /** Assigns contents from an array. */
        template <size_t Num>
        Coefficients& operator= (const std::array<NumericType, Num>& values) { return assignImpl<Num> (values.data()); }

        /** The Coefficients structure is ref-counted, so this is a handy type that can be used
            as a pointer to one.
        */
        using Ptr = ReferenceCountedObjectPtr<Coefficients>;

        //==============================================================================
        /** Returns the coefficients for a first order low-pass filter. */
        static Ptr makeFirstOrderLowPass (double sampleRate, NumericType frequency);

        /** Returns the coefficients for a first order high-pass filter. */
        static Ptr makeFirstOrderHighPass (double sampleRate, NumericType frequency);

        /** Returns the coefficients for a first order all-pass filter. */
        static Ptr makeFirstOrderAllPass (double sampleRate, NumericType frequency);

        //==============================================================================
        /** Returns the coefficients for a low-pass filter. */
        static Ptr makeLowPass (double sampleRate, NumericType frequency);

        /** Returns the coefficients for a low-pass filter with variable Q. */
        static Ptr makeLowPass (double sampleRate, NumericType frequency, NumericType Q);

        //==============================================================================
        /** Returns the coefficients for a high-pass filter. */
        static Ptr makeHighPass (double sampleRate, NumericType frequency);

        /** Returns the coefficients for a high-pass filter with variable Q. */
        static Ptr makeHighPass (double sampleRate, NumericType frequency, NumericType Q);

        //==============================================================================
        /** Returns the coefficients for a band-pass filter. */
        static Ptr makeBandPass (double sampleRate, NumericType frequency);

        /** Returns the coefficients for a band-pass filter with variable Q. */
        static Ptr makeBandPass (double sampleRate, NumericType frequency, NumericType Q);

        //==============================================================================
        /** Returns the coefficients for a notch filter. */
        static Ptr makeNotch (double sampleRate, NumericType frequency);

        /** Returns the coefficients for a notch filter with variable Q. */
        static Ptr makeNotch (double sampleRate, NumericType frequency, NumericType Q);

        //==============================================================================
        /** Returns the coefficients for an all-pass filter. */
        static Ptr makeAllPass (double sampleRate, NumericType frequency);

        /** Returns the coefficients for an all-pass filter with variable Q. */
        static Ptr makeAllPass (double sampleRate, NumericType frequency, NumericType Q);

        //==============================================================================
        /** Returns the coefficients for a low-pass shelf filter with variable Q and gain.

            The gain is a scale factor that the low frequencies are multiplied by, so values
            greater than 1.0 will boost the low frequencies, values less than 1.0 will
            attenuate them.
        */
        static Ptr makeLowShelf (double sampleRate, NumericType cutOffFrequency,
                                 NumericType Q, NumericType gainFactor);

        /** Returns the coefficients for a high-pass shelf filter with variable Q and gain.

            The gain is a scale factor that the high frequencies are multiplied by, so values
            greater than 1.0 will boost the high frequencies, values less than 1.0 will
            attenuate them.
        */
        static Ptr makeHighShelf (double sampleRate, NumericType cutOffFrequency,
                                  NumericType Q, NumericType gainFactor);

        /** Returns the coefficients for a peak filter centred around a
            given frequency, with a variable Q and gain.

            The gain is a scale factor that the centre frequencies are multiplied by, so
            values greater than 1.0 will boost the centre frequencies, values less than
            1.0 will attenuate them.
        */
        static Ptr makePeakFilter (double sampleRate, NumericType centreFrequency,
                                   NumericType Q, NumericType gainFactor);

        //==============================================================================
        /** Returns the filter order associated with the coefficients */
        size_t getFilterOrder() const noexcept;

        /** Returns the magnitude frequency response of the filter for a given frequency
            and sample rate
        */
        double getMagnitudeForFrequency (double frequency, double sampleRate) const noexcept;

        /** Returns the magnitude frequency response of the filter for a given frequency array
            and sample rate.
        */
        void getMagnitudeForFrequencyArray (const double* frequencies, double* magnitudes,
                                            size_t numSamples, double sampleRate) const noexcept;

        /** Returns the phase frequency response of the filter for a given frequency and
            sample rate
        */
        double getPhaseForFrequency (double frequency, double sampleRate) const noexcept;

        /** Returns the phase frequency response of the filter for a given frequency array
            and sample rate.
        */
        void getPhaseForFrequencyArray (double* frequencies, double* phases,
                                        size_t numSamples, double sampleRate) const noexcept;

        /** Returns a raw data pointer to the coefficients. */
        NumericType* getRawCoefficients() noexcept              { return coefficients.getRawDataPointer(); }

        /** Returns a raw data pointer to the coefficients. */
        const NumericType* getRawCoefficients() const noexcept  { return coefficients.begin(); }

        //==============================================================================
        /** The raw coefficients.
            You should leave these numbers alone unless you really know what you're doing.
        */
        Array<NumericType> coefficients;

    private:
        using ArrayCoeffs = ArrayCoefficients<NumericType>;

        template <size_t Num>
        Coefficients& assignImpl (const NumericType* values);

        template <size_t Num>
        Coefficients& assign (const NumericType (& values)[Num]) { return assignImpl<Num> (values); }
    };

    //==============================================================================
    /**
        A processing class that can perform IIR filtering on an audio signal, using
        the Transposed Direct Form II digital structure.

        If you need a lowpass, bandpass or highpass filter with fast modulation of
        its cutoff frequency, you might use the class StateVariableFilter instead,
        which is designed to prevent artefacts at parameter changes, instead of the
        class Filter.

        @see Filter::Coefficients, FilterAudioSource, StateVariableFilter

        @tags{DSP}
    */
    template <typename SampleType>
    class Filter
    {
    public:
        /** The NumericType is the underlying primitive type used by the SampleType (which
            could be either a primitive or vector)
        */
        using NumericType = typename SampleTypeHelpers::ElementType<SampleType>::Type;

        /** A typedef for a ref-counted pointer to the coefficients object */
        using CoefficientsPtr = typename Coefficients<NumericType>::Ptr;

        //==============================================================================
        /** Creates a filter.

            Initially the filter is inactive, so will have no effect on samples that
            you process with it. You can modify the coefficients member to turn it into
            the type of filter needed.
        */
        Filter();

        /** Creates a filter with a given set of coefficients. */
        Filter (CoefficientsPtr coefficientsToUse);

        Filter (const Filter&) = default;
        Filter (Filter&&) = default;
        Filter& operator= (const Filter&) = default;
        Filter& operator= (Filter&&) = default;

        //==============================================================================
        /** The coefficients of the IIR filter. It's up to the caller to ensure that
            these coefficients are modified in a thread-safe way.

            If you change the order of the coefficients then you must call reset after
            modifying them.
        */
        CoefficientsPtr coefficients;

        //==============================================================================
        /** Resets the filter's processing pipeline, ready to start a new stream of data.

            Note that this clears the processing state, but the type of filter and
            its coefficients aren't changed.
        */
        void reset()    { reset (SampleType {0}); }

        /** Resets the filter's processing pipeline to a specific value.
            @see reset
        */
        void reset (SampleType resetToValue);

        //==============================================================================
        /** Called before processing starts. */
        void prepare (const ProcessSpec&) noexcept;

        /** Processes a block of samples */
        template <typename ProcessContext>
        void process (const ProcessContext& context) noexcept
        {
            if (context.isBypassed)
                processInternal<ProcessContext, true> (context);
            else
                processInternal<ProcessContext, false> (context);

           #if JUCE_DSP_ENABLE_SNAP_TO_ZERO
            snapToZero();
           #endif
        }

        /** Processes a single sample, without any locking.

            Use this if you need processing of a single value.

            Moreover, you might need the function snapToZero after a few calls to avoid
            potential denormalisation issues.
        */
        SampleType JUCE_VECTOR_CALLTYPE processSample (SampleType sample) noexcept;

        /** Ensure that the state variables are rounded to zero if the state
            variables are denormals. This is only needed if you are doing
            sample by sample processing.
        */
        void snapToZero() noexcept;

    private:
        //==============================================================================
        void check();

        /** Processes a block of samples */
        template <typename ProcessContext, bool isBypassed>
        void processInternal (const ProcessContext& context) noexcept;

        //==============================================================================
        HeapBlock<SampleType> memory;
        SampleType* state = nullptr;
        size_t order = 0;

        JUCE_LEAK_DETECTOR (Filter)
    };
} // namespace juce::dsp::IIR
