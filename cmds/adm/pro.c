int main(object me, string arg)
{
	buffer tmp;
	int i, size;
	string str = "\n";

	size = sizeof(tmp = read_buffer("/test"));
	for (i = 0; i < size; )
	{
		str += sprintf("%02X", tmp[i]);
		str += (++i % 32) ? " " : "\n";
	}
	str += (i % 32) ? "\n" : "";
	write(str);
	return 1;
}
