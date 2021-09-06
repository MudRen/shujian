// Room: /u/qingyun/jyzj/shanbi.c
// Updated by jpei
// Modify By River@SJ
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", YEL"ɽ��"NOR);
	set("long", @LONG
���͵�ɽ�ڣ�ȫΪ��Ϊ��Ӳ����ʯ��������ţ���΢��С�ľͻỬ������
��������һƬ��ȣ�����������һɽ����
LONG	);
	set("exits", ([
		"westdown" : __DIR__"cuigu",
		"eastdown" : __DIR__"shangou",
	]));
	set("objects",([
              __DIR__"obj/rock1" : 1,
	]));

	set("outdoors", "���ش��");
	set("no_clean_up", 0);

	setup();
}

void init()
{
        add_action("do_bind", ({"bind", "baoza", "xugu", "bandage", "heal", "zhi", "yizhi", "zhiliao"}));
}

int do_bind(string arg)
{
	object monkey, plywood1, plywood2, yaocao, thread;
	object me = this_player();
	if (arg == "xiao hou" || arg == "hou" || arg == "monkey") {
            if(!(monkey = present("xiao hou", this_object())))
		return notify_fail("����ϸ�������û�к��ӣ�\n");
            if(me->query_skill("medicine", 1) < 100 )
                return notify_fail("��е��Լ�ҽ���������ֻ��ҡ��ҡͷ��\n");
	    if(!monkey->query("get_wound"))
		return notify_fail("����û�����ˣ�\n");
	    if(!monkey->query("rock_moved"))
		return notify_fail("����ѹ����ʯ�����ģ�\n");
	    if(!(plywood1 = present("zhi tiao 1", me))
             ||!(plywood2 = present("zhi tiao 2", me)))
		return notify_fail("��ϧ����ͷû���㹻�Ĺ̶��ϹǵĹ��ߡ�\n");
	    if(!(thread = present("xi si", me)))
		return notify_fail("��ϧ����ͷû�������õ��ߡ�\n");
	    if(!(yaocao = present("yao cao", me)))
		return notify_fail("��ϧ����ͷû�в�ҩ��\n");
	    destruct(plywood1);
            destruct(plywood2);
	    thread->add_amount(-1);
	    yaocao->add_amount(-1);
	    monkey->delete("get_wound");
	    monkey->delete("rock_moved");
            monkey->set("get_save", 1);
	    me->set_temp("help_monkey", 1);
	    new(__DIR__"obj/xianguo")->move(me);
	    new(__DIR__"obj/xianguo")->move(me);
	    write(HIY"��������֦����Ϊ�а壬��С�������϶Ϲǣ��Ѳ�ҩ�����˸��������˴���\n"NOR);
	    write(HIY"�Ǻ����ȻҲ֪�ж�ͼ��������ժ��Щ�ʹ�����Ȼ���ȥѰ��ĺ�����ˣȥ�ˡ�\n"NOR);
            message_vision("$n����$NһЩ�ʹ���\n",me,monkey);
	    monkey->random_move();
            return 1;
	}
	return 0;
}
