#include <fstream>
#include <stdexcept>
#include <vector>
#include "PersistenciaDaRede.h"
#include "Perfil.h"
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"
#include "RedeSocial.h"

namespace PersistenciaDaRede {
static void salvaPerfilIndividual(std::ofstream& arquivoStream, Aluno* perfil){
    arquivoStream << perfil->getNumeroUSP() << " " << perfil->getNome() << " " << perfil->getEmail() << " " << perfil->getId() << std::endl;
}
static void salvaPerfilIndividual(std::ofstream& arquivoStream, Professor* perfil){
    arquivoStream << perfil->getNumeroUSP() << " " << perfil->getNome() << " " << perfil->getEmail() << " " << perfil->getDepartamento() << " " << perfil->getId() << std::endl;
}
static void salvaPerfilIndividual(std::ofstream& arquivoStream, Disciplina* perfil){
    if(perfil->getPreRequisito() == NULL){
        arquivoStream << perfil->getNome() << " " << perfil->getResponsavel()->getId() << " -1 " << perfil->getId() << std::endl;
    }
    else{
        arquivoStream << perfil->getNome() << " " << perfil->getResponsavel()->getId() << " "  << perfil->getPreRequisito()->getId() << " " << perfil->getId() << std::endl;
    }
}

template<typename T>
static T leDoArquivo(std::ifstream& arquivoStream){
    T aux;
    arquivoStream >> aux;
    if(arquivoStream.fail()){
        throw std::logic_error("Falha na leitura do arquivo");
    }
    return aux;
}

template<typename T>
static void salvaPerfisDoTipo(std::ofstream& arquivoStream, RedeSocial* r){
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

void salvar(std::string arquivo, RedeSocial* r){
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

RedeSocial* carregar(std::string arquivo){
    std::ifstream input;
    input.open(arquivo, std::ios_base::in);

    RedeSocial* rede = new RedeSocial();

    if(!input){
        return rede;
    }

    const int ultimoId = leDoArquivo<int>(input);
    Perfil::setUltimoId(ultimoId);

    const int numAlunos = leDoArquivo<int>(input);

    for(int i=0; i<numAlunos && input; i++){
        int nusp = leDoArquivo<int>(input);
        std::string nome = leDoArquivo<std::string>(input);
        std::string email = leDoArquivo<std::string>(input);
        const int id = leDoArquivo<int>(input);
        
        rede->adicionar(new Aluno(id, nusp, nome, email));
    }

    int numProfessores;
    input >> numProfessores;

    for(int i=0; i<numProfessores && input; i++){
        const int nusp = leDoArquivo<int>(input);
        std::string nome = leDoArquivo<std::string>(input);
        std::string email = leDoArquivo<std::string>(input);
        std::string dept = leDoArquivo<std::string>(input);
        const int id = leDoArquivo<int>(input);

        rede->adicionar(new Professor(id, nusp, nome, email, dept));
    }

    int numDisciplinas;
    input >> numDisciplinas;

    for(int i=0; i<numDisciplinas && input; i++){
        std::string nome = leDoArquivo<std::string>(input);
        const int responsavel = leDoArquivo<int>(input);
        const int preReq = leDoArquivo<int>(input);
        const int id = leDoArquivo<int>(input);

        Professor* profResponsavel = dynamic_cast<Professor*>(rede->getPerfil(responsavel));
        Disciplina* disciplinaPreReq = dynamic_cast<Disciplina*>(preReq == -1 ? nullptr : rede->getPerfil(preReq));
        rede->adicionar(new Disciplina(id, nome, profResponsavel, disciplinaPreReq));
    }

    int idA;
    while(input >> idA){
        const int idB = leDoArquivo<int>(input);

        Perfil* perfilA = rede->getPerfil(idA);
        Perfil* perfilB = rede->getPerfil(idB);

        perfilA -> adicionarSeguidor(perfilB);

    }

    return rede;
}

} //namespace PersistenciaDaRede