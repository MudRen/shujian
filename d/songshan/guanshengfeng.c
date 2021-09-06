//Room: songshan/guanshengfeng.c ��ʤ��
//Modify by baimo for ss newbie job

#include <ansi.h>
inherit ROOM;
string look_sl();

string look_sl()
{
	object me, room;
	me = this_player();
	if (!(room = find_object("/d/shaolin/guangchang")))
		room = load_object("/d/shaolin/guangchang");
	if (!room || random(me->query_kar())<0)
		return "��Ŭ�����ϱߵ�����ɽ��ȥ��ȴ��ãã�ƺ����ڣ����������\n";
	message_vision("$Nվ�ڷ��ϣ����������������ɽ��ȥ��\n", me);
	"/cmds/std/look.c"->look_room(this_player(), room);
	return "";
}

void create()
{
        set("short", "��ʤ��");
        set("long", @LONG
վ����������ٲ�֮�ϣ���ɫ����һ����ͬ������һƬɽ��֮�У�����
�Ǿ�������������ɽ�ĸ���ɽ�壬����ңң�����ı��ǵش�����ɽ����ɽ����
��(shaolin)����ɽ�ж�������·��·�ߵ����ɼ�һ�Ѷѵ���ʯ��
LONG);
	set("exits", ([
		"northdown" : __DIR__"shanlu3",
		"eastdown" : __DIR__"gsfxia",
	]));
	set("item_desc",([
		"shaolin" : (: look_sl :),
	]));
	set("objects", ([
		CLASS_D("songshan") + "/sha" : 1,
	]));
	set("outdoors", "��ɽ");
	setup();
}

void init()
{
	add_action("do_caishi", "ban");
}

int do_caishi(string arg)
{
	object me,ob;

	me = this_player();

	if (!me->query_temp("ss_qs/asked")) return notify_fail ("��Ҫ���\n");

	if (me->is_busy()) return notify_fail ("��������æ���أ�\n");

	if (me->is_fighting()) return notify_fail("������ս���У��޷�ר�ĸɻ\n");

	if (!arg || arg!= "shikuai" ) return notify_fail ("��Ҫ��ʲô��\n");

	if ( me->query_temp("ss_qs/taked")
	 || (int)me->query("jingli") < 40
	 || (int)me->query("qi") < 30){
		message_vision("$N�������ͣ�һͷײ��ʯͷ�ϡ�\n",me);
		me->unconcious();
		return 1;
	}

	if (random(10) < 7 ){
		me->receive_damage("jingli",random(me->query("con"))/2);
		me->receive_damage("qi", random(me->query("str"))/2);
		message_vision("$Nʹ�����̵ľ������һ��ʯͷ�������������һƨ�����ڵ��ϡ�\n",me);
		return 1;
	}

	me->receive_damage("jingli",me->query("con")/2);
	me->receive_damage("qi",me->query("str")/2);

	message_vision("$N�����ذ���һ���ʯͷ��\n",me);
	ob = new("/d/huanghe/npc/obj/shikuai");
	ob->move(me);
	me->set_temp("ss_qs/taked",1);

	if ((int)me->query_skill("hand", 1)< 51){
		write(HIY"���ڰ�ʯͷ�ı���֮�У��ƺ��Ի����ַ���Щ����\n"NOR);
		me->improve_skill("hand", (int)(me->query("int")/2));
	}
	if ((int)me->query_skill("dodge", 1)< 31){
		write(HIY"���ڰ�ʯͷ�ı����У��ƺ��Ի����Ṧ��Щ����\n"NOR);
		me->improve_skill("dodge", (int)(me->query("int")/2));
	}
	return 1;
}
