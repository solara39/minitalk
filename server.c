int	main()
{
	struct sigaction sa;
	if (-1 == sigemptyset(&sa.sa_mask)
		exit(1);
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	if (-1 == sigaction(SIGINT, &sa, NULL)
		exit(1);
	return (0);
}
