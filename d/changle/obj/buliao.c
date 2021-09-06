// buliao.c
// By River@SJ 2003.2.26 For Changle_Job

#include <ansi.h>
#include <get_place.h>

inherit ITEM;
int check(object ob);
object ppl;

void create()
{
	set_name("�ֲ���Ƭ", ({ "cu bu", "bu", "cloth" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("long", "һ��ֲ�����Ƭ�������Ǵ���������˺�����ģ�Ҳ����Բ鿴(chakan)һ�¡�\n");
		set("no_give", 1);
		set("no_drop", 1);
	}
	setup();
}

void init()
{
	if (environment() == this_player()){
		add_action("do_jianding", "chakan");
		add_action("do_xunwen", "xunwen");
	}
}

int do_jianding(string arg)
{
	object obj, me = this_player();
	object ob, weapon, where, target, *list;
	string str, fam, msg;
	int i =0 ;

	if ( query_temp("target") != getuid(me)) return 0;

	if ( me->query_temp("changle/done"))
		return notify_fail("���ѵ���û�鿴����\n");

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if ( !id(arg) && !me->query_temp("changle/check_bu"))
		return notify_fail("��Ҫ�鿴ʲô��\n");

	if ( id(arg)) {
		message_vision("$N��ϸ�Ĳ鿴�˴ֲ������ֿ�����ʲô�쳣��\n", me);
		tell_object(me, "���ĵ������ǲ鿴��ʬ�壬Ҳ���ܷ���Щʲô��\n");
		me->set_temp("changle/check_bu", 1);
		return 1;
	}

	if ( ! arg || arg != "corpse")
		return notify_fail("��Ҫ�鿴ʲô��\n");

	if ( ! objectp(obj = present("corpse", environment(me))))
		return notify_fail("�㸽����ʬ����Բ鿴ô��\n");

	if ( obj != query_temp("unconcious"))
		return notify_fail("��鿴"+obj->name()+"����ô��\n");

	ob = new("/d/changle/npc/npc_copy");
	weapon = ob->query_temp("weapon");
	if (weapon){
		switch (weapon->query("skill_type")){
			case "sword":		msg = "��������";		break;
			case "blade":		msg = "�ֵ�����";		break;
			case "hook":		msg = "��������";		break;
			case "dagger":		msg = "ذ�׸���";		break;
			case "whip":		msg = "���޾���";		break;
			case "brush":		msg = "���ʹ���";		break;
			case "staff":		msg = "���Ȼ���";		break;
			case "club":		msg = "��������";		break;
			case "axe":		msg = "�ָ�����";		break;
			case "hammer":		msg = "��������";		break;
			case "stick":		msg = "�������";		break;
			case "throwing":	msg = "��������";		break;
		}
		i = 1;
	}
	else
		msg = "�����ڹ�����";

	fam = ob->query("family_type");

	me->set_temp("changle/target_family", fam);
	me->set_temp("changle/target_team", ob->query("team"));
	me->set_temp("changle/target_weapon", i);
	me->set_temp("changle/done", 1);
// dest
	remove_call_out("dest_object");
	call_out("dest_object", 1, ob);

	message_vision(HIY"\n$N��ϸ�ز鿴"+obj->name()+"�������ƺ��Ǳ�"+msg+"�����˿ڿ�����Ӧ����"+fam+"��Ϊ��\n"NOR, me);

	ppl = me;
	list = filter_array(
		users(), (:
			$1->query("combat_exp") > 3000
			&& !wizardp($1)
			&& environment($1)
			&& $1->query("family")
			&& query_idle($1) < 120
			&& interactive($1)
			&& query_ip_number($1) != query_ip_number(ppl)
			&& $1->query("registered") > 1
			&& strsrch(file_name(environment($1)),"/d/sld/seawar") != 0
			&& strsrch(file_name(environment($1)),"/d/wizard") !=0						
			&& !$1->query_condition("relax")
			&& !$1->query_condition("killer")
			&& $1->query_temp("cl_job_time") < uptime()
			&& getuid($1)!=ROOT_UID
		:)
	);

	list -= ({me, 0});

	if(sizeof(list) < 1 )
		return notify_fail("����ֻ�ܲ鿴���ⲽ�ˣ������Ȼ�ȥ����ɡ�\n");

	target = list[random(sizeof(list))];

	if ( ! target )
		return notify_fail("����ֻ�ܲ鿴���ⲽ�ˣ������Ȼ�ȥ����ɡ�\n");

	target->set_temp("cl_job_time", uptime() + 2700);
	where = environment(target);
	if (strsrch(file_name(where), "/d/zhiye/") >= 0
	 || strsrch(file_name(where), "/d/group/") >= 0) {
	 	if ( where->query("outdoors"))
			str = where->query("outdoors") + where->query("short");
	 	else if ( where->query("indoors"))
			str = where->query("indoors") + where->query("short");
		else  str = where->query("short");
	}
	else str = get_place(base_name(where))+where->query("short");
	str = strip(str);

	me->set_temp("changle/user_name", getuid(target));
	target->query("gender")=="Ů��"?msg="��":msg="��";
	tell_object(target, YEL"��ͻȻƳ��һ����Ӱ����������������һ���Ӵܣ����ﲻ����������\n"NOR);
	tell_object(me, YEL"�㰵��Ѱ˼ѯ��"+target->query("family/family_name")+"��"+target->name(1)+"("+capitalize(getuid(target))+")�����ܵõ���ʾ������"+msg+"����"+str+"�������֡�\n"NOR);
	return 1;
}

void dest_object(object ob)
{
	if(ob) destruct(ob);
}

int do_xunwen(string arg)
{
	object me, obj, ob, *living, target;
	string str, address;
	object objwhere;
	int i,j;

	me = this_player();

	if ( ! me->query_temp("changle/user_name") || query_temp("target") != getuid(me)) return 0;

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if ( me->query_temp("changle/done") > 1 )
		return notify_fail("�㲻���Ѿ�ѯ�ʹ��ˣ�������ȥ��\n");

	if ( ! arg || arg != me->query_temp("changle/user_name"))
		return notify_fail("��Ҫѯ��˭��\n");

	if ( ! obj = present( arg, environment(me)))
		return notify_fail("�������������ô��\n");

	if ( !interactive(obj) || !living(obj))
		return notify_fail("������"+obj->name()+"��ʱ�޷��ش�������⡣\n");

	EMOTE_D->do_emote(me ,"hi", obj->query("id"));
	message_vision(CYN"$N����$n���˸�Ҿ�������ʵ�������λ"+ RANK_D->query_respect(obj)+"����������"+me->query_temp("changle/target_family")+"����ɱ�����ְ����"+me->query_temp("changle/npc_name")+"����\n"NOR, me, obj);
	me->start_busy(random(2));
	me->set_temp("changle/done", 2);

	living = livings();
	for (i=0;i < sizeof(living);i++){
		j = random(sizeof(living));
		if (!j || j == sizeof(living) -1) continue;
		if(check(living[j]) ){
			target = living[j];
			objwhere = environment(target);
			str = objwhere->query("short");
			if (!sizeof(objwhere->query("exits"))
			|| str == "��ɮ��"
			|| str == "ɮ��"
			|| str == HIR"������"NOR
			|| str == "��շ�ħȦ" ) continue;
			if( get_place(base_name(environment(target))) == get_place(base_name(environment(me)))) continue;
			if( get_place(base_name(environment(target))) != "" ) break;
		}
	}

	if( ! target ) {
		EMOTE_D->do_emote(obj, "sign");
		tell_object( me, GRN+obj->name()+"����Ķ�������˵�����ղ������˴�����߾�������ϧ��û����������ĸ������뿪�ˡ�\n"NOR);
		tell_object( obj, GRN"����"+me->name()+"�Ķ�������˵�����ղ������˴�����߾�������ϧ��û����������ĸ������뿪�ˡ�\n"NOR);
		tell_room( environment(me), obj->name() + "��" + me->name() + "����С����˵��Щ����\n", ({ obj, me }) ); 
		return 1;
	}

	ob = new("/d/changle/npc/pantu");
	ob->set_temp("target_pantu", getuid(me));
	ob->do_copy(me, me->query_temp("changle/target_team"), me->query_temp("changle/target_weapon"));
	ob->set("env/invisibilty", 10);
	ob->move(objwhere);

	for ( j = 0; j < 5; j ++)
		ob->random_move();

	if ( environment(ob)->query("no_fight") ||  environment(ob)->query("quest") )
		ob->random_move();

	ob->delete("env/invisibilty");

	if (strsrch(file_name(environment(ob)), "/d/zhiye/") >= 0
	 || strsrch(file_name(environment(ob)), "/d/group/") >= 0) {
	 	if ( environment(ob)->query("outdoors"))
			me->set_temp("change/job_place1", environment(ob)->query("outdoors")+environment(ob)->query("short"));
	 	else if ( environment(ob)->query("indoors"))
			me->set_temp("change/job_place1", environment(ob)->query("indoors")+environment(ob)->query("short"));
		else me->set_temp("changle/job_place1", environment(ob)->query("short"));
	}
	else me->set_temp("changle/job_place1", get_place(base_name(environment(ob)))+environment(ob)->query("short"));

	if ( ! me->query_temp("changle/job_place1")) {
		EMOTE_D->do_emote(obj, "sign");
		tell_object( me, GRN+obj->name()+"����Ķ�������˵�����ղ������˴�����߾�������ϧ��û����������ĸ������뿪�ˡ�\n"NOR);
		tell_object( obj, GRN"����"+me->name()+"�Ķ�������˵�����ղ������˴�����߾�������ϧ��û����������ĸ������뿪�ˡ�\n"NOR);
		tell_room( environment(me), obj->name() + "��" + me->name() + "����С����˵��Щ����\n", ({ obj, me }) ); 
		return 1;
	}

	me->set_temp("changle/target", ob);
	address = strip(me->query_temp("changle/job_place1"));
	EMOTE_D->do_emote(obj ,"nod", me->query("id"));
	tell_object( me, GRN+obj->name()+"����Ķ�������˵�����ʲ�"+ob->query("title")+ob->name()+"������߾���������ǰ����"+address+"��\n"NOR);
	tell_object( obj, GRN"����"+me->name()+"�Ķ�������˵�����ʲ�"+ob->query("title")+ob->name()+"������߾���������ǰ����"+address+"��\n"NOR);
	tell_room( environment(me), obj->name() + "��" + me->name() + "����С����˵��Щ����\n", ({ obj, me }) );
	return 1;
}

int check(object ob)
{
	object room;
	string room_name;

	if(!objectp(ob)
	 || !ob->query("startroom")      // add by Yuj@SJ to void job NPC
	 || ob->query("env/invisibility")
	 || ob->query("no_quest")
	 || userp(ob)
	 || ob->query("attitude")=="aggressive"
	 || ob->query("have_master")
	 || !objectp(room=environment(ob))
	 || room->query("no_fight")
	 || room->query("outdoors") == "���ش��"
	 || strsrch(room_name = file_name(room),"/d/") != 0
	 || strsrch(room_name, "/d/wizard/") == 0
	 || strsrch(room_name, "/d/wuguan/") == 0
	 || strsrch(room_name, "/d/death/") == 0
	 || strsrch(room_name, "/d/group/") == 0
	 || strsrch(room_name, "/d/mingjiao/lsd/") == 0
	 || strsrch(room_name, "/d/mingjiao/bhd/") == 0
	 || strsrch(room_name, "/d/shaolin/fumoquan") == 0
	 || strsrch(room_name, "/d/baituo/") == 0)
	 return 0;
	return 1;
}
