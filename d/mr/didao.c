// /d/mr/didao.c
// by leontt 11/10/2000

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",BLU"�ص�"NOR);
	set("long", @long
������Ľ�����ҵ�����ͨ������������ܲ����쳣��ʪ������
long);
	set("exits",([
		"yanziwu" : __DIR__"yanziwu/shuixie",
		"shanzhuang" : __DIR__"mtl/shiqiao1",
		"xiaodao" : __DIR__"houtang",
		"north" : __DIR__"didao1",
		"out" : __DIR__"shiqiao",
	]));
	setup();
}
