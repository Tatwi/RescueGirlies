# Rescue Girlies

Final Version: April 28, 2014  

**To play using Devuan 3, Debian 10, Ubuntu 20.04**  
The game won't compile with new versions of GCC at this time, but the included binary, rescuegirlies-64bit, will run if you take the following steps:  

1. Open a terminal.  
2. Install SuperTux2 to for its dependancies.  
- sudo apt-get install supertux
3. Make a symbolic link to libGLEW that will work with the Rescue Giriles binary. 
- cd /usr/lib/x86_64-linux-gnu
- sudo ln -s libGLEW.so.2.1.0 libGLEW.so.1.10  
4. Download this repository and double click the rescuegirlies-64bit icon.   

## DESCRIPTION
Rescue Girlies is a fork of the SuperTux jump'n'run game. I made RG as a Christmas gift for my children. Run, jump and think your way through the campaign to save your loved ones. Make new friends, eat some cupcakes, and squish many badguys along the way!  

- 3 Story Scenes (One long, two short).  
- 9 Heavily Customized, RPG Side-Scroller Style, Story Based Levels.  
- 21 Bonus Levels.  
- 2 Hidden Levels.  
- Tons of Secrets.  
- Bajillions of Coins to Collect.  
- New Abilities, Enemies, Locations, and Stuff to Spend Your Coins On.  
- Custom graphics, sounds, and voice overs.  

*RESCUE GIRLIES IS NOT COMPATIBLE WITH ANY VERSION OF SUPERTUX.*  

RG has custom c++, scripting, and tilemaps, so the levels are not directly iterchangable, at all. However, many Supertux levels will work with RG, as seen in the (somewhat modified versions of) bonus levels taken directly from Supertux.

The version you are playing is not entirely the same as the one my kids play, due to this version being GPL compliant. Differences between my private version and the GPL version:

- Music choices.
- Non-free ambient sounds and other sound effects.
- Pictures of my family were replaced with generic pictures.
- Voice & Graphical cameo apperances by celebrities my kids enjoy
 were replaced (with my "voice acting" and "art", sorry) or removed.
 
That's it. While I do believe these things in the private version really give the game a sense of sole or heart, I did my best to convey the same feeling in the GPL version. Replacing the sounds proved to be far more difficult than I had imaged, which is why I was not able to release it at Christmas time. 

## STORY
Nolok Takes More Power!  

The evil king, Nolok, captures the mother and father of a family and uses their rings of marriage power to finally capture his arch rival, Tux. The three daughters set off on a magical journey to reunite their family and rescue their captured hero. 

## DOCUMENTATION
Important documentation for SuperTux is contained in multiple files. Please see them:

- **README:** (This file.)Game story, usage, rules and controls.
- **COPYING:** The GNU General Public License, under whose terms SuperTux is licensed. (Most of the data subdirectory is also licensed under CC-by-SA)
- **data/credits.txt:** Credits for people that contributed to the creation of Rescue Girlies and SuperTux. (You can view these in the game menu as well.)
- **tools/supertux-docs:** documentation that came with the 0.3.3 SVN verison of Supertux that Rescue Girlies is based upon.
- **tools/wiki:** Customized plain text copies of the Supertux wiki that I made based upon my time working with the game engine and editor.


RUNNING THE GAME
----------------
NOTE: This game was designed to be run in an 800x600 window. Resizing the window or playing full screen is possible, but it *WILL* ruin the looks of the three story cut scenes. I did this, because my kids only play at that resolution and this game was made for them. :)

*System Requirements:*  

- GNU/Linux 32bit or 64bit Distribution
- OpenGL compliant Accelerated Graphics Processor (Nvidia / AMD/Ati / Intel)

*Recomended:*

- CPU: Intel Core2 Quad / AMD Phenom II X4 or better
- RAM: 2GB DDR2
- VIDEO: Nvidia GeForce 8600GT / AMD Radeon HD5670 or better
- Operating System: Mint 17.3, Debian 7, Ubuntu 12.04/14.04

Minimum:

- CPU: 1.8GHz Dual Core AMD or Intel
- RAM: 1GB RAM
- Video: Nvidia GeForce 6200 / AMD Radeon HD2000 / Intel HD Graphics 4000 (Ivy Bridge)
- Operating System: Lubuntu 11.04 (oldest thing I've tried that compiles/runs RG).

**December 2018 Information Update:**  
The best way to play the game is to use Linux Mint 17.3 or Ubuntu 12.04. Install one of those OS's in VirtualBox or on a spare drive/partition/usb stick/etc, then install SuperTux (to install the dependencies for both games) using:  

sudo apt-get install supertux

Then download and extract Rescue Girlies from GitHub, right click either the rescuegirlies-32bit or rescuegirlies-64bit file and set it as executable, then it can be double clicked to run the game. Works great and isn't too hard. 

Sadly, newer versions of Linux use symlinks for libGLEW that prevent the included compiled files
from running and the newer versions of GCC aren't compatible with the syntax used in Supertux 0.3.3 / Rescue Girlies. That's fine, because older versions of Linux are both available and free! As such, I don't feel overly compelled to update the game, given how I am busy with other projects.

Options and profiles are saved in ~/.rescuegirlies. They will need to be edited manually, unlike Supertux. I did this explicitly because my kids were *ALWAYS* messing up the options in Supertux through the in game menu (especially the language), so I removed them to avoid that possibility. Saved me some sanity, so hopefully it will help you too! :)


## PLAYING THE GAME
**Controls**  
Both keyboards and joysticks/gamepads are supported. You can change the controls via the configuration file. 

**Actions & Abilities:**  
Run, duck, crawl (move while ducking), jump, backflip, pick up objects, duck and pick up an object in front and below you, throw objects (bombs and blocks), and butt-jump (land hard on boxes/enemies to break them).

**Powerups:**  

- **Clothing Chest:** Change your outfit. Now you can backflip, butt-jump, and take 1 hit from an enemy without dying.
- **Cupcake Flower:** Throw cupcakes at the enemy to kill them. Same as fire flower in Supertux and Super Mario Bros.	
- **Snowman:* Thow snow balls at enemies to freeze them. Can be unfrozen with cupcakes. While frozen, enemies are completely inert. Frozen bombs cannot be thrown, but can be carried, dropped, and stomped	upon to make them explode.
- **Invicible:** Makes you invicible to enemies for a short time. However, some spikes will kill you anyway, else the game would be very, very boring.  

The **Esc key** is used to access the menu. In the menu you are able to purchase any of the above Powerups by spending the coins you have collected. The menu can be navigated using the arrow keys or the mouse.  

There is also a special surprise waiting to be discovered that you will use in two different levels. Well, that is if you didn't already read about it on the Internet. :)  

In the worldmap, the arrow keys are used to navigate and the Enter key is pressed to begin playing a level.  

**Cheating:**  
Do it if it makes you happy - this is an open source, single player game. See the config and profile files (noted above) for some pretty self explanatory details. For instance, if you want to skip the long winded intro sequence, load up the game to the world map, exit the game, and then edit the world config file in your profile folder so that completed is true rather than false.

## DEVELOPMENT STATUS
Rescue Girlies was a "one off" game that was created for a single, one time purpose. There will not be any further development of this game by its creator, me, R. Bassett Jr. That said, you are able to play it / mod it, because I wanted to give back to the open source community that made this gift to my children possible. You're free to take what I've done with Rescue Girlies and use parts or all of it for your own purposes, be that learning or creating your own game. 

## THE END
Thank you for trying Rescue Girlies. If you have any questions or comments, please feel free to contact me.  

Sincerely,  
  
R. Bassett Jr. (Tatwi)  
