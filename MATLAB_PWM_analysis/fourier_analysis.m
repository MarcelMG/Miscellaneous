% see LICENSE.txt

% perform a frequency analysis of the two signals 
% and plot the magnitude vs. frequency

fs = 1e7; % sampling frequency (specified in 'to workspace' simulink block)
% import signals from simulink output data             
t = x1.time;
sig1 = x1.signals.values; % left-adjusted PWM DAC output signal
sig2 = x2.signals.values; % center-adjusted PWM DAC output signal
L = length(t)-1; % number of samples
Y1 = fft(sig1); % perform Fast Fourier Transform of the signal
Y1 = abs(Y1/L); % compute magnitude and norm it to 1
Y1 = Y1(1:round(L/2+1)); % take only one half of the spectrum (and not the mirrored)
Y1(2:end-1) = 2*Y1(2:end-1); % multiply by two to compensate for mirrored spectrum
% do the same for the second signal
Y2 = fft(sig2);
Y2 = abs(Y2/L);
Y2 = Y2(1:round(L/2+1));
Y2(2:end-1) = 2*Y2(2:end-1);
f = fs*(0:round(L/2))/L; % frequency axis
figure;
subplot(2,1,1);
Lplot = round(L*100e3/fs); % plot only the frequencies < 100kHz
plot(f(1:Lplot),Y1(1:Lplot)) 
title('left-adjusted PWM DAC output signal')
xlabel('f (Hz)')
ylabel('|Y1(f)|')
subplot(2,1,2);
plot(f(1:Lplot),Y2(1:Lplot)) 
title('center-adjusted PWM DAC output signal')
xlabel('f (Hz)')
ylabel('|Y2(f)|')