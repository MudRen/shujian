// shanlu8.c
// By River 98/09

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", YEL"���"NOR);
	set("long", @LONG
�˴���һ�����ɽ·����������������������Ω�������ȵף����Է��ۣ�
��ɽ�żţ�΢��������ãã����ֻ��һ�˶��ѡ����н��ͣ��߽���һ��ɽ
�ȣ���Χ�������ԡ���������ԶԶ�غ�����һ���߶����ͱڡ�
LONG
	);

	set("exits", ([ 
		"northup"  : __DIR__"qiaobi",
		"southeast"  : __DIR__"shanlu7",  	
	]));

	set("outdoors", "����");

	setup();
}

void init()
{
	mapping fam; 
	object me, room;
	me = this_player(); 
	fam = me->query("family");
	if ( random(10) > 7 && fam && fam["family_name"] == "��Ĺ��" ){
		if(!( room = find_object(__DIR__"shushang")))
			room = load_object(__DIR__"shushang");
		if(!(present("du mang", room)))	return;
		message_vision(HIR"ͻȻ�ŵ�һ���ȳ�֮���������ϵ�����һ����ڴ�ϸ������ͷ��������$N�����ˡ�\n\n"NOR, me);
		me->move(__DIR__"shushang");
		me->add_busy(1);
	}
	return;
}
