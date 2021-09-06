// Room: /d/shaolin/dmyuan.c
// Date: YZC 96/01/19

inherit ROOM;

#include <ansi.h>

int nokill()
{
	object ob = previous_object(1);

	if (ob == find_object("/cmds/skill/exercise")
	|| ob == find_object("/cmds/skill/respirate"))
		return 0;
	return 1;
}

int check(string arg)
{
	if (arg) {
		object me = this_player();
		int i;

		sscanf(arg, "%d", i);
		switch (query_verb()) {
			case "exercise":
				if (me->query("neili") + i >= me->query("max_neili")*2) {
					write("����ɲ���������������ĵط���\n");
					return 1;
				}
				break;
			case "respirate":
				if (me->query("jingli") + i >= me->query("eff_jingli")*2) {
					write("����ɲ���������߾����ĵط���\n");
					return 1;
				}
				break;
		}
	}
	return 0;
}

void init()
{
	add_action("check", ({ "exercise", "respirate" }));
}

void create()
{
        set("short", HIY"��ĦԺ"NOR);
        set("long", @LONG
����һ�����ӵĵ��á����׵�ǽ�Ϲ����˸����书ͼ�ף����ٰ����ü
����ɮ����������ͼ�׻���֮ǰ���ƺ��ڿ��˼�����ϱ�ɽǽ�Ǹ߼��ݶ���
����ܣ��߽�ϸ���������Ǹ��Ÿ��ɵ��书���ţ������а��ż��Ű���ڭ��
�������ţ���λ��ɮ�����붨�С������и�С��ͨ���
LONG
        );
	set("no_fight", (: nokill :));
        set("exits", ([
                "south" : __DIR__"huilang4",
                "north" : __DIR__"dmyuan2",
        ]));
        set("objects",([
                CLASS_D("shaolin") + "/xuan-bei" : 1,
                __DIR__"npc/xiao-bei" : 1,
        ]));

        set("coor/x",20);
	set("coor/y",430);
	set("coor/z",130);
	setup();
}

int valid_leave(object me, string dir)
{
	if( dir == "north" && !me->query("luohan_winner") && !wizardp(me))
	if(objectp(present("xuanbei dashi", environment(me))))
		return notify_fail("������ʦ�ȵ�����ĦԺ�˱����صأ��㲻�����ڡ�\n");
	else 
		return notify_fail("һλ��ɮ��Ȼ�ӱ������˳�������ס����˵������ĦԺ�������صأ��㲻�����롣\n"+
			"����ͣ�������ˣ���λ��ɮһ���֣����˻���������\n");
	return ::valid_leave(me, dir);
}
