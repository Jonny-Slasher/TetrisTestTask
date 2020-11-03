#include "TestApp.h"
#include <stdlib.h>
#include<time.h>
void main()
{
	srand(time(NULL));
	TestApp app;
	app.Run();
}
