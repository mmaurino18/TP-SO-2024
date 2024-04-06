#ifndef GLOBAL_H_
#define GLOBAL_H_
#include <commons/collections/queue.h>
#include <semaphore.h>
#include <pthread.h>
#include "utils/hello.h"
#include <commons/collections/list.h> 


typedef struct
{
    t_queue *cola;
    pthread_mutex_t sem_mutex;
} t_cola;
typedef struct{
    char* nombre;
    int instancias;
    t_cola* cola_bloqueados;
}t_recurso;

typedef struct{
    char* nombre;
    int instancias;
    int pid;
}t_recurso_pcb;

typedef enum{
	FIFO,
	RR,
	VRR
}t_planificador;

extern sem_t sem_new;
extern sem_t sem_ready;
extern sem_t sem_grado_multiprogramacion;
extern pthread_mutex_t sem_exec;
extern pthread_mutex_t sem_detener;
extern t_cola * cola_new;
extern t_cola * cola_ready;
extern t_cola * cola_blocked;

extern int grado_multiprogramacion_ini;
extern int contador_pcb;
extern bool detener;
extern t_log* logger;
extern t_config* config;
extern t_planificador planificador;
extern int conexion_memoria;
extern int conexion_cpu;
extern int conexion_cpu_interrupt;
extern int quantum;
extern char ** recursos_config;
extern char ** instancias_recursos_config;
extern t_list * lista_recursos;
extern t_list * lista_recursos_pcb;
extern pthread_t hilo_planificador_largo_plazo;
extern pthread_t hilo_planificador_corto_plazo;
extern pthread_t hilo_conexion_memoria;
extern pthread_t hilo_conexion_cpu;
extern pthread_t hilo_conexion_cpu_interrupt;
extern t_pcb * running;

//

void asignar_algoritmo(char *);
void obtener_configuracion();
void inicializar_recursos();
void recibir_mensaje(int);
t_cola * inicializar_cola();
void inicializar_estructuras();
void crear_proceso();
t_contexto_ejecucion * crear_contexto();
void liberar_proceso(t_pcb * );
char* estado_a_string(t_estado );

#endif