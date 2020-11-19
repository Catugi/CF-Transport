/**
 * @file transport.h
 * @author your name (you@domain.com)
 * @brief Header do projecto. Aqui são definidas as funções posteriormente usados no 
 *          projecto
 * @version 0.1
 * @date 2020-11-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _transport Transport;
struct _transport
{
    int id : 13;
    char route[64];
    double distance;
    char driver[64];
    int packages;
    double weight_per_package;
    double max_weight;
    Transport *next;
};

Transport *Init();
Transport *Add(int id, double d, char *route, char *dr, int p, double w, double m_w, Transport *trans);
void Print(Transport *trans);
void Free(Transport *trans);
void Menu(void);
bool DeleteTransport(int id, Transport trans);
