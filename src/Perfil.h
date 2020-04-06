#ifndef PERFIL_H
#define PERFIL_H

#define MAXIMO_SEGUIDORES 20
#define MAXIMO_PUBLICACOES 20

#include <memory>
#include <string>
#include <iostream>
#include <vector>

#include "Publicacao.h"
class Publicacao;

class Perfil{
	private:
		int nusp;
		std::string nome;
		std::string email;
		
		std::vector<std::weak_ptr<Perfil> > seguidores;
		int n_seguidores;
		
		std::vector<std::shared_ptr<Publicacao> > feitas;
		int n_feitas;
		
		std::vector<std::weak_ptr<Publicacao> > recebidas;
		int n_recebidas;
	public:
		Perfil(int numeroUSP, std::string nome, std::string email);
		virtual ~Perfil();

		int getNumeroUSP() const;
		std::string getNome() const;
		std::string getEmail() const;

		virtual bool adicionarSeguidor(std::weak_ptr<Perfil> seguidor);

		virtual bool publicar(std::string texto);
		// virtual bool publicar(std::string texto, std::string data);

		virtual bool receber(std::weak_ptr<Publicacao> p);

		virtual std::vector<std::shared_ptr<Publicacao> > getPublicacoesFeitas() const;
		virtual int getQuantidadeDePublicacoesFeitas() const;

		virtual std::vector<std::weak_ptr<Publicacao> > getPublicacoesRecebidas() const;
		virtual int getQuantidadeDePublicacoesRecebidas() const;

		virtual std::vector<std::weak_ptr<Perfil> > getSeguidores() const;
		virtual int getQuantidadeDeSeguidores() const;

		virtual void imprimir() const;

};

#endif 

