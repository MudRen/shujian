// Room: /d/putian/jcyuan.c ���Ժ
// lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIB"���Ժ"NOR);
        set("long", @LONG
�����ǽ��Ժ���൱����ɽ���ֱ�Ժ�Ľ���Ժ����������Ż����գ��ܲ�
͸�硣�������ڰ��磬Ҳ�����ҹһ�㣬ǽ�ϵ��ż�֦���򡣵��Ϲ����Ž�ħ
Τ�ӣ��·�����һ��ˮţƤ�ޡ�������弰��������ִ�����ȡ�����վ���˻�
���䵶��ִ��ɮ���������������ϵ�����������㣬���㲻���������⡣
LONG
        );

        set("exits", ([
                "north" : __DIR__"xm-dian",
                "south" : __DIR__"jingshi",
                "east" : __DIR__"changlang3",
                "west" : __DIR__"changlang2"
        ]));

        set("objects",([
                __DIR__"npc/shami" : 1,
                CLASS_D("putian") + "/da-dian" : 1,
        ]));

        setup();
}
int valid_leave(object me, string dir)
{
	if (objectp(present("dadian dashi", environment(me))) && dir == "south")
		return notify_fail("��ߴ�ʦ������ü����û���벻Ҫ�Ҵ���\n");

	return ::valid_leave(me, dir);
}