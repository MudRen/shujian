// /u/beyond/ningbo/qsddao1.c 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ�ٵ�");
        set("long",@long
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С���������Ǻ��ݳ��ˡ����ѿ���һ
Ƭ����ɫ���������Ǻ��ݷ���
long);
	set("outdoors", "����");
	set("exits",([
		"southeast" : "/d/group/entry/nbqsddao",
		"westup" : "/d/hz/shanlu2",
	]));
	setup();
}
