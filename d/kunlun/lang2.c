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
            "north" : __DIR__"lang",
            "east" : __DIR__"liangong",
            "west" : __DIR__"lang1",
         ]));

         set("outdoors", "����");
         setup();
}
