// /cmds/usr/run.c
// Modify By Mope@SJ /03/01/02
// ������Զ������õ����������������·���������г�
// ȱ����room->query("short")��ͬ��ֻ�ܴﵽ����ĵص�
// ��;���Թ���ˮ���޷�����
// ���ܵ�û�����ӳ��ڵķ��䲻�ɵ���

#include <ansi.h>

#define RUN_D "/cmds/imm/runawayd.c"

int main(object ob,string arg)
{
        mixed a;
        object horse;
        string hname;
        mixed flag;

        if (! arg) return notify_fail("����õ�ȥ�Ķ���·����\n");
        a = RUN_D->search_for_path(ob, arg);

        if (! a) return notify_fail("û������ط�����������ط����ɵ��\n");
        // ·���м����Թ���ˮ�����ﲻ��

        if (stringp(hname = ob->query_temp("is_riding")))
                horse = ob->query_temp("riding_beast");
        else
                return notify_fail("��û��������\n");

        if (ob->is_busy() || ob->is_fighting())
                return notify_fail("����æ���أ��ܲ�����\n");

        if (environment(ob) != environment(horse))
        {
                if (horse && horse->query_temp("is_rided_by") == ob)
                        horse->delete_temp("is_rided_by");
                ob->delete_temp("is_riding");
                ob->delete_temp("riding_beast");
                return notify_fail("�㲢û��������\n");
        }

        if (! (flag=ob->query("env/brief"))) {
                flag = 0;
                ob->set("env/brief", "YES");
        }
        ob->start_busy(1);
        if(wizardp(ob) && ob->query("env/test"))
        write(sprintf("%O\n",a));
        for(int i = sizeof(a[1])-1;i>=0;i--)
        {
        	if(wizardp(ob) && ob->query("env/test"))
        		write(sprintf("Move to %O %d\n",a[1][i],i));
                ob->move(a[1][i]);
                horse->move(a[1][i]);
                tell_room(environment(ob),ob->name()+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
                if(arg == strip((a[1][i])->query("short")))
                {
                	if(wizardp(ob) && ob->query("env/test"))
        			write(sprintf("breaked\n"));
                	break;
                }
        }

        ob->start_busy(2);
        call_out("stop", 1, ob, hname, arg, flag);

        return 1;
}

void stop(object ob, string hname, string arg, mixed flag)
{
        if (!ob || !hname || !arg) return;
        tell_room(environment(ob),ob->name()+"����"+hname+"һ·˳������"+arg+"��\n", ({ob}));
        tell_object(ob, HIY "�����ӱޣ���ҹ�ϵ���"HIY + arg + HIY "��\n" NOR);
        message("vision", "\n"+ob->name()+"������������̬������"+hname+"ͣ������������Ҳ��$Nһ��壡\n", environment(ob), ob);
        if (flag==0) ob->delete("env/brief");
        else ob->set("env/brief", flag);
        
        return;
}

