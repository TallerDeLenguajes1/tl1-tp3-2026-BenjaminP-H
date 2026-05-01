## Documentación del Trabajo Práctico

### 5. ¿Qué es una Wiki y para qué sirve?
Una **Wiki** en un entorno de desarrollo (como GitHub) es un sistema de documentación integrado que permite organizar y compartir información detallada sobre un proyecto. 

Su función principal es servir como una **guía técnica y de usuario** que vive junto al código pero separada de él. Sirve para:
*   Explicar la arquitectura del software.
*   Documentar el uso de funciones y estructuras de datos.
*   Proporcionar instrucciones de instalación y configuración.
*   Mantener un registro de cambios o decisiones de diseño que no son evidentes al leer el código fuente.

---

### 6. Gestión de Memoria: Estática vs. Dinámica

En el desarrollo de este trabajo, se utilizaron ambos tipos de gestión de memoria. A continuación, se detallan sus diferencias fundamentales:

#### Memoria Estática
*   **Asignación:** Se define en tiempo de compilación. El tamaño debe ser conocido antes de ejecutar el programa.
*   **Ubicación:** Se almacena en el **Stack** (Pila).
*   **Control:** El sistema operativo se encarga de asignar y liberar el espacio automáticamente.
*   **Limitación:** No es flexible. Si se declara un arreglo de 100 elementos y se usan solo 10, el resto del espacio se desperdicia.
*   **Ejemplo en el código:** El arreglo global `char *TiposProductos[]`.

#### Memoria Dinámica
*   **Asignación:** Se define en tiempo de ejecución (mientras el programa corre).
*   **Ubicación:** Se almacena en el **Heap** (Montículo).
*   **Control:** El programador tiene el control total. Se utiliza `malloc()` o `calloc()` para solicitar memoria y **es obligatorio** usar `free()` para liberarla y evitar fugas de memoria (*memory leaks*).
*   **Ventaja:** Permite optimizar el uso de recursos, solicitando exactamente la cantidad de memoria necesaria según la entrada del usuario.
*   **Ejemplo en el código:** El uso de `malloc` para el arreglo de clientes y los nombres de los mismos.