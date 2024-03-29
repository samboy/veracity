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

#ifndef VV_RENAME_COMMAND_H
#define VV_RENAME_COMMAND_H

#include "precompiled.h"
#include "vvCommand.h"


/**
 * A command that renames a repository object.
 */
class vvRenameCommand : public vvRepoCommand
{
// construction
public:
	/**
	 * Default constructor.
	 */
	vvRenameCommand(unsigned int extraFlags = 0);

// implementation
public:
	/**
	 * Usage: rename <workingfolder item>
	 */
	virtual bool ParseArguments(
		const wxArrayString& cArguments
		);

	/**
	 * See base class description.
	 */
	virtual class vvDialog* CreateDialog(
		wxWindow* wParent
		);

	/**
	 * See base class description.
	 */
	virtual bool Execute();

// member data
private:
	wxString              msDirectory; //< The object to rename.
	class vvRenameDialog* mwDialog;    //< The dialog to use to gather information from the user.
};


#endif
