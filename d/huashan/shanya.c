// Room: /d/huashan/dashu.c jpei����֮��
// Date: Jpei 2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",  HIW "ɽ��" NOR);
	set("long", @LONG
������һ�����ɸߵ�ɽ�£���̧ͷһ������Ȼ����ɽ����������һ���������
���ɵ����п�ϲ���㲻ס�����Ͽ�����Ȼûע�⵽����û���κγ�·��
LONG
);

	set("no_clean_up", 0);

	set("outdoors", "��ɽ" );
	setup();
}

void init()
{
        add_action("do_tiao", "tiao");
        add_action("do_kao", "kao");
        add_action("do_cai", "cai");
}
int do_kao(string arg)
{
        object ob;
        object me = this_player();
     if (arg != "shanji" )
                 return notify_fail("��Ҫ��ʲô��\n");
         if (me->is_busy() || me->is_fighting())
                 return notify_fail("����æ���ء�\n");

           if( me->query("id") !="jpei" )
                 return notify_fail("����Ҫ��ʲô��\n");

         if ( (int)me->query("jingli")<400)
             {
                     write("������̫���ˣ���Ϣһ�°ɣ�\n");
             return 1;
             } 

        if(random(10) == 3)
             {
             me->add("jingli",-random(300));
             return notify_fail("���������˰��죬���������ɽ��������ץ��������\n"); 
             }

         message_vision("$N����һ��"HIY"���档\n"NOR, me);
         message_vision("��һ��һֻ�������"HIY"�л���"NOR"�Ϳ����ˡ���\n"NOR, me);
         ob = new("/kungfu/class/gaibang/obj/jiaohuaji");
 ob->move(me);
 ob = new("/d/xingxiu/obj/huoyan");
ob->move(environment(me));
     return 1;
}
int do_cai(string arg)
{
	object ob;
        object me = this_player();

        if (arg != "zhuguo")
                return notify_fail("��Ҫ��ʲô��\n");
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ء�\n");

          if( me->query("id") !="jpei" )
                return notify_fail("һ�������Կ������𣬡��������������������滨���֮���ԣ���һ�鷲������ν����ģ�����\n");

        if ( (int)me->query("jingli")<400)
        	{
             	write("������̫���ˣ���Ϣһ�°ɣ�\n");
		return 1;
		}
        if(random(20) == 3)
        	{
        	me->add("jingli",-random(300));
        	return notify_fail("���������˰��죬ʲôҲû�ҵ���\n"); 
         	}

        if (present("zhuguo", me))
               return notify_fail("�������Ѿ���һö"HIR"�������"NOR"�ˣ�ĪҪ̰�����ᣡ\n");
        message_vision("$N���ѵ���Ե��֮�ϣ����ֲ�����һö"HIR"�������"NOR"��\n���Ȼ�����Ա߻��г���һ��"HIG"�ݻ���"NOR"���Ͻ�����������\n"NOR, me);
        ob = new("/u/jpei/zhuguo");
ob->move(me);
        ob = new("/u/jpei/huandan");
//ob->move(me)
	return 1;
}

int do_tiao(string arg)
{
        object me = this_player();
	if (arg != "xiaoxi")
                return notify_fail("��Ҫ����������\n");
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ء�\n");
	if ((int)me->query("max_neili") < 401)
		return notify_fail("�㳢��������СϪ��ȴ�����Լ�������ȥ��\n");
	message_vision("$Nһ��������԰�����ȥ��\n", me);
	tell_object(me, "�㷢���Լ������˸ղ����ĵط���\n");

        me->receive_damage("jing", 30);
	me->move(__DIR__"xiaoxi");
	message_vision("$N��СϪ�Ǳ����˹�����\n", me);

        me->start_busy(random(2));
        return 1;
}

