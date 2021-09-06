#include <ansi.h>
#include <room.h>
inherit ROOM;
int do_decide(string arg);
void create()
{
	set("short", HIB "����" NOR);
	set("long","����һ��С���䣬ƽʱûʲô������\n");

	setup();  
}

void init()
{
	object me = this_player();

	if (!userp(me)) return;
	me->set_temp("caught",1);
	if (!me->query_temp("convinced")) {
	 message_vision("����һ���������������$N�������Ҫ��ָ(duanzhi)���ǳ�������(lianzhao)�ɡ�\n",me);
	 message_vision("����(decide)���ˣ��͸����ҡ��ٺٺ١�\n",me);
	 me->set("eff_qi",me->query("max_qi"));
	 me->set("qi",me->query("max_qi"));
	 me->set("jingli",me->query("eff_jingli"));
	 add_action("do_decide","decide");
	} else {
	 message_vision("ʿ������$N��$N��Ȼ�Ѿ��������Ͳ�������Щ�����ں��˵Ĺ����ˡ�\n",me);
	 me->move("/d/city/kedian");
	 }
}

int do_decide(string arg)
{
	object me = this_player();
	object ob;
	if (!arg || (arg != "duanzhi" && arg != "lianzhao"))
	   return notify_fail("��ľ�����ʲô��\n");
	if (arg == "duanzhi") {
	   me->add("duanzhi",1);
	   message_vision("$N�ҽ�һ�������˹�ȥ��\n",me);
	   message_vision("$N�����˳�ȥ���Ժ�����������һ�䡰��û�ã�����\n",me);
	   me->unconcious();
	   me->move("/d/city/kedian");
	} else {
	   ob = new(__DIR__"wushi");
	   ob->move(this_object());
	   ob->force_me("hehe");
	   ob->kill_ob(me);
	   ob->set("combat_exp",me->query("combat_exp")*9/10);
	   call_out("leave",70,me);
		remove_action("do_decide", "decide");
	}
	return 1;
}

void leave(object me)
{
	if(!me || !living(me) || me->is_ghost()) return;
	me->move("/d/city/kedian");
	me->clear_condition("ruanjin_poison");
	me->delete_temp("caught");
	message_vision("$N��һ��ʿ�����˳�����\n",me);
	message_vision("ʿ����$N��������ξͷ����㣡�´ξ�û��ô���ˡ�\n",me);
}
