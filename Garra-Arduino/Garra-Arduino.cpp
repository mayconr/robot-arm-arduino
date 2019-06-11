#include <Arduino.h>
#include <Servo.h>
#include "Articulacao.h";

Articulacao articulacaoA;
Articulacao articulacaoB;
Articulacao articulacaoC;
Articulacao articulacaoD;
Articulacao articulacaoD2;
Articulacao articulacaoE;

void setup() {
	Serial.begin(9600);
	articulacaoA.inicializa(2, 50);
	articulacaoB.inicializa(3, 50);
	articulacaoC.inicializa(4, 50);
	articulacaoD.inicializa(5, 50);
	articulacaoD2.inicializa(6, 50);
	articulacaoE.inicializa(7, 50);
}

void moveArticulation(String articulation, int movement) {
	if (articulation.equals("A")) {
		int real = map(movement, 0, 100, 70, 170);
		articulacaoA.movePara(real);
		Serial.println("Articulation: "+articulation+"; Moved: "+real);
	} else if (articulation.equals("B")) {
		int real = map(movement, 0, 100, 80, 180);
		articulacaoB.movePara(real);
		Serial.println("Articulation: "+articulation+"; Moved: "+real);
	} else if (articulation.equals("C")) {
		int real = map(abs(movement-100), 0, 100, 80, 180);
		articulacaoC.movePara(real);
		Serial.println("Articulation: "+articulation+"; Moved: "+real);
	} else if (articulation.equals("D")) {
		int realD2 = map(abs(movement-100), 0, 100, 0, 180);
		int realD = map(movement, 0, 100, 0, 180);
		articulacaoD2.movePara(realD2);
		articulacaoD.movePara(realD);
		Serial.println("Articulation: "+articulation+"; Moved: "+realD+" and "+realD2);
	} else if (articulation.equals("E")) {
		int real = map(movement, 0, 100, 0, 120);
		articulacaoE.movePara(real);
		Serial.println("Articulation: "+articulation+"; Moved: "+real);
	}
}

void loop() {
	if (Serial.available() > 0) {
		String str = Serial.readStringUntil(';');
		char data[str.length() + 1];
		str.toCharArray(data, str.length() + 1);
		char *tokenPointer = strtok(data, ";");
		while (tokenPointer != NULL) {
			String token = String(tokenPointer);
			String articulation = token.substring(0,1);
			int movement = token.substring(2, token.length()).toInt();
			moveArticulation(articulation, movement);
			tokenPointer = strtok(NULL, ";");
		}
	}
	articulacaoA.executaMovimento();
	articulacaoB.executaMovimento();
	articulacaoC.executaMovimento();
	articulacaoD.executaMovimento();
	articulacaoD2.executaMovimento();
	articulacaoE.executaMovimento();
	delay(50);
}
