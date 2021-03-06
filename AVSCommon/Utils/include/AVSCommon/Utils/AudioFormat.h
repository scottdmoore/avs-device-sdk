/*
 * AudioFormat.h
 *
 * Copyright 2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

/**
 * @file AudioFormat.h
 */
#ifndef ALEXA_CLIENT_SDK_AVS_COMMON_UTILS_INCLUDE_AVS_COMMON_UTILS_AUDIO_FORMAT_H_
#define ALEXA_CLIENT_SDK_AVS_COMMON_UTILS_INCLUDE_AVS_COMMON_UTILS_AUDIO_FORMAT_H_

#include <ostream>

namespace alexaClientSDK {
namespace avsCommon {
namespace utils {

/**
 * The format of audio data.
 */
struct AudioFormat {
    /**
     * An enum class used to represent the encoding of audio data.
     */
    enum class Encoding {
        /// Represents LPCM (Linear pulse code modulation) encoding.
        LPCM
    };

    /**
     * An enum class used to represent the endianness of audio data.
     */
    enum class Endianness {
        /// Represents little endianness.
        LITTLE,

        /// Represents big endianness.
        BIG
    };

    /// The encoding of the data.
    Encoding encoding;

    /// The endianness of the data.
    Endianness endianness;

    /// The number of samples recorded or played per second.
    unsigned int sampleRateHz;

    /// The bits per sample.
    unsigned int sampleSizeInBits;

    /// The number of channels.
    unsigned int numChannels;
};

/**
 * Write an @c Encoding value to an @c ostream as a string.
 *
 * @param stream The stream to write the value to.
 * @param encoding The encoding value to write to the @c ostream as a string.
 * @return The @c ostream that was passed in and written to.
 */
inline std::ostream& operator<<(std::ostream& stream, const AudioFormat::Encoding& encoding) {
    switch (encoding) {
        case AudioFormat::Encoding::LPCM:
            stream << "LPCM";
            break;
    }
    return stream;
}

/**
 * Write an @c Endianness value to an @c ostream as a string.
 *
 * @param stream The stream to write the value to.
 * @param endianness The endianness value to write to the @c ostream as a string.
 * @return The @c ostream that was passed in and written to.
 */
inline std::ostream& operator<<(std::ostream& stream, const AudioFormat::Endianness& endianness) {
    switch (endianness) {
        case AudioFormat::Endianness::LITTLE:
            stream << "LITTLE";
            break;
        case AudioFormat::Endianness::BIG:
            stream << "BIG";
            break;
    }
    return stream;
}

}  // namespace utils
}  // namespace avsCommon
}  // namespace alexaClientSDK

#endif  // ALEXA_CLIENT_SDK_AVS_COMMON_UTILS_INCLUDE_AVS_COMMON_UTILS_AUDIO_FORMAT_H_
