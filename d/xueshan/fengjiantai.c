// Room: fengjiantai.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "���̨");
	set("long", @LONG
�ߵ������ǰ��Ȼ���ʣ�ֻ��һ����Բ��ʮ�ɿ�ƺ�����ܹ�ͺͺ��ֻ��
Щ�Ӳݣ����ݴ�¶��һƬƬ��ѩ������һƬ�ž���ֻ��������ɽ���Х������
�����Ǻ���Ĺ��졣
LONG
	);

	set("exits", ([
		"northup" : __DIR__"xuelingquan",
		"eastdown" : __DIR__"shanlu4",
                "west" : __DIR__"luofenggang",
	]));
        set("outdoors", "ѩɽ");
	setup();
}

void init()
{
	object ob = this_player();
	if (3000/((int)ob->query_skill("dodge")+10) > random(300) && !ob->query("env/invisibility")) {
		message_vision(HIW"ͻȻһ�������ѩ�����������$N���֮�£��ĵ��㺮��\n"+
			"����ס���²��ȣ�˳��ɽ·ˤ����ȥ��\n"NOR,ob);
		ob->move(__DIR__"shanlu"+(random(4)+1));
		tell_object(ob,HIW"�㷴ӦѸ�٣���æ˫�ֱ�ͷ��������������ǰ����ڵأ�˳��ɽ·ֱ������ȥ��\n"NOR);
		tell_room(environment(ob),HIW"ֻ������ͨ��һ����"+ob->query("name")+"��֪�������������������ˤ�ڵ��ϡ�\n"NOR, ({ ob }));
	}
}
