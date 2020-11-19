/**
 * @file main.c
 * @author Fernando Francisco (you@domain.com)
 * @brief Aqruivo principal do projecto. Ponto de inicialização
 * @version 0.1
 * @date 2020-11-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "transport.h"

int main(int argc, char const *argv[])
{
    // fprintf(stdout, "Escreva os dados do transtporte: ");
    Transport *root = Init();
    double distance;
    char driver[64];
    char route[128];
    int packages;
    double weight_pp, max_weight;
    bool flag = false;
    int opt;

    while (!flag)
    {
        static int id = 1;

        fprintf(stdout, "Escolha uma opção:\n");
        Menu();
        fscanf(stdin, "%d", &opt);
        switch (opt)
        {
        case 1:
        {
            fprintf(stdout, "Escreva os dados:\nRouta (Partida-destino): ");
            fflush(stdin);
            fscanf(stdin, "%s", route);

            fprintf(stdout, "Motorista: ");
            fflush(stdin);
            fscanf(stdin, "%s", driver);

            fprintf(stdout, "Kilométros: ");
            fflush(stdin);
            fscanf(stdin, "%lf", &distance);

            fprintf(stdout, "Num pacotes: ");
            fflush(stdin);
            fscanf(stdin, "%d", &packages);

            fprintf(stdout, "Peso por pacotes: ");
            fflush(stdin);
            fscanf(stdin, "%lf", &weight_pp);

            fprintf(stdout, "Peso total do caminhão: ");
            fflush(stdin);
            fscanf(stdin, "%lf", &max_weight);
            for (int i = 0; i < 10; ++i)
                Add((id++), distance, route, driver, packages, weight_pp, max_weight, root);
        }
        break;
        case 2:
            Print(root);
            break;
        case 3:
            Free(root);
            break;
        case 4:
            flag = true;
            break;
        default:
            break;
        }
    }

    return 0;
}
