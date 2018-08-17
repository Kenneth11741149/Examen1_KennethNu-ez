#include <iostream>
using std::endl;
using std::cin;
using std::cout;


#include <string>
using std::string;
#include <string.h>
#include <stdlib.h>

char** Generateground();
void deleteground(char** matrix);
void print(char** matrix){
	for(int i = 0; i < 11;i++){
		for(int j = 0; j < 11; j++){
			cout <<"[" <<  matrix[i][j] << "]";
		}
		cout << endl;
	}
}
bool intvalidator(char * coords){
	bool isnumber = true;
	for(int i = 1; i < strlen(coords);i++){
		if(isdigit(coords[i])){
		} else {
			cout << "FAKE NUMBER: " << coords[i];
			isnumber = false;
		}
	}
	return isnumber;
}

char** piezaval(char, int, int, int, int,char**);

int main(){
	int playeronepieces = 1;
	int playertwopieces = 1;
	bool playable = true;
	cout << "Bienvienido al Lab de Kenneth" << endl;
	cout << "	Menu" << endl;

	cout << "1. Iniciar el juego" << endl;
	int option = 0;
	cin >> option;
	switch(option){
		case 1:

			{
			char** ground = Generateground();
			int realnumber = 0;
			int realnumber2 = 0;
			ground[0][0] = '+';
			ground[10][0] = '#';
			ground[10][10] = '+';
			ground[0][10] = '#';
			print(ground);
			char coords[5];
			char coords2[5];
			while(playable){
				bool posible = false;
				while(posible == false){
					cout << "ACTUAL: " << endl;
					cin >> coords;
					cout << "Futura: " << endl;
					cin >> coords2;
					if(coords[0] == 'A' || coords[0] == 'B' || coords[0] == 'C' || coords[0] == 'D' || coords[0] == 'E' || coords[0] == 'F' || coords[0] == 'G' || coords[0] == 'H' || coords[0] == 'I' || coords[0] == 'J' || coords[0] == 'K'){
					if(intvalidator(coords)){
							char numeral[2];
							numeral[0] = coords[1];
						        numeral[1] = coords[2];
							realnumber = atoi(numeral);
							cout <<"realnumber" <<  realnumber << endl;

							if(coords2[0] == 'A' || coords[0] == 'B' || coords[0] == 'C' || coords[0] == 'D' || coords[0] == 'E' || coords[0] == 'F' || coords[0] == 'G' || coords[0] == 'H' || coords[0] == 'I' || coords[0] == 'J' || coords[0] == 'K'){

								if(intvalidator(coords2)){
									char numeral2[3];
									numeral2[0] = coords2[1];
									numeral2[1] = coords2[2];
									realnumber2 = atoi(numeral2);
									cout << "Second real " << realnumber << "Fin"<< endl;
									if(coords[1] > 10 || coords[2] > 10 || coords[1] < 0 || coords[2] < 0 
								        || coords2[1] > 10 || coords2[2] > 10 || coords2[1] < 0 || coords2[2] < 0){
												
									 	cout << "Invalid entry numbers too high or too low" << endl;
										cout << coords[1] << "L"  << coords[2] << "K" <<endl;
										cout << coords2[1] << "L2" << coords[2] << "K2" << endl;
									} else {
										ground = piezaval('+',coords[1],coords[2],coords2[1],coords2[2],ground);	
										print(ground);
									}

								}
							} else {
								cout << "SE INGRESO ALGO NO VALIDO;" << endl;
							}	





					} else {
						cout << "Se ingreso algo que no son numeros" << endl;
					}

					} else {
						cout << "1" <<coords << endl;
						cout << "1" <<coords[0] << "B" << coords[1] << "C"<< coords[2] << endl;
						cout << "Coordenadas invalidas Intente denuevo. " << endl;
					}
					
								
				} // Fin del while segundo.
				playable = false;
			} //FIn del primer while


			}
			break;
		default:
			cout << "Solo puede iniciar el juego" << endl;
			break;
	
	}

	return 0;
}

char** Generateground(){
	char** matrix = new char*[11];
	for(int i = 0; i < 11; i++){
		matrix[i] = new char[11];
	}
	for(int i = 0; i < 11; i++){
		for(int j = 0; j < 11; j++){
			matrix[i][j] = ' ';
		}
	
	}
	return matrix;
}

void deleteground(char** matriz){
	for(int i = 0; i < 11 ;i++){
		delete[] matriz[i];
	}
	delete[] matriz;
}

char** piezaval(char piece, int c1, int c2, int c3, int c4, char** ground){	
	if(ground[c1][c2] == piece && ground[c3][c4] != piece) {
		if( c3 == c1 || c3 == c1+1 || c3 == c1-1 ||  c3 == c1 + 2 || c3 == c1 - 2 ){
			if(c4 == c2 || c4 == c2+1 || c4 == c2-1 || c4 == c2 + 2 || c4 == c2 -2){
					if( c3 == c1 + 2 || c3 == c1 - 2 || c4 == c2 + 2 ||  c4 == c2 - 2 ){
						//chequear que no hay nada enmedio
					} else {
						ground[c1][c2] == piece;
						//chequear que se coma los ceercanos
					}
			}
		}

	} else {
		
	}
	return ground;
}
