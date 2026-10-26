#include <stdio.h>

int main() {
printf("====================================\n");
printf("       CHATBOT LOJA FACIL\n");
printf("====================================\n");
printf("Sistema de atendimento ao cliente.\n");
printf("Aqui voce encontra respostas para as\n");
printf("perguntas mais frequentes da nossa loja.\n");
printf("Ola! Seja bem-vindo(a)! Como podemos ajudar?\n");

    int opcao;

do {
    printf("\n===== MENU DE ATENDIMENTO =====\n");
    printf("1 - Consultar horario de funcionamento\n");
    printf("2 - Consultar formas de pagamento\n");
    printf("3 - Consultar prazo de entrega\n");
    printf("4 - Consultar politica de troca\n");
    printf("5 - Falar com atendimento humano\n");
    printf("0 - Encerrar atendimento\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);


        switch (opcao) {
            case 1:
                printf("\nNosso horario de funcionamento e de segunda a sexta, das 9h as 18h.\n");
                break;

            case 2:
                printf("\nAceitamos Pix, cartao de credito, cartao de debito e boleto bancario.\n");
                break;

            case 3:
                printf("\nO prazo de entrega varia de 3 a 7 dias uteis, dependendo da regiao.\n");
                break;

            case 4:
                printf("\nAs trocas podem ser solicitadas em ate 7 dias apos o recebimento do produto.\n");
                break;

            case 5:
                printf("\nSua solicitacao sera encaminhada para o atendimento humano.\n");
                printf("Descreva seu problema para receber ajuda personalizada.\n");
                break;

            case 0:
                printf("\nAtendimento encerrado. Obrigado por entrar em contato!\n");
                break;

            default:
                printf("\nOpcao invalida! Por favor, escolha uma opcao de 0 a 5.\n");
                printf("Voltando ao menu de atendimento...\n");
                break;
        }

} while (opcao != 0);

    return 0;
}

