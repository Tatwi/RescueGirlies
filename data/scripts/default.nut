/**
 * This script gets loaded into the squirrel root vm in supertux. So functions
 * and variables you define here can be used in all threads
 */

//Create Level table
Level <- {
  finish=Level_finish,
  spawn=Level_spawn,
  flip_vertically=Level_flip_vertically,
  toggle_pause=Level_toggle_pause,
  edit=Level_edit
};


// Global variables for use when info needs to across multiple sectors.
// Reset these to 0 at the end of every level that uses them!
// Note: I didn't use an array, because they don't work for all content.
glob0 <- 0;
glob1 <- 0;
glob2 <- 0;
glob3 <- 0;
glob4 <- 0;
glob5 <- 0;
glob6 <- 0;
glob7 <- 0;
glob8 <- 0;
glob9 <- 0;

function end_level()
{
  play_music("music/leveldone.ogg");
  Tux.deactivate();
  wait(6);
  Effect.fade_out(2);
  wait(2);
  Level.finish(true);
}


function bonus_level(cns)
{
	wallet <- get_coins();
	if (wallet <= 0) {
		wallet = 0;
	}
  	if (wallet >= cns){
		remove_coins <- cns * -1;
		Tux.add_coins(remove_coins);
		play_sound("sounds/lifeup.wav");
		Text.set_text(cns + " Coins have been paid to play this level.\n\n            Enjoy!");
		Text.fade_in(1);
		wait(5);
		Text.fade_out(3);
  	}
 	 else {
		Tux.deactivate();
		Text.set_text("Sorry, you don't have enough coins!\n\n" + cns + " Coins are required to play this level.");
		Text.fade_in(1);
		wait(1);
		play_sound("sounds/hurt.wav");
		wait(7);
		Effect.fade_out(3);
  		wait(3);
  		Level.finish(true);
  	}
}



function levelflip()
{
  Effect.fade_out(1);
  wait(1);
  Level.flip_vertically();
  Effect.fade_in(1);
}

function println(val)
{
	print(val);
	print("\n");
}

if(! ("state" in this))
  state <- {};

function secret_found(){
		secretinscript();
		Tux.add_coins(100);
		play_sound("sounds/lifeup.wav");
		Text.set_anchor_point(ANCHOR_MIDDLE);
		Text.set_text("You discovered a well hidden secret!");
		Text.set_font("normal");
		Text.fade_in(1.5);
		Text.fade_out(5);
}

function fwrks_show(loops){
	for (local i = 0; i <= loops; i++){
		poop(rand(5)+1);
		wait((rand(10) + 0.05) / 10 + 0.05);
	}
}