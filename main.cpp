#include "GerenciadorDeArquivos.hpp"

void menu() {
    cout << "1. Cadastrar Conta" << endl;
    cout << "2. Excluir Conta" << endl;
    cout << "3. Adicionar Mídia" << endl;
    cout << "4. Remover Mídia" << endl;
    cout << "5. Visualizar Mídias" << endl;
    cout << "6. Visualizar Contas" << endl;
    cout << "7. Sair" << endl;
    cout << "Escolha uma opção: ";
}

int main() {
    GerenciadorDeArquivos gerenciador;
    int opcao;
    do {
        menu();
        cin >> opcao;
        switch (opcao) {
        case 1: {
            string nome, nomeUsuario, email, senha;
            cout << "Nome: "; cin >> nome;
            cout << "Nome de Usuário: "; cin >> nomeUsuario;
            cout << "Email: "; cin >> email;
            cout << "Senha: "; cin >> senha;
            gerenciador.adicionarConta(new Assinante(nome, nomeUsuario, email, senha));
            break;
        }
        case 2: {
            string nomeUsuario;
            cout << "Nome de Usuário para exclusão: ";
            cin >> nomeUsuario;
            gerenciador.removerConta(nomeUsuario);
            break;
        }
        case 3: {
            string nome, link;
            int duracao;
            cout << "Nome da Mídia: "; cin >> nome;
            cout << "Link: "; cin >> link;
            cout << "Duração (em segundos): "; cin >> duracao;
            gerenciador.adicionarMidia(Midia(nome, link, duracao));
            break;
        }
        case 4: {
            string nome;
            cout << "Nome da Mídia para exclusão: ";
            cin >> nome;
            gerenciador.removerMidia(nome);
            break;
        }
        case 5: {
            gerenciador.listarMidias();
            break;
        }
        case 6: {
            gerenciador.listarContas();
            break;
        }
        case 7:
            cout << "Saindo..." << endl;
            break;
        default:
            cout << "Opção inválida!" << endl;
        }
    } while (opcao != 7);

    return 0;
}
