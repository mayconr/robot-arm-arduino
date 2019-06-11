/*
 * Articulacao.cpp
 *
 *  Created on: 2 de jun de 2019
 *      Author: mgregorio
 */

#include "Articulacao.h"

Articulacao::Articulacao() {
	this->servo = Servo();
}

Articulacao::~Articulacao() {
	// TODO Auto-generated destructor stub
}

void Articulacao::inicializa(int porta, int posicaoInicial) {
	this->porta = porta;
	this->posicaoFutura = posicaoInicial;
	this->servo.attach(porta);
	this->servo.write(100);
}

void Articulacao::movePara(int posicao) {
	this->posicaoAtual = posicaoFutura;
	this->posicaoFutura = posicao;
}

void Articulacao::executaMovimento() {
	if (this->posicaoAtual < this->posicaoFutura) {
		this->posicaoAtual += 1;
		servo.write(posicaoAtual);
	}
	if (this->posicaoAtual > this->posicaoFutura) {
		this->posicaoAtual -= 1;
		servo.write(posicaoAtual);
	}

}
