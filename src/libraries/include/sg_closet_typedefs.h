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

//////////////////////////////////////////////////////////////////

#ifndef H_SG_CLOSET_TYPEDEFS_H
#define H_SG_CLOSET_TYPEDEFS_H

BEGIN_EXTERN_C;

///////////////////////////////////////////////////////////////////////////////

typedef enum
{
	SG_REPO_STATUS__UNSPECIFIED		= -1,
	SG_REPO_STATUS__NORMAL			= 0,
	SG_REPO_STATUS__CLONING			= 1,
	SG_REPO_STATUS__NEED_USER_MAP	= 2,
	SG_REPO_STATUS__IMPORTING		= 3
} SG_closet__repo_status;

#define SG_CLOSET_DESCRIPTOR_STATUS_KEY			"status"
#define SG_CLOSET_DESCRIPTOR_STATUS_NAME_KEY	"name"
#define SG_CLOSET_DESCRIPTOR_KEY				"descriptor"

///////////////////////////////////////////////////////////////////////////////

typedef struct SG_closet_descriptor_handle_is_opaque SG_closet_descriptor_handle;

///////////////////////////////////////////////////////////////////////////////

END_EXTERN_C;

#endif //H_SG_CLOSET_TYPEDEFS_H
