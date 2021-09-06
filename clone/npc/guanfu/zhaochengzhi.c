// /d/city/npc/cheng.c
// this is made by beyond
// update 1997.7.4
// updated by snowman@SJ 13/02/2000
// for change_name()
// change to named for banname list by Lklv 2001.12.6

inherit NPC;

#include <ansi.h>
#include <guanfu.h>
#include "change_name.h"
#include "gtitle.h"

void create()
{
	set_name("�Գ�֮", ({ "zhao chengzhi", "zhao", "chengzhi" }));
	set("title", "����Ʒ֪��");
	set("gender", "����");
	set("age", 43);
	set("str", 20);
	set("dex", 20);
	set("per", 20);
	set("long", "�������Գ�֮����������֪���������������ѿ����������(��������....��)\n");
	set("combat_exp", 30000);

	set("no_get", 1);
	set("no_bark", 1);

	set("shen_type", 0);
	set("attitude", "heroism");

	set_skill("unarmed", 50);
	set_skill("force", 50);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 15);

	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 10);

	set("inquiry", ([
		"change_name" : (: ask_me :),
		"��������" : (: ask_me :),
		"����" : (: ask_me :),
		"������" : (: ask_me :),
		"Ϊ��": (: get_title :),
		"��Ч��͢": (: get_title :),
	]));
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}

void kill_ob(object ob)
{
	command("say ɱ��������������");
	ob->add_condition("killer", 15);
	::kill_ob(ob);
}

void arrest_him(object me)
{
	int i;
	object *inv = all_inventory(me);

	me->clear_condition();
	me->apply_condition("city_jail", 200+(me->query("PKS") * 4) );
	me->set("startroom", JAIL);
	for( i=0; i < sizeof(inv); i++ ) {
		if( inv[i]->query_autoload() ) continue;
		if( inv[i]->is_character() ){
			inv[i]->move(environment(me));
			continue;
		}
		if( inv[i]->query("equipped") )
			inv[i]->unequip();
		destruct(inv[i]);
	}
	me->move(JAIL);
	message("vision", "ֻ����ƹ����һ����һ��������ļһﱻ���˽�����\n", environment(me), me);
}

int accept_object(object me, object obj)
{
	string id, name;
	object wenshu;
	mapping target;

	if (is_busy()) {
		command("say û����������æ����һ�ߵ��ţ�");
		me->add_busy(1);
		return 0;
	}

	start_busy(2);

	if (member_array(me->query("id"), GF_WANTED->query_wanted_list() ) != -1) {
		command("say ����"+me->query("id")+"��������ͨ�����أ���������Ͷ������");
		command("say ���˰������Ұ���"+RANK_D->query_rude(me)+"������Σ���");
		if (userp(me)) {
			tell_object(me, "��һ������Ҫ�����ж���ֻ��һ������������������ǰ����ˣ��ͷ�������������һ�𣬾����˹�ȥ��\n");
			me->unconcious();
			arrest_him(me);
			log_file("job/gfbug", sprintf("%-18s ��Ͷ������Obj id��%s\n",
				me->name()+"("+me->query("id")+")", obj->query("id")), me);
		}
		message_vision("\nֻ��һ����죬�����ߴ�Ĳ�ͷ�Ѿ��㵹��$N��������ȥ�ˡ�\n",me);
		if (!userp(me)) destruct(me);
		return 0;
	}

	if( !objectp(wenshu = present("tiebu wenshu", me)) ){
		command("say �ף���ƽ���޹�����ʲô��������ô֪���㲻�Ǵ���һ�");
		return 0;
	}

	if( !mapp(target = wenshu->query("target")) ){
		command("say ���ø�ʲô�����������ĳ�����");
		return 0;
	}

	if (!stringp(id = obj->query("victim_id")))
		id = obj->query("id");

	if (!stringp(name = obj->query("victim_name")))
		name = obj->query("name");

	if (target["id"] != id || target["name"] != name) {
		command("say Ҫ��ȥ��ͨ���ķ��ˣ������"+obj->query("name")+"�������úÿ����������飡");
		return 0;
	}

	message_vision("$N��$nһ"+obj->query("unit")+obj->name(1)+"��\n", me, this_object());

	if ( obj->is_character() && !obj->is_corpse() ){
		command("say �ã�"+me->query("name")+"��Ȼ��"+obj->query("name")+"��ץ�����ˣ�����λ����Ӣ�ۣ�");
		command("say ���˰������Ұ���"+RANK_D->query_rude(obj)+"������Σ���");

		message_vision("\nֻ���������۹���������$N������ȥ�ˡ�\n",obj);
		command("say ��������ǧ�����ڶ�л��λ"+RANK_D->query_respect(me)+"��");
		GF_WANTED->do_give_reward(id, target, me, 0);
		
		GIFT_D->check_count(me,this_object(),"�ٸ�");
		
		if( userp(obj) )
			arrest_him(obj);
		else 	destruct(obj);
		return notify_fail("");
	}

	if( obj->query("kill_by") != me ){
		command("say Ŷ��"+obj->name()+"����л��λ"+RANK_D->query_respect(me)+"�ˣ�����ȥ�ɡ�");
		command("say ��һ����");
		log_file("job/gfbug", sprintf("%-18s ͨ������Obj��%s��Killed by %s\n",
			me->name()+"("+me->query("id")+")", obj->query("name"),
			(stringp(obj->query("kill_by"))?obj->query("kill_by"):"Unknow") ), me);
	}
	else {
		command("thumb "+me->query("id"));
		command("say "+RANK_D->query_respect(me)+"�������ˣ����Ǵ�����İ���");
		command("say ��������ǧ�����ڶ�л��λ"+RANK_D->query_respect(me)+"��");
		GF_WANTED->do_give_reward(id, target, me, 1);
	}
	destruct(obj);
	return notify_fail("");
}
