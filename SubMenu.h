#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "Client.h"
#include "Pack.h"
#include "inputValidation.h"

using namespace std;

void updateClientMenu(int& option, Client client);
void updatePackMenu(int& option, Pack pack);
