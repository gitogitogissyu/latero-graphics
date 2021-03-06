// -----------------------------------------------------------
//
// Copyright (c) 2015 by Vincent Levesque. All Rights Reserved.
//
// This file is part of latero-graphics.
//
//    latero-graphics is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Lesser General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    latero-graphics is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Lesser General Public License for more details.
//
//    You should have received a copy of the GNU Lesser General Public License
//    along with latero-graphics.  If not, see <http://www.gnu.org/licenses/>.
//
// -----------------------------------------------------------

#ifndef LATERO_GRAPHICS_PLANAR_AUDIO_ENGINE
#define LATERO_GRAPHICS_PLANAR_AUDIO_ENGINE

#include "engine.h"
#include "generatorfwd.h"
#include "audiodevicefwd.h"
#include <latero/tactograph.h>

namespace latero {
namespace graphics { 

class AudioEngine : public Engine
{
public:
	AudioEngine(latero::Tactograph *dev, boost::posix_time::time_duration period);
	virtual ~AudioEngine();
	virtual void EntryPoint();
	void SetGenerator(GeneratorPtr gen);
	void ResetGenerator();
	inline const latero::Tactograph *Dev() const { return dev_; }
private:
	latero::Tactograph *dev_;
	GeneratorPtr gen_;
	boost::posix_time::time_duration period_;
    AudioDevicePtr audioDevPtr_;
};

} // namespace graphics
} // namespace latero

#endif
