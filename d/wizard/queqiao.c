
// Date: Zhuifeng 2010

#include <ansi.h>
inherit ROOM;

void create()
{
          set("short",  HIC "ȵ ��" NOR);
	set("long", @LONG
 �������ȵ�ţ�ÿ��ũ���������գ�ţ�ɺ�֯Ů�ͻ�õ�������������ᣬ
ȵ�ű���һ��ǧ��"HIR"��˼�춹"NOR"(Xiangsi dou)�������Բɼ�(caiji)�춹��ף��
���ÿ��ֻ�ܼ�һ�ε����ɾ��£�Ҳף���Լ�Ҳ���������İ��顣

LONG
);

	set("no_clean_up", 0);
        set("exits", ([
                 "down" : "d/wizard/guest_room",
        ]));
    set("no_fight", 1);
	setup();
}

void init()
{
        add_action("do_caiji", "caiji");
}

int do_caiji(string arg)
{
	object ob;
        object me = this_player();

        if (arg != "xiangsi dou")
                return notify_fail("��Ҫ��ʲô��\n");
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ء�\n");

          if( me->query("xsd2010"))
                return notify_fail("һ�������Կ������𣬡��Ҳ����ɹ�ʵҪ�յ��ͷ��ģ��ѵ������һ���������𣿣���\n");

        if ( (int)me->query("jingli")<400)
        	{
             	write("������̫���ˣ���Ϣһ�°ɣ�\n");
		return 1;
		}
        if(random(20) == 3)
        	{
        	me->add("jingli",-random(300));
        	return notify_fail("��ʹ�����̵��������ϱģ������޷�������˼�춹��������ͷ�󺹡�\n"); 
         	}

        if (present("xiangsi dou", me))
               return notify_fail("�������Ѿ���һö"HIR"��˼�춹"NOR"�ˣ�ĪҪ̰�����ᣡ\n");
               
        message_vision("$N���ѵ���Ե�����ϣ����ֲ�����һö"HIR"��˼�춹"NOR""��\n, me);
        
        ob = new("/u/jpei/zhuguo");
        ob->move(me);
        me->set("xsd2010",1);
	return 1;
}


