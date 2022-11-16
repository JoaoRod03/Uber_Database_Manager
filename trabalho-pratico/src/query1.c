/**
 * @file query1.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 1.
 * 
 */

#include "../include/query1.h"

void query1 (int counter, Driver *drivers_cat, User *users_cat, Ride *rides_cat, char *id) {
        if (isDriver(id, strlen(id))) {
            int id_driver = atoi(id);                           // Converter string id do input para int
            Driver q1_d = drivers_cat[id_driver];               // Ir buscar o driver pretendido pelo ID ao Catálogo

            // Calcula a taxa base e a taxa por distância de acordo com a classe do carro
            float taxa_base;
            if (strcpy(q1_d.car_class, "basic")) taxa_base = 3.25;
                else if (strcmp(q1_d.car_class, "green") == 0) taxa_base = 4;
                else if (strcmp(q1_d.car_class, "premium") == 0) taxa_base = 5.2;
            float taxa_dist;
            if (strcpy(q1_d.car_class, "basic")) taxa_dist = 0.62;
                else if (strcmp(q1_d.car_class, "green") == 0) taxa_dist = 0.79;
                else if (strcmp(q1_d.car_class, "premium") == 0) taxa_dist = 0.94;


            char avaliacao_media[15]; int total_avaliacoes = 0; double av_media = 0;
            char numero_viagens[10]; int num_viagens = 0;
            char total_auferido[15]; double tot_auferido = 0;

            // for loop que percorre o catálogo das Rides, e se cada ride for do Driver pretendido, faz os devidos cálculos
            for (int i = 1; i <= 1000000; i++) {
                if (strcmp(rides_cat[i].driver, id) == 0) {
                    total_avaliacoes += atoi(rides_cat[i].score_driver);
                    num_viagens++;
                    tot_auferido += atoi(rides_cat[i].distance) * taxa_dist + taxa_base;
                }
            }
            // Se o número de viagens for 0, o divisor será 0, logo iria dar erro. Logo, a avaliação média é imediatamente 0
            if (num_viagens != 0) av_media = (double) total_avaliacoes / (double) num_viagens;
            else av_media = 0;

            // Colocar nas respetivas strings os valores devidos, para posteriormente juntar tudo na string output
            sprintf(avaliacao_media, "%.3f", av_media);
            sprintf(numero_viagens, "%i", num_viagens);
            sprintf(total_auferido, "%.3f", tot_auferido);

            char output[150];
            sprintf(output, "%s;%s;%i;%s;%s;%s", q1_d.name, q1_d.gender, age(q1_d.birth_date), avaliacao_media, numero_viagens, total_auferido);
            handle_outputs(counter, output);
        }
        else {                                                      // Se não for Driver / Se for User

            User q1_u;                                              // Definição do User pretendido
            for (int i = 1; i <= 100000; i++) {                     // Procura no catálogo dos users as informações do User pretendido
                if (strcmp(users_cat[i].user, id) == 0) q1_u = users_cat[i];
            }
           
            int taxa_dist, taxa_base;
            char avaliacao_media[15]; int total_avaliacoes = 0; double av_media = 0;
            char numero_viagens[10]; int num_viagens = 0;
            char total_gasto[15]; double tot_gasto = 0;

            // for loop que percorre o catálogo das Rides, e se cada ride for do User pretendido, faz os devidos cálculos
            for (int i = 1; i <= 1000000; i++) {
                if (strcmp(rides_cat[i].user, id) == 0) {
                    total_avaliacoes += atoi(rides_cat[i].score_user);
                    num_viagens++;
                    // Calcula a taxa base e a taxa por distância de acordo com a classe do carro do Driver dessa Ride
                    if (strcmp(drivers_cat[atoi(rides_cat[i].driver)].car_class, "basic") == 0) taxa_base = 3.25;
                        else if (strcmp(drivers_cat[atoi(rides_cat[i].driver)].car_class, "green") == 0) taxa_base = 4;
                        else if (strcmp(drivers_cat[atoi(rides_cat[i].driver)].car_class, "premium") == 0) taxa_base = 5.2;
                    if (strcmp(drivers_cat[atoi(rides_cat[i].driver)].car_class, "basic") == 0) taxa_dist = 0.62;
                        else if (strcmp(drivers_cat[atoi(rides_cat[i].driver)].car_class, "green") == 0) taxa_dist = 0.79;
                        else if (strcmp(drivers_cat[atoi(rides_cat[i].driver)].car_class, "premium") == 0) taxa_dist = 0.94;
                    tot_gasto += atoi(rides_cat[i].distance) * taxa_dist + taxa_base;
                }
            }
            
            // Se o número de viagens for 0, o divisor será 0, logo iria dar erro. Logo, a avaliação média é imediatamente 0
            if (num_viagens != 0) av_media = (double) total_avaliacoes / (double) num_viagens;
            else av_media = 0;

            // Colocar nas respetivas strings os valores devidos, para posteriormente juntar tudo na string output
            sprintf(avaliacao_media, "%.3f", av_media);
            sprintf(numero_viagens, "%i", num_viagens);
            sprintf(total_gasto, "%.3f", tot_gasto);

            char output[150];
            sprintf(output, "%s;%s;%i;%s;%s;%s", q1_u.name, q1_u.gender, age(q1_u.birth_date), avaliacao_media, numero_viagens, total_gasto);
            handle_outputs(counter, output);
        }
}