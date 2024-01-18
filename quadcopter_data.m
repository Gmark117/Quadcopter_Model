clc
clear all
close all

%% Vector of parameters
quad_data = [ ...
    9.81,        ... % g
    0.063,       ... % m
    5.82857e-05, ... % ixx
    7.16914e-05, ... % iyy
    1.0e-04,     ... % izz
    0.0624,      ... % L
    0.0107,      ... % CT
    7.8264e-04,  ... % CQ
    1.15         ... % rho
];

%% Initial conditions
y_init_conds = [ ...
    0, ... % u
    0, ... % v
    0, ... % w
    0, ... % omega_x
    0, ... % omega_y
    0, ... % omega_z
    0, ... % phi
    0, ... % theta
    0  ... % psi
];

%% Desired hoovering height
h_des = 1;

%% PID parameters
K_z = 5;

%% Run Simulation
% Run the Simulink model
paramNameValStruct.SimulationMode = 'normal';
paramNameValStruct.AbsTol         = '1e-5';
paramNameValStruct.SaveState      = 'on';
paramNameValStruct.StateSaveName  = 'xoutNew';
paramNameValStruct.SaveOutput     = 'on';
paramNameValStruct.OutputSaveName = 'youtNew';

simOut = sim('Quadcopter_Model', paramNameValStruct);

%% Plot solutions

figure
plot3(simOut.pos(:,1), simOut.pos(:,2), simOut.pos(:,3))

ft1 = simOut.external_forces(:,1);
ft2 = simOut.external_forces(:,2);
ft3 = simOut.external_forces(:,3);
ft4 = simOut.external_forces(:,4);

figure
subplot(2,1,1)
plot(simOut.tout, simOut.external_forces(:,1), 'DisplayName', 'f_t1');
hold on
plot(simOut.tout, simOut.external_forces(:,2), 'DisplayName', 'f_t2');
plot(simOut.tout, simOut.external_forces(:,3), 'DisplayName', 'f_t3');
plot(simOut.tout, simOut.external_forces(:,4), 'DisplayName', 'f_t4');
legend

subplot(2,1,1)
plot(simOut.tout, quad_data(1)*quad_data(2)*ones(size(simOut.tout)), 'DisplayName', 'm*g');
hold on
plot(simOut.tout, ft1+ft2+ft3+ft4, 'DisplayName', 'Total Thrust');
legend







