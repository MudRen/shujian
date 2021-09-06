// suxingh.c
// shilling 97.2
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("���Ǻ�",({"su xinghe","su"}));
	set("gender", "����" );
	set("nickname", "�ϱ�����");
	set("shen_type", 0);
	set("class", "scholar");
	set("age",60);
	set("str", 35);
	set("con", 30);
	set("int", 45);
	set("dex", 35);
	set("per", 30);

	set("no_clean_up",1);

	set("long",
"���˾��Ǻųƴϱ����˵����Ǻӣ���˵�������Ʊ磬 \n"
"��һ�������е����ߣ��������书Ҳ��������֪��\n");

	set("combat_exp", 30000000);
	set("attitude", "peaceful");
	set("chat_chance", 1);

	set("max_qi", 8000);
	set("max_jing", 8000);
	set("neili", 15000);
	set("max_neili",8000);
	set("jiali", 200);

	set_skill("force", 280);
	set_skill("dodge", 280);
	set_skill("parry", 280);
	set_skill("blade", 280);
  set_skill("qingyun-shou", 250);
	set_skill("beiming-shengong", 280);
	set_skill("ruyi-dao", 280);
	set_skill("liuyang-zhang", 280);
	set_skill("zhemei-shou", 280);
	set_skill("literate", 200);
	set_skill("piaomiao-shenfa", 280);
	set_skill("hand", 280);
	set_skill("strike", 280);
	set_skill("art", 150);
	set_skill("medicine", 180);

	map_skill("strike", "liuyang-zhang");
	map_skill("parry", "ruyi-dao");
	map_skill("blade", "ruyi-dao");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("force", "beiming-shengong");
	map_skill("hand", "zhemei-shou");
	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");	
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.wanshi" :),
                (: perform_action, "blade.ruyi" :),
           
	}) );

	create_family("��ң��", 2, "����");
	set("title","��ң�ɵڶ��������");
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/blade")->wield();
}


void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("beiming-shengong", 1) < 100) {
		command("say ����ң���ڹ���ԴȪ�����ڱ�ڤ�񹦵��ķ���"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�ı�ڤ���Ƿ�Ӧ��������߰���");
		return;
	}
if ((string)ob->query("gender")=="����")
   {
		message_vision("���ǺӴ�Ŀ��˼Ƭ��, ˵�������ð�, �Ҿ��������ˡ���\n",ob);
       command("recruit " + ob->query("id"));
       ob->set("title", "��ң�ɵ���������");
       return;}
   else
      {
		message_vision("����ң�ɴӲ���Ů��֮��?��\n",ob);
       return;}
 }

