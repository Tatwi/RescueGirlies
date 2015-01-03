// Each function is a moving image for the voice over story.


function events(){
	// triggers all the events
	logo();
	story(1, -50);
		wait(2);
	girlies();
		wait(4.5);
	st();
	story(2, -50);
		wait(6);
	playstorm();
		wait(12.4);
	story(3, -150);
	magic();
		wait(5.4);
	nolok();
		wait(9.8);
	marriage();
		wait(1);
	story(4, -50);
		wait(1.2);
	captux();
		wait(7.4);
	sadfaces();
		wait(4);
	story(5, -150);
		wait(1.2)
	xmas();
		wait(0.1);
	quincyjack();
		wait(3.5);
	santa();
		wait(2);
	story(6, -100);
		wait(2);
	tent();
		wait(0.1);
	weetux();
		wait(3);
}

function story(pg, y){
	if (pg == 1){
		Text.set_text("Once upon a time there were three \nbeautiful girlies. One was named \nNeillia, the other was named Baylea, \nand another was named Abby and they \nloved to lots of different things. \nOne of the things they liked to do \nthe most was play Supertux on their \ncomputer. They would play that game \nall day and all night if they were \nallowed, but they weren't allowed to \ndo that.");
	}
	if (pg == 2){
		Text.set_text("As a matter of fact, one night they\nwent to bed and they left the game\non. And while they were \nsleeping, there was thunder and \nlightning and a big electrical storm \nand the power went out, except the \ncomputer stayed on. That was pretty \nstrange, but not when you realize \nwhat happened.");
	}
	if (pg == 3){
		Text.set_text("There was magic involved, but the \nonly person who noticed that this \nmagic happened was the evil king \nNolok. He thought, \n\nI better get into my ship! That's \nwhere I can go and find magic power!\n\nSo, he did. He flew off into the \nhouse and he noticed something. Maybe \nit's something that most people \nwouldn't notice, or any person would \nnotice from our realm. He noticed \nthat two of those people had magic \npowers. They had marriage power! So \nhe decided he would kidnap them and \ntry to take their powers. He took \nthem back to his castle and took \ntheir rings of marriage power.");
	}
	if (pg == 4){
		Text.set_text("With his new found power, Nolok set \noff to destroy his arch enemy Tux. It \nwas easy for Nolok to capture Tux and \ntake him back to his castle too. So \nnow he had Tux, and the mommy, and \nthe daddy prisoner. That was very sad \nfor everyone. But it was most sad \nwhen the girlies woke up the next \nmorning and found they didn't have a \nmommy or a daddy. They looked all over\nthe house and couldn't find them.");
	}
	if (pg == 5){
		Text.set_text("They were lucky though, because\nit was Christmas time and their little\nhelper elf, Quincyjack, saw the whole thing.\n\nQuincyjack decided that it was a good \ntime to come to life and tell the \ngirlies what happened. He used his \nmagical powers to send them on a \njourney inside the game. He sent with \nthem their magical van and the wishes \nof the Christmas Kingdom. Quincyjack \nappologized to the girlies that he \ncouldn't go with them, but he had to \nreport this crazy news to Santa \nhimself.");
	}
	if (pg == 6){
		Text.set_text("With their van in tow, the girlies \njumped into their magical castle and \ndrifted off into the game. When they \nlanded they headed toward Tux's \nhouse, where they were sure they \ncould get some help from Tux's little \nboy. The girlies new it would be a \nlong hard journey to rescue their \nparents and Tux, but they new \nQuincyjack wouldn't have sent them if \nhe didn't believe they could do it.");
	}
	Text.set_pos(0, y);
	Text.fade_in(3);
}

function logo(){
	logo <- FloatingImage("images/engine/menu/logo_dev.png");
	logo.set_anchor_point(ANCHOR_TOP_LEFT);
	logo.set_pos(200, 100);
	logo.fade_in(3);
	wait(5);
	for(local i = 0; i <= 100; i++){
		logo.set_pos(200, 100 - (i * 3));
		wait(0.01);
	}
	logo <- null;
}

function girlies(){
	girls <- FloatingImage("images/stories/story-1-girlies.jpg");
	girls.set_anchor_point(ANCHOR_TOP_LEFT);
	x <- 200;
	y <- 50;
	girls.set_pos(x, y);
	girls.fade_in(1);
	for(local n = 0; n <= 40; n++){
		x++;
		y++;
		girls.set_pos(x, y);
		wait(0.01);
	}
	wait(7);
	girls.fade_out(3);
	for(local n = 0; n <= 100; n++){
		x = x + 7;
		girls.set_pos(x, y);
		wait(0.01);
	}
	girls <- null;
}

function st(){
	st <- FloatingImage("images/stories/story-1-supertux.jpg");
	st.set_anchor_point(ANCHOR_TOP_LEFT);
	x <- 0;
	y <- 600;
	st.set_pos(x, y);
	st.fade_in(0.5);
	for(local n = 0; n <= 30; n++){
		y = y - 20;
		st.set_pos(x, y);
		wait(0.01);
	}
	wait(7);
	st.fade_out(3);
	wait(3);
	st <- null;
}

function playstorm(){
	STORM.flash();
	wait(1);
	STORM.flash();
	STORM.thunder();
	wait(0.3);
	STORM.flash();
}

function magic(){
	poop(2);
	wait(0.2);
	poop(rand(10) + 5);
	wait(0.3);
	poop(rand(5) + 1);
}

