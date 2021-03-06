#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{

    //Load menu images from file
    sf::image image;
    image.LoadFromFile("images/mainmenu.png");
    sf::Sprite sprite(image);

    //Setup clickable regions

    //Play menu item coordinates
    MenuItem playButton;
    playButton.rect.Top = 145;
    playButton.rect.Bottom = 380;
    playButton.rect.Left = 0;
    playButton.rect.Right = 1023;
    playButton.action = Play;

    //Exit menu item coordinates
    MenuItem exitButton;
    exitButton.rect.Left = 0;
    exitButton.rect.Right = 1023;
    exitButton.rect.Top = 383;
    exitButton.rect.Bottom = 560;
    exitButton.action = Exit;

    _menuItem.push_back(playButton);
    _menuItem.push_back(exitButton);

    window.Draw(sprite);
    window.Display();

    return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
    std::list<MenuItem>::iterator it;

    for ( it = _menuItem.begin(); it != _menuItem.end(); it++)
    {
        sf::Rect<int> menuItemRect = (*it).rect;
        if( menuItemRect.Bottom > y
            && menuItemRect.Top < y
            && menuItemRect.Left < x
            && menuItemRect.Right > x)
        {
            return (*it).action;
        }
    }
    return Nothing;
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow&window)
{

    sf::Event menuEvent;

    while(true)
    {

        while(window.GetEvent(menuEvent))
        {
            if(menuEvent.Type = sf::Event::MouseButtonPressed)
            {
                return HandleClick(menuEvent.MouseButton.X,menuEvent.MouseButton.Y);
            }
            if(menuEvent.Type == sf::Event::Closed)
            {
                return Exit;
            }
        }
    }
}
