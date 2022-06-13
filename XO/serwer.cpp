// Server side C/C++ program to demonstrate Socket
// programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include<list>
#include<vector>
#include<iostream>
using namespace std;
#define PORT 8080


void show(char* XO) {

	for (int i = 0; i < 9; i++) {
		if (i % 3 == 0) cout << "\n\n";//<< "------"<<endl;
		cout << i << "\t";
	}
	cout << "\n\n";

	for (int i = 0; i < 9; i++) {
		if (i % 3 == 0) cout << "\n\n";//<< "------"<<endl;
		cout << (char)XO[i] << "\t";
	}
}

bool no_winer(char* XO) {
	for (int i = 0; i < 9; i++) {
		if (XO[i] == '0')
			return false;
	}
	return true;
}

// 0 1 2 
// 3 4 5 
// 6 7 8 
// sprawdzanie kto wygral
bool check(char* XO) {
	// poziomo gora
	if (XO[0] == XO[1] && XO[1] == XO[2]) {
		if (XO[0] != '0' && XO[1] != '0' && XO[2] != '0') {
			show(&XO[0]);
			cout << "\n" << (char)XO[0] << " Winned the game(1)!";
			return true;
		}
	}
	// poziomo srodek
	if (XO[3] == XO[4] && XO[1] == XO[5]) {
		if (XO[3] != '0' && XO[4] != '0' && XO[5] != '0') {
			show(&XO[0]);
			cout << "\n" << (char)XO[3] << " Winned the game!(2)";
			return true;
		}
	}
	// poziomo dol
	if (XO[6] == XO[7] && XO[7] == XO[8]) {
		if (XO[6] != '0' && XO[7] != '0' && XO[8] != '0') {
			show(&XO[0]);
			cout << "\n" << (char)XO[6] << " Winned the game!(3)";
			return true;
		}
	}
	// skos od lewej 
	if (XO[0] == XO[4] && XO[4] == XO[8]) {
		if (XO[0] != '0' && XO[4] != '0' && XO[8] != '0') {
			show(&XO[0]);
			cout << "\n" << (char)XO[0] << " Winned the game!(4)";
			return true;
		}
	}
	// skos od prawej
	if (XO[2] == XO[4] && XO[4] == XO[6]) {
		if (XO[2] != '0' && XO[4] != '0' && XO[6] != '0') {
			show(&XO[0]);
			cout << "\n" << (char)XO[2] << " Winned the game!(5)";
			return true;
		}
	}
	// skos pion 1 
	if (XO[0] == XO[3] && XO[3] == XO[6]) {
		if (XO[0] != '0' && XO[3] != '0' && XO[6] != '0') {
			show(&XO[0]);
			cout << "\n" << (char)XO[0] << " Winned the game!(6)";
			return true;
		}
	}
	// skos pion 2
	if (XO[1] == XO[4] && XO[4] == XO[7]) {
		if (XO[1] != '0' && XO[4] != '0' && XO[7] != '0') {
			show(&XO[0]);
			cout << "\n" << (char)XO[1] << " Winned the game!(7)";
			return true;
		}
	}
	// skos pion 2
	if (XO[2] == XO[5] && XO[5] == XO[8]) {
		if (XO[2] != '0' && XO[5] != '0' && XO[8] != '0') {
			show(&XO[0]);
			cout << "\n" << (char)XO[2] << " Winned the game!(8)";
			return true;
		}
	}
	if (no_winer(&XO[0])) {
		show(&XO[0]);
		cout << "\n" << " No one winned the game!";
		return true;
	}
	return false;
}

char switcher(char player) {
	if (player == 'X') return 'Y';
	if (player == 'Y') return 'X';
	else { cout << "\n switcher: blad!\n"; return 'S'; }
}

