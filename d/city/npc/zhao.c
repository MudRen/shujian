// /d/city/npc/cheng.c
// this is made by beyond
// update 1997.7.4
// updated by snowman@SJ 13/02/2000
// for change_name()
// change to named for banname list by Lklv 2001.12.6
inherit NPC;
#include <mudlib.h>
#include <guanfu.h>

string *banned_name = ({
// Mud ��������
"�Լ�","ɱ��","����","ѩ��","��ң","����","����","����","����","����","���","ĳ��",
"ʬ��","����","�ܹ�","����","����","��ʦ","�ſ�","���","�齣","���ִ���","����ͨ",
"����","������","�̿�","����","��ʦ","���","ͷ­","ɱ�˷�","������","����һ��",
// Mud ������������
"��ɽ","��ɽ","��ɽ","��ɽ","̩ɽ","ѩɽ","��ɽ","��ɽ","����","�置","����","��ԭ",
"�Ͻ�","����","�ƺ�","�й�","�л�","����ɽ","����ɽ","����ɽ","�䵱ɽ","����ɽ",
"����","�һ���","��ľ��",
"����","ؤ��","����","����","Ľ��","��Ĺ","ȫ��","����","����","����","�һ�","����",
"������","������","�嶾��","����","а��","��������","�������","�ٸ�","����",
"������","�䵱��","���ư�","��ͨ����","������","����Ľ��","��Ĺ��","��ɽ��","��ɽ��",
"����","������","������",
// ��Ҫ��������
"��ӹ","��Сƽ","������","ë��","���Ż�","�ʵ�","������",
// С˵����
"������","���޼�","����","���","�����","���","���˷�","ΤС��","Ԭ��־","��һ��",
"�¼���","����","����","�Ƿ�","����","��������","ŷ����","���߹�","��ҩʦ","�λ�ү",
"һ�ƴ�ʦ","������","�ܲ�ͨ","����","������","�������",
// �໰
"ͳһ","����","�����о�","���ִ�","����","�����","ȥ���","������","������","����",
"�쵰","����","ɱ��","����","ǿ��","��Ů","̨��","�쵼","����","ƨ��","ƨ��","����",
"��ƨ","����","����","���","��Ѿ","����","����","����","ɵ��","����","����","�Ҳ�",
"̫��","�¹�","�˸�","����","ʺ","���","��","ɫ��","����","�ض�","��","��","��",
"ү","��","�鷿",
});

string ask_me();

void create()
{
	set_name("�Գ�֮", ({ "zhao chengzhi", "zhao" }));
	set("title", "����֪��");
	set("gender", "����");
	set("age", 43);
	set("str", 20);
	set("dex", 20);
	set("per", 20);
	set("long", "�������Գ�֮����������֪���������������ѿ����������(��������....��)\n");
	set("combat_exp", 30000);
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
	]));
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
	add_action("change_name", "zhuce");
}

