#include "stdio.h"
#include "stdlib.h"

//types and macrodefinition
#define MAX_USERS 10
#define TRUE 1
#define FALSE 0

typedef enum RIGHTS {
	E_NO_RIGHT = 0,
	E_READ = 1,
	E_WRITE = 2,
	E_DELETE = 4,
	E_RENAME = 8,
	E_COPY = 16
}E_RIGHTS;

//global variables
unsigned char UserRights[MAX_USERS] = { 0 };

//private functions prototypes
void AddRights(unsigned char user, unsigned char rights);
void UpdateRights(unsigned char user, unsigned char rights);
unsigned char HasUserRight(unsigned char user, unsigned char rights);

//private functions implementations

void AddRights(unsigned char user, unsigned char rights) {
	if (user < MAX_USERS) {
		UserRights[user] |= rights;
	}
}
void UpdateRights(unsigned char user, unsigned char rights) {
	if (user < MAX_USERS) {
		UserRights[user] &= (~rights);
	}
}
unsigned char HasUserRight(unsigned char user, unsigned char rights) {
	unsigned char hasRights = FALSE;
	if (user < MAX_USERS) {
		if ((UserRights[user] & rights) == rights) {
			hasRights = TRUE;
		}
		else {
			//doesn't have rights; already set
		}
	}
	else {
		//already set
	}
	return hasRights;
}

int main(void) {
	//test code
	AddRights(0, E_COPY | E_DELETE);
	AddRights(1, E_COPY | E_RENAME);
	AddRights(7, E_READ | E_DELETE);
	printf("user 0 - right copy result is %d\n", HasUserRight(0, E_COPY));
	printf("user 0 - right read result is %d\n", HasUserRight(0, E_READ));
	UpdateRights(0, E_COPY);
	printf("user 0 - right copy result is %d\n", HasUserRight(0, E_COPY));
	printf("user 0 - right read result is %d\n", HasUserRight(0, E_READ));
	getchar();
}