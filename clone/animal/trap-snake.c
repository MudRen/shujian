// trap-snake by Darken@SJ
// Modify by Looklove@SJ
// Modify By River@SJ 2002.11

inherit NPC;
#include <ansi.h>
#include <pktime.h>
int do_target(string arg);
int do_pickup(string arg);

void create()
{
	set_name("С����", ({ "qing she","she" }));
	set("race", "Ұ��");
	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" }) );
	set("shen", 1);
	set("attitude", "peaceful");
	set("age", 1+ random(3));
	set("combat_exp", 1);
	set("no_get",1);
	set("max_qi",1);
	set("eff_qi",1);
	set("qi",1);
	set("max_jing",1);
	set("eff_jing",1);
	set("jing",1);
	set("max_jingli",1);
	set("eff_jingli",1);
	set("jingli",1);
	set("neili",1);
	set("jiali", 1);
	set("max_neili",1);
	set_skill("force",1);
	set_skill("dodge",1);
	set_skill("parry",1);
	set_skill("unarmed",1);
	set("chat_chance", 3);
	set("chat_msg", ({
		"С�����гɻ������ƣ�Χ������Χ��\n",
		"С������������������ȱ�������ȥ��\n",
		"С���������㣬�������˹�����\n",
	}) );
	setup();
}

void init()
{
	object me,snake;

	me = this_player();
	snake = this_object();

	if (me->query("id") == query("target")
	 && userp(me)
	 && !environment(me)->query("no_fight")){
		if ( snake->query_leader() != me ) {
			snake->set_leader(me);
			message_vision("С���߾�����$Nһ���ж���\n",me);
			snake->add_busy(1);
			me->start_busy(1);
		}
		snake->kill_ob(me);
	}
	if (present(snake, environment(me)) && query("owner") == me->query("id")) {
		add_action("do_target","target");
		add_action("do_pickup","pickup");
	}
}


void kill_ob(object ob)
{
	object me;
	if(!ob) return;
	if(!stringp(query("owner")))
	{
		::kill_ob(ob);
		return;
	}
	me = find_player(query("owner"));
	if(!me)
	{
		::kill_ob(ob);
		return;
	}
	
	//ϴ��id ������ɱ
	if(userp(ob) && ob->query("no_pk"))
	{
		remove_killer(ob);
		remove_enemy(ob);
		ob->remove_enemy(this_object());
		ob->remove_killer(this_object());
		tell_object(ob,"���Ѿ�����ϴ�֣����ǲ�Ҫ���뽭�������ɣ�\n");
		return;
	}
	
	//pk time
	if(pktime_limit(ob, me))
	{
		remove_killer(ob);
		remove_enemy(ob);
		ob->remove_enemy(this_object());
		ob->remove_killer(this_object());
		return;		
	}
}

int hit_ob(object me, object victim, int damage)
{
	victim->add_condition("snake_poison", 8+random(6));
	return 0;
}

int do_target(string arg)
{
	object me, *ob, obj;
	int i,j,e;
	me=this_player();

	if (!arg || ! obj=(find_player(arg)))
		return notify_fail("��Ҫ�Ը�˭��\n");
	if (present(arg))
		return notify_fail("��Ҫ�Ը����˾����Աߣ���̫�ðɣ�\n");
	if (me->query("combat_exp") >= 5000000)
		return notify_fail("�������ĸ��ֻ�Ҫ�����������ĵĶ����������Ա���ݣ���Ц������\n");

        if (userp(obj) && me->query("no_pk"))
                return notify_fail("���Ѿ�����ϴ�֣����ǲ�Ҫ���뽭�������ɣ�\n");

        if (userp(me) && obj->query("no_pk") && !obj->query_condition("pk"))
                return notify_fail(obj->name()+"�Ѿ�����ϴ�֣����ǲ�Ҫ���뽭�������ɣ�\n");

        if (!wizardp(me))
                if(pktime_limit(me, obj)) return 0;

	if (environment(me)->query("no_fight"))
		return notify_fail("���ﲻ�ʺ�������\n");

	message_vision(HIG"$N����һЩ�Źֵ������������߱��ֻ��š�\n"NOR, me);
	j = (me->query("max_pot")-100) / 2 * 3;
	e = me->query("combat_exp") / 5 * 3;
	if (e > 1000000) e = 1000000+random(200000);
	if (j > 200) j = 200 + random(30);
	ob = all_inventory(environment(me));

	for (i=0;i<sizeof(ob);i++) {
		if (ob[i]->id("qing she") && ob[i]->query("owner")==me->query("id")) {
			if (ob[i]->is_fighting())
				return notify_fail("�������æ���أ�����û������ָ�ӡ�\n");
			if (!me->query_temp("other_kill/"+obj->query("id")) 
			|| ! obj->query_temp("kill_other/"+ me->query("id"))
			|| ! me->query_temp("revenge/"+ obj->query("id"))) {
				me->add_condition("killer", 15);
				obj->set_temp("other_kill/"+me->query("id"), 1);
			}
			ob[i]->set("target",arg);
			ob[i]->set("combat_exp", e);
			ob[i]->set("max_qi", me->query("max_qi"));
			ob[i]->set("max_jing", me->query("max_jing"));
			ob[i]->set("eff_jingli", me->query("eff_jingli"));
			ob[i]->set("max_neili", me->query("max_neili"));
			ob[i]->set("jiali", me->query("jiali"));
			ob[i]->set("str", me->query("str"));
			ob[i]->set("con", me->query("con"));
			ob[i]->set("dex", me->query("dex"));
			ob[i]->set("int", me->query("int"));
			ob[i]->set_skill("unarmed",j +random(50));
			ob[i]->set_skill("force",j + random(50));
			ob[i]->set_skill("dodge",j + random(50));
			ob[i]->set_skill("parry",j + random(50));
			ob[i]->reincarnate();
			ob[i]->set("long", "һ��С���ߣ���������"+me->name(1)+"("+capitalize(me->query("id"))+")��ѱ���ġ�\n");
			call_out("check_place", 1, me, ob[i]);
		}
	}
	return 1;
}

void check_place(object me, object ob)
{
	if ( !ob ) return;
	if ( ob->query_leader()) return;
	if ( !ob->query("target")) return;
	if ( !me || environment(me) != environment(ob)){
		tell_room(environment(ob), ob->name() + "����һ�������븽���ĲݶѲ����ˡ�\n", ({ ob }));
		destruct(ob);
		return;
	}
	call_out("check_place", 1, me, ob);
}

int do_pickup(string arg)
{
	object me, *ob;
	int i;
	me=this_player();

	if(!arg || arg != "qing she")
		return notify_fail("����pickup qing sheָ������С���ߡ�\n");

	if(!present(arg,environment(me)))
		return notify_fail("��Ҫ��ʲô��\n");

	ob = all_inventory(environment(me));
	for (i=0;i<sizeof(ob);i++) {
		if (ob[i]->id("qing she") && ob[i]->query("owner")==me->query("id")) {
			ob[i]->move(me);
			ob[i]->delete("target");
			ob[i]->set_leader(0);
		}
	}
	message_vision(HIG"$N����һЩ�Źֵ��������߱�ԹԵ�����$N���ϡ�\n"NOR, me);
	return 1;
}

void unconcious()
{
	::die();
}
