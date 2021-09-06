// xihuazi.c (kunlun)

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int ask_gold(object);

int ask_leg();

void create()
{
	set_name("������", ({ "xi huazi", "xi" }));
	set("long",
		"���������ɵ��Ĵ����ӣ�������ף�����ʮ�ֱ��ꡣ\n");
	set("gender", "����");
	set("age", 26);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 36);
	set("int", 23);
	set("con", 25);
	set("dex", 28);

	set("max_qi", 800);
	set("max_qi", 800);
	set("max_jing", 600);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 30);
	set("combat_exp", 400000);
	set("score", 1000);
	set("inquiry", ([
	//	"������" : (: ask_gold :),
              "����" : (: ask_leg :),
	]) );

	set_skill("force", 95);
	set_skill("xuantian-wuji", 105);
	set_skill("dodge", 80);
	set_skill("taxue-wuhen", 100);
	set_skill("parry", 100);
	set_skill("sword", 101);
	set_skill("liangyi-jian", 105);
	set_skill("cuff", 100);
	set_skill("zhentian-quan", 100);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("sword", "liangyi-jian");
	map_skill("cuff", "zhentian-quan");
              map_skill("parry", "liangyi-jian");

	prepare_skill("cuff", "zhentian-quan");

        create_family("������", 4, "����");
	setup();
	carry_object(BINGQI_D("changjian"))->wield();
	carry_object("/d/kunlun/obj/pao3")->wear();
}
void attempt_apprentice(object ob)
{
	if(ob->query("gender")=="Ů��"){
		command("fear");
		command("say "+RANK_D->query_respect(ob)+"ʦ����׼����Ů���ӣ���ȥ����ʦ�ȥ�ɡ�");
		return;
	}
	if(ob->query_skill("xuantian-wuji",1) < 60){
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
	ob->set("title","�����ɵ��������" );
}

int ask_gold(object who)
{
	object me = this_player();
	

	if( me->query("family/family_name") != "������" ) {
		command("hmm "+(string)me->query("id"));
		command("say ������ɵ��ӣ�Ҳ�������ĳ�����\n");
		return 1;
	}

        if( (int)me->query_skill("xuantian-wuji", 1) < 40 ) {
		command("pat "+(string)me->query("id"));
		command("say �����Ǹ�ʦ�������İ��������ҿڷ磡\n");
		return 1;
	}

	if( (int)me->query("kl_given") <(int)me->query("age")){
		 command("nod "+(string)me->query("id"));
               who->add_money("gold",(int)(me->query_skill("xuantian-wuji", 1)/2) );
               command("give "+me->query("id")+" "+(int)(me->query_skill("xuantian-wuji", 1))/2+" gold");
                me->set("kl_given",(int)me->query("age"));
	command("say "+RANK_D->query_respect(me)+"�������۹Ⱑ������ô֪����һ�����Ϊ�����Ű�������...");
	command("say �ҽ����µ���Ǯ�������Ǯׯ���Ժ�����֧�ְ���");
}
	return 1;
}
int ask_leg()
{
        object ob;
        mapping myfam;
        ob = this_player();

        myfam = (mapping)ob->query("family");
        
        if(!myfam || myfam["family_name"] != "������")
        return 0;
        if(ob->query("kl_leg")){
                command("say �㲻���Ѿ���������ô��");
                return 1;
        }
       ob->set_skill("leg",201);
       ob->set("kl_leg",1);
       write("��Ļ����ȷ�������ϣ�ף��Ϸ���!\n");
       return 1;
}


