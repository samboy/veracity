# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# Copyright 2010-2013 SourceGear, LLC
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

set(C_SOURCES sg_mongoose.c sg_mongoose.h)
set(ALL_SOURCE ${C_SOURCES})
add_library(sgmongoose STATIC ${ALL_SOURCE})
set_target_properties(sgmongoose PROPERTIES FOLDER "Libraries")

IF (WIN32)
target_link_libraries(sgmongoose wsock32.lib)
ELSE (WIN32)
target_link_libraries(sgmongoose)
ENDIF (WIN32)
