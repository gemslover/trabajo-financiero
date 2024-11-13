# Software de Cálculo Financiero en C++

Este es un proyecto respecto un programa en C++ diseñado para realizar cálculos financieros básicos como:

- **Tasa Interna de Retorno (TIR)**
- **Amortización Decreciente**
- **Intereses Simples y Compuestos**

Este software es útil para aquellos que buscan analizar sus inversiones y tomar decisiones financieras informadas con conocimientos basicos y principiantes:

## Funcionalidades

### 1. Tasa Interna de Retorno (TIR)
El proyecto se permite calcular la Tasa Interna de Retorno (TIR) de un conjunto de flujos de efectivo. El cálculo de la TIR es crucial para evaluar la rentabilidad de una inversión. 
La fórmula utilizada para este cálculo toma en cuenta los flujos de caja y determina la tasa de descuento que hace que el valor neto presente (NPV) sea cero.

### 2. Amortización Decreciente
El software tambien tiene la capacidad de calcular la amortización decreciente de una deuda o préstamo a lo largo del tiempo, lo que es útil para analizar los pagos de un préstamo a lo largo de distintos períodos.

### 3. Intereses Simples y Compuestos
Se incluye lo que son los cálculos de intereses simples y compuestos, lo cual es importante para entender cómo se generan los intereses en distintas modalidades y cómo afectan a las inversiones.

## Cómo Usar el Programa

1. **Compilar el Código:**
   - Para ejecutar el programa, primero debes compilar el código fuente utilizando un compilador de C++ como `g++` o cualquier IDE compatible con C++.
   
   - Si estás usando `g++` en la terminal, puedes compilarlo con el siguiente comando:
     ```bash
     g++ programa_financiero.cpp -o programa_financiero
     ```
   - Esto generará el archivo ejecutable `programa_financiero`.

2. **Ejecutar el Programa:**
   - Una vez compilado, puedes ejecutar el programa desde la terminal con el siguiente comando:
     ```bash
     ./programa_financiero
     ```

3. **Seleccionar las Opciones:**
   - El programa presentará un menú donde podrás elegir entre varias opciones, como calcular la TIR, la amortización o los intereses.
   - Para calcular la **TIR**, el programa te pedirá que ingreses los flujos de efectivo (la inversión inicial será negativa, y los flujos futuros positivos).
   - En el momento de calcular el intereses simples o compuestos, deberás ingresar la cantidad de dinero, la tasa de interés y el tiempo.

4. **Resultados:**
   - El programa le presentara los resultados de los cálculos de forma clara dependiendo de la opción seleccionada.

## Estructura del Código

El código está dividido en las siguientes secciones:

- **Función TIR:** Calcula la Tasa Interna de Retorno para un conjunto de flujos de efectivo. (NO FUNCIONAL DEL TODO POR AHORA, LAS CAPACIDADES ESTAN PRESENTES PERO NO FUNCIONALES)
- **Menú de Opciones:** Permite al usuario seleccionar entre diferentes cálculos financieros.
- **Función de Intereses:** Calcula los intereses simples o compuestos en función de los datos ingresados.
- **Amortización:** Calcula la amortización decreciente, que es útil para el análisis de préstamos.

## Requisitos

- Un compilador de C++ (por ejemplo, `g++` o cualquier IDE compatible con C++).
- Conocimientos básicos de cómo compilar y ejecutar programas en C++.
---

