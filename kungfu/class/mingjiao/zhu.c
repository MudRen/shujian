// zhu.c ��Ԫ�
// Modify By River@sj 99.06
#include <ansi.h>
inherit NPC;

string ask_gold();
void create()
{
	set_name("��Ԫ�", ({ "zhu yuanzhang","zhu","yuanzhang" }) );
	set("title", "���̺�ˮ�����");
	set("gender", "����");
	create_family("����",38,"����");
	set("age",36);
	set("long","���Ǻ��������Ļʵۣ��������̵�Ӱ���ȡ�����¡�\n");
	set("str", 24);
	set("int", 30);
	set("con", 23);
	set("dex", 20);
	set("per", 10);
	set("shen_type",1);
	set("combat_exp", 90000);
	set("unique", 1);
	set("inquiry", ([
		"��Ϣ"  : (: ask_gold :),
	]));
	set_skill("cuff",60);
	set_skill("literate",180);
	set_skill("force",60);
	set_skill("dodge",60);
	set_skill("parry",60);	
	set_skill("blade",60);	
	set("max_qi",600);
	set("max_jing",400);
	set("neili",400);
	set("max_neili",400);
	set("jiali",20);
	set("eff_jingli",200);
	set_skill("taizu-quan",60);
	map_skill("parry","taizu-quan");
	map_skill("cuff","taizu-quan");
	prepare_skill("cuff","taizu-quan"); 
	setup();
	carry_object("/d/mingjiao/obj/black-cloth")->wear();
	carry_object(BINGQI_D("blade"))->wield();
}

void attempt_apprentice(object ob)
{     
	command("say �Ǻǣ����书��΢���ɲ�����ͽ����");
	command("say ��λ"+RANK_D->query_respect(ob)+"������ذɡ�");
	return;
}

string ask_gold()
{
	mapping fam;

	if( !(fam = this_player()->query("family")) || fam["family_name"] != "����" )
		return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��";

	if( this_player()->query_temp("mingjiao_gold") != 1 )
		return RANK_D->query_respect(this_player())+"��֪��ʲô��Ϣ����";

	this_player()->set_temp("mingjiao_gold", 2);
	return RANK_D->query_respect(this_player())+"��˵���Ƿ��Ǳ��������䰡�����Ҵ��������Ǳ��������е���͵�������������ѽ���Ѱ�أ�����·��İɣ�\n";
}
