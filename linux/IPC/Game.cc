#include "MsgQue.h"
#include <thread>
#include <fstream>

const int MAX_NUM = 1000;

const int player1_key = 5000;
const int player2_key = 5001;
const int rcv1_key = 5002;
const int rcv2_key = 5003;

MsgQue player1_queue(player1_key);
MsgQue player2_queue(player2_key);
MsgQue rcv1_queue(rcv1_key);
MsgQue rcv2_queue(rcv2_key);



void player(int send_id, int rcv_id, string filename) {
	ofstream out(filename);

	if (!out.is_open()) {
		cerr << "Create file" << filename << "faild.\n";
	}

	for (int i = 0; i < MAX_NUM; i++) {
		message msg(1, rand() % 3), msg_get;
		SendMsg(send_id, msg);
		RcvMsg(rcv_id, msg_get);
		out << hands[msg.mtext] << " " << msg_get.mtext << "\n";
	}

	out.close();
}

void judger(int q1, int q2, int a1, int a2, string filename) {

	ofstream out(filename);
	if(!out.is_open()) {
		cerr << "Create file" << filename << "faild.\n";
	}

	message msg1, msg2;
	message rcv1, rcv2;

	for(int i = 0; i < MAX_NUM; i++) {
		RcvMsg(q1, msg1);
		RcvMsg(q2, msg2);
		
		if(msg1.mtext == msg2.mtext) {
			rcv1. mtext = 0;
		} else if (msg1.mtext + msg2.mtext == 2) {
			if (msg1.mtext == 0) rcv1.mtext = -1;
			else rcv1.mtext = 1;
		} else {
			if (msg1.mtext < msg2.mtext) rcv1.mtext = 1;
			else rcv1.mtext = -1;
		}
		rcv2.mtext = -rcv1.mtext;

		SendMsg(a1, rcv1);
		SendMsg(a2, rcv2);

		out << hands[msg1.mtext] << " " << hands[msg2.mtext] << " "
			<< rcv1.mtext << " " << rcv2.mtext << "\n";
	}
	out.close();
}
int main() {
	srand(time(0));

	thread p1(player, player1_queue.getID(), rcv1_queue.getID(), "player1.txt");
	thread p2(player, player2_queue.getID(), rcv2_queue.getID(), "player2.txt");
	thread p3(judger, player1_queue.getID(), player2_queue.getID(),
			rcv1_queue.getID(), rcv2_queue.getID(), "results.txt");

	p1.join();
	p2.join();
	p3.join();

	ifstream in("results.txt");
	int count1 = 0, count2 = 0;
	for (int i = 0; i < MAX_NUM; i++) {
		string temp1, temp2;
		int rcv1, rcv2;

		in >> temp1 >> temp2 >> rcv1 >> rcv2;
		if(rcv1 == 1) count1++;
		if(rcv2 == 1) count2++;
	}

	cout << "Player 1 wins " << count1 << " times.\n";
	cout << "Player 2 wins " << count2 << " times.\n";
	cout << "Draw " << MAX_NUM-count1-count2 << " times.\n";

	if (count1 == count2) {
		cout << "So it ends in a draw.\n";
	} else {
		cout << "So the winner is " << (count1 > count2 ? "Player1" : "Player 2") << endl;
	}

	return 0;
}
