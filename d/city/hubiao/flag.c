// OBJ: flag.c
// Date: Look 99/04/25

#include <ansi.h>

inherit ITEM;

string* dir_alias = ({
        "n","north","e","east",
        "w","west","s","south",
        "nu","northup","eu","eastup",
        "wu","westup","su","southup",
        "nd","northdown","ed","eastdown",
        "wd","westdown","sd","southdown",
        "ne","northeast","se","southeast",
        "nw","northwest","sw","southwest",
        "u","up","d","down","out"
});

void setup()
{}

void init()
{
        add_action("do_here", "here");
        add_action("do_lead", "lead");
}

void create()
{
        set_name("����", ({"biao qi", "qi", "flag"}));
        set_weight(150);
        if (clonep())
                set_default_object(__FILE__);
        else {
              set("unit", "��");
              set("long", HIY "����һ�������ھֵ����죬һ���ǿ�����ˣ����ں����ھֵ���������ԶԶ�㿪�ˡ�\n");
              set("value", 1000);
              set("no_drop", 1);
              set("no_give", 1);
              set("no_get", 1);
        }
        setup();
}

int do_here(string str)
{
        object ob,ob_mubiao,my_object,me = this_player();
        if (!str)
                return notify_fail("��Ҫ���˼�Ů��������һ�ӾͲ���ô����\n");
        if (!(my_object = present(str, environment(me))))
                return notify_fail("��Ҫ�ҵ��˲������ȥ�����ҿ��ɡ�\n");

        if (!(ob_mubiao = present("nv juan", environment(me))))
                return notify_fail("�˶�����Ū���ˣ���������ʲô����!\n");

        if (my_object->query("name") != me->query_temp("mubiao"))
                return notify_fail(my_object->query("name")+"˵����"+RANK_D->query_respect(me)+"�㿪ʲô��Ц���ⲻ���ҵļҾ죡\n");
        if (!living(my_object))
                return notify_fail("Ŷ������Ȱ���Ū����˵��\n");
        tell_object(me, HIW + my_object->query("name")+"���ȵء���������һ����\n");
        tell_object(me, HIW + RANK_D->query_respect(me)+"ʹ���Ƿ����žۣ���ͬ���죡��������һ�ݣ�\n" NOR);
        tell_object(me, HIW "��������һ��СС����˼����ʦһ��Ҫ���¡�\n" NOR);

        me->delete_temp("mubiao");
        me->delete_temp("killed");

        me->add("potential",800+random(50));
        me->add("combat_exp",1600+random(100));
   //     me->add("SJ_Credit",1+random(2));
        ob = present("gold_money", me);
        
        if (!ob)
        {
                ob = new("/clone/money/gold");
                ob->move(me);
                ob->set_amount(5+random(5));
        }
        else
        {
                ob->add_amount(5+random(5));
        }

        me->apply_condition("husong_job", 0);
        destruct(this_object());
        destruct(me->query_temp("husongjob"));
        me->delete_temp("pass");
        me->delete_temp("mubiao");
        me->delete_temp("husongjob");
        me->delete_temp("killed");

        return 1;
}

int do_lead(string str)
{
        object ob_mubiao,me = this_player();
        int i, flag = 0;
        if (!str)
                return notify_fail("��Ҫ���˼�Ů����ʲô�ط��죿��\n");

	for ( i = 0; i<sizeof(dir_alias); i++)
		if (str == dir_alias[i]) { flag = 1; break;}
	if (!flag) return notify_fail("��Ҫ���˼�Ů����ʲô�ط��죿��\n");

        if (!(ob_mubiao = present("nv juan", environment(me))))
                return notify_fail("�����Ů�첻�����ﰡ!\n");
        if (me->query_temp("mubiao") != ob_mubiao->query_temp("mubiao"))
        	return notify_fail("��Ҫ����Ŷ��С�ĳ��¡�\n");

	ob_mubiao->force_me(str);

        return 1;
}
