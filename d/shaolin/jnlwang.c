//jnlwang.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "����������");
	set("long", @LONG
������й����Ž��������������������ܵ�ǽ���ϻ���������ʤ����
��ʮ��Ը����ʮ������ıڻ�����ͼ��ΰ��ɫ��Ѥ��������������������ϸ
�������м���������ڶ���Ĥ�ݡ�
LONG
	);

	set("exits", ([
//		"north" : __DIR__"hguangz2",
                "west" : __DIR__"pingtai",
       ]));
         set("objects",([
		CLASS_D("shaolin") + "/dao-pin" : 1,
	        __DIR__"obj/muchui" : 1,
         ]));

		setup();
}



