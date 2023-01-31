/**
 * @file tests.c
 *  Este ficheiro contém as funções relacionadas com os testes funcionais e de desempenho.
 * 
 */

#include <time.h>

#include "../include/query1.h"
#include "../include/query2.h"
#include "../include/query3.h"
#include "../include/query4.h"
#include "../include/query5.h"
#include "../include/query6.h"
#include "../include/query7.h"
#include "../include/query8.h"
#include "../include/query9.h"

struct driver_struct {
    Driver* driverscat;
    GHashTable* drivershash;
};

struct user_struct {
    User* userscat;
    GHashTable* usershash;
};

void check(int counter, char *dataset) {
    char filename[30], filepath[60], resultfile[50];
    sprintf(filename, "command%d_output.txt", counter);
    sprintf(resultfile, "Resultados/%s", filename);

    if (strcmp(dataset, "rwo") == 0) sprintf(filepath, "Datasets/R-WITHOUT/outputs/%s", filename);
    if (strcmp(dataset, "rw") == 0) sprintf(filepath, "Datasets/R-WITH/outputs/%s", filename);
    if (strcmp(dataset, "lwo") == 0) sprintf(filepath, "Datasets/L-WITHOUT/outputs/%s", filename);
    if (strcmp(dataset, "lw") == 0) sprintf(filepath, "Datasets/L-WITH/outputs/%s", filename);

    FILE *expected = fopen(filepath, "r");
    FILE *result = fopen(resultfile, "r");
    if (compare(expected, result)) printf("Test %d passed ✅\n", counter);
        else printf("Test %d failed ❌\n", counter);
}

void q1_test(int counter, char *id, char *dataset) {
    query1(counter, id, 3);
    check(counter, dataset);
}

void q2_test(int counter, char *input, char *dataset) {
    query2(counter, input, 3);
    check(counter, dataset);
}

void q3_test(int counter, char *input, char *dataset) {
    query3(counter, input, 3);
    check(counter, dataset);
}

void q4_test(int counter, char *input, char *dataset) {
    query4(counter, input, 3);
    check(counter, dataset);
}

void q5_test(int counter, char *data1, char *data2, char *dataset) {
    query5(counter, data1, data2, 3);
    check(counter, dataset);
}

void q6_test(int counter, char *input, char *dataset) {
    query6(counter, input, 3);
    check(counter, dataset);
}

void q7_test(int counter, char *input, char *dataset) {
    query7(counter, input, 3);
    check(counter, dataset);
}

void q8_test(int counter, char *input, char *dataset) {
    query8(counter, input, 3);
    check(counter, dataset);
}

void q9_test(int counter, char *data1, char *data2, char *dataset) {
    query9(counter, data1, data2, 3);
    check(counter, dataset);
}

void regular_without() {
    system("mkdir Resultados");                                               // Criar diretório para os Resultados
    FILE *inputs; inputs = fopen("Datasets/R-WITHOUT/inputs.txt", "r");
    FILE *drivers; drivers = fopen("Datasets/R-WITHOUT/drivers.csv", "r");
    FILE *users; users = fopen("Datasets/R-WITHOUT/users.csv", "r");
    FILE *rides; rides = fopen("Datasets/R-WITHOUT/rides.csv", "r");

    driver_struct drivers_struct = inserir_drivers(drivers);
    user_struct users_struct = inserir_users(users);
    Ride* rides_cat = inserir_rides(rides);

    fclose(drivers);
    fclose(users);
    fclose(rides);

    int counter = 1;

    char *input; input = malloc(100 * sizeof(char));
    while (fgets(input, 100, inputs)) {
        if (strchr(input, '\n')) *(strchr(input, '\n')) = '\0';                             // Trocar '\n' por '\0' na string input
        
        if (input[0] == '1') q1_test(counter, input + 2, "rwo");
        else if (input[0] == '2') q2_test(counter, input + 2, "rwo");
        else if (input[0] == '3') q3_test(counter, input + 2, "rwo");
        else if (input[0] == '4') q4_test(counter, input + 2, "rwo");
        else if (input[0] == '5') q5_test(counter, input + 2, input + 13, "rwo");
        else if (input[0] == '6') q6_test(counter, input + 2, "rwo");
        else if (input[0] == '7') q7_test(counter, input + 2, "rwo");                             // Tem de fazer parsing porque o tamanho da city varia
        else if (input[0] == '8') q8_test(counter, input + 2, "rwo");
        else if (input[0] == '9') q9_test(counter, input + 2, input + 13, "rwo");
        counter++;
    }

    free(drivers_struct.driverscat);
    free(users_struct.userscat);
    free(rides_cat);
    g_hash_table_destroy(users_struct.usershash);
    g_hash_table_destroy(drivers_struct.drivershash);
    fclose(inputs);
    free(input);
    system("rm -r Resultados");
}

