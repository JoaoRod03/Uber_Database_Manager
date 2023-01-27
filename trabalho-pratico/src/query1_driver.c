/**
 * @file query1_driver.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 1, caso seja Driver.
 * 
 */

#include "../include/query1_driver.h"

void query1_driver (int counter, char *id, int mode) {
    //printf("\nA executar Q1 (linha de input %i)\n", counter);

    // Se o driver não existir
    if (!is_driver(id)) {
        if (mode == 1) puts("\nResultado: Driver não existe!\n");
        if (mode == 0) handle_outputs(counter, "");
        return;
    }

    // Se o Driver estiver inativo
    if (stricmp(get_driver_status(id), "inactive") == 0) {
        if (mode == 1) puts("\nResultado: Driver inativo!\n");
        if (mode == 0) handle_outputs(counter, "");
        return;
    }

    // Calcula a taxa base e a taxa por distância de acordo com a classe do carro
    float taxa_base, taxa_dist;
    if (stricmp(get_driver_car_class(id), "basic") == 0) {
        taxa_base = 3.25;
        taxa_dist = 0.62;
    }
    else if (stricmp(get_driver_car_class(id), "green") == 0) {
        taxa_base = 4;
        taxa_dist = 0.79;
    }
    else if (stricmp(get_driver_car_class(id), "premium") == 0) {
        taxa_base = 5.2;
        taxa_dist = 0.94;
    }

    int total_avaliacoes = 0; double av_media = 0;
    int num_viagens = 0;
    double tot_auferido = 0;

    // for loop que percorre o catálogo das Rides, e se cada ride for do Driver pretendido, faz os devidos cálculos
    for (int i = 1; i <= get_nr_rides(); i++) {
        if (stricmp(get_ride_driver(i), id) == 0) {
            total_avaliacoes += atof(get_ride_score_driver(i));
            num_viagens++;
            tot_auferido += atof(get_ride_distance(i)) * taxa_dist + taxa_base + atof(get_ride_tip(i));
        }
    }
    // Se o número de viagens for 0, o divisor será 0, logo iria dar erro. Logo, a avaliação média é imediatamente 0
    if (num_viagens != 0) av_media = (double) total_avaliacoes / (double) num_viagens;
    else av_media = 0;

    char output[150];
    sprintf(output, "%s;%s;%i;%.3f;%i;%.3f\n", get_driver_name(id), get_driver_gender(id), age(get_driver_birth_date(id)), av_media, num_viagens, tot_auferido);
    if (mode == 1) puts("\nForma do Resultado: nome;genero;idade;avaliacao_media;numero_viagens;total_auferido");
    if (mode == 1) printf("Resultado: %s\n",output);
    if (mode == 0) handle_outputs(counter, output);
}