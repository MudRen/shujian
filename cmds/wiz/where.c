// where.c
// 06-14-95

inherit F_CLEAN_UP;

int main(object me, string str)
{
        object ob, where, *ob_list;
        int i;

        if (!str)
                return notify_fail("ָ���ʽ��where <�������>\n"); 
        ob = find_player(str);
        if( !ob ) ob = find_living(str);
        if( !ob || !me->visible(ob)) {
                str = resolve_path(me->query("cwd"), str);
                ob_list = filter_array(children(str), (: clonep :));
                write("\n�ܹ��ҵ���"+chinese_number(sizeof(ob_list))+"�����Ƽ���\n");
                for(i=0; i<sizeof(ob_list); i++) {
                	where = environment(ob_list[i]);
                	write(sprintf("  %-50s  in  %s(%s)\n", ob_list[i]->name()+"("+file_name(ob_list[i])+")",
                        where ? (where->is_character() ? where->name() : where->query("short")) : "����",
                        where ? (where->is_character() ? where->query("id") : base_name(where)) : "none"));
                }
                return 1;
        }
        if (!ob) return notify_fail("����û�����.\n");
        where = environment(ob);
        if (!where) return notify_fail("����˲�֪��������Ү...\n");
        printf("%s(%s)������%s(%s).\n",
                (string)ob->name(),
                (string)ob->query("id"),
                (string)where->query("short"),
                (string)file_name(where));
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ: where <��ҵ� ID>

���ָ����������֪���Ŀǰ���ڵ�λ��.

HELP
        );
        return 1;
}
