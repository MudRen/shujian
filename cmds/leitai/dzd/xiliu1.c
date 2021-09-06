// Room: /d/dzd/xiliu1.c

inherit __DIR__"dzd_room";

void create()
{
	set("short","Ϫ��");
	set("long",@LONG
�ߵ������ͻȻ��ǰһ�����峺��Ϫˮ˳�����¡�Ϫ�߳��������滨��ݣ�ɢ����Ũ��
����������ϸ�����ţ���������ˮ�ɻ�ģ���ģ����Ǽ��亱����������ܽ��������һƬ��
��,������һƬ���֡�
LONG
	);
	set("outdoors","���ǵ�");
	set("exits",([
		"east" : __DIR__"shulin1",
		"west" : __DIR__"caodi1",
		"north" : __DIR__"xiliu2",
		"south" : __DIR__"haitan1",
	]));
	set("objects",([
		__DIR__"npc/eyu" : random(2),
		__DIR__"npc/obj/flower" : 1,
	]));
	setup();
}

int valid_leave(object me,string dir)
{
	object ob;
	if(userp(me) && me->query_temp("dzd_quest/no_poison")) {
		ob = present("flower",environment(me));
		if(ob) ob->delete_temp("poison");
		me->delete_temp("dzd_quest/no_poison");
	}
	return ::valid_leave(me, dir);
}
