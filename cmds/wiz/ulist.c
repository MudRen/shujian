// user list

inherit F_CLEAN_UP;

int main(string str)
{
        object *ob;
        int i;

	ob = filter_array(objects(), (: userp :));
	for(i=0; i<sizeof(ob); i++)
		write(sprintf("%10s : %40O%s\n", ob[i]->query("id"), ob[i],
		interactive(ob[i])?"":" ������"));
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : ulist

������������ҵ�/obj/user number ��ʾ������
HELP
    );
    return 1;
}
