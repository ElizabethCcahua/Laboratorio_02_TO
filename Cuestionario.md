## Cuestionario

### Resolución de polinomios usando una lista enlazada

**Pregunta:**  
Proponer un pseudocódigo sobre la resolución de polinomios usando una lista enlazada. Por ejemplo:

**f(X) = 7X² + 2X + 1**

El pseudocódigo debe guardar los resultados obtenidos para diferentes valores de **X**.

### Pseudocódigo

```text
INICIO

    DEFINIR NodoTermino
        coeficiente
        exponente
        siguiente
    FIN DEFINIR

    DEFINIR NodoResultado
        valorX
        resultado
        siguiente
    FIN DEFINIR

    CREAR listaPolinomio
    CREAR listaResultados

    // Representar f(X) = 7X² + 2X + 1
    INSERTAR(listaPolinomio, 7, 2)
    INSERTAR(listaPolinomio, 2, 1)
    INSERTAR(listaPolinomio, 1, 0)

    LEER cantidadValores

    PARA i <- 1 HASTA cantidadValores HACER

        LEER X
        resultado <- 0
        actual <- inicio(listaPolinomio)

        MIENTRAS actual != NULL HACER
            resultado <- resultado +
                         actual.coeficiente * (X ^ actual.exponente)

            actual <- actual.siguiente
        FIN MIENTRAS

        INSERTAR_RESULTADO(listaResultados, X, resultado)

    FIN PARA

    actualResultado <- inicio(listaResultados)

    MIENTRAS actualResultado != NULL HACER

        ESCRIBIR "X = ", actualResultado.valorX,
                 " | f(X) = ", actualResultado.resultado

        actualResultado <- actualResultado.siguiente

    FIN MIENTRAS

FIN
```

### Explicación

El pseudocódigo representa cada término del polinomio mediante un nodo que almacena su **coeficiente, exponente y enlace al siguiente término**. Para cada valor ingresado de `X`, se recorre la lista enlazada y se calcula la suma de los términos mediante la expresión `coeficiente × X^exponente`.

Cada resultado obtenido se almacena en una segunda lista junto con el valor de `X` utilizado. Finalmente, esta lista se recorre para mostrar todos los valores evaluados y sus respectivos resultados, permitiendo conservar los resultados de diferentes evaluaciones del polinomio.

