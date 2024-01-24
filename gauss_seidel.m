function [x, num_iterations] = gauss_seidel(A, b, tol, max_iterations)
    % Gauss-Seidel method to solve Ax = b.
    % A: matrix of coefficients
    % b: vector of constants
    % tol: tolerance for stopping criterion
    % max_iterations: maximum number of iterations

    % Get the number of rows of A
    n = length(b);
    
    % Initial guess
    x = zeros(n, 1);
    
    % Main iteration loop
    for k = 1:max_iterations
        x_old = x;

        for i = 1:n
            % Gauss-Seidel formula
            x(i) = (b(i) - A(i, 1:i-1) * x(1:i-1) - A(i, i+1:end) * x_old(i+1:end)) / A(i, i);
        end

        % Check for convergence
        if norm(x - x_old, inf) < tol
            num_iterations = k;
            return;
        end
    end
    
    % If max number of iterations reached
    num_iterations = max_iterations;
    fprintf('Gauss-Seidel: Maximum number of iterations reached.\n');
end

% Example usage:
A = [4 1 2; 1 3 0; 0 1 2];
b = [4; 1; 2];
tol = 1e-5;
max_iterations = 1000;

[x, num_iterations] = gauss_seidel(A, b, tol, max_iterations);

fprintf('Solution x:\n');
disp(x);
fprintf('Number of iterations: %d\n', num_iterations);

