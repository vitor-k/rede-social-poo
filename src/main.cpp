#include <string>
#include <iostream>
#include "Perfil.h"
#include "RedeSocial.h"
#include "Professor.h"
#include "Aluno.h"
#include "Disciplina.h"
#include "Publicacao.h"
#include "PersistenciaDaRede.h"
#include <vector>
#include <list>


void myScanf(std::string& texto){
	std::cin.ignore(100, '\n');
	std::getline(std::cin, texto);
}

int imprimirTelaPrincipal(){
	int retorno;
	std::cout << 
	"Escolha uma opcao:\n" <<
	"1) Cadastrar Perfil\n" <<
	"2) Cadastrar Disciplina\n" <<
	"3) Logar\n" << 
	"0) Terminar" <<std::endl;

	std::cin >> retorno;
	return retorno;
}

void listarPerfis(RedeSocial* rede){
	std::vector<Perfil*>* perfis = rede->getPerfis();

	for(unsigned int i=0; i<perfis->size(); i++){
		std::cout << (*perfis)[i]->getId() << ") " << (*perfis)[i]->getNome() << std::endl;
	}
}

void cadastrarPerfil(RedeSocial* rede){
	int nusp;
	std::string nome, email, resp, depart;
	Perfil* perf;

	std::cout << "Informe os dados do perfil\n" <<
	"Numero USP: ";
	std::cin >> nusp;
	std::cout << "Nome: ";
	myScanf(nome);
	std::cout << "Email: ";
	std::cin >> email;
	std::cout << "Professor (s/n): ";
	std::cin >> resp;
	if(resp.find('s') != std::string::npos){
		std::cout << "Departamento: ";
		std::cin >> depart;

		perf = new Professor(nusp, nome, email, depart);
	}
	else{  //strings que nao contem nem 's' nem 'n' sao don't care. Podem ser agrupadas com 'n'.
		perf = new Aluno(nusp, nome, email);
	}
	rede->adicionar(perf);
}

void cadastrarDisciplina(RedeSocial* rede){
	std::string nome;
	int numResponsavel, numPreRequisito;
	std::vector<Perfil*>* perfis = rede->getPerfis();
	Disciplina *disciplina, *preRequisito;
	Professor *responsavel;

	std::cout << "Informe os dados da disciplina\n" <<
	"Nome: ";
	myScanf(nome);
	std::cout << "Responsavel:\n";
	listarPerfis(rede);
	std::cout << "Digite o numero ou 0 para cancelar: ";
	
	std::cin >> numResponsavel;
	if(numResponsavel == 0) return;

	responsavel = dynamic_cast<Professor*>((*perfis)[numResponsavel-1]);
	if(!responsavel){
		std::cout << "Somente professores podem ser responsaveis por disciplinas\n";
		return;
	}

	std::cout << "Pre-requisito:\n";
	listarPerfis(rede);
	std::cout << "Digite o numero ou 0 para nenhum: ";
	std::cin >> numPreRequisito;
	if(numPreRequisito){
		preRequisito = dynamic_cast<Disciplina*>((*perfis)[numPreRequisito-1]);
		if(!preRequisito){
			std::cout << "Pre-requisito deve ser uma disciplina\n";
			return;
		}
		disciplina = new Disciplina(nome, responsavel, preRequisito);
	}
	else{
		disciplina = new Disciplina(nome, responsavel);
	}

	rede->adicionar(disciplina);
}

Perfil* login(RedeSocial* rede){
	int numEscolhido;
	std::cout << "Escolha um perfil:\n";
	listarPerfis(rede);
	std::cout << "Digite o numero ou 0 para cancelar: ";
	std::cin>>numEscolhido;	
	if(numEscolhido == 0){
		return NULL;
	}
	else{
		return (*rede->getPerfis())[numEscolhido-1];
	}
}

void telaPublicacoesFeitas(Perfil* user){
	std::cout << "Publicacoes feitas: " << std::endl;
	std::list<Publicacao*>* feitas = user->getPublicacoesFeitas();
	for(Publicacao* pub: (*feitas)){
		pub->imprimir();
	}
}
void telaPublicacoesRecebidas(Perfil* user){
	int escolha;
	std::list<Publicacao*>* recebidas = user->getPublicacoesRecebidas();

	int i=0;
	std::cout << "Publicacoes recebidas: " << std::endl;
	for(Publicacao* pub: (*recebidas)){
		std::cout << ++i << ") ";
		pub->imprimir();
	}
	std::cout << "Digite o numero da mensagem para curtir ou 0 para voltar: ";
	std::cin >> escolha;
	if(escolha){
		auto it = recebidas->begin();
		for(i=0;i<escolha-1;i++){
			it++;
		}
		(*it)->curtir(user);
	}
}
void telaFazerPublicacao(Perfil* user){
	std::string resp, data="", texto;

	std::cout << "Evento (s/n):";
	std::cin >> resp;
	if(resp.find('s') != std::string::npos){
		std::cout << "Data: ";
		std::cin >> data;
	}
	std::cout << "Texto: ";
	myScanf(texto);

	if(data.length()){
		user->publicar(texto, data);
	}
	else{
		user->publicar(texto);
	}
	
}
void telaSeguirPerfil(RedeSocial* rede, Perfil* user){
	int escolhido;

	std::cout << "Perfil:" << std::endl;
	listarPerfis(rede);

	std::cout << "Digite o numero ou 0 para cancelar: ";
	std::cin >> escolhido;

	if(escolhido){
		(*(rede->getPerfis()))[escolhido-1]->adicionarSeguidor(user);
	}
}

void imprimirTelaLogged(Perfil* user){
	user->imprimir();
	std::cout << "---\n";

	std::cout << "Escolha uma opcao:\n" << 
	"1) Ver publicacoes feitas\n" <<
	"2) Ver pubblicacoes recebidas\n" <<
	"3) Fazer publicacao" << std::endl;
	if(!dynamic_cast<Disciplina*>(user))
		std::cout << "4) Seguir perfil" <<std::endl;
	std::cout << "0) Deslogar" <<std::endl;
}

void loggedIn(RedeSocial* rede, Perfil* user){
	bool deslogar = (user==NULL);
	int escolha;

	while(!deslogar){
		imprimirTelaLogged(user);

		std::cin >> escolha;
		switch(escolha){
			case 1:
				telaPublicacoesFeitas(user);
				break;
			case 2:
				telaPublicacoesRecebidas(user);
				break;
			case 3:
				telaFazerPublicacao(user);
				break;
			case 4:
				if(!dynamic_cast<Disciplina*>(user))
					telaSeguirPerfil(rede, user);
				break;
			case 0:
				deslogar = true;
				break;
		}
	}
}

int main(){
	bool continuar = true;
	char salvar;
	int escolha;
	std::string arquivo;

	std::cout << "Arquivo: ";
	std::cin >> arquivo;

	try{
		RedeSocial* rede = PersistenciaDaRede::carregar(arquivo);

		while(continuar){
			escolha = imprimirTelaPrincipal();
			switch(escolha){
				case 1:
					cadastrarPerfil(rede);
					break;
				case 2:
					cadastrarDisciplina(rede);
					break;
				case 3:
					loggedIn(rede, login(rede));
					break;
				case 0:
					continuar = false;
					break;
			}
		}

		
		std::cout << "Deseja Salvar? (s/n) ";
		std::cin >> salvar;

		if(salvar == 's'){
			PersistenciaDaRede::salvar(arquivo, rede);
		}
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}