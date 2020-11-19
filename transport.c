/**
 * @file transport.c
 * @author Fersnando Francisco (jambafernandofr@gmail.com)
 * @brief Arquivo para a definição dos mêtodos para manipular uma viagem
 * @version 0.1
 * @date 2020-11-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "transport.h"

Transport *
Init()
{
    Transport *pointer = malloc(sizeof(Transport));
    if (!pointer)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    memset(pointer, 0, sizeof(Transport));
    return pointer;
}
Transport *
Add(int id, double d, char *route, char *dr, int p, double w, double m_w, Transport *trans)
{
    Transport *root, *temp;
    if (!trans)
    {
        temp = Init();
        temp = temp->next;
        strncpy(temp->route, route, sizeof(temp->route));
        strncpy(temp->driver, dr, sizeof(temp->driver));
        temp->id = id;
        temp->distance = d;
        temp->packages = p;
        temp->weight_per_package = w;
        temp->max_weight = m_w;
        root = temp;
        temp = NULL;
        free(temp);
        return root;
    }
    else
    {
        temp = trans;
        while (temp->next)
        {
            if (!temp->next)
            {
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
        temp->next = Init();
        strncpy(temp->route, route, sizeof(temp->route));
        strncpy(temp->driver, dr, sizeof(temp->driver));
        temp->id = id;
        temp->distance = d;
        temp->packages = p;
        temp->weight_per_package = w;
        temp->max_weight = m_w;
        root = temp;
        temp = NULL;
        free(temp);
        return root;
    }
}
void Print(Transport *trans)
{
    system("clear");

    while (trans)
    {
        if (trans->id > 0)
        {
            fflush(stdout);
            double total_weight = trans->packages * trans->weight_per_package;
            double percentage = total_weight / trans->max_weight;
            if (total_weight <= ((4.0 / 10) * trans->max_weight))
            {
                fprintf(stdout, "%d  - A carga ocupa %.2f\nVelocidade máxima permitida é de 80 km/h\n",
                        trans->id, (percentage * 100));
            }
            else if ((total_weight >= (4.0 / 10) * trans->max_weight) && (total_weight <= (7.0 / 10) * trans->max_weight))
            {
                fprintf(stdout, "%d  - A carga ocupa %.2f\nVelocidade máxima permitida é de 70 km/h\n",
                        trans->id, (percentage * 100));
            }
            else if ((total_weight >= (7.0 / 10) * trans->max_weight) && (total_weight <= trans->max_weight))
            {
                fprintf(stdout, "%d  - A carga ocupa %.2f\nVelocidade máxima permitida é de 60 km/h\n",
                        trans->id, (percentage * 100));
            }
            else
            {
                fprintf(stdout, "%d  - O peso da sua carga é inválida para este caminhão\n", trans->id);
                fprintf(stdout, "Peso máximo permitido %.2f, o peso da sua carga %.2f, necessita de mais %.2f\n",
                        trans->max_weight, total_weight, (total_weight - trans->max_weight));
            }
            fprintf(stdout, "Dados gerais da viagem:\n\tRouta %s\n\tMotorista %s\n\tKilemétros %.2f\n\t",
                    trans->route, trans->driver, trans->distance);
            fprintf(stdout, "Pacotes %d\n\tPeso por pacotes %.2f\n\tPeso total da carga %.2f\n",
                    trans->packages, trans->weight_per_package, total_weight);
            fprintf(stdout, "\tCarga máxima do caminhão %.2f\n", trans->max_weight);
            total_weight <= trans->max_weight ? fprintf(stdout, "\tEspaço que sobra %.2f\n\tBoa viagem\n",
                                                        (trans->max_weight - total_weight))
                                              : fprintf(stdout, "\tViagem cancelada\n");
        }

        trans = trans->next;
    }
}

void Free(Transport *trans)
{
    Transport *next;
    while (trans)
    {
        if (trans->next)
        {
            next = trans->next;
            free(trans);
            trans = next;
        }
        else
        {
            free(trans);
            trans = NULL;
        }
    }
}

bool DeleteTransport(int id, Transport trans)
{
}
void Menu(void)
{
    fprintf(stdout, "1 - Adicionar viagem\n2 - Imprimir viagens\n3 - Apagar viagem\n4 - Sair\n");
}