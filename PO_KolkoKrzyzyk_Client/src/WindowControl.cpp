//MASZYNA STANOW KTORA PRZELACZA OKNA I REAGUJE NA PRZYCISKI
//WYSTAWIANA PRZEZ QMLA - QML MA MOZLIWOSC DOSTANIA SIE DO SYGNALOW ORAZ SLOTOW

#include "include/WindowControl.h"

//konstruktor klasy WindowControl, kt�ra dziedziczy po klasie QObject
WindowControl::WindowControl(QObject* parent) : QObject(parent)
{
	_errInfo = "";

	//state machine object
	_windowView = new QStateMachine();

	//state objects
	//definicje obiektow stanow dla maszyny stanow programu
	_startView = new QState();
	_connectToServer = new QState();			// Tworzenie nowego obiektu stanu dla po��czenia z serwerem
	_loginView = new QState();
	_login = new QState();
	_logout = new QState();
	_newAccountView = new QState();
	_createAccount = new QState();
	_homeView = new QState();
	_startMatchmaking = new QState();
	_stopMatchmaking = new QState();
	_matchmakingView = new QState();
	_startGame = new QState();
	_endGame = new QState();
	_gameView = new QState();
	_endgameView = new QState();
	_exit = new QFinalState();

	//add names
	//ustawienie nazw obiektow w maszynie stanow programu
	_startView->setObjectName("startView");
	_connectToServer->setObjectName("connectToServer");
	_loginView->setObjectName("loginView");
	_login->setObjectName("login");
	_logout->setObjectName("logout");
	_newAccountView->setObjectName("newAccount");
	_createAccount->setObjectName("createAccount");
	_homeView->setObjectName("homeView");
	_startMatchmaking->setObjectName("startMatchmaking");
	_stopMatchmaking->setObjectName("stopMatchmaking");
	_matchmakingView->setObjectName("_matchmakingView");
	_startGame->setObjectName("startGame");
	_endGame->setObjectName("endGame");
	_gameView->setObjectName("gameView");
	_endgameView->setObjectName("endgameView");
	_exit->setObjectName("exit");

	//adding states to machine
	//dodanie stanow do maszyny
	_windowView->addState(_startView);
	_windowView->addState(_connectToServer);
	_windowView->addState(_loginView);
	_windowView->addState(_login);
	_windowView->addState(_logout);
	_windowView->addState(_newAccountView);
	_windowView->addState(_createAccount);
	_windowView->addState(_homeView);
	_windowView->addState(_startMatchmaking);
	_windowView->addState(_stopMatchmaking);
	_windowView->addState(_matchmakingView);
	_windowView->addState(_startGame);
	_windowView->addState(_endGame);
	_windowView->addState(_gameView);
	_windowView->addState(_endgameView);
	_windowView->addState(_exit);

	//initial state
	_windowView->setInitialState(_startView);


	//transitions
	//przejscia miedzy stanami w maszynie stanow
	//this - wskazanie na instancje windowcontrol
	_startView->addTransition(this, &WindowControl::welcomeButtonClicked, _connectToServer);			//button enter the game
	_connectToServer->addTransition(this, &WindowControl::connectionOk, _loginView);					//signal connected to server
	_connectToServer->addTransition(this, &WindowControl::connectionNotOk, _startView);				    //signal connection failed
	_loginView->addTransition(this, &WindowControl::newAccountButtonClicked, _newAccountView);		    //button for new account
	_newAccountView->addTransition(this, &WindowControl::goToLoginButtonClicked, _loginView);			//button go back to login view
	_newAccountView->addTransition(this, &WindowControl::createNewAccountButtonClicked, _createAccount);//button create new account
	_createAccount->addTransition(this, &WindowControl::accountCreated, _loginView);					//signal account created
	_createAccount->addTransition(this, &WindowControl::accountNotCreated, _newAccountView);			//signal account creation error
	_loginView->addTransition(this, &WindowControl::logInButtonClicked, _login);						//button login
	_login->addTransition(this, &WindowControl::loginOk, _homeView);									//signal login successful
	_login->addTransition(this, &WindowControl::loginNotOk, _loginView);								//signal login failed
	_homeView->addTransition(this, &WindowControl::logOutButtonClicked, _logout);						//button logout
	_logout->addTransition(this, &WindowControl::logoutOk, _startView);								    //signal logout successful
	_homeView->addTransition(this, &WindowControl::exitButtonClicked, _exit);							//exit app
	_homeView->addTransition(this, &WindowControl::playButtonClicked, _startMatchmaking);				//button  start matchmaking
	_startMatchmaking->addTransition(this, &WindowControl::matchmakingNotOk, _homeView);				//signal error joining to matchmaking queue
	_startMatchmaking->addTransition(this, &WindowControl::matchmakingOk, _matchmakingView);			//signal palyer in matchmaking queue
	_matchmakingView->addTransition(this, &WindowControl::exitMatchmakingButtonClicked, _stopMatchmaking);	//button exit matchmaking queue
	_stopMatchmaking->addTransition(this, &WindowControl::exitMatchmakingOk, _homeView);				//signal player removed from queue
	_stopMatchmaking->addTransition(this, &WindowControl::exitMatchmakingNotOk, _matchmakingView);		//signal player not removed
	_matchmakingView->addTransition(this, &WindowControl::gameReady, _startGame);						//signal game found
	_startGame->addTransition(this, &WindowControl::gameStarted, _gameView);							//signal game started
	_gameView->addTransition(this, &WindowControl::gameEnd, _endGame);									//signal game is finished
	_gameView->addTransition(this, &WindowControl::gameLeaveButtonClicked, _endGame);					//button exit game before end
	_endGame->addTransition(this, &WindowControl::playAgainButtonClicked, _startMatchmaking);			//button start another game
	_endGame->addTransition(this, &WindowControl::goToMenuButtonClicked, _startMatchmaking);			//button go to menu

	//entered signals
	//tworzenie po��czenia pomi�dzy sygna�em entered emitowanym przez "startView" a slotem "inStartView" w lkasie WindowControl
	QObject::connect(_startView, &QState::entered, this, &WindowControl::inStartView);
	QObject::connect(_connectToServer, &QState::entered, this, &WindowControl::inConnectToServer);
	QObject::connect(_loginView, &QState::entered, this, &WindowControl::inLoginView);
	QObject::connect(_login, &QState::entered, this, &WindowControl::inLogin);
	QObject::connect(_logout, &QState::entered, this, &WindowControl::inLogout);
	QObject::connect(_newAccountView, &QState::entered, this, &WindowControl::inNewAccountView);
	QObject::connect(_createAccount, &QState::entered, this, &WindowControl::inCreateAccount);
	QObject::connect(_homeView, &QState::entered, this, &WindowControl::inHomeView);
	QObject::connect(_startMatchmaking, &QState::entered, this, &WindowControl::inStartMatchmaking);
	QObject::connect(_stopMatchmaking, &QState::entered, this, &WindowControl::inStopMatchmaking);
	QObject::connect(_matchmakingView, &QState::entered, this, &WindowControl::inMatchmakingView);
	QObject::connect(_startGame, &QState::entered, this, &WindowControl::inStartGame);
	QObject::connect(_endGame, &QState::entered, this, &WindowControl::inEndGame);
	QObject::connect(_gameView, &QState::entered, this, &WindowControl::inGameView);
	QObject::connect(_endgameView, &QState::entered, this, &WindowControl::inEndGameView);

	//tmp signals
	//sygnaly testowe do sprawdzenia poprawnosci dzialania programu - wywoluja funkcje stateinfo do sprawdzenia w ktorym stanie jestesmy
	QObject::connect(_startView, &QState::entered, this, &WindowControl::stateInfo);
	QObject::connect(_connectToServer, &QState::entered, this, &WindowControl::stateInfo);
	QObject::connect(_loginView, &QState::entered, this, &WindowControl::stateInfo);
	QObject::connect(_login, &QState::entered, this, &WindowControl::stateInfo);
	QObject::connect(_logout, &QState::entered, this, &WindowControl::stateInfo);
	QObject::connect(_newAccountView, &QState::entered, this, &WindowControl::stateInfo);
	QObject::connect(_createAccount, &QState::entered, this, &WindowControl::stateInfo);
	QObject::connect(_homeView, &QState::entered, this, &WindowControl::stateInfo);
	QObject::connect(_startMatchmaking, &QState::entered, this, &WindowControl::stateInfo);
	QObject::connect(_stopMatchmaking, &QState::entered, this, &WindowControl::stateInfo);
	QObject::connect(_matchmakingView, &QState::entered, this, &WindowControl::stateInfo);
	QObject::connect(_startGame, &QState::entered, this, &WindowControl::stateInfo);
	QObject::connect(_endGame, &QState::entered, this, &WindowControl::stateInfo);
	QObject::connect(_gameView, &QState::entered, this, &WindowControl::stateInfo);
	QObject::connect(_endgameView, &QState::entered, this, &WindowControl::stateInfo);
	QObject::connect(_windowView, &QState::finished, this, &WindowControl::inExit);

	//wywo�anie metody start na obiekcie windowView
	_windowView->start();
}


