/*
 * cpu.h
 *
 *  Created on: Sep 2, 2023
 *      Author: utnso
 */

#ifndef SRC_CPU_H_
#define SRC_CPU_H_

#include<stdio.h>
#include<stdlib.h>
#include<commons/log.h>
#include<commons/string.h>
#include<commons/config.h>
#include<readline/readline.h>
#include <utils/hello.h>

t_log* logger;
t_config* config;

int conexion_memoria;
char *ip_memoria;
char *puerto_memoria;
char *puerto_escucha_dispatch;
char *puerto_escucha_interrupt;
int conexion_memoria;

t_contexto_ejecucion* pcb;


//variable que uso en global
bool recibi_archivo;
bool hay_desalojo;
bool hay_finalizar;
bool hayInterrupcion;
bool instruccion_ejecutando;

t_contexto_ejecucion * contexto_ejecucion;
t_instruccion* instruccion_a_realizar;

typedef enum{
	AX,
	BX,
	CX,
	DX,
    EAX,
    EBX,
    ECX,
    EDX,
    SI,
    DI
}t_estrucutra_cpu;

typedef struct{
	int marco;
	int desplazamiento;
	int nro_pagina;
}t_traduccion;



//semaforos
sem_t contador_instruccion;
pthread_mutex_t contador_marco_obtenido;


int marco_obtenido;
int tamanio_pagina;

void obtener_configuracion();
void procesar_conexion(void *conexion1);
void iniciar_servidor_cpu();
void generar_conexion_memoria();
void ejecutar_ciclo_de_instruccion(int cliente_fd);
void iniciar_servidor_interrupt(char * puerto);
void transformar_en_instrucciones(char* auxiliar);
char** parsear_instruccion(char* instruccion);
void fetch(int cliente_fd);
void decode(t_instruccion* instrucciones,int cliente_fd);
void solicitar_instruccion_ejecutar_segun_pc(int pc,int pid);
void enviar_recurso_a_kernel(char* recurso, op_code operacion, int cliente_fd);

t_estrucutra_cpu devolver_registro(char* registro);
void setear(t_estrucutra_cpu pos, uint32_t valor) ;
uint32_t obtener_valor(t_estrucutra_cpu pos);



#endif /* SRC_CPU_H_ */
