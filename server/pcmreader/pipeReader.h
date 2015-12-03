/***
    This file is part of snapcast
    Copyright (C) 2015  Johannes Pohl

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
***/

#ifndef PIPE_READER_H
#define PIPE_READER_H

#include "pcmReader.h"



/// Reads and decodes PCM data from a named pipe
/**
 * Reads PCM from a named pipe and passes the data to an encoder.
 * Implements EncoderListener to get the encoded data.
 * Data is passed to the PcmListener
 */
class PipeReader : public PcmReader
{
public:
	/// ctor. Encoded PCM data is passed to the PipeListener
	PipeReader(PcmListener* pcmListener, const msg::SampleFormat& sampleFormat, const std::string& codec, const std::string& fifoName, size_t pcmReadMs = 20);
	virtual ~PipeReader();

protected:
	void worker();
};


#endif