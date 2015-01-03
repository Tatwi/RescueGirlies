//  SuperTux
//  Copyright (C) 2009 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "supertux/menu/main_menu.hpp"

#include "audio/sound_manager.hpp"
#include "gui/menu_manager.hpp"
#include "supertux/fadeout.hpp"
#include "supertux/globals.hpp"
#include "supertux/menu/menu_storage.hpp"
#include "supertux/menu/addon_menu.hpp"
#include "supertux/menu/options_menu.hpp"
#include "supertux/menu/contrib_menu.hpp"
#include "supertux/screen_manager.hpp"
#include "supertux/textscroller.hpp"
#include "supertux/title_screen.hpp"
#include "supertux/world.hpp"
#include "util/gettext.hpp"
#include "util/string_util.hpp"
#include "video/renderer.hpp"
#include "supertux/menu/profile_menu.hpp"


#include "supertux/menu/profile_menu.hpp"

#include <sstream>

#include "gui/menu_manager.hpp"
#include "gui/menu_item.hpp"
#include "supertux/gameconfig.hpp"
#include "supertux/globals.hpp"
#include "util/gettext.hpp"

#include <string>
using std::string;
//string selectedPlayer("blah");

MainMenu::MainMenu() :
  m_main_world()
{
	
	set_pos(SCREEN_WIDTH/2, SCREEN_HEIGHT/2 - 35);
	add_label(_("Select Profile"));
	add_hl();
	
	std::ostringstream nee;
	nee << "Neillia";
	add_entry(MNID_STARTGAME, nee.str());
	
	std::ostringstream baylea;
	baylea << "Baylea";
	add_entry(MNID_STARTGAME2, baylea.str());
	
	std::ostringstream abby;
	abby << "Abby";
	add_entry(MNID_STARTGAME3, abby.str());
	
	std::ostringstream guestAcc;
	guestAcc << "Guest";
	add_entry(MNID_STARTGAME4, guestAcc.str());
	
	add_hl();
	add_entry(MNID_CREDITS, _("Credits"));
	add_entry(MNID_QUITMAINMENU, _("Quit"));
}

void
MainMenu::check_menu()
{
  switch (check())
  {
    case MNID_STARTGAME:
	    g_config->profile = 1;
      if (m_main_world.get() == NULL)
      {
        m_main_world.reset(new World());
        m_main_world->load("levels/world1/info");
      }
      TitleScreen::start_game(m_main_world.get());
      break;
      
     case MNID_STARTGAME2:
	    g_config->profile = 2;
      if (m_main_world.get() == NULL)
      {
        m_main_world.reset(new World());
        m_main_world->load("levels/world1/info");
      }
      TitleScreen::start_game(m_main_world.get());
      break;
      
     case MNID_STARTGAME3:
	    g_config->profile = 3;
      if (m_main_world.get() == NULL)
      {
        m_main_world.reset(new World());
        m_main_world->load("levels/world1/info");
      }
      TitleScreen::start_game(m_main_world.get());
      break;
      
      case MNID_STARTGAME4:
	    g_config->profile = 4;
      if (m_main_world.get() == NULL)
      {
        m_main_world.reset(new World());
        m_main_world->load("levels/world1/info");
      }
      TitleScreen::start_game(m_main_world.get());
      break;
      
      case MNID_CREDITS:
      MenuManager::set_current(NULL);
      g_screen_manager->push_screen(new TextScroller("credits.txt"),
	new FadeOut(0.5));
      break;


    case MNID_QUITMAINMENU:
      g_screen_manager->quit(new FadeOut(0.25));
      sound_manager->stop_music(0.25);
      break;
  }
}



/* EOF */
