// /u/beyond/ningbo/qsddao1.c 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ�ٵ�");
        set("long",@long
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С�����������Ǻ��ݳ��ˡ�
long);
	set("outdoors", "������");
	set("group", 1);
	set("exits",([
		"southeast" : "/d/ningbo/shilu",
		"northwest" : "/d/ningbo/qsddao1",
	]));
	setup();
}