// sprawdzenie poprawnosci danych dla pojedynczych przypadkow
void check_test() {
	char XO[9];
	XO[0] = 'X'; XO[1] = '0'; XO[2] = '0';
	XO[3] = 'X'; XO[4] = '0'; XO[5] = '0';
	XO[6] = 'X'; XO[7] = '0'; XO[8] = '0';
	show(&XO[0]);
	check(&XO[0]);
	XO[0] = '0'; XO[1] = 'X'; XO[2] = '0';
	XO[3] = '0'; XO[4] = 'X'; XO[5] = '0';
	XO[6] = '0'; XO[7] = 'X'; XO[8] = '0';
	show(&XO[0]);
	check(&XO[0]);
	XO[0] = '0'; XO[1] = '0'; XO[2] = 'X';
	XO[3] = '0'; XO[4] = '0'; XO[5] = 'X';
	XO[6] = '0'; XO[7] = '0'; XO[8] = 'X';
	show(&XO[0]);
	check(&XO[0]);
	XO[0] = 'X'; XO[1] = '0'; XO[2] = '0';
	XO[3] = '0'; XO[4] = 'X'; XO[5] = '0';
	XO[6] = '0'; XO[7] = '0'; XO[8] = 'X';
	show(&XO[0]);
	check(&XO[0]);
	XO[0] = 'X'; XO[1] = 'Y'; XO[2] = 'Y';
	XO[3] = 'Y'; XO[4] = 'X'; XO[5] = 'X';
	XO[6] = 'X'; XO[7] = 'Y'; XO[8] = 'Y';
	show(&XO[0]);
	check(&XO[0]);
}


void game() {
	//check_test();
	//return 0;

	char XO[9];
	for (int i = 0; i < 9; i++)
		XO[i] = '0';
	XO[0] = '0'; XO[1] = '0'; XO[2] = '0';
	XO[3] = '0'; XO[4] = '0'; XO[5] = '0';
	XO[6] = '0'; XO[7] = '0'; XO[8] = '0';

	show(&XO[0]);

	char player;
	player = 'X';

	cout << endl;

	// logika gry
	while (!(check(&XO[0]))) { // dopoki nie ma wygranej albo /przegranej dla obu stron
		int wybierz_pole;
		bool stop = true;
		while (stop) { // dziala dopoki nie ustawisz pola
			show(&XO[0]);
			cout << player << " "; cin >> wybierz_pole; // wybor pola
			if (wybierz_pole > -1 && wybierz_pole < 9) {
				if (XO[wybierz_pole] == '0') {
					XO[wybierz_pole] = player; // wpis pola
					cout << "ustawiono pole\n";
					player = switcher(player); // zamiana X na Y, Y na X
					stop = false;
				}
				else {
					cout << "\n to pole zostalo juz wybrane! \n";
				}
			}
			else {
				cout << "\n nieprawidlowe pole \n";
			}
		}
	}

}

int main(int argc, char const* argv[])
{
    vector<int> wektor;
	vector<char>wektor_buffer;
	while(true){
	
        int server_fd, new_socket, valread;
        struct sockaddr_in address;
        int opt = 1;
        int addrlen = sizeof(address);
        char buffer[1024] = { 1,2,3 };
		
		char hellos [] = {'W','I','T','A','J',' ','W',' ','G','R','Z','E','\n'};
        //char* hello = "Witaj\rw\rgrze!\n";
    	char* hello = &hellos[0];
        // Creating socket file descriptor
        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
            perror("socket failed");
            exit(EXIT_FAILURE);
        }
    
        // Forcefully attaching socket to the port 8080
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,sizeof(opt))) {
            perror("setsockopt");
            exit(EXIT_FAILURE);
        }
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);
    
        // Forcefully attaching socket to the port 8080
        if (bind(server_fd, (struct sockaddr*)&address,
                sizeof(address))< 0) {
            perror("bind failed");
            exit(EXIT_FAILURE);
        }
        if (listen(server_fd, 1000) < 0) {
            perror("listen");
            exit(EXIT_FAILURE);
        }
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address,
                    (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        
        valread = read(new_socket, buffer, 1024); // zmienna odibiera char od wlochatego
        send(new_socket, hello, strlen(hello), 0);
        
		cout <<"aktualne dane\n" ;
		cout << " wektor: size: "<<wektor.size() << " \n";
		cout << " wektor_buffer: size: "<<wektor_buffer.size() << " \n";

		wektor.push_back(valread);
		wektor_buffer.push_back(buffer[0]);

		for(vector<char>::iterator it = wektor_buffer.begin(); it != wektor_buffer.end();it++){
			cout << *it << " " ;
		} 
		cout << "\n";
		for(vector<int>::iterator it = wektor.begin(); it != wektor.end();it++){
			cout << *it << " " ;
		} 
		cout << "\n";

        
        printf("%s\n", buffer);
        
		
        printf("Madry Hello message sent\n");
	printf("----------------------------\n");
    // closing the connected socket
        close(new_socket);
    // closing the listening socket
        shutdown(server_fd, SHUT_RDWR);
    }
    return 0;
}
