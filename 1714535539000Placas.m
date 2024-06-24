distancia = 0.1; % Distancia entre las placas
largo_1 = 0.15; % Largo de la placa 1
largo_2 = 0.15; % Largo de la placa 2
k = 9000000000; % Constante de Coulomb
resistencia = 50; % Resistencia del gel
tiempo = 1800; % Tiempo de la prueba
I = 120/resistencia; % Corriente eléctrica
area_placa_1 = largo_1 * 0.01; % Área de la placa 1
area_placa_2 = largo_2 * 0.01; % Área de la placa 2
carga_placa = I*tiempo; % Carga de las placas
x_gota = 0.05; % Posición de la gota en x
y_gota = 0; % Posición de la gota en y
radio_gota = 0.005; % Radio de la gota
carga_gota = (3.19*(10^(-10))); % Carga de la gota de sangre
densidad1 = carga_placa/area_placa_1; % Densidad de carga de la placa 1
densidad2 = carga_placa/area_placa_2; % Densidad de carga de la placa 2
mayor = largo_1/2; % Inicializar el valor de la placa más larga
uno = largo_1/2; % Mitad (a) de la longitud de la placa 1
dos = largo_2/2; % Mitad (a) de la longitud de la placa 2

% Inicializamos la posición de cada una de las placas
x_plate = [0, distancia];
y_plate1 = [-largo_1/2, largo_1/2]; 
y_plate2 = [-largo_2/2, largo_2/2];
% Determinamos cuál es la placa más larga
if largo_1 > largo_2
    mayor=largo_1/2;
elseif largo_2 > largo_1
    mayor=largo_2/2;
end

% Definir el rango de coordenadas en el espacio donde se calculará el campo eléctrico
[x,y] = meshgrid(0.01:0.01:x_plate(2)-0.01, -mayor:0.01:mayor);

% Cálculo del campo eléctrico de la primera placa y de la segunda placa (usamos la integral que
% vimos en clase y evaluamos de -a a a)
Ex1 = ((k*densidad1*(uno-y))./(x.*sqrt((x.^2)+((uno-y).^2)))) - ((k*densidad1*(-uno-y))./(x.*sqrt((x.^2)+((-uno-y).^2))));
Ey1 = ((k*densidad1)./(sqrt((x.^2)+((y-uno).^2)))) - ((k*densidad1)./(sqrt((x.^2)+((y+uno).^2))));

Ex2 = ((k*densidad2*(dos-y))./((distancia-x).*sqrt(((distancia-x).^2)+((dos-y).^2)))) - ((k*densidad2*(-dos-y))./((distancia-x).*sqrt(((distancia-x).^2)+((-dos-y).^2))));
Ey2 = -(((k*densidad2)./(sqrt(((distancia-x).^2)+((y-dos).^2)))) - ((k*densidad2)./(sqrt(((distancia-x).^2)+((y+dos).^2)))));

% Suma de los campos eléctricos en x y en y
Ex = Ex1 + Ex2;
Ey = Ey1 + Ey2;

% Campo eléctrico
E = sqrt(Ex.^2 + Ey.^2);

% Normalización de los vectores
ExFinal = Ex./E;
EyFinal = Ey./E;

% Gota de Sangre 
% Cálculo de las componentes en x y y del campo eléctrico
Rx = x-(x_gota);
Ry = y-(y_gota);
R = (Rx.^2+Ry.^2).^(3/2);

Exs = (1.4)*(k*Rx.*carga_gota./R);
Eys = (1.4)*(k*Ry.*carga_gota./R);

% Normalización de los vectores
Es = sqrt(Exs.^2+Eys.^2);

u = Exs./Es;
v = Eys./Es;

% Suma de los dos campos 
ExTodo = Ex+Exs;
EyTodo = Ey+Eys;

ETodo = sqrt(ExTodo.^2+EyTodo.^2);

% Normalización de los vectores
w = ExTodo./ETodo;
z = EyTodo./ETodo;


% Graficar el campo eléctrico
quiver(x, y, w, z);
hold on;
% Graficar la gota de sangre
rectangle('Position', [x_gota-radio_gota, y_gota-radio_gota, 2*radio_gota, 2*radio_gota], 'Curvature', [1, 1], 'FaceColor', 'black');
hold on;
% Dibujar las placas
U1 = -largo_1/2:0.01:largo_1/2;
V1 = U1;

U2 = -largo_2/2:0.01:largo_2/2;
V2 = U2;

plot(U1-U1,V1,"+r")
plot(U1-U1+0.006, V1,"+r")
plot(U1-U1+0.01,V1, "r","LineWidth", 3)
plot(U1-U1+0.01,V1, "r","LineWidth", 3)

plot(U2-U2+distancia, V2, "g", "LineWidth", 3)
plot(U2-U2+distancia+0.002, V2, "_g")
plot(U2-U2+distancia+0.0045, V2, "_g")
hold off;
xlabel('x');
ylabel('y');
title('Campo eléctrico entre dos placas paralelas');
axis equal;