# ElaboracaoSimuladorDeArquivosDeMidia-LVP9
LVP9 - Disciplina Técnicas de programação - UFCG
Elabore um sistema em C++ que simule um serviço de streaming de mídia, utilizando herança múltipla e manipulação de arquivos, com as seguintes classes:

Classe Conta: Classe base que contém atributos gerais como nome, nome do usuário, email e senha.
Classes Assinante e Administrador: Herdam da classe Conta. A classe Assinante inclui atributos como lista de programas assistidos (vector<string>), enquanto Administrador possui a sua senha master, que o permite administrar todas as contas e mídias. O Sistema vem com um Administrador padrão cadastrado (senha: Adm123#, chave: Adm1234!@#%, nome: Administrador, nome de usuário: admin, email: admin@ssm.com)
Classe GerenciadorDeArquivos: Focada na leitura e escrita de dados em arquivos, esta classe deve ter métodos para manter (salvar, ler e excluir) uma mídia do catálogo (Set) de Mídias (cada mídia possui nome, link e a duração em segundos) e uma Conta do catálogo (Set) de Contas.
No sistema (main), as operações seguintes devem ser suportadas:

Cadastrar e excluir Conta (a autorização é dada quando o Administrador informa corretamente o nome do usuário, senha e a sua chave mestra corretas).
Adicionar ou remover Mídia (a autorização é dada quando o Administrador informa corretamente o nome do usuário, senha e a sua chave mestra corretas)
Visualizar todas as mídias salvas (a autorização é dada quando o Assinante ou Administrador informa corretamente o nome do usuário e a senha)
Visualizar conta(s) (a autorização é dada quando o Assinante ou Administrador informa corretamente o nome do usuário e a senha). Caso o usuário seja Administrador, a listagem deve trazer todos os usuários. Caso Assinante, o sistema deve mostrar os detalhes do próprio usuário).
Considerações:

Com relação a manipulação de arquivo, a leitura das mídias e contas inicialmente armazenadas nos arquivos deve ser feita pelo construtor do GerenciadorDeArquivos, ou seja, ele deve ler os atributos (de cada objeto), armazenar em um objeto e, em seguida, inserir esse objeto no conjunto (Set). Já a escrita dos objetos no arquivo deve ser feita em um método de salvamento. Lembre-se de que esse método deve ser chamado pelo destrutor para garantir que o catálogo realmente será salvo. Para isso, vocês devem utilizar objetos de leitura do tipo ifstream e de escrita do tipo ofstream, ambos da biblioteca de manipulação de arquivos <fstream>.

 
