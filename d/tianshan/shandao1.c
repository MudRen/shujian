// Room: /d/tianshan/shandao1.c
// By Linux

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"ɽ��"NOR);
	set("long", @LONG
����ɽ��֮�У�Խ�ߵ��Ե��Ҳ�Խ�������۵�·��᫣���ʯ��ᾡ�������
�ƻ�첽��ȥ���ƻ������ң�����˺�һ�ᣬ��������˸˸���Ʋ�������
LONG);
	set("exits", ([
		"east" : __FILE__,
		"south" : __FILE__,
		"west" : __FILE__,
		"north" : __FILE__,
	]));       

	set("outdoors", "��ɽ");
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "west") me->add_temp("mark/steps",-1);
	if (dir == "south") me->add_temp("mark/step",1);
	if (dir == "east") me->add_temp("mark/steps",1); 
        if (dir == "north") me->add_temp("mark/step",-1);

	if (me->query_temp("mark/steps") > 8 || me->query_temp("mark/step") < -8) {
		me->move(__DIR__"shanjin2");
		me->delete_temp("tonglao");
		me->delete_temp("mark");
		log_file("quest/tonglao", sprintf("%8s%-10sδͨ��ͯ�ѽ��Եڶ���������%d������%d���ݣ�%d��������%d��\n",
			me->name(),"("+me->query("id")+")", me->query("kar"), me->query("pur"), 
			me->query_per(), me->query("quest/tonglao/quest")), me);
		return notify_fail(CYN"\n�������������ƿ��е��а�š���\n"NOR"��֪�������߻ص�ԭ����ɽ·�ϡ�\n"NOR);
	}
	if (me->query_temp("mark/steps") == me->query_temp("tonglao/steps") 
	 && me->query_temp("mark/step") == me->query_temp("tonglao/step")) {
		if (random(me->query("kar")) >= 20
		 && random(me->query("pur")) >= 25
		 && me->query("per") < 15
		 && random (41 - me->query_per()) >= 25) {
			me->delete_temp("tonglao");
			me->set_temp("tonglao/pass2",1);
			me->delete_temp("mark");
			me->set("quest/tonglao/second", 1);
			log_file("quest/tonglao", sprintf("%8s%-10sͨ��ͯ�ѽ��Եڶ���������%d������%d���ݣ�%d/%d��������%d��\n",
				me->name(),"("+me->query("id")+")", me->query("kar"), me->query("pur"), me->query("per"), 
				me->query_per(), me->query("quest/tonglao/quest")), me);
			tell_object(me, YEL"\n����Ŀ��ɽ����ȥ��ֻ���ǵƻ𷢳������͵Ĺ�â���Ĳ�ͬѰ���ƻ��ɫ��\n"
					     "������ơ���ӿ�Ų������̵�����ǰ�����㿴�ø�������ˡ�\n\n"NOR);
			me->move(__DIR__"shangu");
			return notify_fail(YEL"�㷢����аħ����ڴ˾ۻᣬ�Ͻ��㵽�Աߵ���ʯ�ж���������\n"NOR);
	        }
		else {
			me->move(__DIR__"shanjin2");
			me->delete_temp("tonglao");
			me->delete_temp("mark");
			log_file("quest/tonglao", sprintf("%8s%-10sδͨ��ͯ�ѽ��Եڶ���������%d������%d���ݣ�%d��������%d��\n",
				me->name(),"("+me->query("id")+")", me->query("kar"), me->query("pur"), 
				me->query_per(), me->query("quest/tonglao/quest")), me);
			return notify_fail(CYN"�������������ƿ��е��а�š���\n��֪�������߻ص�ԭ����ɽ·�ϡ�\n"NOR);
		}
	}
        return ::valid_leave(me, dir);
}
