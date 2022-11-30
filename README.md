# FreeCAN
An automated vehicle CAN network test tool

# SW State
1. normal state
2. Log PlayBack state

in state 2 user can't click button,but could see output and input

# commit message pattern

    pattern: <type>(<scope>) : <subject>

type:

- feature
- fix
- docs
- style - code style
- refactor
- perf - performance
- test - add unit test or other test
- revert
- build  

scope is commit's influence ,like module, view also can be folder name.

scope：

- view:trigger
- view:dbfDesign
- view:input
- view:otherArea
- view:Pics
- Log
- Doc
- PlayBack:User
- PlayBack:Output
- UML
- Scripts
- ...

subject is commit Summary. should be short then 50 chars

one commit just include one scope!

# TODO

type:

- Feature
- Question
- Perf

# Design

1. Menubar should have edit/open/save/saveAs/new functions at least.
2. Menubar could generate items in trigger.qml and refresh it
3. signal name area should have link with bits area
