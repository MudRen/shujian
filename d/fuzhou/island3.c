// island3.c  ɳ̲ �������ԣ��Ա����
// Looklove 2k/5/18
// 2001.9.27 update

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIB"ɳ̲"NOR);
        set("long", @LONG
����һ��Ƭɳ̲����Χ�����˱��ǣ������з�ڶ���ð����ĭ��ůů����
���������ϣ�ɹ�������������ġ������ĺ�ˮһ�������������ˢ�������
��Сʯ�ӡ�Զ���м����ʯ���������ﾭ���Ų��εĳ����
LONG
        );
        set("outdoors","����");
        set("exits",([
		"west" : __DIR__"island4",
		"east" : __DIR__"island1",
		"north" : __DIR__"rock",
        ]));
	set("objects", ([
                MISC_D("beike") : 1,
	]));
        setup();
}