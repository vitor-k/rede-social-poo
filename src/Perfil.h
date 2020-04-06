#ifndef PERFIL_H
#define PERFIL_H

#define MAXIMO_SEGUIDORES 20
#define MAXIMO_PUBLICACOES 20

#include <string>
#include <iostream>

class Publicacao;

class Perfil{
	private:
		int nusp;
		std::string nome;
		std::string email;
		
		Perfil** seguidores;
		int numSeguidores;
		
		Publicacao** feitas;
		int numFeitas;
		
		Publicacao** recebidas;
		int numRecebidas;
		
		virtual void publicar(Publicacao* p);
	public:
		Perfil(int numeroUSP, std::string nome, std::string email);
		virtual ~Perfil();

		int getNumeroUSP() const;
		std::string getNome() const;
		std::string getEmail() const;

		virtual bool adicionarSeguidor(Perfil* seguidor);

		virtual bool publicar(std::string texto);
		virtual bool publicar(std::string texto, std::string data);

		virtual bool receber(Publicacao* p);

		virtual Publicacao** getPublicacoesFeitas() const;
		virtual int getQuantidadeDePublicacoesFeitas() const;

		virtual Publicacao** getPublicacoesRecebidas() const;
		virtual int getQuantidadeDePublicacoesRecebidas() const;

		virtual Perfil** getSeguidores() const;
		virtual int getQuantidadeDeSeguidores() const;

		virtual void imprimir() const;
};

#endif 

