// /d/mr/yunjinlou.c
// update 1997.6.20 by beyond

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",MAG"�ƽ�¥"NOR);
	set("long",@long
�ƽ�¥���踻����һ�����û���ǿ�ȸ����ͼ������������д��һ������
(duilian)��������һ��������������᷿�����������Ǻ�Ժ�������Ǻ�԰��
long);
	set("item_desc", ([
		"duilian" : "��Ҷ�Ʋ���, �軨ѩ���ޡ�\n"
	]));
	set("valid_startroom", 1);
	set("exits",([
		"east" : __DIR__"keting",
		"west" : __DIR__"xiangfang1",
		"south" : __DIR__"hhyuan",
		"up" : __DIR__"cangshuge",
		"north" : __DIR__"houyuan",
	]));
	set("objects",([
		__DIR__"../npc/wang" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
        mapping fam;
        fam = (mapping)me->query("family");

        if ((!fam || fam["family_name"] != "����Ľ��") && dir == "up"
         && objectp(present("wang furen", environment(me))))
        	return notify_fail("�����˺���һ������¥��������٢��ɽׯ�Ĳ������Ҳ���ϣ�\n");
	return ::valid_leave(me, dir);
}
