// zhanchun.c (kunlun)
// By Spiderii ��ʱ�رգ�����ͽ
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
	set_name("ղ��", ({ "zhan chun", "zhan", "chun" }));
	set("long",
		"���Ǻ�̫����ϲ���ĵ��ӣ����õ�Ҳ��Ϊ������\n");
	set("gender", "Ů��");
	set("age", 24);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 24);
	set("con", 28);
	set("dex", 26);

	set("eff_jingli", 850);
	set("max_qi", 850);
	set("max_jing", 600);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 30);
	set("combat_exp", 380000);
	set("score", 4000);

	set_skill("force", 95);
	set_skill("xuantian-wuji", 105);
	set_skill("dodge", 95);
	set_skill("taxue-wuhen", 105);
	set_skill("parry", 100);
	set_skill("sword", 101);
	set_skill("liangyi-jian", 105);
	set_skill("leg", 90);
	set_skill("chuanyun-tui", 100);


	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("sword", "liangyi-jian");
	map_skill("leg", "chuanyun-tui");
              map_skill("parry", "liangyi-jian");

              prepare_skill("leg", "chuanyun-tui");

        create_family("������", 4, "����");
	setup();
	carry_object(BINGQI_D("changjian"))->wield();
	carry_object("/d/kunlun/obj/pao3")->wear();
}
void attempt_apprentice(object ob)
{
        if(ob->query("gender")=="����"){
	   command("fear");
	   command("say "+RANK_D->query_respect(ob)+"ʦ����׼�����е��ӣ���ȥ����ʦ��ȥ�ɡ�");
   	   return;
	 }
         if(ob->query_skill("xuantian-wuji",1)<60){
	   command("hmm");
	   command("say "+RANK_D->query_respect(ob)+"��������޼���̫��ҿɲ������㡣");
 	   return;
	 }
	 if(ob->query("appren_hezudao", 1) == 1) {
	   command("say ǰ�����ҿ������Ц��������ɱ�������ˡ�");
	   return;
	 }
	 command("say ��Ȼ"+RANK_D->query_respect(ob)+"��ôŬ�����Ҿ�������ɡ�");
	 command("recruit " + ob->query("id"));
	 ob->set("title","�����ɵ��������");
}
