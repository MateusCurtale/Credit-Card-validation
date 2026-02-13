#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void valida_cartao(string numero);
void verifica_bandeira(string numero);

int main(void)
{
    long numero;

    // pede o número do cartão para o usuário
    do
    {
        numero = get_long("Número do cartão: ");
    }
    while (numero < 0);

    // converte o número do cartão para string
    char str_numero[20];
    sprintf(str_numero, "%ld", numero);

    // valida o número do cartão
    valida_cartao(str_numero);
    verifica_bandeira(str_numero);
}

void valida_cartao(string str_numero)
{

    // calcula o comprimento do número do cartão
    int comprimento = strlen(str_numero);

    // verifica se o comprimento é válido (13, 15 ou 16 dígitos)
    if (comprimento != 13 && comprimento != 15 && comprimento != 16)
    {
        printf("Número de cartão inválido.\n");
        return;
    }

    // implementa o algoritmo de Luhn para validar o número do cartão
    int soma = 0;
    for (int i = comprimento - 1; i >= 0; i--)
    {
        int digito = str_numero[i] - '0'; // converte o caractere para um número

        if ((comprimento - i) % 2 == 0) // se a posição for par (contando da direita)
        {
            digito *= 2;    // dobra o dígito
            if (digito > 9) // se o resultado for maior que 9, subtrai 9
            {
                digito -= 9;
            }
        }
        soma += digito; // adiciona o dígito à soma total
    }

    // verifica se a soma é um múltiplo de 10
    if (soma % 10 == 0)
    {
        printf("Número de cartão válido.\n");
    }
    else
    {
        printf("Número de cartão inválido.\n");
    }
}

void verifica_bandeira(string str_numero)
{

    // verifica a bandeira do cartão com base nos primeiros dígitos
    if (str_numero[0] == '4')
    {
        printf("Bandeira: Visa\n");
    }
    else if (str_numero[0] == '5' && (str_numero[1] >= '1' && str_numero[1] <= '5'))
    {
        printf("Bandeira: Mastercard\n");
    }
    else if (str_numero[0] == '3' && (str_numero[1] == '4' || str_numero[1] == '7'))
    {
        printf("Bandeira: American Express\n");
    }
    else
    {
        printf("Bandeira: Desconhecida\n");
    }
}
