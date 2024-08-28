#include <stdio.h>
int main(int c, char* argv[]) {
    if (remove(argv[1]) == 0)
        printf("El archivo se elimino exitosamente");
    else
        printf("No se pudo eliminar el archivo");
    return 0;
}
