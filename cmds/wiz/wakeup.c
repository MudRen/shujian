// full.c for apprentice
// written by snowman@SJ 29/10/1999

inherit F_CLEAN_UP;
 
int main(object me,string str)
{
	object ob;
        if (!geteuid()) seteuid(getuid());
        if (!str)
                ob = me;
        else	ob = present(lower_case(str), environment(this_player()));
        
        if (!ob) return notify_fail ("����û������Ҫ���ѵ��ˡ�\n");
        
  	ob->revive();
  	if (wizardp(ob)) ob->reincarnate();

        if (me != ob)
            	message_vision("$Nָ��$n��������������������......����$p�ͱ������ˣ�\n", me, ob);
        else write("�㻽�����Լ���\n");
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ: wakeup [���ID]
 
 ���ѻ��Ի�˯������ҡ�

HELP );
        return 1;
}
