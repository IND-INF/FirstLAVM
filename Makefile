.PHONY: clean
CFLAGS = -Wall -g
OBJ = main.o Experiments\first_experiment.o Experiments\second_experiment.o Experiments\third_experiment.o\
	Error_searchs\linear_system_relative_error.o Error_searchs\linear_system_residual.o\
	Solving_algorithms\gaussian_elimination.o Solving_algorithms\pivot_element_selection.o\
	Solving_algorithms\lower_upper_factorisation.o Solving_algorithms\solving_with_lower_and_upper.o\
	Matrix_generators\matrix_generation.o Matrix_generators\hilbert_matrix.o matrix.o

main: $(OBJ)
	gcc $(OBJ) -o main

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	del $(OBJ) main