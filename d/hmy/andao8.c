// andao8.c
// Created by Numa 19991021

#include <ansi.h>
inherit ROOM;

string *way = ({
	"up",
	"down",
	"west",
	"east",
	"south",
	"north",
	"southeast",
	"southwest",
	"northeast",
	"northwest",
	"southup",
	"southdown",
	"northup",
	"northdown",
	"eastup",
	"eastdown",
	"westup",
	"westdown",
});

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ͨ�������İ���������������ʽ���̾ߣ���΢�������֮�£�
ɢ���ű���ĺ��⣬����Խ��Խ�����з�ë����������֮�����ֲ�״�������
�Ľ��������и��е�һ�󾪲���
LONG
	);
	set("exits", ([ 
	  "southeast" : __DIR__"andao7",
	  "enter" : __DIR__"jail_gate",
	]));
	set("objects",([
		__DIR__"npc/shang_gp" : 1,
		__DIR__"npc/yuzu" : 2,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	int i;
	
	if(me->query_temp("hostage/job_2_1")) {
		for(i=0;i<sizeof(way);i++) {
			if (dir == way[i] && objectp(present("yu zu", environment(me)))) {
				tell_room(environment(me),"���䶢��" + me->name() + "���˼��ۣ��ȵ���" + RANK_D->query_rude(me) + "����Ȼ�ҵ�������̵ļ�������������ô��ʰ�㣡\n");
				return 0;
				break;
			}
		}
	}
	if (dir == "enter" && objectp(present("shangguan peng", environment(me)))) {
		message_vision("�Ϲ�������$N�����ȵ���" + RANK_D->query_rude(me) + "��Ҫ���ȥ�����ǹ�������ء�\n",me);
		return 0;
	}
        return ::valid_leave(me, dir);
}
