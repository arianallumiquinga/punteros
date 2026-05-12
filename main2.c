/*https://www.canva.com/design/DAHJaQsWgto/KL8HROy08IAAzXP5tSzJpw/edit*/
#include <stdio.h>
#include <string.h>

int main()
{
    int cantidad[5] = {0};
    int recurso[5] = {0};
    float tiempo[5] = {0};

    char nombreProducto[5][20];

    int cont = 0;
    int opc = 0;

    do
    {
        printf("\n\n\t----------Opciones-----------\n");
        printf("\t1. Agregar producto\n");
        printf("\t2. Editar producto\n");
        printf("\t3. Eliminar producto\n");
        printf("\t4. Calcular produccion\n");
        printf("\t5. Salir\n");
        printf(">> ");
        scanf("%d", &opc);
        while(getchar() != '\n');

        switch(opc)
        {

        case 1:

            if(cont >= 5)
            {
                printf("No se pueden registrar mas productos.\n");
                break;
            }

            printf("Ingrese el nombre del producto %d: ", cont + 1);
            fgets(nombreProducto[cont], 20, stdin);
            nombreProducto[cont][strcspn(nombreProducto[cont], "\n")] = '\0';

            printf("Ingrese la cantidad del producto %d: ", cont + 1);
            scanf("%d", &cantidad[cont]);

            printf("Ingrese el tiempo de produccion del producto %d: ", cont + 1);
            scanf("%f", &tiempo[cont]);

            printf("Ingrese el numero de recursos necesarios del producto %d: ", cont + 1);
            scanf("%d", &recurso[cont]);

            while(getchar() != '\n');

            cont++;

            printf("\nProducto registrado correctamente.\n");

            break;

        case 2:

            if(cont == 0)
            {
                printf("No existen productos registrados.\n");
                break;
            }

            printf("\nID\tNombre\t\tCantidad\tTiempo\tRecursos\n");

            for(int i = 0; i < cont; i++)
            {
                printf("%d\t%s\t\t%d\t\t%.2f\t%d\n",
                       i + 1,
                       nombreProducto[i],
                       cantidad[i],
                       tiempo[i],
                       recurso[i]);
            }

            char buscar[20];
            int encontrado = -1;

            printf("\nIngrese el nombre del producto a editar: ");
            fgets(buscar, 20, stdin);
            buscar[strcspn(buscar, "\n")] = '\0';

            for(int i = 0; i < cont; i++)
            {
                if(strcmp(nombreProducto[i], buscar) == 0)
                {
                    encontrado = i;
                    break;
                }
            }

            if(encontrado == -1)
            {
                printf("Producto no encontrado.\n");
            }
            else
            {
                printf("Nuevo nombre: ");
                fgets(nombreProducto[encontrado], 20, stdin);
                nombreProducto[encontrado][strcspn(nombreProducto[encontrado], "\n")] = '\0';

                printf("Nueva cantidad: ");
                scanf("%d", &cantidad[encontrado]);

                printf("Nuevo tiempo: ");
                scanf("%f", &tiempo[encontrado]);

                printf("Nuevo recurso: ");
                scanf("%d", &recurso[encontrado]);

                while(getchar() != '\n');

                printf("\nProducto editado correctamente.\n");
            }

            break;

        case 3:

            if(cont == 0)
            {
                printf("No existen productos registrados.\n");
                break;
            }

            printf("\nID\tNombre\t\tCantidad\tTiempo\tRecursos\n");

            for(int i = 0; i < cont; i++)
            {
                printf("%d\t%s\t\t%d\t\t%.2f\t%d\n",
                       i + 1,
                       nombreProducto[i],
                       cantidad[i],
                       tiempo[i],
                       recurso[i]);
            }

            char eliminar[20];
            int pos = -1;

            printf("\nIngrese el nombre del producto a eliminar: ");
            fgets(eliminar, 20, stdin);
            eliminar[strcspn(eliminar, "\n")] = '\0';

            for(int i = 0; i < cont; i++)
            {
                if(strcmp(nombreProducto[i], eliminar) == 0)
                {
                    pos = i;
                    break;
                }
            }

            if(pos == -1)
            {
                printf("Producto no encontrado.\n");
            }
            else
            {
                nombreProducto[pos][0] = '\0';
                cantidad[pos] = 0;
                tiempo[pos] = 0;
                recurso[pos] = 0;

                printf("Producto eliminado correctamente.\n");
            }

            break;

        case 4:

            {
                float tiempoDisponible;
                int recursosDisponibles;

                float tiempoTotal = 0;
                int recursosTotales = 0;

                printf("\n--- CALCULO DE PRODUCCION ---\n");

                printf("Ingrese el tiempo disponible de la fabrica: ");
                scanf("%f", &tiempoDisponible);

                printf("Ingrese los recursos disponibles: ");
                scanf("%d", &recursosDisponibles);

                for(int i = 0; i < cont; i++)
                {
                    tiempoTotal += cantidad[i] * tiempo[i];
                    recursosTotales += cantidad[i] * recurso[i];
                }

                printf("\nTiempo total requerido: %.2f\n", tiempoTotal);
                printf("Recursos totales requeridos: %d\n", recursosTotales);

                if(tiempoTotal <= tiempoDisponible &&
                   recursosTotales <= recursosDisponibles)
                {
                    printf("\nLa fabrica SI puede cumplir con la demanda.\n");
                }
                else
                {
                    printf("\nLa fabrica NO puede cumplir con la demanda.\n");
                }

                while(getchar() != '\n');
            }

            break;

        case 5:

            printf("Salida exitosa.\n");
            break;

        default:

            printf("Opcion no valida.\n");
        }

    } while(opc != 5);

    return 0;
}
