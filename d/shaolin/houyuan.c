//houyuan

#include <ansi.h>
 
inherit ROOM;

void create()
{
	set("short", HIW"С��"NOR);
	set("long",@LONG
����һ��ܼ򵥴��ݣ�ֻ��һ��һ�Σ�����������ż������飬�Աߵ�һ
յ�͵�ɢ���Ż谵�Ĺ���������������һ��������������Ĺۿ����顣
LONG
    );
	set("exits",([
		"enter"  :    __DIR__"liwu",
		"north"  :   __DIR__"xiaojin1",
	]));
	set("cant_hubiao", 1);
	set("objects",([
		"/d/mr/npc/murong-bo": 1,
	]));
	set("valid_startroom", 1);
	setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "������" || myfam["generation"] != 35 ) && dir != "north" 
               &&!present("jiaxin", me)&&objectp(present("murong bo", environment(me))))
        return notify_fail("Ľ�ݲ���ס��˵������ʦ���������澲�ޣ���Ҫȥ���������˼ҡ�\n");
                
        return ::valid_leave(me, dir);
}
