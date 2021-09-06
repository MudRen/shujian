// Room: /d/taishan/.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ʯ����");
        set("long", @LONG
������һ���ʯƺ��ʯ�����׭�ġ���վ�������������綷����ȴû��
���ؿ�ʯ�ߵ����ֺͿ�ʯ����������˴˴��������ɽ��ɽ·Խ��Խ�������ˡ�
LONG
        );
        set("exits", ([
                "northup" : __DIR__"huima",
                "westdown" : __DIR__"doumo",
        ]));
        set("objects",([
                __DIR__"npc/seng-ren" : 1,
        ]));
        set("outdoors", "̩ɽ");
	setup();
}

void init()
{
        add_action("do_mosong", "mosong");
}

int do_mosong(string arg)
{
        object me;
        me = this_player();
	if (!living(me)) return notify_fail("");
        if ( !arg || ( arg != "stone" ) )
		return notify_fail("ʲô��\n");
        if (me->query_skill("literate",1)<150)
		return notify_fail("����Ļ�̫�����ʶʯ���ϵ����ġ�\n");
        if (me->query_skill("buddhism",1)<160)
		return notify_fail("��������ķ�̫�ͣ����������վ��⡣\n");
        if (me->query_skill("yijin-jing",1)<180)
		return notify_fail("����Ž�վ��������Լ����׽��Ϊ̫�������������\n");
        if (me->query_skill("shaolin-shenfa",1)<180)
		return notify_fail("����ʶ��վ��⣬�����ñ����ᱳʹ��ԭ��������̫����ܾ�վ��\n");
	if (!me->query_temp("sl_wm4"))
		return notify_fail("�����ʯ��һ��Īչ��\n");
	if (random(30)==1) {
		write (HIY"�����ʯƺ�ϵġ���վ�����ĥ��һ�ض����ƺ���һЩ��������Щ���ʡ�\n"NOR);
		me->delete_temp("sl_wm4");
		me->set_temp("sl_findjing",1);
	}
	message_vision("$N��ר���ж�ʯƺ�ϵġ���վ�����\n", me);
	me->add("jingli", -20);
	return 1;
}
