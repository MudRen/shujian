#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIB"�����ϻ�ɢ"NOR, ({ "hehuan san","san" }) );
        set("long",HIB"����Ѫ���������Ƶ�ҩ�ۣ�ֻ��Ҫ��(sa)һ�����ܷ������ã�hehehe\n"NOR);
        set("unit", "��");
        set("weight", 90);
        set("no_sell",1);
        set("no_get",1);
        set("value", 0);
}

void init()
{
        add_action("do_sa","sa");
}

int do_sa(string arg)
{
        object me=this_player() , ob;

        if(!arg) return notify_fail("��Ҫ��˭��\n");

        ob = present(arg, environment(me));
        if(!ob) return notify_fail("��Ҫ��˭��\n");

        if(ob==me) return notify_fail("��Ҫ���������.....\n");

        if( !wizardp(me) && userp(ob) )
                return notify_fail("������������Ŀ�ꡣ\n");

        if(ob->query("id")!="guo fu" && ob->query("id")!="guo xiang" )
                return notify_fail("������������Ŀ�ꡣ\n");

        message_vision("$N����Ľ�ҩ����$n��ȥ��\n",me, ob);
        if (random(me->query_skill("force",1)) < random(ob->query_con()*4))
        {
                message_vision(HIR"$N��ҩ����δ�����ͱ�$n���������˿�ȥ��\n"NOR,me,ob);
                me->start_busy(5);
                ob->kill_ob(me);
                destruct(this_object());
                return 1;
        } else {
       message_vision(HIB"$N"HIB"�ٺ���Ц�˼�������ָ����$n"HIB"���ᵯ�˵��ĭ��\n"MAG"��һ�����$n"MAG"������ͨ������˹�ȥ��\n",me, ob);
        if (me->query_temp("xy/job")!=0)
                me->add_temp("xy/job",1);
        ob->unconcious();
        destruct(this_object());
        return 1;
        }
}
