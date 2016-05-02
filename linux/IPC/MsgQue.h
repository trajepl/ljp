#ifndef _MSG_QUE_
#define _MSG_QUE_

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

using namespace std;

enum hand {
	stone = 0, scissor =1, cloth = 2
};

vector<string> hands{"stone", "scissor", "cloth"};

struct message {
	long mtype;
	int mtext;

	message(long t=1, int d=-2): mtype(t), mtext(d) {}
};

class MsgQue {
	public:
		MsgQue(int k): key(k), id(-1) {
			id = msgget(key, 0600 | IPC_CREAT);
			// cout  << id << endl;
			if (id == -1) {
				cerr << "MsgGet error.\n";
			}
		}

		~MsgQue() {
			msgctl(id, IPC_RMID, 0);
		}
		
		int getID() {return id;}

	private:
		int key, id;
};

void SendMsg(int id, message &msg) {
	// cout  << "Send " << id << endl;
	if (msgsnd(id, &msg, sizeof(int), 0) == -1)
		cerr << "MsgSnd error.\n";
}

void RcvMsg(int id, message &msg) {
	// cout  << "Recive " << id << endl;
	if (msgrcv(id, &msg, sizeof(int), 0, 0) == -1) {
		cerr << "MsgRcv error.\n";
	}
}

#endif
