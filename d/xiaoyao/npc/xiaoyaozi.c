// xiaoyaozi.c ��ң��
// shilling 97.2

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

string ask_wyz();
void create()
{
	set_name("��ң��", ({ "xiaoyao zi", "xiaoyao","zi" }));
	set("title", "��ң�ɿ�ɽ��ʦ");
	set("long", 
		"��������ң�ɿ�ɽ��ʦ��������Ϊ��ң������һ���ڽ�����\n"
		"�����ܽ��ɣ��������ڽ����в��Ǻܶ���֪��������ʵ����\n"
		"����ȴ�ǡ���������������Ѯ��������⣬��ü�԰ס�\n");
	set("gender", "����");
	set("age", 75);
	set("class", "scholar");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 60);
	set("int", 60);
	set("con", 60);
	set("dex", 60);
	set("per", 60);
	
	set("max_qi", 15500);
	set("max_jing", 13000);
	set("neili", 33000);
	set("eff_jingli", 13000);
	set("max_neili", 33000);
	set("jingli", 13000);
	set("jiali", 200);
	set("combat_exp", 8000000);
	set("score", 200000);
	set("quest/�����˲�/�书/yuxiang",1);
	set("quest/�����˲�/�书/pass",1);

	set_skill("force", 450);
	set_skill("beiming-shengong", 450);
	set_skill("dodge", 200);
	set_skill("lingbo-weibu", 450);
	set_skill("liuyang-zhang", 450);
	set_skill("parry", 450);
	set_skill("blade", 450);
	set_skill("ruyi-dao", 450);
	set_skill("zhemei-shou", 450);
	set_skill("art", 200);
	set_skill("hand", 450);
	set_skill("literate", 300);
	set_skill("strike", 450);
	set_skill("sword", 450);
	set_skill("qingyun-shou", 450);
	set_skill("piaomiao-shenfa", 450);
	map_skill("force", "beiming-shengong");
	map_skill("dodge", "lingbo-weibu");
	map_skill("hand", "zhemei-shou");
	map_skill("hand", "zhemei-shou");
	map_skill("strike", "liuyang-zhang");
	
	map_skill("parry", "ruyi-dao");
	map_skill("blade", "ruyi-dao");

	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.wanshi" :),
                (: perform_action, "blade.ruyi" :),     
	}) );




	set("inquiry", ([

		"������" : (: ask_wyz :),
			
	]));
	create_family("��ң��", 1, "��ɽ��ʦ");
	set("class", "taoist");

	setup();
	carry_object(__DIR__"obj/blade")->wield();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("beiming-shengong", 1) < 180) {
		command("say ����ң���ڹ���ԴȪ�����ڱ�ڤ�񹦵��ķ���"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�ı�ڤ���Ƿ�Ӧ��������߰���");
		return;
	}

       
	if (ob->query_int() < 35) {
		command("say ����ң���书�����ӡ���ң�����֡�");
		command("say ����ν����ң������ֻ�ܿ����Լ�ȥ����");
		command("say ����" + RANK_D->query_respect(ob) + "�������ƺ����д���߰���");
		return;
	}
	if ((string)ob->query("gender")=="����")
   {
		command("smile");
	command("say �벻���������Ͼ�Ȼ�����˿��Լ̳��ҵ���ң�ķ���");
	command("recruit " + ob->query("id"));
    ob->set("title",HIC"��ң����ң�Ӵ���"NOR);
       return;}
   else
      {
		message_vision("����ң�ɴӲ���Ů��֮��?��\n",ob);
       return;}
	
}




string ask_wyz()
{
	object ob = this_player();
	mapping fam = ob->query("family");
	if (!fam || fam["family_name"] != "��ң��" )
		return RANK_D->query_respect(ob)+"��������������ң����������Ϊ�߾��ĵ��ӣ�ֻ�������Ҳ��֪����ȥ�����ˡ�";
        if (ob->query_skill("beiming-shengong", 1) < 300 )
	return "��λ"+ RANK_D->query_respect(ob) +"��������������ң����������Ϊ�߾��ĵ��ӣ�ֻ�������Ҳ��֪����ȥ�����ˡ�";


if(  ob->query("marks/xiaoyao") || ob->query("quest/xiaoyao/pass") || ob->query_temp("marks/xiaoyao/gotowyz"))
      return "��λ"+ RANK_D->query_respect(ob) +"���Ҳ�������ȥ�����ʦ�����𣿡�";
	
       ob->set_temp("marks/xiaoyao/gotowyz", 1);
	command("nod " + ob->query("id"));
	return "���ʦ��������ң����������Ϊ�߾��ĵ��ӣ���������ɽ�չ����У���������Ҳ�쵽�ˣ������������Щ����Ҫ��ȥ������ȥ���Ұ����һ����ɡ�";       
}
