#ifndef CONTA_HPP
#define CONTA_HPP

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Conta {
protected:
    string nome;
    string nomeUsuario;
    string email;
    string senha;

public:
    Conta(string nome, string nomeUsuario, string email, string senha)
        : nome(nome), nomeUsuario(nomeUsuario), email(email), senha(senha) {}

    virtual ~Conta() {}

    string getNomeUsuario() const { return nomeUsuario; }
    string getEmail() const { return email; }
    string getSenha() const { return senha; }
    string getNome() const { return nome; }

    virtual void mostrarDetalhes() const {
        cout << "Nome: " << nome << endl;
        cout << "Nome de Usuário: " << nomeUsuario << endl;
        cout << "Email: " << email << endl;
    }
};

class Assinante : public Conta {
private:
    vector<string> listaProgramasAssistidos;

public:
    Assinante(string nome, string nomeUsuario, string email, string senha)
        : Conta(nome, nomeUsuario, email, senha) {}

    void adicionarProgramaAssistido(string programa) {
        listaProgramasAssistidos.push_back(programa);
    }

    void mostrarDetalhes() const override {
        Conta::mostrarDetalhes();
        cout << "Programas assistidos: ";
        for (const auto& programa : listaProgramasAssistidos) {
            cout << programa << ", ";
        }
        cout << endl;
    }
};

class Administrador : public Conta {
private:
    string chaveMestre;

public:
    Administrador(string nome, string nomeUsuario, string email, string senha, string chaveMestre)
        : Conta(nome, nomeUsuario, email, senha), chaveMestre(chaveMestre) {}

    string getChaveMestre() const { return chaveMestre; }

    void mostrarDetalhes() const override {
        Conta::mostrarDetalhes();
        cout << "Administrador do sistema" << endl;
    }
};

#endif
