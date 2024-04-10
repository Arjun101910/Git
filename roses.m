function roses(frame)
    % Ensure the frame loops from the end to the beginning
    frame = mod(frame - 2, 48) + 1;
    
    % Rose parameters
    openness = 1.05 - cos(pi * frame / (48 / 2.5)) .* (1 - frame / 48) .^ 2;
    opencenter = openness * 0.2;
    petal_count = 3.6;
    num_radial_points = 30;
    radial_resolution = 10;
    B = 1.27689;
    num_petals = 40;
    petal_sep = 5 / 4;
    petal_theta = (1 / petal_count) * pi * 2;
    num_data_points = num_petals * radial_resolution + 1;

    % Generate grid
    radial_vals = linspace(0, 1, num_radial_points);
    angular_vals = linspace(0, num_petals * petal_theta, num_data_points);
    [R, Theta] = ndgrid(radial_vals, angular_vals);

    % Rose shape calculations
    M = (1 - mod(petal_count * Theta, 2 * pi) / pi);
    X = 1 - (petal_sep * M.^2 - 1 / 4) .^ 2 / 2;
    phi = (pi / 2) * linspace(opencenter, openness, num_data_points) .^ 2;
    Y = 1.995 * (R .^ 2) .* (B * R - 1) .^ 2 .* sin(phi);
    R2 = X .* (R .* sin(phi) + Y .* cos(phi));
    X_final = R2 .* sin(Theta);
    Y_final = R2 .* cos(Theta);
    Z = X .* (R .* cos(phi) - Y .* sin(phi)) * 1;

    % Plotting
    C = hypot(hypot(X_final, Y_final), Z * 0.9);
    surf(X_final, Y_final, Z, C, 'FaceColor', 'interp', 'EdgeColor', 'none');
    colormap([linspace((48 - frame) / 48, 1, 256) .^ 2; zeros(1, 256); zeros(1, 256)]');
    
    % Decorations
    set(gcf, 'color', 'w');
    daspect([1 1 1]);
    axis([-1 1 -1 1 -0.5 1], 'off');
    set(gca, 'clipping', 'off');
    camzoom(1.6);
    camorbit(-frame * 3, 0);
end
