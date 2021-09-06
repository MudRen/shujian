#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"�ɺ�ҩ"NOR, ({ "menghan yao","yao" }) );
        set("long",HIG"�������޳�֮ͽʹ���ɺ�ҩ�����˲���ʱ��ҩ(xiayao)��\n"NOR);
        set("unit", "С��");
        set("weight", 10);
        set("no_sell",1);
        set("no_give",1);
        set("no_get",1);
        set("value", 0);
}

void init()
{
        add_action("poison","xiayao");
}

int poison(string arg)
{
        object me=this_player();
        object ob;

        if(!arg) return notify_fail("��Ҫ��˭��ҩ��\n");

        ob = present(arg, environment(me));

        if(!ob) return notify_fail("��Ҫ��˭��ҩ��\n");

        if((ob->query("id") != "wu dunru")&&
            (ob->query("id") != "wu xiuwen")&&
            (ob->query("id") != "yelv yan")&&
            (ob->query("id") != "wanyan ping"))
                 return notify_fail("������������Ŀ�ꡣ\n");

        if(ob == me) return notify_fail("��Ȼ�������ܺóԣ���������С�ĵ�ɡ�\n");

        if( !wizardp(me) && userp(ob) )
                return notify_fail("������������Ŀ�ꡣ\n");

        message_vision("������$N����û��ע�⣬ͻȻ������$n�ı��Ӷ���һ�¡�\n",me, ob);
        if (random(me->query_skill("poison",1)) < random(ob->query_int()*4))
        {
                message_vision(HIR"$n����$N���һ��������ʲô������\n"NOR,me,ob);
                me->start_busy(5);
                ob->kill_ob(me);
                destruct(this_object());
                return 1;
        } else {
        message_vision(HIR"$n������������Ӻ���һ�ڣ���ǰ��Ȼһ�ڡ�\n"NOR,me,ob);
        message_vision(HIR"$N�û���$n����һ�ߡ�$n����һ�Σ��͵��ڵ��ϡ�\n"NOR,me,ob);
        if (me->query_temp("xy/job")!=0)
                me->add_temp("xy/job",1);
        ob->unconcious();
                destruct(this_object());
        return 1;
        }
}
