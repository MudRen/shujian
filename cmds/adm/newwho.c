string func(object ob)
{
	string ret = ob->query("family/family_name");

	if (!ret) ret = "��ͨ����";
	return ret;
}

int main(object me, string arg)
{
	mapping list = unique_mapping(users(), (: func :));
	string *index = sort_array(keys(list), -1);
	int i = sizeof(index);

	while (i--)
		write(sprintf("%8s: %d\n", index[i], sizeof(list[index[i]])));
	return 1;
}
