#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"ʯ�ҷ�"NOR, ({ "shihui fen","fen" }) );
        set("long",HIW"�������޳�֮ͽʹ��ʯ�ҷۡ�������(sa)����˵��۾���\n"NOR);
        set("unit", "С��");
        set("weight", 10);
        set("no_sell",1);
        set("no_give",1);
        set("no_get",1);
        set("value", 0);
}

void init()
{
        add_action("blind","sa");
}

int blind(string arg)
{
        object me=this_player();
        object ob;

        if(!arg) return notify_fail("��Ҫ��˭��\n");

        ob = present(arg, environment(me));

        if(!ob) return notify_fail("��Ҫ��˭��\n");

        if(ob == me) return notify_fail("��ҩˮ��Ƚ��ʺϡ�\n");

        if((ob->query("id") != "cheng ying")&&
            (ob->query("id") != "wu tianfeng")&&
            (ob->query("id") != "feng mofeng"))
                 return notify_fail("������������Ŀ�ꡣ\n");

        if( !wizardp(me) && userp(ob) )
                return notify_fail("������������Ŀ�ꡣ\n");

        message_vision("$NͻȻ����$n����һ�ѷ�ĩ��\n",me, ob);
        if (random(me->query_skill("throwing",1)) < random(ob->query_dex()*4))
        {
                message_vision(HIR"$n����$N�ƺ�һ�������޳�С������\n"NOR,me,ob);
                me->start_busy(5);
                ob->kill_ob(me);
                destruct(this_object());
                return 1;
        } else {
        message_vision(HIR"$n��$N�����۾�����ʱ�۾���ʹ��Ŀ��ʶ�\n"NOR,me,ob);
        if (me->query_temp("xy/job")!=0)
                me->add_temp("xy/job",1);
        ob->start_busy(5);
        ob->add("dex",-20);
        ob->add("str",10);
        ob->kill_ob(me);
        destruct(this_object());
        return 1;
        }
}
