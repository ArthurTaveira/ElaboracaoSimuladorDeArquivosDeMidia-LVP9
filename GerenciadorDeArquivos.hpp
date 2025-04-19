#ifndef GERENCIADOR_DE_ARQUIVOS_HPP
#define GERENCIADOR_DE_ARQUIVOS_HPP

#include <fstream>
#include <set>
#include "Conta.hpp"

using namespace std;

class Midia {
public:
    string nome;
    string link;
    int duracao;

    Midia(string nome, string link, int duracao)
        : nome(nome), link(link), duracao(duracao) {}

    void mostrarDetalhes() const {
        cout << "Nome: " << nome << ", Link: " << link << ", Duração: " << duracao << "s" << endl;
    }
};

class GerenciadorDeArquivos {
private:
    set<Midia> catalogoMidias;
    set<Conta*> catalogoContas;

    void carregarMidias() {
        ifstream arquivo("midias.txt");
        if (arquivo.is_open()) {
            string nome, link;
            int duracao;
            while (arquivo >> nome >> link >> duracao) {
                catalogoMidias.insert(Midia(nome, link, duracao));
            }
            arquivo.close();
        }
    }

    void carregarContas() {
        ifstream arquivo("contas.txt");
        if (arquivo.is_open()) {
            string tipo, nome, nomeUsuario, email, senha, chave;
            while (arquivo >> tipo >> nome >> nomeUsuario >> email >> senha) {
                if (tipo == "Assinante") {
                    catalogoContas.insert(new Assinante(nome, nomeUsuario, email, senha));
                } else if (tipo == "Administrador") {
                    arquivo >> chave;
                    catalogoContas.insert(new Administrador(nome, nomeUsuario, email, senha, chave));
                }
            }
            arquivo.close();
        }
    }

public:
    GerenciadorDeArquivos() {
        carregarMidias();
        carregarContas();
    }

    ~GerenciadorDeArquivos() {
        salvarMidias();
        salvarContas();
    }

    void salvarMidias() {
        ofstream arquivo("midias.txt");
        for (const auto& midia : catalogoMidias) {
            arquivo << midia.nome << " " << midia.link << " " << midia.duracao << endl;
        }
        arquivo.close();
    }

    void salvarContas() {
        ofstream arquivo("contas.txt");
        for (const auto& conta : catalogoContas) {
            if (auto a = dynamic_cast<Assinante*>(conta)) {
                arquivo << "Assinante " << a->getNome() << " " << a->getNomeUsuario() << " "
                        << a->getEmail() << " " << a->getSenha() << endl;
            } else if (auto ad = dynamic_cast<Administrador*>(conta)) {
                arquivo << "Administrador " << ad->getNome() << " " << ad->getNomeUsuario() << " "
                        << ad->getEmail() << " " << ad->getSenha() << " " << ad->getChaveMestre() << endl;
            }
        }
        arquivo.close();
    }

    void adicionarMidia(const Midia& midia) {
        catalogoMidias.insert(midia);
    }

    void removerMidia(const string& nome) {
        auto it = catalogoMidias.begin();
        while (it != catalogoMidias.end()) {
            if (it->nome == nome) {
                catalogoMidias.erase(it);
                return;
            }
            ++it;
        }
    }

    void adicionarConta(Conta* conta) {
        catalogoContas.insert(conta);
    }

    void removerConta(const string& nomeUsuario) {
        auto it = catalogoContas.begin();
        while (it != catalogoContas.end()) {
            if ((*it)->getNomeUsuario() == nomeUsuario) {
                delete *it;
                catalogoContas.erase(it);
                return;
            }
            ++it;
        }
    }

    void listarMidias() const {
        for (const auto& midia : catalogoMidias) {
            midia.mostrarDetalhes();
        }
    }

    void listarContas() const {
        for (const auto& conta : catalogoContas) {
            conta->mostrarDetalhes();
        }
    }
};

#endif
