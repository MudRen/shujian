// tdhjob ��һ������ npc by Lklv

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;

#include <ansi.h>
#include <get_place.h>
#include "skill.h"
#include "place.h"
#include "man1.h"

string *first_title = ({
	"������","��˳��","�Һ���","��̫��","�껯��",
	"��ľ��","�����","������","��ˮ��","������"
});
string *second_title = ({
	"����","����","�Ե�","̽��","����","����","����"
});

void create()
{
	string title, title2;
	mapping name;

	name = RNAME_D->get_random_name(1);
	title = first_title[random(sizeof(first_title))];
	title2 = second_title[random(sizeof(second_title))];

	set_name(name["name"], name["id"]);
	set("gender", "����");
	set("shen", DE_LVL*10);
	set("age", 20 + random(40));
	set("meitude", "peaceful");
	set("��ػ�/tangkou",title);
	set("��ػ�/title",title2);
	set("tdh_job_target1", 1);
	set("no_get", 1);
	set("no_quest", 1);
	set("no_bark", 1);

	set("max_qi", DE_LVL*10-DE_GIFT*5);
	set("max_jing", DE_LVL*10-DE_GIFT*10);
	set("eff_jingli", DE_LVL*10);
	set("combat_exp", 500000);

	set("str", DE_GIFT+random(DE_GIFT/4));
	set("dex", DE_GIFT+random(DE_GIFT/4));
	set("int", DE_GIFT+random(DE_GIFT/4));
	set("con", DE_GIFT+random(DE_GIFT/4));

	set("no_ansuan", 1);
	set("no_bark", 1);
	set("no_quest", 1);

	set_skill("cuff", DE_LVL);
	set_skill("dodge", DE_LVL);
	set_skill("force", DE_LVL);
	set_skill("parry", DE_LVL);
	set_skill("xinyuegong", DE_LVL);
	set_skill("taizu-quan", DE_LVL);
	set_skill("taiji-shengong", DE_LVL);
	set_skill("literate", query("int") * 10);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("cuff", "taizu-quan");
	map_skill("parry", "taizu-quan");
	prepare_skill("cuff", "taizu-quan");

	set("inquiry", ([
		"��ػ�": (: ask_tdh :),
		"����": (: ask_tdh :),
		"���帴��": (: ask_fq :),
		"�½���": (: ask_chen :),
		"֣�ɹ�": (: ask_zheng :),
		"����ү": (: ask_zheng :),
		"�����巴ĸ�ظ���": (: ask_qk :),
		"�п�": (: ask_qk :),
		"����": (: ask_qk :),
		"����": (: ask_target :),
		"ؤ��": "��˵��ػ������Ҳ�кܶ�ؤ����ֵܡ�\n",
		"��Ѫ��צ": "��˵��ػ��ܶ����½���������ôһ�Ź��򣬺���������\n",
	]));
	setup();

	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(ARMOR_D("shoes"))->wear();
	add_money("silver", 20 + random(20));
	if (clonep())
		call_out("dest", 1200);
}

void kill_ob(object ob)
{
	object me = this_player();

	if ( !me || !ob ) return;
	if (userp(me) && query("have_killer") != me->name()){
		command("say ��������ӵ��߹�����������Ϊ�������");
//                 command("chat "+me->name()+"��թ�ն񣬾�ȻͶ����͢�������ӵ��߹������С��...");
		set("have_killer", me->name());
		set("job_npc",1);///added by Ciwei
	}
	::kill_ob(ob);
}

void die()
{
	object ob, jober, killer;
	ob = this_object();

	if ( objectp(killer = query_temp("last_damage_from")) ){
		killer->add("shen", -DE_LVL* 20);
		killer->set_temp("kill_tdhnpc", ob->name());
	}
	if ( query("��ػ�jober")
	&& objectp( jober = find_player(query("��ػ�jober")) )
	&& jober->query_temp("tdhjob")
	&& jober->query_temp("��ػ�job/target_1id") == query("id")){
		log_file("job/tiandi", sprintf("%8s%-10s��%4d������ʧ��(3)��ʱ�䣺%4d���־��飺%d��",
			jober->name(), "("+jober->query("id")+")", jober->query("job_time/��ػ�")+1, uptime()-jober->query_temp("��ػ�job/time"), jober->query("combat_exp")), jober);
		jober->delete_temp("��ػ�job");
		jober->set_temp("��ػ�job/lost", query("name"));
		message_vision(HIY"\n���ˣ�"+ob->name()+"����������ʧ�ܣ�\n"NOR, jober);
	}

	command("say ���˹���Ҳ����Ҫ���帴����");
	::die();
}
