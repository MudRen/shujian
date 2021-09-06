// Room: /d/shaolin/jianyu.c
// Date: YZC 96/02/06
// Modify by looklove 2000/8/25 about water& food

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ڳ����ģ�����һ˿������Ҳ�ް����Ϣ���ڰ�����ϡ���Կ������
�ƺ��м�����Ӱ��������ת��ͷȥ������������ס���������ŵص����㡣�ı�
����ȥ�������Ҽ�Ӳ���ƺ����Ǹ������ɣ�ֻ���ϱ������һ��С�ţ����Ͽ�
�˸����ƴ�Ķ��������ͷ��õġ��ű���һ�Ѷ�������ȥ�����ݵ�ɢ�˿�����
ϸ��ȴ��һ�߰׵÷����Ŀݹǡ�
LONG
	);

	set("no_update", 1);
	set("valid_startroom",1);
	set("objects",([
		CLASS_D("shaolin") + "/qing-yuan" : 1,
		"/d/shaolin/obj/fojing1"+random(2) : 1,
	]));
	setup();

}

void init()
{       
	object ob = this_player();
        ob->set("water",500);
        ob->set("food",500);

	if(userp(ob)) {
		message("vision",
			HIY "ֻ���η����ſ��һ�죬һ���������ļһﱻ���˽�����\n\n" NOR, 
			environment(ob), ob);
		tell_object(ob, "����ٺٵ�Ц�ţ���������������������...��\n");
		ob->set("startroom", "/d/shaolin/jianyu");
		if (!ob->query_condition("bonze_jail")) ob->apply_condition("bonze_jail", 60);
	}
}
