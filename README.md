# Ch-air-
Ch(air) Emergency ventilator
A simple ventilator based on a standard manual resuscitator plus worldwide easly accesible parts.

It can be made in simple workshops, or adapted for mass production.

Some parts can be mass manufactured and posted widely, such as: linkage, mounting kit, and extensions such as controller, sensing, logging.

The base part do not have any electronics.  The electrical part is a standard car windscreen wiper motor.  It is to be powered by low voltage from a standard benchtop power supply, which thus is used to regulate breath rate. A standard UPS for office or home use for PC can be used for backup operation.

We have developed extensions for expiration pause, trig, and 12V battery operation with built-in speed setting, see video of version 2.  They are described in build instruction for version 2.

The mounting frame is easy to source: a wooden chair as in the prototype.  Or suitable sturdy wooden box, whatever... For mass production of complete unit of course a tailored frame is preferred.
It can be made from a vareity of materials and means, so a mertal working or a furniture or appliance manufacturer can easily produce it.

For version 3 we are developing a cirquit board that adds functionality, lower cost of functions such as pause and trig, add alarm etc, makes setting easier, and substantially lowers production costs.

Videos of prototype operating

Version 1
Presentation video and more: https://photos.app.goo.gl/yRxQ9RMRdP5GabSL6 
Also see the trig explanation in video of Version 3 in link below

Version 2
... in progress

Now here are three simply shot videos where i show how the trig works, and also other settings.

Here is also the sensing of exhale demonstrated. Now it only blinks a lamp; it is intended to be extended by a timer setting off an alarm if main switch is on and there is no OK breath for a few seconds.  Adding an own backup battery to the alarm, it also works when power and main backup goes out.  :)   This is a catch-all *) solution.  It can not alarm for wrong flow or pressure, but any time flow back from patient is too low.

*) If the non-rebreatning valve go bad so air go directly to exhaust instead of to patient, the signals will be off in phase and also this error may thus be detected if compared to crank position. https://tribun.cloud/index.php/s/mzqPWbDTTHnb4xj?path=%2FCh(air)%2FDevelopment%2FV2-V3 

The build now have low quality and is leaking water, this is for validation of ideas.

Functions

Maximum pressure and PEEP pressure regulation is realised reliably by bubbling in separate transparent water bottles.  Adjust the pressures by adjusting water levels.

Pressure readout by water levels in transparent tubes.

Inspiration volume is easily mechanically adjustable, and adjustable are to some extent also length of and pauses between inspiration and expiration.

It is prepared to connect to O2 equipment: it have a tube and buffer lung.

Beeing implemented in version 2: Add Trig inspiration on patient inhale attempt. Also easily settable expiratory phase.  The functions are provided by standard electric control blocks.

Planned for version 3: Alarm if exhale is too faint.  This detects various problems: broken tube, mask or intubation problems, far too little water in any bottle, motor or any other mechanical problem.  Also inspiratory pause is settable.  Motor is stopped/started quickly but softly to enhance ligetime, and have overload warning.  A cirquit board for all functions of version 2 & 3 is in design.

Status

We are currently documenting prototype version 2, which increases reliability and safety, enables 12V operation, and adds easily settable expiration pause, and adds trig function.

Whenever we are not enhancing it, it is operating in wear tests.

Week 17 or 18 we hope to have version 3 in some kind of working state.

You can follow development here:
https://tribun.cloud/index.php/s/mzqPWbDTTHnb4xj



Extensions

We have an Arduino PC based measuring system for flow, volume and pressure. See description pdf. But for simple operation the mechanical machine is enough by itself.

We are also working on two types of additional controllers, the one for version 2 is based on standard time realy etc, while the one for version 3 is a special cirquit board. Functions see above.

Ch(air) of any version can also work in basic operation like version 1 (no Trig, less flexible pauses, no alarm etc). In that case the latter Ch(air) versions "only" add better developed reliability and build instructions.

Controller board

The controller board may deserve a project by itself as it can be used in other mechanicals designs incorporating a similar mechanic operation: a one-direction motor pumping, and no electrical valve. 

We will share the design, see forum and development link above.

It follows the same philosophy as Ch(air): Built from the most easily accessible electronic components produced during the last decades and today, and no speciality IC, no microcontroller.  The idea is that it can be produced in most places in the world in small electronic shops.  Of course it can also be mass produced easily, and posted around the world as a building part for Ch(air) and similar machines.

It may also be partly redesinged to have ratio and BPM settings instead of timers (but that cost a few more components).  And revamped for other kinds of machines.First 
