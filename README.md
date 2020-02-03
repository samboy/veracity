# Veracity

Veracity is an open source distributed version control system primarily
written by SourceGear LLC which versions not only the artifacts placed
under version control in the repository, but also associated data for
features such as the integrated bug tracking system and agile build
management tool. Written in C and JavaScript, Veracity is released
under the Apache License and has a publicly available code repository,
however it is still mostly developed by SourceGear with limited community
involvement.

# Integrated Bug tracking

Veracity's ability to tie a bug tracking system to specific versions of
the repository artifacts in a distributed way allows a user to easily keep
the bug tracking database in sync with the artifacts in every clone of
the repository. But, Veracity bug tracking data is only one data set
which is versioned along with the repository artifacts in a "distributed
database". Other such data includes a user list enabling built-in user
access controls; and file locks (Veracity supports a "lock" mechanism
similar to many traditional client-server version control systems).
How and where the decentralized database is stored is intended by the
developers to be configurable. Veracity allows storing the repository
separately from the working copy, and was designed to use an API which
hides the back-end storage of the data, so that any given repository can
use a wide variety of database formats or storage location. However,
although a user can already have multiple working copies associated
with a single repository, only one repository format (FS3) is actually
supported as of version 1.0.

# Usage

Some of Veracity's features are specifically intended to make the
software more attractive in a corporate environment. Veracity's authors
feel this distinguishes it from other DVCSs such as Mercurial or Git,
which often seem targeted toward open-source communities at the expense
of corporate users. However, Damon Poole writes for Dr. Dobb's that
DVCS in general, not just Veracity, can offer users just as suitable a
solution as the centralized version control systems more commonly used
in the corporate world; teams should consider all their options to select
the best system for their project's needs.

# See Also

The book [Version Control by Example](https://ericsink.com/vcbe/vcbe_usletter_lo.pdf) (PDF download)
has an entire chapter about Veracity.

# Note

This README.md file is based on the [now-deleted Wikipedia page on
Veracity](http://archive.is/2G7To).  The Wikipedia page was deleted 
because the software was abandoned back in 2013 and never achieved any
widespread usage nor popularity.

The text of this file is available under the Creative Commons
Attribution-ShareAlike License; additional terms may apply.  Since the 
page’s history is [unknown](https://archive.is/Q1qk8), attribution 
credit goes to the Wikipedia and its editors.