function nolok(){
	nolok <- FloatingImage("images/creatures/nolok/jump-1.png");
	nolok.set_anchor_point(ANCHOR_TOP_LEFT);
	nolokship <- FloatingImage("images/tiles/doodads/villian_ship.png");
	nolokship.set_anchor_point(ANCHOR_TOP_LEFT);
	x <- 20;
	y <- 270;
	nolok.set_pos(x, y);
	nolokship.set_pos(x, y);
	nolok.fade_in(0.5);
	wait(4.2);
	nolok.fade_out(0.5);
	nolok <- null;
	nolokship.fade_in(0.5);
	wait(6.9);
	play_sound("sounds/z95engine-flyby-quiet.wav");
	for(local i = 0; i <= 60; i++){
		x = x + 20
		nolokship.set_pos(x, y);
		wait(0.01);
	}
	wait(2);
	
	nolokship <- null;
}

function marriage(){
	hearts <- FloatingImage("images/stories/hearts.sprite");
	hearts.set_anchor_point(ANCHOR_TOP_LEFT);
	rings <- FloatingImage("images/stories/ring.sprite");
	rings.set_anchor_point(ANCHOR_TOP_LEFT);
	rob <- FloatingImage("images/stories/rob.png");
	rob.set_anchor_point(ANCHOR_TOP_LEFT);
	sarah <- FloatingImage("images/stories/sarah.png");
	sarah.set_anchor_point(ANCHOR_TOP_LEFT);
	hearts.set_pos(380, 180);
	rings.set_pos(620, 0);
	sarah.set_pos(0, 250);
	rob.set_pos(600, 250);
	sarah.fade_in(2);
	rob.fade_in(2);
	wait(2);
	for (local i = 0; i <= 250; i++){
		sarah.set_pos(0 + i, 250);
		rob.set_pos(600 - i, 250);
		wait(0.01);
	}
	hearts.fade_in(0.5);
	wait(5);
	sarah.fade_out(2);
	rob.fade_out(2);
	hearts.fade_out(2);
	wait(2);
	hearts <- null;
	sarah <- null;
	rob <- null;
	rings.set_visible(true);
	rings.fade_out(2);
	for(local i = 0; i <= 200; i++){
		rings.set_pos(620, 0 + (i * 2));
		wait(0.01);
	}
	rings <- null;
}

function captux(){
	nolok <- FloatingImage("images/creatures/nolok/jump-1.png");
	nolok.set_anchor_point(ANCHOR_TOP_LEFT);
	prey <- FloatingImage("images/creatures/tux_original/run.sprite");
	prey.set_anchor_point(ANCHOR_TOP_LEFT);
	nolok.set_pos(500, 400);
	prey.set_pos(0, 480);
	prey.fade_in(1);
	
	for (local i = 0; i <= 250; i++){
		prey.set_pos(0 + (i *2), 480);
		if ( i >= 200){
			if (i == 200){nolok.set_visible(true);}
			nolok.set_pos(500, 200 + i);
		}
		wait(0.01);
	}
	prey <- null;
	play_sound("sounds/kill.wav")
	nolok.fade_out(2);
	wait(2);
	nolok <- null;
}

function sadfaces(){
	sadface1 <- FloatingImage("images/stories/sadface.png");
	sadface1.set_anchor_point(ANCHOR_TOP_LEFT);
	sadface2 <- FloatingImage("images/stories/sadface.png");
	sadface2.set_anchor_point(ANCHOR_TOP_LEFT);
	sadface1.set_visible(true);
	sadface2.set_visible(true);
	sadface1.fade_out(5.5);
	sadface2.fade_out(5.5);
	for (local i = 0; i <= 500; i++){
		sadface1.set_pos(50 + i, i);
		sadface2.set_pos(750 - i, i);
		wait(0.01);
	}
	sadface1 <- null;
	sadface2 <- null
}

function xmas(){
	img <- FloatingImage("images/stories/story-1-xmas.jpg");
	img.set_anchor_point(ANCHOR_TOP_LEFT);
	img.fade_in(2);
	wait(4);
	img.fade_out(2);
	wait(2);
	img <- null;
}

function quincyjack(){
	img <- FloatingImage("images/stories/story-1-quincyjack.jpg");
	img.set_anchor_point(ANCHOR_TOP_LEFT);
	img.fade_in(3);
	wait(14);
	img.fade_out(4);
	wait(4);
	img <- null;
}

function santa(){
	saintnick.goto_node(1);
	play_sound("sounds/jingle-bells.ogg");
}

function tent(){
	img <- FloatingImage("images/engine/menu/girlies.png");
	img.set_anchor_point(ANCHOR_TOP_LEFT);
	img.set_pos(100, 20);
	img.fade_in(2);
	for (local i = 0; i <= 400; i++){
		img.set_pos(100 + (i * 0.5), 20 + i);
		if (i == 200){
			img.fade_out(2);
		}
		wait(0.01);
	}
	img <- null;
}

function weetux(){
	img <- FloatingImage("images/stories/story-1-weetux.jpg");
	img.set_anchor_point(ANCHOR_TOP_LEFT);
	img.set_pos(200, 300);
	img.fade_in(1);
	wait(3);
	img.fade_out(5);
	for (local i = 0; i <= 500; i++){
		img.set_pos(200, 300 + i);
		wait(0.01);
	}
	img <- null;
}
