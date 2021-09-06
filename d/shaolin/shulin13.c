// Room: /d/shaolin/shulin13.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ǰ��Ȼһ�ڣ������У�ֻ������ǰ�󣬵�����������ǵص�������
����ʮ�ɸߵĴ���������һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ�����
���ڵ�˿��Ҳ�ޡ��߰Ѻ��������ڵ��ϣ�һ�Ų���ȥ������β���������
�ƺ���ʧ�˷�����ûͷ��Ӭ�㵽���Ҵ���
LONG
	);

	set("exits", ([
		"east" : __DIR__"shulin"+(random(8)+6),
		"south" : __DIR__"shulin"+(random(8)+6),
		"west" : __DIR__"shulin"+(random(8)+6),
		"north" : __DIR__"shulin"+(random(8)+6),
	]));

	set("outdoors", "shaolin");
	set("coor/x",70);
  set("coor/y",550);
   set("coor/z",160);
   setup();
}

void init()
{

	object ob, room;
	mapping fam;

	int i = random(2);
	if( i == 0) return;

	ob = this_player();
	room = this_object();

	if (ob->query("id") == "seng bing" || !living(ob)) return;

	room->delete("exits");

	if ( (fam = ob->query("family"))
	&& fam["family_name"] == "������" 
	&& ob->query("guilty") != 1 )  
	ob->set("guilty",3);

	ob->set("startroom", "/d/shaolin/jieluyua");

	message_vision(HIR "\n$Nһ��С�ģ��߽���ɮ�������µ����壡
$Nֻ���ý���һ���ʹ��ԭ���ǲ��������ڵ��µ���ǩ��\n\n" NOR, ob);

	message_vision(HIR "\n$Nʹ�ü���ʧȥ��֪��......\n\n" NOR, ob);

	call_out("trapping", 20, ob, room);

}

void trapping(object ob, object room)
{
	if ( !ob || !living(ob) ) return;

	message_vision(HIY "\nɮ���ǰ�$N���ݾ������˳������ͽ��˽���Ժ��\n\n\n" NOR, ob);
     	ob->move(__DIR__"jieluyua"); 

	room->set("exits/south", __DIR__"shulin"+(random(8)+6));
	room->set("exits/north", __DIR__"shulin"+(random(8)+6));
	room->set("exits/east", __DIR__"shulin"+(random(8)+6));
	room->set("exits/west", __DIR__"shulin"+(random(8)+6));
}