int change_name(string arg)
{
	string new_name, name, f_mname, f_class;
	int i, f_gen;
	object me = this_player();

/*	if (!me->query_temp("name_modify_paid") && !wizardp(me)) {
		command("say ��͢���Ĺ涨��ƽ�񲻵�����������գ����������ǲ��ǣ�");
		return 1;
	}
*/
	if ( !arg ) {
		command("say �㵽��Ҫ��ʲô���ְ���");
		return 1;
	}

	name = me->query("name");
	new_name = arg;
	f_gen = me->query("family/generation");
	f_class = me->query("class");
	f_mname = me->query("family/master_name");

	switch(me->query("family/family_name")){
		case "�һ���":
			if (f_gen == 2) {
				if (strlen(arg) != 6 || arg[4..5] != "��")
					return notify_fail("������ֱ����������֣������Է��β��\n");
			}
			break;
		case "������":
		case "������":
		case "������":
			if (f_class == "bonze" || f_class == "huanxi") {	// ������һ����Ǯȥ�� huanxi �Ļ���
				if (strlen(arg) != 4)
					return notify_fail("������ֱ����������֡�\n");
				switch (f_gen) {
					case 40:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					case 39:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					case 38:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					case 37:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					case 36:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					case 35:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					case 14:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					case 13:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					case 5:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					case 4:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					case 3:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					default:
						if (name[0..1] != arg[0..1])
							return notify_fail("��ķ��ű����������֣����ҵ�һ���ֲ��ܱ䡣\n");
				}
				if (f_class == "huanxi")
					me->set("class", "bonze");
			} else if (f_mname == "������")
				if (strlen(arg) > 6 || arg[0..1] != "��")
					return notify_fail("����������������������֣����ҵ�һ���ֱ���Ϊ�Ρ�\n");
			break;
		case "������":
			if (f_gen == 2) {
				if (strlen(arg) != 6 || arg[4..5] != "��")
					return notify_fail("������ֱ����������֣��������ӽ�β��\n");
			}
			break;
		case "����Ľ��":
			if (f_gen == 2) {
				if (strlen(arg) < 6 || arg[0..3] != "Ľ��")
					return notify_fail("������ֱ������������֣�������Ľ�ݿ�ͷ��\n");
			}
	}

	i = strlen(new_name);

	if (i < 4 || i > 8 || i%2) {
		command("say ��"+new_name+"����");
		command("say ����������ֱ����� 2 �� 4 �������ֲ��С�");
		return 1;
	}

	while(i--)
		if( i%2==0 && !is_chinese(new_name[i..<1]) ) {
			command("say ����á����ġ�ȡ���֣������ҿɲ���ʶ�����֡�");
			return 1;
		}

	if (!wiz_level(me->query("id"))
	&& (!"/adm/daemons/named"->valid_name(new_name) || member_array(new_name, banned_name)!=-1)) {
		command("say ���������ֻ���������˵����ţ���������ġ�");
		return 1;
	}

	// Modified by mxzhao 2004/02/18
	{
		mixed ret = dbquery("select U_Name from Users where U_Name='"+new_name+"'");
		
		if (!ret)
		{
			write("���ݿ�����ʧ�ܡ�\n");
			return 0;
		}
		
		if (sizeof(ret) > 0)
		{
			write("���������ѱ�������ʹ�á�\n");
			return 0;
		}
		
		if (dbquery("update Users set "
			"U_Name='"+new_name+"' "
			"where U_Username='"+me->query("id")+"'"))
		{
			write("���ݿ�����ʧ�ܡ�\n");
			return 0;
		}
	}
	/*
	{
		mixed mysql = db_connect("localhost","mud","root");

		if (!intp(mysql))
			return notify_fail("��ʱ�����޸�������\n");
		if (db_exec(mysql, "select U_Name from " + INTERMUD_MUD_NAME + "_Users where U_Name='"+new_name+"'")) {
			db_close(mysql);
			return notify_fail("�Ѿ����������ʹ�������������\n");
		}
		db_exec(mysql, "update " + INTERMUD_MUD_NAME + "_Users set "
			"U_Name='"+new_name+"' "
			"where U_Username='"+me->query("id")+"'"
		);
		db_close(mysql);
	}
*/

	me->set("name", new_name);
	me->add("name_modify", 1);
	command("chat �ӽ��Ժ�"+name+"("+getuid(me)+") ������Ϊ��" + new_name + "��");
	log_file("name_modify",
		sprintf("%-18s �� %d �θ���Ϊ��%s\n",
			name+"("+getuid(me)+")", me->query("name_modify"), new_name
		), me
	);
	me->delete_temp("name_modify_paid");
	start_busy(2);
	if (new_name == name)
		command("say ���������Ǯ���ҿ������ţ����˸�һģһ�������֡�");
	command("say ��Ļ��������Ѿ�������ϣ���������ˡ�");
	return 1;
}

string ask_me()
{
	object me = this_player();
	string mname = (string)me->query("name");

	if(me->query_temp("name_modify_paid")){
		command("nod");
		return "�ðɣ���ֻҪע��( zhuce <����> )��������־����ˡ�\n";
	}

	if(mname == "���ִ���"){
		me->set_temp("name_modify_paid", 1);
		return "�����������գ�����ͬ���������Ҫע��( zhuce <����> )ʲô���֣�";
	}

	if( this_object()->is_busy())
		return "����æ�Ÿ�д�����أ���ȵȡ�";

	if(me->query_temp("name_wait_modify")){
	       command("hmm");
	       return "���Ǹ������㣬���²���ô�ð���\n";
	}

	if (!wiz_level(me->query("id"))
	&& (!"/adm/daemons/named"->valid_name(mname) || member_array(mname, banned_name)!=-1)) {
		command("pat");
		me->set_temp("name_modify_paid", 1);
		return "���Ѿ��õ�֪ͨ��������ĸ������ã���Ҫ����( zhuce <����> )ʲô���֣�";
	}
	command("consider");
	command("say "+me->query("name", 1)+"���������ն�Ҫ�޸Ļ��������������پ������º��Ѱ�......\n");
	me->set_temp("name_wait_modify", 1);
	if(me->query("class") == "bonze")
		command("say ���ˣ����У���ÿɸĲ��˱��ֳƺš�\n\t������� ��һ���ͱ��� zhuce �Ա��ֿ�ͷ�����֡�");
	return "�������Ҫ�ģ��ϱ�����������"+chinese_number(200*(me->query("name_modify")+1))+"���ƽ𣬽������ʷ����\n";
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
