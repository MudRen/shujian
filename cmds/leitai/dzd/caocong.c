// Room: /d/dzd/caocong.c

#include <ansi.h>
#define OUT_DOWN __DIR__"caodi2" 
inherit __DIR__"dzd_room";

int do_kill(string arg);
int do_zuan(string arg);
string look_out();

void create()
{
	set("short","�ݴ�");
	set("long",@LONG
��Ƭ�ĻĲ���û�������Ӱ���ӲݴԵķ�϶(out)������ȫ���������ڲݵ���С·�ϵĶ�����
һ��΢�紵������ֻ��������������Ʈ����������һ��ӲӲ�Ķ�����һ����㾪��������ԭ
����һ���˵��ȹǡ�
LONG
	);
	set("outdoors","���ǵ�");
	set("item_desc",([
		"out" : (: look_out :),
	]));
	setup();
}

void init()
{
	object room,*ob;
	object me = this_player();
	object here = this_object();
	int i;
	
	::init();
	add_action("do_kill","kill");
	add_action("do_kill","ansuan");
	add_action("do_kill","touxi");
	add_action("do_zuan","zuan");

	if(userp(me) && !wizardp(me)) {
		if(!room=find_object(OUT_DOWN))
			room=load_object(OUT_DOWN)	;
		ob = all_inventory(here);
		for(i=0;i < sizeof(ob);i++) {
			if(userp(ob[i]) && !wizardp(ob[i]) && ob[i] != me) {
				tell_object(me,HIW"��ͻȻ����"+ob[i]->name()+"Ҳ�ڲݴ���,�������һ����\n"NOR);
				message_vision(HIW"$n����$N������$n�����һ������$N���˹���!\n"NOR,me,ob[i]);
				me->kill_ob(ob[i]);
				ob[i]->kill_ob(me);
				return;
			}
		}
	}
	"/cmds/std/look.c"->look_room(me,here);
}

int do_zuan(string arg)
{
	object me = this_player();
	if(me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if(!arg || arg != "out")
		return notify_fail("��Ҫ�굽�Ķ���\n");
	message_vision(HIY"$N˫��һ�ŵأ������Ѽ�һ��Ĵ��˳�ȥ��\n"NOR,me);
	me->move(OUT_DOWN);
	message("vision",HIY""+me->name()+"�Ӳݴ������˳�����\n"NOR,OUT_DOWN,me);
	return 1;
}

string look_out()
{
	object room;
	if(!room = find_object(OUT_DOWN))
		room = load_object(OUT_DOWN);
	"/cmds/std/look.c"->look_room(this_player(),room);
	return """";
}

int do_kill(string arg)
{
	object ob,room;
	object me = this_player();
	if(me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if(!arg || !(room = find_object(OUT_DOWN)))
		return notify_fail("��Ҫ͵Ϯ˭��\n");
	if(!(ob = present(arg,room)))
		return notify_fail("��Ҫ͵Ϯ˭��\n");
	if(!ob->is_character() || ob->is_corpse())
		return notify_fail("�����һ�㣡\n");
	if(!userp(ob))
		return notify_fail("͵Ϯnpc? ����\n");
	if(wiz_level(me) < wiz_level(ob))
		return notify_fail("�㲻��͵Ϯ��ʦ�ȼ�����ߵĶ��֡�\n");
	message_vision(HIW"$N�Ӳݴ���һԾ������������磬ֱȡ"+ob->name()+"��\n"NOR,me);
	message_vision(HIW"��Ȼһ��ɱ��Ϯ����$Ņͷ��ȥ��ֻ��һ����ӰЮ�Ž������Ӷ�������\n"NOR,ob);
	me->move(room);
	if(!random(10)) {
		message_vision(HIY"ȴ��$N����׼������������һ���ù����ƣ��û���$n����������\n"NOR,ob,me);
		me->start_busy(3);
	} else if(!random(5)) {
			message_vision(HIW"$N���һ������æ���������һ����$n��������$N�ıǼ��ӹ���\n"NOR,ob,me);
		} else {
			message_vision(HIR"$Nֻ��һ�������̹ǵ�ɱ��Ϯ���������رܣ��ѱ�$nһ�����У���\n"NOR,ob,me);
			ob->start_busy(3);
			}
	me->kill_ob(ob);
	if(!userp(ob))
		ob->kill_ob(me);
	else {	
		ob->fight_ob(me);
		if(userp(me))
			tell_object(ob,HIR"�����Ҫ��" + me->name() + "�����ಫ������Ҳ���������һ��killָ�\n"NOR);
		}

	return 1;	 
}
