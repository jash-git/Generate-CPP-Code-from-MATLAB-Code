function y = averagingFilterCG(x) %#codegen
arguments
    x (1,:) double
end
slider = zeros(16,1);
y = zeros(size(x));
for i = 1:numel(x)
    slider(2:end) = slider(1:end-1); % move one position in the buffer
    slider(1) = x(i); % Add a new sample value to the buffer
    y(i) = sum(slider)/numel(slider); % write the average of the current window to y
end
end