int ft_min(int left, int up, int left_up)
{
	int	min;
	
	min = 2147483647;
	if (left < min)
		min = left;
	if (up < min)
		min = up;
	if (left_up < min)
		min = left_up;
	return (min);
}

int is_overlap(char empty, char obs, char fill)
{
	if (empty == obs)
		return (1);
	if (empty == fill)
		return (1);
	if (obs == fill)
		return (1);
	return (0);
}