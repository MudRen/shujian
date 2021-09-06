// Room: /u/xdd/gumu/xuanya
// Modify by river 98/08/29
#include <ansi.h>;
#include <room.h>;
inherit ROOM;

void create()
{
	set("short", HIM"����"NOR);
	set("long", @LONG
�˴����Ǿ�·����ͺͺ��ʯ�ڣ���������������������������(xuanya)��
�������и���Ĺ�������ܲ��˹�Ĺ֮���������Ӵ˴�һԾ���£���ȴһ����
�����±��п�Ħ�����(tree)��֦Ҷ��ʢ�����ɡһ������ס��Բ֮�ء�
LONG        );

	set("outdoors","��Ĺ");
 
	set("exits", ([
		"north" : __DIR__"rukou",
	]));    

	set("item_desc", ([
		"xuanya" :HIM"������ֻ��һƬ�������ơ���(tiao)��ȥ������ȥ�޻ء�\n"NOR,
		"tree" : "һ�øߴ�ľ���,����������������ҡ�εĺۼ���\n", 
	]));

	setup();
}

void init()
{
	add_action("do_tiao", "tiao"); 
	add_action("do_yao", "yao");
}

int do_tiao(string arg)
{ 
	object me,tmp,*ob;
	int i;
	me = this_player();
	if ( arg == "xuanya") {
		if (me->query_temp("mark/jump") < 2) {
			write("�������,�ҹ�Ĺ�񹦾���,���ٿ���һ�°�. \n");
			me->add_temp("mark/jump", 1);
			return 1;
		}
		message_vision(HIR"$N������������,����һ��,�ֵܽ�����,�����ټ�,���������ڶ���\n"NOR, me);       
		me->delete_temp("mark/jump");
		me->set_temp("last_damage_from", "������ɱ��");      
		me->die();
		if (tmp = present("corpse", this_object())){
			ob = deep_inventory(tmp);
			i = sizeof(ob);
			while (i--) if (userp(ob[i])) ob[i]->move(this_object());
			destruct(tmp);
			if(me) tell_room(this_object(), me->name()+"��ʬ�Ƕ��Ҳ����ˡ�\n");
		}
		return 1;        
	}
	return notify_fail("��Ҫ�������\n");    
}

int do_yao(string arg)
{
	mapping fam;
	object me = this_player();

	if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
		return notify_fail("�㲻�ǹ�Ĺ���ˣ�����������Ĺ�书��\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");          

	if (me->query("jing") < 40)
		return notify_fail("�㾫�����ܼ���,ȥ����ЪϢ��. \n");

	if (arg == "tree") {           
		if (me->query_skill("parry", 1) < 51)
			return notify_fail("��ʹ������ľ��������Ǵ���ȴ��˿������\n");
		if (me->query_skill("parry", 1) > 100)
			return notify_fail("��ʹ����ҡ�δ��������ִ����챻��ҡ���ˡ�\n");          
		write("��ʹ����ҡ���Ŵ�������Ĵ���΢΢�ζ���\n");
		me->receive_damage("jing", 15 + random(20));
		me->improve_skill("parry", (int)(me->query_int()/3)+(int)(me->query_skill("parry")/4));
		return 1;
	}
	return notify_fail("��Ҫҡʲô��\n");
}
