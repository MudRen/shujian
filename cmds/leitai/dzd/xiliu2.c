// Room: /d/dzd/xiliu2.c

inherit __DIR__"dzd_room";

void create()
{
	set("short","Ϫ��");
	set("long",@LONG
�ߵ������ͻȻ��ǰһ�����峺��Ϫˮ˳�����¡�Ϫ�߳��������滨��ݣ�ɢ����
Ũ������������ϸ�����ţ���������ˮ�ɻ�ģ���ģ����Ǽ��亱����������ܽ��������һ
Ƭ�ݵأ�������һƬ��ѹѹ��ɭ�֡�
LONG
	);
	set("outdoors","���ǵ�");
	set("exits",([
		"east" : __DIR__"senlin1",
		"west" : __DIR__"caodi2",
		"north" : __DIR__"xiliu3",
		"south" : __DIR__"xiliu1",
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
	if(userp(me) && me->query("no_poison")) {
		ob = present("flower",environment(me));
		ob->delete("poison");
		me->delete("no_poison");
	}
	return ::valid_leave(me, dir);
}
