
void Game::Start(void)
{
  if(_gameState != Uninitialized)
    return;

  _mainWindow.Create(sf::VideoMode(1024,768,32),"Hacker");

  _gameState = Game::ShowingSplash;

  while(!IsExiting())
  {
    GameLoop();
  }

  _mainWindow.Close();
}


bool Game::IsExiting()
{
  if(_gameState == Game::Exiting)
    return true;
  else
    return false;
}


void Game::GameLoop()
{
    switch(_gameState)
    {
        case Game::ShowingMenu:
        {
            ShowMenu();
            break;
        }
        case Game::ShowingSplash:
        {
            ShowSplashScreen();
            break;
        }
        case Game::Playing:
        {
            sf::Event currentEvent;
            while(_mainWindow.GetEvent(currentEvent))
            {
                _mainWindow.Clear(sf::Color(sf::Color(0,0,0)));
                _mainWindow.Display();

                if(currentEvent.Type == sf::Event::Closed) _gameState =
                                                            Game::Exiting;

                if(currentEvent.Type == sf::Event::KeyPressed)
                {
                    if(currentEvent.Key.Code == sf::Key::Escape) ShowMenu();
                }
            }
            break;
        }
    }
}

void Game::ShowSplashScreen()
{
    SplashScreen splashScreen;
    splashScreen.Show(_mainWindow);
    _gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
    MainMenu mainMenu;
    MainMenu::MenuReult result = mainMenu.Show(_mainWindow);
    switch(result)
    {
        case MainMenu::Exit:
            _gameState = Game::Exiting;
            break;
        case MainMenu::Play:
            _gameState = Game::Playing;
            break;
    }
}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
