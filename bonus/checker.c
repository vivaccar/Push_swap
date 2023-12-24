#include "checker.h"

int	main(int argc, char	**argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc == 1 || (!argv[1][0] && argc == 2))
		return (0);
	check_input(argc, argv);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else 
		argv = argv + 1;
	start_stack(&stack_a, argv);
}