// Room: /d/mr/houting.c
// this is made by beyond
// last update 1997/JULY/5
// Lklv Modify at 2001.9.20

#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIW"����"NOR);
	set("long", @LONG
����������������ɽ���滨�������������������춷�̡����̲�ʯ����
������Ľ�ݼ�����������ĵط�������Ľ�ݵ�����ò�Ҫ�����������ں�����
�аڷ���һ���㰸������ڷ���һ����λ���ӣ�paizi)��������ǽ�Ϲ���һ��
���񳯷�ͼ����ǽ�Ϲ���һ�ڱ����������������һ���᷿�����������á�
LONG
    );
	set("item_desc",([
		"paizi" : "Ľ������������λ\n",
		"sword" : "����һ�������ı�����͸�ű���ɫ��\n",
		"baojian" : "����һ�������ı�����͸�ű���ɫ��\n",
		"jian" : "����һ�������ı�����͸�ű���ɫ��\n",
	]));

	set("exits",([
		"east" : __DIR__"xiangfang2",
		"west" : __DIR__"xiangfang3",
		"south" : __DIR__"neitang",
		"north" : __DIR__"dating",
	]));

	setup();
}

void init()
{
        add_action("do_ketou", "ketou");
        add_action("do_ketou", "�ݼ�");
}

int do_ketou()
{
        object me,ob,obj;

        me = this_player();
        ob = this_object();

	if (me->query("family/family_name") != "����Ľ��")
		return notify_fail("��������ƿ��˼�����ͷ����Ľ�ݼҵ����ȱ�ʾ�˾��⡣\n");
        if ( !present("yu xi",me) ) return 0;
        if ( me->query_temp("Ľ��/ketou") == 2 ) {
		obj=unew(BINGQI_D("sword/biyu-jian"));
        if(!clonep(obj) || (int)me->query("combat_exp", 1) < 50000)
		return notify_fail("����˰���ͷ�����ʲôҲû�з�����\n");
        obj->move(ob);
        message("vision","ֻ��������һ�������������һ�Ѻ��������ı�����\n",me);
        destruct(present("yu xi",me));
        me->delete_temp("Ľ��/ketou");
        return 1;
	}
	else {
		me->add_temp("Ľ��/ketou", 1);
		message_vision("$N����������������ǰ���˸���ͷ��\n", me);
		return 1;
        }
}
