# :man_student:TRABAJO FIN DE GRADO: Plataforma en la Nube para el Monitoreo y Detección de Afecciones Cardiacas

[Link a la documentación.](https://1drv.ms/b/s!AqhgxLU5tSeVgSKK-BMJhF4JYwiC?e=IgdN8t)

## :open_book:Resumen del proyecto

Este TFG se basa en la creación de una aplicación móvil para la monitorización, en tiempo real, de los datos cardiacos, azúcar y oxígeno del usuario. Para el desarrollo de esta funcionalidad se ha requerido la creación de un simulador en Arduino, que será el encargado de generar los datos cardiacos que recogerá la aplicación: será nuestro ‘monitor cardiaco’ particular.

Todas las funcionalidades de autenticación, guardado de datos, persistencia y envío de alertas de las que hará uso aplicación estarán soportadas por una infraestructura en la nube, encargada de proveer la mayoría de estos servicios necesarios.

Estos tres módulos (simulador, aplicación e infraestructura) trabajan de manera coordinada y suponen, en conjunto, los engranajes que dan vida a este proyecto, cuyo objetivo principal será buscar una alternativa fiable, rápida, multiplataforma y viable a la consulta de datos cardiacos en tiempo real.

Gracias a herramientas como Arduino o Google Cloud Platform se ha conseguido no solo ofrecer al usuario un vistazo en tiempo real de su estado de salud, sino también consultar sus estados anteriores en cuestión de segundos y, si lo precisa, mandar alertas al centro médico más cercano en un abrir y cerrar de ojos.

En definitiva, el proyecto aquí definido constituye un sistema basado en tres módulos, que se coordinarán para mantener al usuario informado en todo momento de su estado de salud y, si lo necesita, pedir ayuda de manera urgente.

## :card_index_dividers: Módulos
| ![enter image description here](https://openexpoeurope.com/wp-content/uploads/2019/12/flutter-logo-sharing.png) | ![enter image description here](https://upload.wikimedia.org/wikipedia/commons/thumb/5/5b/Arduino_Logo_Registered.svg/1200px-Arduino_Logo_Registered.svg.png) | ![enter image description here](https://upload.wikimedia.org/wikipedia/commons/b/bd/Firebase_Logo.png) |
|--|--|--|

Los mencionados módulos están repartidos en tres repositorios diferentes:
 - Aplicación móvil, desarrollada en Dart + Flutter. [Link](https://github.com/martinBDev/Flutter-app-TFG).
 - Código del simulador Arduino. Se ha utilizado un Arduino Nano 33 BLE para la generación de datos. [Link](https://github.com/martinBDev/Arduino-app-TFG).
 - Infraestructura *Cloud*, basada en funciones *serverless* de Google (Firebase). Se ocupan del guardado de datos, generación de alertas e emails, búsquedas de centros médicos cercanos, creación de documentos de usuarios, etc. [Link](https://github.com/martinBDev/Firebase-app-TFG).

## :test_tube:Pruebas
Para asegurar el correcto funcionamiento del proyecto se han realizado una serie de pruebas y tests, enfocadas tanto a la aplicación para móviles como a las funciones *serverless*.
### :calling: Pruebas de la *App*
Las pruebas de la app se han desarrollado y ejecutado haciendo uso de la librería interna de tests de Flutter, junto con [Mockito](https://site.mockito.org/):

 - [X] Pruebas Unitarias: *testeo* de funcionalidades concretas de la *app*. Hasta 31 *tests* diferentes.
	 - Inicio de Sesión
	 - Cerrado de Sesión
	 - Registro
	 - Consulta de datos históricos
	 - Invocación de las diferentes funciones *serverless*
 - [X] Pruebas de Widgets: comprobación del correcto renderizado de los componentes visuales de la *app*. Un total de 27 *tests*.
 - [X] Pruebas de Usabilidad: sesiones de pruebas guiadas y supervisadas sobre 3 usuarios de diferentes edades y ocupaciones.
 - [X] Pruebas de Accesibilidad: uso de herramientas automatizadas para medir la accesibilidad de la *app*.
 - [X] Pruebas de Rendimiento: mediciones del tiempo de respuesta de la aplicación, tasa de fotogramas, uso de RAM y consumo de CPU.

### :building_construction: Pruebas de la Infraestructura
Las pruebas de las funciones *serverless* y de la infraestructura se ejecutaron haciendo uso de la librería [Mocha](https://mochajs.org/) para JavaScript:

 - [X] Pruebas Unitarias: prueba de funcionalidades de cada función. En total, 17 pruebas.
	 - Creación de datos de usuario
	 - Acceso de usuarios a sus datos
	 - Encontrar centro médico más cercano
	 - Guardado de métricas
	 - Generación de emails de alerta
- [X] Pruebas de Rendimiento: se ha medido el consumo de memoria y de CPU de las diferentes funciones, así como el tiempo de ejecución y de respuesta de las mismas.
