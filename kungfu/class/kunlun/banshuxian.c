// bashuxian.c (kunlun)

inherit NPC;
inherit F_MASTER;
string ask_me();
#include <ansi.h>

void create()
{
	set_name("�����", ({ "ban shuxian", "ban" }));
	set("title", "���������ŷ���");
	set("long",
		"���������������š����ｭ��������������̫��ķ��ˡ�\n"
		"����һ����ĸߴ�İ���Ů�ӣ�ͷ�����ף�˫Ŀ������ü�ļ����ɷ����\n");
	set("gender", "Ů��");
	set("age", 44);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 26);
	set("int", 24);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 3500);
	set("max_jing", 2000);
	set("neili", 3200);
	set("max_neili", 3200);
	set("jiali", 50);
	set("eff_jingli",2000);
	set("combat_exp", 1300000);
	set("score", 40000);

              set_skill("literate", 120);
	set_skill("force", 175);
	set_skill("xuantian-wuji", 180);
	set_skill("dodge", 165);
	set_skill("taxue-wuhen", 175);
	set_skill("parry", 180);
	set_skill("sword", 200);
	set_skill("leg", 160);
	set_skill("chuanyun-tui", 180);

             set_skill("liangyi-jian",200);	
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("leg", "chuanyun-tui");
	map_skill("parry", "liangyi-jian");
	map_skill("sword", "liangyi-jian");

	prepare_skill("leg", "chuanyun-tui");

        create_family("������", 3, "���ŷ���");
	set("class", "taoist");
	set("inquiry",([
		"�ؼ�" : (: ask_me :),
	]));

	setup();
	carry_object(BINGQI_D("changjian"))->wield();
	carry_object("/d/kunlun/obj/pao2.c")->wear();
}
void attempt_apprentice(object ob)
{
	if(ob->query("gender")=="����"){
		command("hmm");
		command("say "+RANK_D->query_respect(ob)+"������Щ�������Ҽ��˾ͷ���������߿���");
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
	command("say �ðɣ��Ժ���͸���ѧ�书�ɣ�����ð���ѧ�գ�����������");
	command("recruit " + ob->query("id"));
	ob->set("title","�����ɵ��Ĵ�����");
}
string ask_me()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family"))
	 || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��";

	if( this_player()->query("gender") == "����")
		return "�����߿����ҿ���������Щ�����˾ͷ���";

	ob = unew("/d/kunlun/obj/lyj-book.c");

	if(!clonep(ob)) return "�������ˣ������澭�ѱ���ʦ�������ˡ�";

	if(clonep(ob) && ob->violate_unique()){
		destruct(ob);
		return "�������ˣ������澭�ѱ���ʦ�������ˡ�";
	} 
	ob->move(this_player());
	return "��ʦ���������Ȿ�����ǽ��ĵá������û�ȥ�ú����С�";
}
