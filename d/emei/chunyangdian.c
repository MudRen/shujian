// Room: /d/emei/chunyangdian.c
// Modify by Lklv add �����ﶡ����

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIR "������" NOR);
	set("long", @LONG
�������һǧ���ף������ľ�Դ䣬�ľ����ˡ���ǰ��һʯ��������ʯ��
��˵����������ɽʱ������������Ϣ�����ڴ˿��ݹ۶�����壬�����𶥣���
���ͱڣ�������ߡ�������������ˮ�֣������ǹ��Ƹ�
LONG
	);
	set("outdoors", "��üɽ");
	set("exits", ([
		"eastdown" : __DIR__"guiyunge",
		"westup" : __DIR__"shenshuian",
	]));
        set("objects",([
		CLASS_D("emei") + "/ding-minjun" : 1,
		"/d/emei/npc/dizi" : 1,
	]));
	setup();
}
