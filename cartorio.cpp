#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro() // Função responsável por cadastrar usuários no sistema
{
	// Criação de variáveis para armazenar dados do usuário e o nome do arquivo
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado: "); // Solicita o CPF do usuário
    scanf("%s", cpf); // Lê o CPF digitado e armazena na variável cpf

    strcpy(arquivo, cpf); // Copia o CPF para a variável que será usada como nome do arquivo

    FILE *file; // Declara um ponteiro para arquivo
    file = fopen(arquivo, "w"); // Cria ou sobrescreve o arquivo com o nome correspondente ao CPF
    fprintf(file, cpf); // Escreve o CPF no arquivo
	fclose(file); // Fecha o arquivo após a escrita

    // Adiciona uma vírgula para separar o próximo dado
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    // Captura o nome e escreve no arquivo
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", nome);
    fclose(file);

    // Adiciona outra vírgula para separar os dados
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    // Captura o sobrenome e escreve no arquivo
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", sobrenome); // Escreve o sobrenome no arquivo
    fclose(file);

    // Adiciona outra vírgula para separação
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    // Captura o cargo e escreve no arquivo
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo); // Escreve o cargo no arquivo
    fclose(file);

    system("pause"); // Pausa para o usuário visualizar
}

int consulta() // Função para consultar dados de usuários
{
    setlocale(LC_ALL, "Portuguese"); // Define o idioma para suporte a caracteres especiais

    char cpf[40];
    char conteudo[100]; // Buffer para leitura dos dados do arquivo

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf); // Lê o CPF que será usado como nome do arquivo

    FILE *file;
    file = fopen(cpf, "r"); // Tenta abrir o arquivo correspondente ao CPF

    if (file == NULL) // Verifica se o arquivo existe
    {
        printf("Não foi possível abrir o arquivo, não localizado!\n");
        return 1; // Retorna erro se o arquivo não for encontrado
    }

    // Exibe os dados do usuário contidos no arquivo
    printf("\nEssas são as informações do usuário:\n");
    while (fgets(conteudo, 100, file) != NULL) // Lê cada linha do arquivo
    {
        printf("%s", conteudo);
    }
    printf("\n\n");
    fclose(file); // Fecha o arquivo

    system("pause"); // Pausa para o usuário visualizar
    return 0;
}

int deletar() // Função para deletar registros de usuários
{
    char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf); // Lê o CPF que será usado como nome do arquivo a ser removido

    remove(cpf); // Remove o arquivo correspondente ao CPF

    FILE *file;
    file = fopen(cpf, "r"); // Tenta abrir o arquivo para verificar se foi deletado

    if (file == NULL) // Verifica se o arquivo não existe mais
    {
        printf("O usuário não se encontra no sistema.\n");
        system("pause");
    }
}

int main() // Função principal
{
    int opcao = 0;

    while (1) // Loop infinito para o menu
    {
        system("cls"); // Limpa a tela
        setlocale(LC_ALL, "Portuguese"); // Configura suporte a caracteres especiais

        // Exibe o menu para o usuário
        printf("### Cartório da EBAC ###\n\n");
        printf("Escolha a opção desejada do menu\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("Opção: ");

        scanf("%d", &opcao); // Lê a escolha do usuário

        system("cls"); // Limpa a tela após a escolha

        // Redireciona para a função correspondente à escolha
        switch (opcao)
        {
        case 1:
            registro(); // Chama a função de registro
            break;

        case 2:
            consulta(); // Chama a função de consulta
            break;

        case 3:
            deletar(); // Chama a função de deletar
            break;

        default:
            // Mensagem de erro para opção inválida
            printf("Essa opção não está disponível!\n");
            system("pause");
            break;
        }
    }

    return 0; // Encerra o programa
}
