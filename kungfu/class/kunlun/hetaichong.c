// hetaichong.c (kunlun)
// By Spiderii ��ʱ�رգ�����ͽ
inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_ding();
string ask_su();
#include <ansi.h>

void create()
{
	set_name("��̫��", ({ "he taichong", "he" }));
	set("title", "����������");
        set("nickname", MAG"��������"NOR);
	set("long",
		"���������������š����ｭ��������������̫�塣\n"
		"��Ȼ����Ѵ󣬵���Ȼ���ó�������ʱӢ��������\n");
	set("gender", "����");
	set("age", 40);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("max_qi", 3500);
	set("max_jing", 3000);
	set("neili", 4500);
	set("max_neili", 4000);
	set("eff_jingli", 3200);
	set("jiali", 50);
	set("combat_exp", 1800000);
	set("score", 4000);

              set_skill("literate", 140);
	set_skill("force", 200);
	set_skill("xuantian-wuji", 200);
	set_skill("dodge", 190);
	set_skill("taxue-wuhen", 190);
	set_skill("parry", 195);
	set_skill("sword", 200);
	set_skill("liangyi-jian", 195);
	set_skill("cuff", 180);
	set_skill("zhentian-quan", 180);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("cuff", "zhentian-quan");
	map_skill("parry", "liangyi-jian");
	map_skill("sword", "liangyi-jian");

	prepare_skill("cuff", "zhentian-quan");

        create_family("������", 3, "������");
	set("class", "taoist");

	set("inquiry", ([
		"�ķ�" : (: ask_me :),
		"��ϰ֮" : (: ask_su :),
		"׷ɱ" : (: ask_ding :),
	]));

	set("book_count", 1);
	set("ding_count", 18);

	setup();
	carry_object(BINGQI_D("changjian"))->wield();
	carry_object("/d/kunlun/obj/pao2.c")->wear();
}
void attempt_apprentice(object ob)
{
        if(ob->query("gender")=="Ů��"){
 	    command("haha");
	    command("say "+RANK_D->query_respect(ob)+"�Ϸ�ɲ�����Ů���ӣ���ȥ���ҷ���ȥ�ɡ�");
	    return;
	}
        if(ob->query("appren_hezudao", 1) == 1) {
  	   command("say "+RANK_D->query_respect(ob)+"���ҿ������Ц��������ɱ���ˡ�");
	   return;
	}
	if(ob->query_skill("xuantian-wuji",1) < 100){
  	   command("hmm");
	   command("say "+RANK_D->query_respect(ob)+"��������޼���̫��ҿɲ������㡣");
 	   return;
	}
	command("say �ðɣ��ұ������㣬ֻ����Ͷ��������֮����ð���ѧ�ա�");
	command("recruit " + ob->query("id"));
	ob->set("title","�����ɵ��Ĵ�����");

}
string ask_me()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family"))
	 || fam["family_name"] != "������")
	   return RANK_D->query_respect(this_player())+ "�뱾��������������֪�˻��Ӻ�̸��";
/*
        if(this_player()->query("gender")!="Ů��" && this_player()->query("per") < 23)
   	   return "�����ľ����������";
*/
        ob = unew("/d/kunlun/obj/force-book.c");
        if(!clonep(ob)) return "�������ˣ������ľ��ѱ���ʦ�������ˡ�";
        if(clonep(ob) && ob->violate_unique()){
               destruct(ob);
  	       return "�������ˣ������ľ��ѱ���ʦ�������ˡ�";
        }
	ob->move(this_player());
	return "�������б����ķ��������й����������ģ����û�ȥ�ú����У��пն�������Ŷ";
}

string ask_ding()
{
        mapping fam;
	object ob;

	if (!(fam = this_player()->query("family"))
	 || fam["family_name"] != "������")
	    return RANK_D->query_respect(this_player())+ "�뱾��������������֪�˻��Ӻ�̸��";
		
	if(this_player()->query_skill("mantian-huayu",1) < 60)
            return "�������ԸΪʦ��Ч����������ƽʱһ�����࣬����ȥ��";
		   
	if(present("sangmen ding", this_player()) )
	    return RANK_D->query_respect(this_player())+"���������ϲ���������ô����Ҫ�ˣ�";

        if (query("ding_count") < 1)
	    return "ɥ�Ŷ��Ѹ�������ȥ׷ɱ��ϰ֮���ˣ���Ͳ���ȥ�ˡ�";
	add("ding_count", -1);
	this_player()->set_temp("kunlun/ding",1);
	ob = new(BINGQI_D("sm_ding"));
	ob->move(this_player());
	return "�������ԸΪʦ��Ч����������ƽʱһ�����࣬���ɥ�Ŷ������ȥ�ɡ�";
}

string ask_su()
{
        mapping fam;

	if (!(fam = this_player()->query("family"))
	 || fam["family_name"] != "������")
	    return RANK_D->query_respect(this_player())+ "�뱾��������������֪�˻��Ӻ�̸��";
		
	if(this_player()->query_temp("kunlun/ding",1))
            return "�㻹����������ʲô��������ȥ׷��ϰ֮";
	    return "��ϰ֮��һﾹȻ��͵�����ɵ������񽣣����ɵ��ӱص�����׷ɱ��";
}