//usuwanie obiektow np startView przy nastepnej petli (za pomoca deleteLater)
//zapewnia, �e maszyna stan�w zostanie usuni�ta po przetworzeniu wszystkich bie��cych zdarze�
WindowControl::~WindowControl()
{
	_startView->deleteLater();
	_connectToServer->deleteLater();
	_loginView->deleteLater();
	_login->deleteLater();
	_logout->deleteLater();
	_newAccountView->deleteLater();
	_createAccount->deleteLater();
	_homeView->deleteLater();
	_startMatchmaking->deleteLater();
	_stopMatchmaking->deleteLater();
	_matchmakingView->deleteLater();
	_startGame->deleteLater();
	_endGame->deleteLater();
	_gameView->deleteLater();
	_endgameView->deleteLater();
	_exit->deleteLater();

	_windowView->deleteLater();
}



//GAME ERROR INFO

//Q_PROPERTY - errInfo
//metoda zwracaj�ca bie��c� warto�� prywatnego pola _errInfo
QString WindowControl::getErrInfo()
{
	return _errInfo;
}

void WindowControl::setErrInfo(const QString& newErrInfo)  // Metoda ktora ustawia nowa wartosc zmiennej errinfo
{
	_errInfo = newErrInfo;
	emit errInfoChanged();								   // Informuje wszystkie po��czone sloty o zmianie warto�ci w�a�ciwo�ci errInfo
}




