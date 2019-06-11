/*
 * Articulacao.h
 *
 *  Created on: 2 de jun de 2019
 *      Author: mgregorio
 */
#include <Servo.h>


#ifndef ARTICULACAO_H_
#define ARTICULACAO_H_

class Articulacao {
public:
	Articulacao();
	virtual ~Articulacao();
	void inicializa(int porta, int posicaoInicial);
	void movePara(int posicao);
	void executaMovimento();
private:
	int porta;
	int posicaoAtual;
	int posicaoFutura;
	Servo servo;
};

#endif /* ARTICULACAO_H_ */
