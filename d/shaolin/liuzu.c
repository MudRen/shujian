//liuzu.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "�����");
	set("long", @LONG
�����ǹ�����������ĵط��������ǹ��������⣬���ͣ��زأ�������
���������������ɽ�����ų����Ħ������ݿɣ�����ɮ貣�������ţ�
������̣�������ܵ����� 
LONG
	);

	set("exits", ([
//		"north" : __DIR__"hguangz2",
                "east" : __DIR__"pingtai",
       ]));
         set("objects",([
		CLASS_D("shaolin") + "/dao-cheng" : 1,
                __DIR__"obj/muchui" : 1,
	]));

		setup();
}



