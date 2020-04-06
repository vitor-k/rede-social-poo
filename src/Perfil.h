#ifndef PERFIL_H
#define PERFIL_H

#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>

class Publicacao;

class Perfil{
	private:
		std::vector<Perfil*> seguidores;
		int numSeguidores;

		std::list<Publicacao*> feitas;
		int numFeitas;

		std::list<Publicacao*> recebidas;
		int numRecebidas;

		virtual void publicar(Publicacao* p);

        bool seguidoPor(Perfil* p);

		int id;
        static int lastId;

		std::string nome;
    protected:
        
	public:
		Perfil(std::string nome);
		Perfil(int id, std::string nome);
		virtual ~Perfil();

		static void setUltimoId(int ultimoId);
		static int getUltimoId();

		int getId() const;
		std::string getNome() const;

		virtual void adicionarSeguidor(Perfil* seguidor);

		virtual void publicar(std::string texto);
		virtual void publicar(std::string texto, std::string data);

		virtual bool receber(Publicacao* p);

		virtual std::list<Publicacao*>* getPublicacoesFeitas() const;

		virtual std::list<Publicacao*>* getPublicacoesRecebidas() const;

		virtual std::vector<Perfil*>* getSeguidores() const;

		virtual void imprimir() const = 0;

};

#endif// PERFIL_H
