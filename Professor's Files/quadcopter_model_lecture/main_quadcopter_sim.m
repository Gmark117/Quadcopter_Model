clc
clear all
close all

%% setup problem data
% vector of parameters
quad_data = [ ...
 9.81, ...% g 
 0.063,...% m 
 5.82857e-05, ... % ixx 
 7.16914e-05, ... % iyy 
 1.0e-04,     ... % izz 
 0.0624,     ... % L
 0.0107,     ... % CT  
 7.8264e-04, ... % CQ 
 1.15        ... % rho
];

sensors_data = [...
   0.0900,... % acc-x bias
  -0.0600,... % acc-y bias 
   0.3370,... % acc-z bias
  -0.0095,... % gyro-x bias
  -0.0075,... % gyro-y bias
   0.0015,...  % gyro-z bias
   0.0,...     % imu-x position in body frame
   0.0,...     % imu-y position in body frame
   0.0,...     % imu-z position in body frame
   0.44        % minimum sonar altitude
];

% initial conditions
y_init_conds = [
  0, ... %u
  0, ... %v       
  0, ... %w       
  0, ... %omega_x 
  0, ... %omega_y 
  0, ... %omega_z 
  0, ... %phi    
  0, ... % theta 
  0 ... %psi   
];

% desired hoovering height
h_des = 1;

% PID parameters
K_z = 6.0 ;

%% Run simulation
% runs the simulink model

paramNameValStruct.SimulationMode = 'normal';
paramNameValStruct.AbsTol         = '1e-5';
paramNameValStruct.SaveState      = 'on';
paramNameValStruct.StateSaveName  = 'xoutNew';
paramNameValStruct.SaveOutput     = 'on';
paramNameValStruct.OutputSaveName = 'youtNew';

simOut = sim('quadcopter_model',paramNameValStruct);

%% plot solution

figure
plot3(simOut.pos(:,1),simOut.pos(:,2),simOut.pos(:,3))


ft1 = simOut.externat_forces(:,1);
ft2 = simOut.externat_forces(:,2);
ft3 = simOut.externat_forces(:,3);
ft4 = simOut.externat_forces(:,4);

figure
subplot(2,1,1)
plot(simOut.tout,simOut.externat_forces(:,1),'DisplayName','f_t1');
hold on
plot(simOut.tout,simOut.externat_forces(:,2),'DisplayName','f_t2');
plot(simOut.tout,simOut.externat_forces(:,3),'DisplayName','f_t3');
plot(simOut.tout,simOut.externat_forces(:,4),'DisplayName','f_t4');
legend

subplot(2,1,2)
plot(simOut.tout,quad_data(1)*quad_data(2)*ones(size(simOut.tout)),'DisplayName','m*g');
hold on
plot(simOut.tout,ft1+ft2+ft3+ft4,'DisplayName','total thrust');
legend







