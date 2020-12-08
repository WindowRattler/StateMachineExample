//BenjaminKramer
//12-7-2020

//An illustration of a State Machine
//demonstrating how a Security System
//would enact different alarms/alerts
#include <iostream>

using namespace std;

class SecurityAlert;
class AlertStateContext;
class Armed;
class Bell;
class Disarmed;

//SecurityAlert class, initializing
//the State Machine
class SecurityAlert {
public:
	virtual void alert(AlertStateContext *ctx) = 0;
	virtual void alertType() = 0;

  virtual ~SecurityAlert() {}
};
//An Armed state for the Security System
class Armed : public SecurityAlert {
public:
	void alert(AlertStateContext *ctx) {
		cout << "\tch-click...\n";
	}
	void alertType() {
		cout << "\nAlarm System: ARMED\n\n";
	}
};
//A Doorbell State for the Security System
class Bell : public SecurityAlert {
public:
	void alert(AlertStateContext *ctx) {
		cout << "\tdiiinnngg-doongg-goooonnnggg...\n";
	}
	void alertType() {
		cout << "\nSomeone's At The Door\n\n";
	}
};
//A Disarmed state for the Security System
class Disarmed : public SecurityAlert {
public:
	void alert(AlertStateContext *ctx) {
		cout << "\tcl-shick......\n";
	}
	void alertType() {
		cout << "\nAlarm System: DISARMED\n\n";
	}
};
//AlertStateContext to enact the different
//states whenever their methods are called
class AlertStateContext {
private:
	SecurityAlert *currentState;

public:
	AlertStateContext(SecurityAlert *state) {
		currentState = state;
	}

	void setState(SecurityAlert *state) {
		currentState = state;
	}

	SecurityAlert *getState() {
		return currentState;
	}

	void alert() {
		currentState->alert(this);
	}

};
//main
int main() {
  std::cout << "\nSecurity System: ACTIVATED\n" << std::endl;
  SecurityAlert* armed = new Armed;
	AlertStateContext *stateContext = new AlertStateContext(armed);
	stateContext->getState()->alertType();
	stateContext->alert();
  SecurityAlert* bell = new Bell;
  stateContext->setState(bell);
	stateContext->getState()->alertType();
	stateContext->alert();
	stateContext->alert();
	stateContext->alert();
  stateContext->setState(bell);
	stateContext->getState()->alertType();
	stateContext->alert();
	stateContext->alert();
	stateContext->alert();
  delete armed;
  SecurityAlert* disarmed = new Disarmed;
	stateContext->setState(disarmed);
	stateContext->getState()->alertType();
	stateContext->alert();
  delete disarmed;
  delete bell;
  std::cout << "\n\nSecurity System: DEACTIVATED\n" << std::endl;
  std::cout << "\nClosing Portal\n" << std::endl;
}
