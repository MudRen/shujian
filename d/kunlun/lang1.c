#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	 set("short","����");
	 set("long",@long
����һ�����ȣ�����ǰ���Ϳͷ������Ͽ������ִ��Ľ�����ʿ�߹�����
�����⣬��һƬ��ɫ�����֣��ľ����£�ֻ�������ϴ�������������
long);
	 set("exits",([
            "north" : __DIR__"huayuan1",
            "south" : __DIR__"sanshengtang",
            "east" : __DIR__"lang2",
         ]));

         set("outdoors", "����");
         setup();
}