//POPUP MESSAGE

//Q_PROPERTY - popupMessage
QString WindowControl::getPopupMessage()			    // Metoda zwracaj�ca aktualn� wiadomo�� wy�wietlan� w oknie popup
{
	return _popupMessage;								// Zwracanie warto�ci aktualnej wiadomo�ci do wy�wietlenia w oknie popup	
}

// Metoda ustawiaj�ca now� wiadomo�� do wy�wietlenia w oknie popup
void WindowControl::setPopupMessage(const QString& popupMessage)
{
	_popupMessage = popupMessage;						// Ustawienie nowej wiadomo�ci do wy�wietlenia w oknie popup
	emit popupMessageChanged();
}




//RANKING GRACZY

//Q_PROPERTY - playerRanking - pobranie aktualnego rankingu graczy
QJsonArray WindowControl::getPlayerRanking()
{
	return _playerRanking;											// Zwraca warto�� aktualnego rankingu graczy
}

// Aktualizuje ranking graczy na podstawie nowych danych
void WindowControl::updatePlayerRanking(const QJsonArray& data)
{
	setPlayerRanking(data);											// Wywo�anie metody setPlayerRanking(), aby zaktualizowa� ranking graczy
}

// Ustawienie nowej listy rankingowej graczy
void WindowControl::setPlayerRanking(const QJsonArray& list)
{
	_playerRanking = list;											// Przypisanie nowej listy rankingowej graczy do zmiennej _playerRanking
	emit playerRankingChanged();									// Emitowanie sygna�u playerRankingChanged(), informuj�c o zmianie rankingu graczy
}



//debug
void WindowControl::stateInfo()
{
	QState* state = qobject_cast<QState*>(sender());	    // Pobranie wska�nika do stanu, kt�ry wyemitowa� sygna�      
	QString stateName = state->objectName();                // Pobranie nazwy stanu
	if (state) {										    // Sprawdzenie, czy wska�nik na stan nie jest null
		qDebug() << "Entered state:" << stateName;          // Je�li wska�nik na stan nie jest null, wypisz nazw� stanu
	}
}