// Room: /d/huashan/qianchi.c
// Date: Look 99/03/25

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ǧ�ߴ�");
	set("long", @LONG
ǰ����һб���촹ʯ�ݵ�ɽ�ף�����Ǻպ�������ǧ�ߴ���ǧ�ߴ�����һ
�����Ҽ����ѷ쿪����ɣ�б��Լ��ʮ�ȣ���Լ��ʮ�ף�����һ�����䡣���
���Ǿ���ʮ�㣬���ǲ�Ҫð���ʵǵĺá�
LONG
	);
	set("exits", ([
		"westdown" : __DIR__"qingke",
		"southup" : __DIR__"baichi",
	]));

	set("objects", ([ 
		__DIR__"npc/jianke" : 1,
	]));
 
	set("no_clean_up", 0);
	set("outdoors", "��ɽ" );

	set("coor/x",60);
  set("coor/y",80);
   set("coor/z",20);
   setup();
}
 
int valid_leave(object me, string dir)
{
        if (dir == "southup") {
                me->receive_damage("jing", 30);
                me->receive_damage("qi", 30);
        }
	return 1;
}

void init2(object me)
{
        if (me->query_dex() <= random(30) && userp(me) && !wizardp(me) ) {
                me->receive_damage("qi", 50);
                message_vision(HIC"һ��ɽ�紵����$Nһ��С�Ľ���̤�˸��գ�... ��...\n"NOR, me);
                me->move(__DIR__"path1");
                tell_object(me, HIR"���ɽ�Ϲ���������ֻ���û����޴����ۡ�\n"NOR);
		message("vision", HIR"ֻ��" + me->name() + "��ɽ�Ϲ�µµ�ع������������ڵ��ϰ�������������\n"NOR, environment(me), me);
        }
}

