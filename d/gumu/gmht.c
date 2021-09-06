// Room: /u/xdd/gumu/gmhout.c
// Modify By River 98/08/29
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", HIG"����"NOR);
	set("long", @LONG
����Ҳ�ǿյ�����ûʲô���裬��ǰ��д��һ�д��֣�zi�����������ڶ�
����һ���������� (westpic)�Ļ���������Ů�ɣ����ǹ�Ĺ�ɵ�ʦ���ֳ�Ӣ��
ʦ�����ŵ�Ф�񣬶��ࣨeastpic��������ȴ��һ����ʿ�� 
LONG        );

	set("exits", ([
		"east" : __DIR__"gmqs",
		"west" : __DIR__"gmzt",
		"north" : __DIR__"gmws1",
		"south" : __DIR__"gmws",
	]));

	set("item_desc", ([
		"westpic" : "���ڻ������������һ����ʮ�����꣬���ڶԾ���װ����һ����ʮ�������\n"+
			"Ѿ�ߣ��������裬�����̺򡣻��о���ӳ�����곤Ů����ò��������ü���ޣ�\n"+
			"�۽�֮��ȴ��������һ��ɱ����\n",          
		"eastpic" : "ֻ�����е���������ߣ���������������ʳָָ�Ŷ����ǣ�ֻ�Ǳ������⣬��\n"+
			"òȴ��������\n",
		"zi" : HIR"\t���ҹ�Ĺ�����������������񹦣�������ʦ��\n"NOR,
	]));
	create_door("south", "ʯ��", "north", DOOR_CLOSED);
	setup();
}

void init()
{
	add_action("do_ketou", "ketou"); 
	add_action("do_tuo", "tuo");
}

int can_betray(object me)
{
	mapping skills = me->query_skills();

	if (sizeof(skills) < 1)
		return 1;
	foreach (string skill in keys(skills))
		if (SKILL_D(skill)->valid_enable("force"))
			return 0;
	return 1;
}

int do_ketou(string arg)
{
	mapping fam;
	object key, me = this_player();
	fam = me->query("family");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if( !arg || arg != "westpic") return 0;
		message_vision("$N�����򵹣�˫ϥ���أ�������������ʦ���ŵĻ������һ����ͷ. \n", me);
	me->add_temp("marks/ketou", 1);
	if( me->query_temp("marks/tuo") == 2 
	 && me->query_temp("marks/ketou") == 4 ){
		if( fam && fam["family_name"] != "��Ĺ��" && !can_betray(me))
			return notify_fail("������ô�����Ĺ���ģ�\n"); 
		if( fam && fam["family_name"] == "��Ĺ��")
			return notify_fail("���Ѿ��ǹ�Ĺ�ɵĵ����ˣ��Ͳ��ö��ͷ�ˡ�\n");
		if( ! fam && me->query("expell"))
			return notify_fail("������ô�����Ĺ���ģ���\n");
		if ( fam && fam["family_name"] != "��Ĺ��") {
			int count = me->add("betrayer", 1);
			log_file("static/BETRAY",
				me->query("name")+"("+me->query("id")+")��"+count+"�δ�"
				+me->query("family/family_name")+"�����Ĺ��\n",
				me
			);
			if (count <= 1)
				count = 10;
			else if (count == 2)
				count = 4;
			else
				count = 2;
			me->add("combat_exp", - me->query("combat_exp") / count);
			me->setup();
		}
		me->create_family("��Ĺ��", 5, "����");
		me->set("class","sworder");
		tell_object(me,HIR"\n��ϲ����Ը��Ϊһ����Ĺ���ӡ�\n\n"NOR);
		me->start_busy(2);
		me->delete_temp("marks/tuo");
		me->delete_temp("marks/ketou");
		return 1;
	}
	if( me->query_temp("marks/ketou") == 15 ){
		me->delete_temp("marks/ketou");
		if(me->query_temp("marks/goldkey"))
			return notify_fail(HIR"�㲻���Ѿ��ù�������ô��Ҫ�ã�\n"NOR);
		key=unew(__DIR__"obj/goldkey");
		if(!clonep(key))
			return notify_fail (HIR"����¶��һ��С��,������տ���Ҳ,�����������������. \n"NOR);  
		if(clonep(key) && key->violate_unique()){
			destruct(key);
			return notify_fail (HIR"����¶��һ��С��,������տ���Ҳ,�����������������. \n"NOR);
		}
		message_vision(HIY"$N��ǰ��ʯ��ͻȻ�³�,¶��һ�ѽ�Կ��,$N�õ�һ�ѽ�Կ��. \n"NOR, me);
		me->set_temp("marks/goldkey", 1);
		key->move(me);
	}
	return 1;
}

int do_tuo(string arg)
{
	object me = this_player();
	if (me->query_temp("marks/tuo") == 2)
		return notify_fail("���ٹ���û�У�\n");
	if ( arg=="eastpic") {
		message_vision("$N���������Ļ���ݺ�����һ��. \n", me);
		me->add_temp("marks/tuo", 1);
		return 1;
	}
	return notify_fail("�㲻Ҫ������ٿ�ˮ����\n");
}
