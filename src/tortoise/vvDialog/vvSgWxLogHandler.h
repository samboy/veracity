/*
Copyright 2010-2013 SourceGear, LLC

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef VV_SG_WX_LOG_HANDLER_H
#define VV_SG_WX_LOG_HANDLER_H

#include "precompiled.h"
#include "vvSgLogHandler.h"


/**
 * An sglib log handler that reports messages to the wxLog* system.
 */
class vvSgWxLogHandler : public vvSgGeneralLogHandler
{
// construction
public:
	vvSgWxLogHandler();
};


#endif
