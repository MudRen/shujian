// Room: /d/huashan/jitan.c
// Date: Look 99/03/25

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "��̳");
	set("long",@long
�����ǻ�ɽ���������Ǽ�������ļ�̳����ɽ���Ӷ�Ҫ��ɽ�������壬��
��ȡ�ϲԶԻ�ɽ���յı��ӡ�
long);
	set("exits", ([
		"out" : __DIR__"yunuci",
	]));
	set("objects", ([
		__DIR__"npc/lingshan" : 1,
		__DIR__"npc/shitong" : 1,
	]));
	setup();
}

void init()
{
//        add_action("do_jitan", "jitan");
}

int do_jitan(string arg)
{
	object me, ob, ling;
	int addskill;
	string* quest_skill = ({ "jiuyin-zhengong","hamagong", "kuihua-xinfa" });

	me = this_player();
	ob = this_object();
	ling = present("ling pai", me);

	if( !living(me) ) return 0;
	
	if(!ling)
		return notify_fail("������û��������θ�οӢ�ҵ�����֮�飿\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");

	if( !me->query_temp("jitan") )
		return notify_fail("��Ҫ��ʲô��\n");

	if ( !arg ) return notify_fail("��Ҫ��ʲô��\n");
	switch (arg){
		case "strike":	break;
		case "hand":	break;
		case "claw":	break;
		case "force":	break;
		case "cuff":	break;
		case "finger":	break;
		case "leg":	break;
		default:	return notify_fail("��Ҫ��ʲô��\n");
	}

	message_vision("$N�����ش���ͯ���нӹ������ˣ��ڷ��ڼ�̳ǰ�������ؿ���������ͷ��\n", me);
	write(HIW"ͻȻ����н���һ�����磬���������ˡ�ֻ��������һ���ҽУ��ʹ���ȥ��\n"NOR, me);

	addskill = (int)me->query("int",1) * 2;
	addskill += (int)me->query("kar",1) * 2;
	addskill += random(me->query_skill(arg, 1) /10);

	addskill = random(addskill) + 1;
	if (arg != "force") {
		me->improve_skill( arg , addskill);
		write("���"+to_chinese(arg)+"�õ���"+CHINESE_D->chinese_number(addskill)+"����ߡ�\n", me);
	}
	else {
		addskill=random(addskill/10) + 2;
		while( member_array(me->query_skill_mapped("force"),quest_skill)== -1 )
		{
			me->improve_skill( me->query_skill_mapped("force") , addskill);
			write("���"+to_chinese(me->query_skill_mapped("force"))+"�õ���"+CHINESE_D->chinese_number(addskill)+"����ߡ�\n", me);
		}
	}
	ling->add_temp("done", 1);
	me->delete_temp("jitan");
	return 1;
}
