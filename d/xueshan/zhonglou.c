 // zhonglou.c ��¥

#include <ansi.h>

inherit ROOM;
string zhong(object);
string chu(object);
void create()
{
        set("short",NOR "��¥");
        set("long",@LONG
�����Ǵ�������¥��ÿ���硢�С�������Ҫ�ټ��������ʱ�򣬶�Ҫ��
��¥ͬʱ���졣��¥�ڹ�һ��ǧ�����( zhong)����Լ��һ�磬��������һ��
�޴�����(chui)������Ҳ���ϰٽ���û��һ�����⹦��Ϊ���൱���ڹ�
���޷�����ġ�
LONG);
        set("exits",([
                "east": __DIR__ "huilang1",
        ]));

        setup();
 
}
string gu(object me)
{
     return "����һ������ͭ����ɵĴ��ӡ�\n";
 }
string chui(object me)
{
     return "����һ���޴�İ���ľ鳣���Լ���ߣ���ڴ�ϸ��\n";
 }
void init()
{
     add_action("do_strike", "ji"); 
}
int do_strike(string arg)
{
            object me = this_player();

                if (!living(me)) return 0;
                if (arg != "zhong" && arg != "dazhong")
           return notify_fail("��Ҫ�û�ʲ�᣿\n");

                if ( (int)me->query_str() < 30 )
	  return notify_fail("��ʹ�����̵������ƶ���鳣����Ӳ��˼��£�ûʲô������\n");

	  if ( (int)me->query_skill("longxiang-boruo", 1) < 81 )
	  return notify_fail("���ӷ����۵�һ�����죬�����ͷ�ζ��������ڹ���Ϊ��ǳ�����ǿ��߰ɡ�\n");
                
                if ( (int)me->query_skill("hammer", 1) > 101 )
	  return notify_fail("�����ɵ��ƶ�����û����ӣ����ӷ���������졣\n");
               
                if ( ((int)me->query("jingli") < 40 ) ||  ((int)me->query("qi") < 40 ) )
	  return notify_fail("��о��Ѿ�������ȥ�û������ˡ�\n");

	        me->add("qi", -20);
               me->add("jingli", -20);
              message_vision("$N�ƶ���鳣��������ȥ����ʱ�����������������¡�\n", me);
              me->improve_skill("hammer",me->query_int());
	  return 1;
}