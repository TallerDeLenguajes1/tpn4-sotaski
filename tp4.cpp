#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Tarea {
    int TareaID;          //Numerado en ciclo iterativo
    char *Descripcion; //
    int Duracion;        // entre 10 – 100
}tareas;

typedef struct Nodo{
	tareas T;	
    Nodo *Siguiente;
}ListaTarea;

void CargarTareas(tareas *_tarea, int cant);
void Mover(tareas *tPendiente, tareas *tRealizda, int cant);//   PUNTO 3
void MostrarTareas(tareas *_tarea, int cant);//                  PUNTO 4

int main(){
    int cant = 0;
    printf("Ingrese la cantidad de tareas a realizar: ");
    scanf("%d", &cant);
    fflush(stdin);
    
    tareas *TareasPendientes = (tareas*) malloc(sizeof(tareas) *cant);
    tareas *TareasRealizadas = (tareas*) malloc(sizeof(tareas) *cant);

    CargarTareas(TareasPendientes, cant); 

    printf("\n\n\nTODAS LAS TAREAS\n");
    MostrarTareas(TareasPendientes, cant);
    

    Mover(TareasPendientes, TareasRealizadas, cant); 
    printf("\n\n\nTODAS LAS TAREAS REALIZADAS\n");
    MostrarTareas(TareasRealizadas, cant);


    printf("\n\n\nTODAS LAS TAREAS PENDIENTES\n");
    MostrarTareas(TareasPendientes, cant);


  

    getchar();
    return 0;
}

void CargarTareas(tareas *_tarea, int _cant){
    char descrip[200];
    int tamanio= 0;
    for (int i = 0; i < _cant; i++)
    {
        
        _tarea[i].TareaID = i + 1;
        
        printf("\nla descripcion de la tarea con ID %d: ", _tarea[i].TareaID);
        gets(descrip);   
        _tarea[i].Descripcion = (char *) malloc(sizeof(char) * strlen(descrip)); 
        strcpy( _tarea[i].Descripcion, descrip);     

        fflush(stdin);
        _tarea[i].Duracion = rand() % 101 + 10; 

    }
    
}

void Mover(tareas *tPendiente, tareas *tRealizda, int cant){
    int j = 0;
    int respuesta = 0;

    for (int i = 0; i < cant; ++i)
    {
        printf("\n\nLa tarea con ID %d fue ralizad(0 = NO y 1 = SI): ", tPendiente[i].TareaID);
        scanf("%d", &respuesta);
        if (respuesta == 1)
        {
            tRealizda[j] = tPendiente[i];
            j++; 
            tPendiente[i].TareaID= NULL;
            tPendiente[i].Descripcion = NULL;
            tPendiente[i].Duracion = NULL;
        }    
    
    }

}

void MostrarTareas(tareas *_tarea, int cant){
    for (int i = 0; i < cant; ++i)
    {
         printf("\ntarea %d", _tarea[i].TareaID);
         printf("\nTipo de tarea: ");
         puts(_tarea[i].Descripcion);
         printf("Tiempo de duracion: %d nimutos", _tarea[i].Duracion);
    }
   
}



