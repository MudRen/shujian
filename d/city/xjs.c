// /d/city/xjs.c С��ɽ
// this is made by beyond update 1997.7.5
// Lklv modified at 2002.1.23 ��ػ����

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIW"С��ɽ"NOR);
	set("long",@long
С��ɽԭ��Ϊ�����룬���滷ˮ��ɽ��԰�ֶ��ں��ĵ�С���ϣ�ɽ������
��ͤɽ��ֲ�ɰء�ɽ��´ǽ����С��������֮�����Ļ���һ�������Ļ�����
���ж���һ��������������ˮ������һ��ɽ����
long);
        set("no_fight", 1);
	set("exits",([
		"west" : __DIR__"dhq",
	]));
        set("objects", ([
                NPC_D("tdh/lishikai"): 1,
        ]));
	set("outdoors", "����");
	setup();
}
