#include "PersistenciaDaRede.h"
#include "Perfil.h"
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"


PersistenciaDaRede::PersistenciaDaRede(){}
PersistenciaDaRede::~PersistenciaDaRede(){}

void PersistenciaDaRede::salvaPerfilIndividual(std::ofstream& arquivoStream, Aluno* perfil){
    arquivoStream << perfil->getNumeroUSP() << " " << perfil->getNome() << " " << perfil->getEmail() << " " << perfil->getId() << std::endl;
}
void PersistenciaDaRede::salvaPerfilIndividual(std::ofstream& arquivoStream, Professor* perfil){
    arquivoStream << perfil->getNumeroUSP() << " " << perfil->getNome() << " " << perfil->getEmail() << " " << perfil->getDepartamento() << " " << perfil->getId() << std::endl;
}
void PersistenciaDaRede::salvaPerfilIndividual(std::ofstream& arquivoStream, Disciplina* perfil){
    if(perfil->getPreRequisito() == NULL){
        arquivoStream << perfil->getNome() << " " << perfil->getResponsavel()->getId() << " -1 " << perfil->getId() << std::endl;
    }
    else{
        arquivoStream << perfil->getNome() << " " << perfil->getResponsavel()->getId() << " "  << perfil->getPreRequisito()->getId() << " " << perfil->getId() << std::endl;
    }
}

template<typename T>
void PersistenciaDaRede::leDoArquivo(std::ifstream& arquivoStream, T* destino){
    T aux;
    arquivoStream >> aux;
    if(arquivoStream.fail()){
        throw std::logic_error("Falha na leitura do arquivo");
    }
    (*destino) = aux;
}

template<typename T>
void PersistenciaDaRede::salvaPerfisDoTipo(std::ofstream& arquivoStream, RedeSocial* r){
    int quantidadeDeT = 0;
    T* perfilPtr;
    std::vector<Perfil*>* perfisDaRede;

    perfisDaRede = r->getPerfis();

    for(unsigned int i=0; i<perfisDaRede->size(); i++){
        if(dynamic_cast<T*>((*perfisDaRede)[i])){
            quantidadeDeT++;
        }
    }

    arquivoStream << quantidadeDeT << std::endl;

    for(unsigned int i=0; i<perfisDaRede->size(); i++){
        perfilPtr = dynamic_cast<T*>((*perfisDaRede)[i]);
        if(perfilPtr){
            salvaPerfilIndividual(arquivoStream, perfilPtr);
        }
    }
}

void PersistenciaDaRede::salvar(std::string arquivo, RedeSocial* r){
    std::ofstream output;
    output.open(arquivo, std::ios_base::out);

    output << Perfil::getUltimoId() << std::endl;
    
    salvaPerfisDoTipo<Aluno>(output, r);

    salvaPerfisDoTipo<Professor>(output, r);

    salvaPerfisDoTipo<Disciplina>(output, r);

    for(Perfil* A : *(r->getPerfis())){
        int idA = A->getId();
        for(Perfil* B : *(A->getSeguidores())){
            output << idA << " " << B->getId() << std::endl;
        }
    }

    output.close();
}

RedeSocial* PersistenciaDaRede::carregar(std::string arquivo){
    std::ifstream input;
    input.open(arquivo, std::ios_base::in);

    RedeSocial* rede = new RedeSocial();

    if(!input){
        return rede;
    }

    int ultimoId;
    leDoArquivo<int>(input, &ultimoId);
    Perfil::setUltimoId(ultimoId);

    int numAlunos;
    leDoArquivo<int>(input, &numAlunos);

    int i;
    for(i=0; i<numAlunos && input; i++){
        int nusp, id;
        std::string nome, email;

        leDoArquivo<int>(input, &nusp);
        leDoArquivo<std::string>(input, &nome);
        leDoArquivo<std::string>(input, &email);
        leDoArquivo<int>(input, &id);

        rede->adicionar(new Aluno(id, nusp, nome, email));
    }

    int numProfessores;
    input >> numProfessores;

    for(i=0; i<numProfessores && input; i++){
        int nusp, id;
        std::string nome, email, dept;

        leDoArquivo<int>(input, &nusp);
        leDoArquivo<std::string>(input, &nome);
        leDoArquivo<std::string>(input, &email);
        leDoArquivo<std::string>(input, &dept);
        leDoArquivo<int>(input, &id);

        rede->adicionar(new Professor(id, nusp, nome, email, dept));
    }

    int numDisciplinas;
    input >> numDisciplinas;

    for(i=0; i<numDisciplinas && input; i++){
        int responsavel, preReq, id;
        std::string nome;
        Professor* profResponsavel;
        Disciplina* disciplinaPreReq;

        leDoArquivo<std::string>(input, &nome);
        leDoArquivo<int>(input, &responsavel);
        leDoArquivo<int>(input, &preReq);
        leDoArquivo<int>(input, &id);

        profResponsavel = dynamic_cast<Professor*>(rede->getPerfil(responsavel));
        disciplinaPreReq = dynamic_cast<Disciplina*>(preReq == -1 ? nullptr : rede->getPerfil(preReq));
        rede->adicionar(new Disciplina(id, nome, profResponsavel, disciplinaPreReq));
    }

    int idA;
    while(input >> idA){
        int idB;
        Perfil * perfilA, *perfilB;

        //leDoArquivo<int>(input, &idA);
        leDoArquivo<int>(input, &idB);

        perfilA = rede->getPerfil(idA);
        perfilB = rede->getPerfil(idB);

        perfilA -> adicionarSeguidor(perfilB);

    }

    return rede;
}