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

load("suite_web_filter.js");
load("../js_test_lib/vv_serve_process.js");

function st_web_filter()
{
    var suite = new suite_web_filter();

    suite.setUp = function ()
    {
        this.server_process = new vv_serve_process(18008, { runFromWorkingCopy: true });
        this.rootUrl = this.server_process.url;
        this.repoUrl = this.rootUrl + "/repos/" + encodeURI(repInfo.repoName);
        this.suite_setUp();
    }

    suite.tearDown = function ()
    {
        this.server_process.stop();
    }

    return suite;
}
