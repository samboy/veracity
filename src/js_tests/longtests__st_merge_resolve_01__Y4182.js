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

load("../js_test_lib/vscript_test_lib.js");

//////////////////////////////////////////////////////////////////
// Test for Y4182, Y8599, SPRAWL-993.  Certain MERGE situations
// cause an item to retain its state as it was in the baseline
// (causing it or its parent directory to appear CLEAN and thus
// letting the pendingtree-remove-clean code flush the unneeded
// ptnodes) which caused problems for STATUS and RESOLVE when
// trying to use __find_by_gid on a sparse tree and causing an 
// error to be thrown (or a "TODO Fix Path for Display" message
// to be substituted in for a pathname).
//////////////////////////////////////////////////////////////////

function st_merge_status()
{
    load("update_helpers.js");          // load the helper functions
    initialize_update_helpers(this);    // initialize helper functions

    //////////////////////////////////////////////////////////////////

    this.setUp = function()
    {
        this.workdir_root = sg.fs.getcwd();     // save this for later

        //////////////////////////////////////////////////////////////////
        // fetch the HID of the initial commit.

        this.csets.push( sg.wc.parents()[0] );
        this.names.push( "*Initial Commit*" );

        //////////////////////////////////////////////////////////////////
	// create:
	//
	//      0
	//     /
	//    1

        this.do_fsobj_mkdir("dir_0");
        this.do_fsobj_mkdir("dir_0/dir_00");
        this.do_fsobj_mkdir("dir_0/dir_00/dir_000");
        this.do_fsobj_mkdir("dir_0/dir_00/dir_000/dir_0000");
        this.do_fsobj_create_file("dir_0/dir_00/dir_000/dir_0000/file_0");
        vscript_test_wc__addremove();
        this.do_commit("Simple ADDs 0");

        this.do_fsobj_append_file("dir_0/dir_00/dir_000/dir_0000/file_0", "Content added in 'Simple ADDs 1' CSET");
        this.do_fsobj_create_file("file_1");
        vscript_test_wc__addremove();
	vscript_test_wc__rename("dir_0/dir_00", "dir_00_1");
        this.do_commit("Simple ADDs 1");

	this.rev_trunk_head = this.csets[ this.csets.length - 1 ];

	//////////////////////////////////////////////////////////////////
	// update back to '0' and start a new branch '2':
	//
	//      0
	//     / \
	//    1   2

	this.do_update_when_clean_by_name("Simple ADDs 0");
	sg.exec(vv, "branch", "attach", "master");
        this.do_fsobj_append_file("dir_0/dir_00/dir_000/dir_0000/file_0", "Content added in 'Simple ADDs 2' CSET");
        this.do_fsobj_create_file("file_2");
        vscript_test_wc__addremove();
	vscript_test_wc__rename("dir_0/dir_00", "dir_00_2");
        this.do_commit_in_branch("Simple ADDs 2");

	this.rev_branch_head = this.csets_in_branch[ this.csets_in_branch.length - 1 ];

	//////////////////////////////////////////////////////////////////

	var o = sg.exec(vv, "heads");
	print("Heads are:");
	print(o.stdout);

	print("");
	print("rev_trunk_head  := " + this.rev_trunk_head);
	print("rev_branch_head := " + this.rev_branch_head);
	print("");
	print("================================================================");
	print("End of Setup");
	print("================================================================");
	print("");
    }

    //////////////////////////////////////////////////////////////////
    //
    //////////////////////////////////////////////////////////////////

    this.do_update_by_rev = function(rev)
    {
	print("vv update --rev=" + rev);
	var o = sg.exec(vv, "update", "--rev="+rev);

	//print("STDOUT:\n" + o.stdout);
	//print("STDERR:\n" + o.stderr);

	testlib.ok( o.exit_status == 0, "Exit status should be 0" );
	this.assert_current_baseline(rev);
    }

    this.do_exec_merge = function(rev, bExpectFail, msgExpected)
    {
	print("vv merge --rev=" + rev);
	var o = sg.exec(vv, "merge", "--rev="+rev, "--verbose");
	
	print("STDOUT:\n" + o.stdout);
	print("STDERR:\n" + o.stderr);

	if (bExpectFail)
	{
	    testlib.ok( o.exit_status == 1, "Exit status should be 1" );
	    testlib.ok( o.stderr.search(msgExpected) >= 0, "Expecting error message [" + msgExpected + "]. Received:\n" + o.stderr);
	}
	else
	{
	    testlib.ok( o.exit_status == 0, "Exit status should be 0" );
	}

	// omit the 'vv status' and 'vv resolve list --all' dumps
	// and let the test look at things first.
    }

    //////////////////////////////////////////////////////////////////
    // NOTE: this.confirm() and vscript_test_wc__confirm_wii()
    //       compute a STATUS and compare that with the expected results.
    //       A STATUS reflects the changes made to the WD from the
    //       BASELINE.  So the STATUS should show how the FINAL RESULT
    //       changed from the BASELINE.
    //
    //       This feels a little odd because we are accustomed to
    //       think about the total net changes from the ANCESTOR to
    //       the FINAL RESULT.
    //
    //       So, for example, if a file was renamed between the
    //       ancestor and the baseline branch (but not in the other
    //       changeset), it will not show up in the status.  It will
    //       have the new name in the final result, but that is not
    //       a change relative to the baseline.
    //////////////////////////////////////////////////////////////////

    this.test_simple_tb_1 = function()
    {
	this.force_clean_WD();

	this.do_update_by_rev(this.rev_trunk_head);

	// do MERGE, but don't defer the expect_test stuff to
	// after we have probed things a bit.

	this.do_exec_merge(this.rev_branch_head, 0, "");

	print("");
	print("================================");
	print("Doing 'vv resolve list --all'...");
	print("");

	var r = sg.exec(vv, "resolve", "list", "--all");

	print("STDOUT:\n" + r.stdout);
	print("STDERR:\n" + r.stderr);

	testlib.ok( r.exit_status == 0, "Exit status should be 0" );

	print("");
	print("================================");
	print("Doing 'vv status'...");
	print("");

	var s = sg.exec(vv, "status");

	print("STDOUT:\n" + s.stdout);
	print("STDERR:\n" + s.stderr);

	testlib.ok( s.exit_status == 0, "Exit status should be 0" );

	print("");
	print("================================");
	print("Confirming expected results...");
	print("");

        var expect_test = new Array;
        expect_test["Added (Merge)"] = [ "@/file_2" ];
	expect_test["Modified"]      = [ "@/dir_0/dir_00_1~g[0-9a-f]*/dir_000/dir_0000/file_0" ];
	expect_test["Auto-Merged"]   = [ "@/dir_0/dir_00_1~g[0-9a-f]*/dir_000/dir_0000/file_0" ];
	expect_test["Renamed"]       = [ "@/dir_0/dir_00_1~g[0-9a-f]*" ];
	expect_test["Unresolved"]    = [ "@/dir_0/dir_00_1~g[0-9a-f]*",
					 "@/dir_0/dir_00_1~g[0-9a-f]*/dir_000/dir_0000/file_0" ];
	expect_test["Choice Unresolved (Name)"]     = [ "@/dir_0/dir_00_1~g[0-9a-f]*" ];
	expect_test["Choice Unresolved (Contents)"] = [ "@/dir_0/dir_00_1~g[0-9a-f]*/dir_000/dir_0000/file_0" ];
        vscript_test_wc__confirm_wii(expect_test);
    }
}
