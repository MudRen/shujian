// Room: /d/gb/pomiao.c
// update by Looklove at 2000/8/25

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ���������õ������������ưܲ�����������������һ�ԣ����ϵ�
��Ҳ�����˻ҳ���һ����֪���Ѿ��ܾ�û������������ˡ����з��Ÿ����㰸��
�������ҵ����ż�����ʣ�����ļ���ͷ��Ҳ��������Ϊ���ε�ԭ��ɣ���˵ؤ
�ｭ�Ͼݵ�ͱ����ڴ˴�������ǽ�Ͽ���һ��С�š�
LONG
	);
	set("valid_startroom", 1);
	set("outdoors","����");
	set("exits", ([
		"south" : __DIR__"xinglin9",
		"north" : __DIR__"houyuan",
	]));
	set("objects", ([
		CLASS_D("gaibang") + "/lu" : 1,
	]));
	setup();
	create_door("north", "����", "south", DOOR_CLOSED);
}

void reset()
{
	object ob=present("lu youjiao",this_object());
	::reset();
	if(ob){
		ob->delete_temp("gb_job2");
		ob->delete_temp("gb_job3");
		ob->delete_temp("smy_job");
	}
}

void init()
{
        object me = this_player();
	int i;
        if ( userp(me) && me->query("gb_bags") && !me->query_temp("change_bags")){
		i = me->query("gb_bags");
                me->set("gb/bags", i);
                me->delete("gb_bags");
                me->set_temp("change_bags", 1);
		log_file("change_gb", sprintf("%8s%-10s ��������޸���ϣ����˵�ǰΪ%3d����",
			me->query("name"), "("+me->query("id")+")", me->query("gb/bags")), me);
        }
}
int valid_leave(object me, string dir)
{
        if (!wizardp(me) && dir == "north" && objectp(present("lu youjiao", environment(me)))){
        	if ( me->query_temp("noget_wugou")>10)
			return notify_fail("³�н����������ǰ�������������ڲ�����㡣��\n");
	}
        return ::valid_leave(me, dir);
}