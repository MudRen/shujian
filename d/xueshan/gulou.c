 // gulou.c ��¥
// by dubei
 

inherit ROOM;
string gu(object);
string chui(object);
void create()
{
        set("short","��¥");
        set("long",@LONG
�����Ǵ����¹�¥��ÿ���硢�С�������Ҫ�ټ��������ʱ�򣬶�Ҫ��
��¥ͬʱ���졣��¥�ڼ���һ����(gu)���ú�����ţƤ�����Ų����ü���
ö�𶤶��Ρ��Ա�����һ�����(chui)��
LONG);
        set("exits",([
                "west": __DIR__"huilang2"
        ]));

        setup();
}
string gu(object me)
{
     return "����һ���ģ��ú�����ţƤ�����ţ������ü���ö�𶤶��Ρ�\n";
 }
string chui(object me)
{
     return "����һ�����Ǿ޴��ľ鳣���Լ���ߣ���ڴ�ϸ��\n";
 }
void init()
{
     add_action("do_strike", "qiao"); 
}
int do_strike(string arg)
{
            object me = this_player();

                if (!living(me)) return 0;
                if (arg != "dagu" && arg != "gu")
           return notify_fail("��Ҫ�û�ʲ�᣿\n");

                if ( (int)me->query_str() < 20 )
	  return notify_fail("������������鳣�̫���ˣ����Ƿ����ɡ�\n");

	  if ( (int)me->query_skill("longxiang-boruo", 1) < 41 )
	  return notify_fail("��ķ����˵�һ�����죬�����ͷ�ζ��������ڹ���Ϊ��ǳ�����ǿ��߰ɡ�\n");
                
                if ( (int)me->query_skill("hammer", 1) > 61 )
	  return notify_fail("������Ӷ�����û���ģ������������磬�����쳹���ܡ�\n");

                if ( ((int)me->query("jingli") < 40 ) ||  ((int)me->query("qi") < 40 ) )
	  return notify_fail("��о��Ѿ�������ȥ�ù��ˡ�\n");

	        me->add("qi", -20);
               me->add("jingli", -20);
              message_vision("$N�Ӷ���鳣����Ĵ�ȥ����ʱ�������˴������ܡ�\n", me);
              me->improve_skill("hammer",me->query_int());
	  return 1;
}