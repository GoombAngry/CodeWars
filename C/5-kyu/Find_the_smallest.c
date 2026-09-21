#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Representara cada resultado para luego filtrarlos por el numero mas bajo registrado
struct Result {
    long long number;
    size_t i;
    size_t j;
};


// Obtienes el listado de los numeros mas bajos
struct Filter{
    struct Result* resultados;
    size_t length;
};

char* longToString(long long n){
    char* final = NULL;
    char* tmp = NULL;
    size_t size = 0;
    while((unsigned) (n / (long long)10) != 0 || n != 0){
        unsigned char aux = (unsigned) (n % (long long)10) + '0';
        size++;
        if(!final){
            final = calloc(size,sizeof(char));
            if(!final) return NULL;
            final[size-1] = aux;
        }else{
            tmp = realloc(final,size*sizeof(char));
            if(!tmp){
                free(final);
                return NULL;
            }
            final = tmp;
            final[size-1] = aux;
        }
        n/=10;
    }
    tmp = realloc(final,(size+1)*sizeof(char));
    if(!tmp){
        free(final);
        return NULL;
    }
    final = tmp;
    final[size] = '\0';

    return final;
}

void reverserString(char* cadena){
    if(!cadena) return;
    size_t length = strlen(cadena)+1;
    char* aux = malloc(length*sizeof(char)); // Reserve NULL BYTE include!
    if(!aux) return;
    aux[length-1] = '\0';

    memcpy(aux,cadena,length); // Copy full bytes from cadena to aux

    size_t index = 0;
    for (int i = strlen(cadena) - 1; i >= 0; i--)
    {
        cadena[index] = aux[i];
        index++;
    }
    free(aux);

}

long long stringToLong(const char* cadena){
    size_t s = strlen(cadena)-1;
    long long result = 0;
    const char* tmp = cadena;
    while(*(tmp) != '\0'){
        result += (*(tmp) - '0') * (long long)pow(10,s);
        s--;
        tmp++;
    }
    tmp = NULL;
    return result;
}

long long moveDigit(char* cadena,size_t from, size_t to){
    if(!cadena) return 0;
    size_t cadena_length = strlen(cadena)-1;
    // if(from < 0 || from > cadena_length || to < 0 || to > cadena_length || from == to)
    if (from > cadena_length || to > cadena_length || from == to) return stringToLong(cadena);
    size_t g = strlen(cadena)+1;
    char* copy = calloc(g,sizeof(char));
    if(!copy) return 0;
    memcpy(copy,cadena,g); // Copiamos la cadena original a una aux para trabajar sobre la aux
    
    for (size_t i = from; (from > to)?(i > to):((i < to)); (from > to)?(i--):(i++))
    {
        char p = copy[i];
        copy[i] = copy[(from > to)?(i-1):(i+1)];
        copy[(from > to)?(i-1):(i+1)] = p;
    }
    long long r = stringToLong(copy);
    free(copy);
    return r;
}

struct Filter* filterResults(struct Result* results,size_t length_results,long long lowerNumber){
    if(!results) return NULL;
    struct Filter* filtro = calloc(1,sizeof(struct Filter));
    struct Result* tmp = NULL;
    if(!filtro) return NULL;
    for (size_t i = 0; i < length_results; i++)
    {
        if(results[i].number == lowerNumber){
            filtro->length++;
            if(!filtro->resultados){
                filtro->resultados = calloc(filtro->length,sizeof(struct Result));
                if(!filtro->resultados) return NULL;
            }else{
                tmp = realloc(filtro->resultados,filtro->length*sizeof(struct Result));
                if(!tmp){
                    free(filtro->resultados);
                    filtro->resultados = NULL;
                    return NULL;
                }
                filtro->resultados = tmp;
            }
            filtro->resultados[filtro->length-1] = results[i];
        }
    }
    tmp = NULL;

    // Other filtro
    
    for (size_t i = 0; i < filtro->length; i++)
    {
        while(i!=0 && filtro->resultados[i].i < filtro->resultados[i-1].i){
            struct Result copy = filtro->resultados[i];
            filtro->resultados[i] = filtro->resultados[i-1];
            filtro->resultados[i-1] = copy;
        }
    }
    return filtro;
}

long long *smallest(long long n) {
    if(n <= 0){
        return calloc(3,sizeof(long long));
    }
    char* original = longToString(n);
    if(!original) return malloc(3 * sizeof(long long));
    reverserString(original); // Original number in char*
    
    long long lower = stringToLong(original);
    size_t n_results = 1,length = strlen(original);
    struct Result* resultados = calloc(n_results,sizeof(struct Result));
    if(!resultados) return malloc(3 * sizeof(long long));
    resultados[0].i = 0;
    resultados[0].j = 0;
    resultados[0].number = lower;
    struct Result* tmp = NULL;

    for (size_t i = 0; i < length ; i++)
    {
        for (size_t j = 0; j < length; j++)
        {
            if(i != j){     
                n_results++;
                if(!resultados){
                    resultados = calloc(n_results,sizeof(struct Result));
                    if(!resultados) return malloc(3 * sizeof(long long));
                }else{
                    tmp = realloc(resultados,n_results*sizeof(struct Result));
                    if(!tmp){
                        free(resultados);
                        return malloc(3 * sizeof(long long));
                    }
                    resultados = tmp;
                }
                long long iter = moveDigit(original,i,j);
                lower = (lower == 0)?iter:(iter < lower)?iter:lower;
                resultados[n_results-1].i = i;
                resultados[n_results-1].j = j;
                resultados[n_results-1].number = iter;
                
            }
        }
        
    }

    struct Filter* filtro = filterResults(resultados,n_results,lower);
    if(!filtro) return malloc(3 * sizeof(long long));
    free(resultados); 

    // --------------- Seteando resultado ----------------------
    long long* r = calloc(3,sizeof(long long));
    if(!r) return malloc(3 * sizeof(long long));
    r[0] = filtro->resultados[0].number;
    r[1] = filtro->resultados[0].i;
    r[2] = filtro->resultados[0].j;
    
    free(filtro->resultados); // Liberamos los resultados dentro del filtro
    free(filtro); // Liberamos memoria del filtro
    free(original); // Liberamos el contenedor alphanumerico del long long
    return r;
}

int main(){
    
    long long* r = smallest(123456789);
    printf("[%lld, %lld, %lld]\n",r[0],r[1],r[2]);
    
    return EXIT_SUCCESS;
}