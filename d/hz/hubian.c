// /u/beyond/hangzhou/hubian.c ������
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",GRN"������"NOR);
        set("long", @LONG
��������ɽ��ˮ�㣬�̲�����������ɽɫ����ӳ��Ȥ�����ۺ������羵
���У������������续���Ρ�����֮�����������Թ����������ǳ����ޡ�
�����ġ��㡢�ᡢ�������������δ���ʫ�������ġ�ˮ�������緽�ã�ɽɫ
���������棬�������������ӣ���ױŨĨ�����ˡ�һʫ���������������ľ�
ɫ�������쾡�¡�
LONG
        );
	set("objects",([
		__DIR__"npc/you" : 2,
		__DIR__"npc/dao-ke" : 1,
	]));
        set("exits", ([
		"southwest" : __DIR__"baidi",
		"south" : __DIR__"llwying",
	]));
	set("outdoors", "����");

	setup();
}
