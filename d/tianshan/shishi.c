// Room: /d/tianshan/shishi.c
// By Linux

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����ʯ��");
	set("long", @LONG
���������չ�������ʯ�ң�ֻ��ʯ���ı���ʯ��ĥ�����ǹ⻬��ʯ���Ͽ�
�����������������ԲȦ��ÿ��Ȧ�ж����˸��ָ�����ͼ�Σ��е���������
�������Σ��е��ǲ�ȱ��ȫ�����֣�����Щֻ�ǼǺź�������ԲȦ��ע������
һ�������׶���������һ�������Ӷ��������֣�ԲȦ֮��������ǧ������Ҳ��
�˾Űٸ���ǽ���ƺ���һ��С��(Zi)���ϱߵ�ǽ�ϸ�����һ����ı��顣
LONG);   
	 set("item_desc", ([                    
                "zi": HIW"\n��ǽ�������̵�����ɽ������Ҫ�����ұ�����ɽ��÷�ֿھ������ϱ�ǽ\n"+
			"�ϵı���(south bing)���ƿ����뿪ʯ�ҡ�\n\n"+
			"		                        ��ɽͯ����\n\n"NOR,
        ])); 
	setup();
}

void init()
{
	add_action("do_learn", ({"yanxi", "learn"}));    
	add_action("do_break", ({"break", "po"}));    
}

int do_learn(string arg)
{
	object me;
	int improve, cost;
	me = this_player();
	improve = me->query_int() / 10 + random(me->query_int() * 5 / 6);

	if( !arg || arg=="" ) return 0;

	if (arg == "east wall" ){             
		if( !me->query("tonglao/ok"))  
			return notify_fail("�㿴��ǽ�ڿ��˰��죬Ҳ����������д����ʲô��\n");
		if(me->query_skill("liuyang-zhang", 1) > 80 )  
			return notify_fail("ǽ�ϵ�������Ҫ��������˵̫ǳ�ˡ�\n");

		cost = 300 / (int)me->query("int");
		cost = 300 / (int)me->query("int");

		if ((int)me->query("jingli") < cost || (int)me->query("jing") < cost){
			message_vision("$Nר�ĵĿ���ǽ�ϵ�������Ҫ����ͻȻͷ�����͡�\n",me);
			me->unconcious();
			return 1;
		} 
		message_vision("$NĬ��������Ҫ����������ʯ����Ȼ�������\n",me);  
		me->improve_skill("liuyang-zhang", improve);            
		me->add("jing", -cost);
		me->add("jingli", -cost);                        
		return 1;
	}
	if (arg == "west wall" ){             
		if( !me->query("tonglao/ok"))  
			return notify_fail("�㿴��ǽ�ڿ��˰��죬Ҳ����������д����ʲô��\n");
		if(me->query_skill("zhemei-shou", 1) > 80 )  
			return notify_fail("ǽ�ϵ���÷�ֿھ�������˵̫ǳ�ˡ�\n");

		cost = 300 / (int)me->query("int");
		cost = 300 / (int)me->query("int");

		if ((int)me->query("jingli") < cost || (int)me->query("jing") < cost){
			message_vision("$Nר�ĵĿ���ǽ�ϵ���÷�ֿھ���ͻȻͷ�����͡�\n",me);
			me->unconcious();
			return 1;
		} 
		message_vision("$NĬ����÷�ֿھ���������ʯ����Ȼ�������\n",me);  
		me->improve_skill("zhemei-shou", improve);            
		me->add("jing", -cost);
		me->add("jingli", -cost);                        
		return 1;
	}
	return 0;
}

int do_break(string arg)
{
	object me;
	me = this_player();
	if( !arg || arg=="" ) return 0;
	if (arg == "south bing" ){   
		message_vision("����Ӧ�����飬�ֳ�һ���󶴡�\n", me); 
		message_vision("$N�������ӣ�������Ǹ��󶴣�����һ�󺮷紵�������ֱ���ѩ��ס�ˡ�\n", me);                      
		me->move(__DIR__"shanjin1");
		message("vision", me->name() + "���Ա�һ��������עĿ�Ĵ������˳�����\n",environment(me), ({me}) );
		return 1;
	}
	return 0;
}
