// zhang.c ����
// Modify By River@sj 99.06

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_gold();
string ask_xunluo();
int do_yes();
int do_no();

object ob = this_object();

void create()
{
	set_name("����", ({ "zhang zhong", "zhang", "zhong" }) );
	set("nickname","���ڵ���");
	set("title", "������ɢ��");
	set("gender", "����");
	set("age",51);
	set("long", "������������ɢ��֮һ���˳����ڵ��˵����С�\n");
	set("rank_info/respect","����");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("shen_type",0);
	set("combat_exp", 600000);
	set("unique", 1);
	set("no_get","���ж�����˵̫���ˡ�\n");

	set_skill("sword",80);
	set_skill("literate",80);
	set_skill("force",80);
	set_skill("liehuo-jian",85);
	set_skill("dodge",80);
	set_skill("parry", 80);
	set_skill("cuff",80);
	set_skill("taizu-quan",85);
	set_skill("piaoyi-shenfa",85);
	set_skill("shenghuo-shengong",85);
	map_skill("cuff","taizu-quan");
	map_skill("force","shenghuo-shengong");
	map_skill("dodge","piaoyi-shenfa");
	map_skill("sword","liehuo-jian");
	map_skill("parry","liehuo-jian");
	prepare_skill("cuff", "taizu-quan");
	create_family("����", 36, "ɢ��");
	set("max_qi",1500);
	set("max_jing",1200);
	set("jiali",50);
	set("eff_jingli",1100);
	set("inquiry", ([
	//	"����"  : (: ask_gold :),
		"̫��ȭ��"  : (: ask_me :),
		"�ؼ�"  : (: ask_me :),
		"��ӡ"  : (: ask_xunluo :),
	]));

	set("xl", 2);
	set("xl2", "zhang-zhong");
	setup();
	carry_object("/d/mingjiao/obj/yel-cloth")->wear();
	carry_object(BINGQI_D("changjian"))->wield();
}

#include "5san_app.h";
#include "xunluo.h";

string ask_me()
{
	mapping fam;
	object ob;

	if( !(fam = this_player()->query("family")) || fam["family_name"] != "����" )
		return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��";

	if( this_player()->query_temp("marks/��1") ) {
		ob=unew("/d/mingjiao/obj/force_book");
		if(!clonep(ob)) return "�������ˣ�̫��ȭ���Ѹ�������ȥ�ˡ�";
		if(clonep(ob) && ob->violate_unique()){
			destruct(ob);
			return "�������ˣ�̫��ȭ���Ѹ�������ȥ�ˡ�";
		}
		ob->move(this_player());
		this_player()->delete_temp("marks/��1");
		return "�ðɣ���Ȼ���������Ѿ�ͬ�⣬��Ͱ��Ȿ̫��ȭ����ȥ�ɡ�\n";
	}
	return "�Բ��𣬲�������ͬ���Ҳ��ܸ��㡣\n";
}

string ask_gold()
{
	mapping fam;

	if( !(fam = this_player()->query("family")) || fam["family_name"] != "����" )
		return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��";

	if( this_player()->query_temp("mingjiao_gold") )
		return "�Ҳ����Ѿ�����������㻹��֪��ʲô����";

        if( this_player()->query_skill("shenghuo-shengong", 1) < 216 )
		return RANK_D->query_respect(this_player()) + "���ҽ̲��ã�����������Ǻ����Ⱑ��";

	if( this_player()->query("mingjiao_given") >= 300 )
		return "�ҽ̱�������Ѿ�Ѱ�أ���л" + RANK_D->query_respect(this_player()) + "���ġ�";

	if( this_player()->query_skill("shenghuo-shengong", 1) > this_player()->query("mingjiao_given") + 20 )
		this_player()->set_temp("mingjiao_gold", 1);

	return "�ҽ̴󲿷ֱ����Ѿ����佭����֪���٣��������ɽ������ֵ��Ĵ���������֪���ڿ�����Ϣ��\n";
}

void init()
{
	object me, ob;
	::init();

	me = this_player();
	ob = this_object();        

	add_action("do_yes","yes");
	add_action("do_no","no");
	if( me->query_temp("mingjiao_gold") == 2 ) {
		command("touch " + me->query("id"));
		command("say " + RANK_D->query_respect(me) + "һ����������Ϣ�˰ɣ�");
		message_vision(HIW"$N�����������ڱ�������Ϣ������$n��\n"NOR,me,ob);
		command("say ��λ" + RANK_D->query_respect(me) + "������Ϊ�ҽ̳���������ɼѣ�");
		command("say �����ﻹ��Щ������" + RANK_D->query_respect(me) + "�Ƿ�Ը������("HIY"yes"CYN"/"HIY"no"CYN")��\n");
		me->set_temp("mingjiao_gold", 3);
		me->add_busy(2);
	}
}

int do_yes()
{

	object me, ob;
	int gold = 0;
	me = this_player();
	ob = this_object();

	if( me->query_temp("mingjiao_gold") != 3 ) return 0;

	if( (int)me->query_skill("shenghuo-shengong", 1) > 300 ) 
		gold = 300 - (int)me->query("mingjiao_given");
	else gold = (int)me->query_skill("shenghuo-shengong", 1) - (int)me->query("mingjiao_given");

	gold *= 10000;

	if( (int)me->query_skill("literate", 1) < 100 ) gold *= 4; 
	else if( (int)me->query_skill("literate", 1) >= 150 ) gold *= 2; 
	else gold *= 3; 

	gold = gold/2 + random(gold/2);

	me->delete_temp("mingjiao_gold");
	me->add("balance", gold);
	me->set("mingjiao_given", (int)me->query_skill("shenghuo-shengong", 1));
	command("say ������" + MONEY_D->money_str(gold) + "������ͽ���������Ǯׯ�����Ժ�һ��Ҫ�ú�Ϊ�����̳�������");
	command("pat " + me->query("id"));
	return 1;
}

int do_no()
{
	object me, ob;
	int neili = 0, jingli = 0;

	me = this_player();
	ob = this_object();

	if( me->query_temp("mingjiao_gold") != 3 ) return 0;

	if( (int)me->query_skill("shenghuo-shengong", 1) > 300 ) 
		neili = 300 - (int)me->query("mingjiao_given");
	else neili = (int)me->query_skill("shenghuo-shengong", 1) - (int)me->query("mingjiao_given");

	if( (int)me->query_skill("force") < 200 ) neili = neili*3/2; 

	jingli = neili + random(neili/3);
	neili = neili + random(neili/5);

	me->delete_temp("mingjiao_gold");
	me->add("max_neili", neili);
	me->add("max_jingli", jingli);
	me->add("eff_jingli", jingli);
	me->set("mingjiao_given", (int)me->query_skill("shenghuo-shengong", 1));
	command("say ��Ȼ��λ" + RANK_D->query_respect(me) + "��ȱ������Ϊ�����⣬�ҾͰ����ҩ��������ðɣ�");
	message_vision("$N��$n����ҩ�����£��پ���������������\n"NOR,me,ob);
	tell_object(me, HIC"��������" + chinese_number(jingli) + "�㾫����" + chinese_number(neili) + "��������\n"NOR);
	command("thank " + ob->query("id"));
	return 1;
}