void regular_with() {
    system("mkdir Resultados");                                               // Criar diretório para os Resultados
    FILE *inputs; inputs = fopen("Datasets/R-WITH/inputs.txt", "r");
    FILE *drivers; drivers = fopen("Datasets/R-WITH/drivers.csv", "r");
    FILE *users; users = fopen("Datasets/R-WITH/users.csv", "r");
    FILE *rides; rides = fopen("Datasets/R-WITH/rides.csv", "r");

    driver_struct drivers_struct = inserir_drivers(drivers);
    user_struct users_struct = inserir_users(users);
    Ride* rides_cat = inserir_rides(rides);

    fclose(drivers);
    fclose(users);
    fclose(rides);

    int counter = 1;

    char *input; input = malloc(100 * sizeof(char));
    while (fgets(input, 100, inputs)) {
        if (strchr(input, '\n')) *(strchr(input, '\n')) = '\0';                             // Trocar '\n' por '\0' na string input
        
        if (input[0] == '1') q1_test(counter, input + 2, "rw");
        else if (input[0] == '2') q2_test(counter, input + 2, "rw");
        else if (input[0] == '3') q3_test(counter, input + 2, "rw");
        else if (input[0] == '4') q4_test(counter, input + 2, "rw");
        else if (input[0] == '5') q5_test(counter, input + 2, input + 13, "rw");
        else if (input[0] == '6') q6_test(counter, input + 2, "rw");
        else if (input[0] == '7') q7_test(counter, input + 2, "rw");                             // Tem de fazer parsing porque o tamanho da city varia
        else if (input[0] == '8') q8_test(counter, input + 2, "rw");
        else if (input[0] == '9') q9_test(counter, input + 2, input + 13, "rw");
        counter++;
    }

    free(drivers_struct.driverscat);
    free(users_struct.userscat);
    free(rides_cat);
    g_hash_table_destroy(users_struct.usershash);
    g_hash_table_destroy(drivers_struct.drivershash);
    fclose(inputs);
    free(input);
    system("rm -r Resultados");
}

void large_without() {
    system("mkdir Resultados");                                               // Criar diretório para os Resultados
    FILE *inputs; inputs = fopen("Datasets/L-WITHOUT/inputs.txt", "r");
    FILE *drivers; drivers = fopen("Datasets/L-WITHOUT/drivers.csv", "r");
    FILE *users; users = fopen("Datasets/L-WITHOUT/users.csv", "r");
    FILE *rides; rides = fopen("Datasets/L-WITHOUT/rides.csv", "r");

    driver_struct drivers_struct = inserir_drivers(drivers);
    user_struct users_struct = inserir_users(users);
    Ride* rides_cat = inserir_rides(rides);

    fclose(drivers);
    fclose(users);
    fclose(rides);

    int counter = 1;

    char *input; input = malloc(100 * sizeof(char));
    while (fgets(input, 100, inputs)) {
        if (strchr(input, '\n')) *(strchr(input, '\n')) = '\0';                             // Trocar '\n' por '\0' na string input
        
        if (input[0] == '1') q1_test(counter, input + 2, "lwo");
        else if (input[0] == '2') q2_test(counter, input + 2, "lwo");
        else if (input[0] == '3') q3_test(counter, input + 2, "lwo");
        else if (input[0] == '4') q4_test(counter, input + 2, "lwo");
        else if (input[0] == '5') q5_test(counter, input + 2, input + 13, "lwo");
        else if (input[0] == '6') q6_test(counter, input + 2, "lwo");
        else if (input[0] == '7') q7_test(counter, input + 2, "lwo");                             // Tem de fazer parsing porque o tamanho da city varia
        else if (input[0] == '8') q8_test(counter, input + 2, "lwo");
        else if (input[0] == '9') q9_test(counter, input + 2, input + 13, "lwo");
        counter++;
    }

    free(drivers_struct.driverscat);
    free(users_struct.userscat);
    free(rides_cat);
    g_hash_table_destroy(users_struct.usershash);
    g_hash_table_destroy(drivers_struct.drivershash);
    fclose(inputs);
    free(input);
    system("rm -r Resultados");
}

void large_with() {
    system("mkdir Resultados");                                               // Criar diretório para os Resultados
    FILE *inputs; inputs = fopen("Datasets/L-WITH/inputs.txt", "r");
    FILE *drivers; drivers = fopen("Datasets/L-WITH/drivers.csv", "r");
    FILE *users; users = fopen("Datasets/L-WITH/users.csv", "r");
    FILE *rides; rides = fopen("Datasets/L-WITH/rides.csv", "r");

    driver_struct drivers_struct = inserir_drivers(drivers);
    user_struct users_struct = inserir_users(users);
    Ride* rides_cat = inserir_rides(rides);

    fclose(drivers);
    fclose(users);
    fclose(rides);

    int counter = 1;

    char *input; input = malloc(100 * sizeof(char));
    while (fgets(input, 100, inputs)) {
        if (strchr(input, '\n')) *(strchr(input, '\n')) = '\0';                             // Trocar '\n' por '\0' na string input
        
        if (input[0] == '1') q1_test(counter, input + 2, "lw");
        else if (input[0] == '2') q2_test(counter, input + 2, "lw");
        else if (input[0] == '3') q3_test(counter, input + 2, "lw");
        else if (input[0] == '4') q4_test(counter, input + 2, "lw");
        else if (input[0] == '5') q5_test(counter, input + 2, input + 13, "lw");
        else if (input[0] == '6') q6_test(counter, input + 2, "lw");
        else if (input[0] == '7') q7_test(counter, input + 2, "lw");                             // Tem de fazer parsing porque o tamanho da city varia
        else if (input[0] == '8') q8_test(counter, input + 2, "lw");
        else if (input[0] == '9') q9_test(counter, input + 2, input + 13, "lw");
        counter++;
    }

    free(drivers_struct.driverscat);
    free(users_struct.userscat);
    free(rides_cat);
    g_hash_table_destroy(users_struct.usershash);
    g_hash_table_destroy(drivers_struct.drivershash);
    fclose(inputs);
    free(input);
    system("rm -r Resultados");
}

int main() {
    puts("Regular Dataset Without Invalid Entries:");
    regular_without();
    puts("-------------------------------------------");
    puts("Regular Dataset With Invalid Entries:");
    regular_with();
    puts("-------------------------------------------");
    puts("Large Dataset Without Invalid Entries:");
    large_without();
    puts("-------------------------------------------");
    puts("Large Dataset With Invalid Entries:");
    large_with();
    puts("-------------------------------------------");
}