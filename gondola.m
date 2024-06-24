% Valores iniciales
altura_inicial = 0;
altura_maxima = 59;
altura_frenado = 30;
tiempo_espera_cima = 7;
velocidad_subida = 10 * 1000 / 3600;
g = 9.81;
masa = 1000;
a_anterior = 0;


% Para los loops
x_posicion = [];
velocidad_grafica = [];
aceleracion_grafica = [];
jerk_grafica = [];
aceleracion = 0;
x = altura_inicial;
tiempo_posicion = [];
gs_grafica = [];
t = 0;
time_step = 0.1;

%Subida con velocidad constante
while x <= altura_maxima
    aceleracion = (velocidad_subida-velocidad_subida)/t;
    x = velocidad_subida*t;
    x_posicion = [x_posicion,x];
    velocidad_grafica = [velocidad_grafica, velocidad_subida];
    aceleracion_grafica = [aceleracion_grafica, aceleracion];
    jerk = (aceleracion-a_anterior)/t;
    jerk_grafica = [jerk_grafica,jerk];
    a_anterior = aceleracion;
    tiempo_posicion = [tiempo_posicion, t];
    gs_grafica = [gs_grafica,0];
    t = t + time_step;   
end

% Calculamos en qué momento debe empezar la caída libre
tiempo_despues = t + tiempo_espera_cima;

% Tiempo de espera
while t <= tiempo_despues
    velocidad = 0;
    aceleracion = 0;
    x_posicion = [x_posicion,altura_maxima];
    velocidad_grafica = [velocidad_grafica,velocidad];
    aceleracion_grafica = [aceleracion_grafica, aceleracion];
    jerk = (aceleracion-a_anterior)/t;
    jerk_grafica = [jerk_grafica,jerk];
    a_anterior = aceleracion;
    tiempo_posicion = [tiempo_posicion, t];
    t = t + time_step;
    gs_grafica = [gs_grafica,0];
end


% Variables que nos ayudarán a calcular el tiempo desde que empezó el
% recorrido y el tiempo  desde que empezó la caída libre 
tiempo = 0;
ti = t- time_step;
total = t;

% Caída libre
while x >= altura_frenado
    dif = (g*(tiempo^2))/2; 
    x = altura_maxima - dif;
    velocidad = g*tiempo;
    x_posicion = [x_posicion,x];
    velocidad_grafica = [velocidad_grafica,velocidad];
    aceleracion_grafica = [aceleracion_grafica, g];
    jerk = ((g-a_anterior)/(total-ti))/g;
    jerk_grafica = [jerk_grafica,-jerk];
    total = t + tiempo;
    tiempo_posicion = [tiempo_posicion, total];
    tiempo = tiempo + 0.05;
    gs_grafica = [gs_grafica,-(g-a_anterior)/g];
    a_anterior =g;
end


% Frenado magnético

% Variables de referencia
t = total+time_step;
ti = total;
a= 0.1; % radio del dipolo
R = 0.0000000968; % resistencia del material
M = 4*pi*10^(-7); % constante permeabilidad
U = 24000; % momento dipolar consultar
Q = [x;velocidad]; % [z;v]
v_anterior = velocidad;
a_anterior = 9.81;
h = 0.01;
F = @(t, Q) [Q(2,1); (-900*9.81+((-9*((24000*4*pi*10^(-7))^2)*(0.1^4))/(4*R))*((Q(1,1)^2)/((Q(1,1)^2)+(0.1^2))^5)*(Q(2,1)))/900];

% Frenado magnético con Runge Kutta
while Q(2,1)>=0
    K1 = F(t, Q);
    K2 = F(t+(h/2), Q+(h/2)*K1); 
    K3 = F(t+(h/2), Q+(h/2)*K2);
    K4 = F(t+h,Q+h*K3);
    Q_nueva = Q+(h/6)*(K1+(2*K2)+(2*K3)+K4);
    Q = Q_nueva;
    if Q_nueva(2,1)>=0
        Posicion = x-(Q_nueva(1,1)-x);
        x_posicion = [x_posicion,Posicion];
        velocidad_grafica = [velocidad_grafica,Q_nueva(2,1)];
        tiempo_posicion = [tiempo_posicion, t];
        aceleracion = (Q_nueva(2,1)-v_anterior)/(t-ti);
        aceleracion_grafica = [aceleracion_grafica, aceleracion];
        jerk = -((aceleracion-a_anterior)/(t-ti))/g;
        jerk_grafica = [jerk_grafica,jerk];
        t = t+h;
        gs_grafica = [gs_grafica,-((aceleracion-a_anterior)/g)];
        a_anterior = aceleracion;
    end
end

if Posicion < 0
    fprintf('Se estrelló\n');
else 
    fprintf('Se detuvo a los: \n');
    disp(Posicion)
end



% Gráficas
subplot(5,1,1)
plot(tiempo_posicion, x_posicion)
xlabel('Tiempo (s)')
ylabel('Altura (m)')
title('Posición vs Tiempo')
grid on

subplot(5,1,2)
plot(tiempo_posicion, velocidad_grafica)
xlabel('Tiempo (s)')
ylabel('Velocidad (m/s)')
title('Velocidad vs Tiempo')
grid on

subplot(5,1,3)
plot(tiempo_posicion, aceleracion_grafica)
xlabel('Tiempo (s)')
ylabel('Aceleración (m/s^2)')
title('Aceleración vs Tiempo')
grid on

subplot(5,1,4)
plot(tiempo_posicion, jerk_grafica)
xlabel('Tiempo (s)')
ylabel('Jerk')
title('Jerk vs Tiempo')
grid on

subplot(5,1,5)
plot(tiempo_posicion, gs_grafica)
xlabel('Tiempo')
ylabel('G')
title('G vs Tiempo')
grid on