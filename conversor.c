#include <stdio.h>

// Tasas de cambio (valores aproximados, puedes actualizarlos)
#define USD_TO_GTQ 7.80
#define EUR_TO_GTQ 8.50
#define GTQ_TO_USD (1.0 / USD_TO_GTQ)
#define GTQ_TO_EUR (1.0 / EUR_TO_GTQ)
#define USD_TO_EUR 0.90
#define EUR_TO_USD (1.0 / USD_TO_EUR)

// Función para convertir monedas
double convertir(double monto, char origen, char destino) {
    if (origen == destino) {
        return monto; // No hay conversión si son la misma moneda
    }
    
    switch (origen) {
        case 'Q': // Quetzales
            if (destino == 'U') return monto * GTQ_TO_USD;
            if (destino == 'E') return monto * GTQ_TO_EUR;
            break;
        case 'U': // Dólares
            if (destino == 'Q') return monto * USD_TO_GTQ;
            if (destino == 'E') return monto * USD_TO_EUR;
            break;
        case 'E': // Euros
            if (destino == 'Q') return monto * EUR_TO_GTQ;
            if (destino == 'U') return monto * EUR_TO_USD;
            break;
    }
    
    return -1; // Indica error en conversión
}

int main() {
    char origen, destino;
    double monto, resultado;
    
    printf("=== Conversor de Monedas ===\n");
    printf("Opciones:\n");
    printf("Q - Quetzales (GTQ)\n");
    printf("U - Dólares (USD)\n");
    printf("E - Euros (EUR)\n");

    // Selección de moneda de origen
    printf("\nIngrese la moneda de origen (Q/U/E): ");
    scanf(" %c", &origen);

    // Selección de moneda de destino
    printf("Ingrese la moneda de destino (Q/U/E): ");
    scanf(" %c", &destino);

    // Monto a convertir
    printf("Ingrese la cantidad a convertir: ");
    scanf("%lf", &monto);

    // Realizar conversión
    resultado = convertir(monto, origen, destino);

    // Mostrar resultado
    if (resultado != -1) {
        printf("\n%.2f %c equivale a %.2f %c\n", monto, origen, resultado, destino);
    } else {
        printf("\nError: Moneda inválida.\n");
    }

    return 0;
}
