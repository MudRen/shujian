// island5.c ɳ̲
// By Looklove for a Quest
// 2001.9.27 update

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"ɳ̲"NOR);
        set("long", @LONG
����һ��Ƭɳ̲����Χ�����˱��ǣ������з�ڶ���ð����ĭ��ůů����
���������ϣ�ɹ�������������ġ������ĺ�ˮһ�������������ˢ�������
��Сʯ�ӡ�Զ���м����ʯ���������ﾭ���Ų��εĳ����
LONG
        );
        set("outdoors","����");
        set("exits",([
		"north" : __DIR__"island4",
		"eastup" : __DIR__"lagoon",
        ]));

	set("objects", ([
                MISC_D("beike") : 2,
	]));

        setup();
}