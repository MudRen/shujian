// NPC :gaoshengtai.c ����̩
// Modify By River 98/12

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string huanggong();

void create()
{
        object ob;
        set_name("����̩", ({ "gao shengtai", "gao","shengtai" }));
        set("title", "������Ʋ����ү");
        set("gender", "����");
        set("age", 40);
        set("str", 28);
        set("dex", 20);
        set("long", "����һ�����۴�����������ӣ���縳��룬��ò���ţ�
˫�ֳ���һ֦����,���˱����˳�Ϊ���߾���ĸ���̩��\n");
        set("max_qi", 2000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("eff_jingli",1000);
        set("jiali",30);
        set("combat_exp", 500000);
        set("shen_type", 1);
        set("attitude", "friendly");
        create_family("������", 14 , "�׼ҵ���");

        set_skill("force",105);
        set_skill("sword",110);
        set_skill("cuff",90);
        set_skill("duanjia-quan",90);
        set_skill("dodge",100);
        set_skill("tianlong-xiang",90);
        set_skill("parry",110);
        set_skill("qiantian-yiyang",110);
        set_skill("duanjia-jianfa",100);
        map_skill("parry", "duanjia-jianfa");
        map_skill("dodge", "tianlong-xiang");
        map_skill("cuff","duanjia-quan");
        map_skill("force", "qiantian-yiyang");
        map_skill("sword", "duanjia-jianfa");
        prepare_skill("cuff","duanjia-quan");

        set("inquiry", ([
		"��ʹ�" : (: huanggong :),
        ]));

        set_temp("apply/attack", 70);
        set_skill("strike",90);
        set_skill("qingyan-zhang",100);
        set_temp("apply/defense", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 20);

        setup();
	if (clonep(this_object()))
	if (ob = carry_object(BINGQI_D("sword/tiedi"))) ob->wield();
	carry_object(ARMOR_D("cloth"))->wear();
}

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping fam = ob->query("family");
	if (ob->query("gender") == "Ů��"){
		command ("say ��λС�������������Ůͽ���㻹����ذɡ�");
		return;
	}
	if (ob->query("tls") && fam["family_name"]=="������" ){
		command ("say ���Ѿ��������³��ҵ����ˣ��Ҳ����������ˣ�");
		return;
	}
	if(ob->query("int") < 18){
		command("say ѧ�Ҵ���μ��书���뵨����ϸ�����ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ˣ�");
		return;
	}
	if ((int)ob->query("shen") < 0){
		command ("say  �Ҵ���������������ɣ����ҿ�" + RANK_D->query_respect(ob) +"��¶�׹⣬���ʺ����Ҵ�����ϡ�");
		return;
	}
	if ( fam && fam["generation"] == "������"){
		command("shake");
		command("say "+RANK_D->query_respect(ob)+"�Ѱ�������Ϊʦ��"+RANK_D->query_self(me)+"����������Ϊͽ��");
		return;
	}
	if( fam && fam["master_name"] == "������"){
		command("haha");
		command("say "+RANK_D->query_respect(ob)+"���ǻ�����ǰ��������"+RANK_D->query_self(me)+"����������Ϊͽ��");
		return;
	}
	command("smile");
	command("say �ܺã�" + RANK_D->query_respect(ob) + "ֻҪ��Ϊ�Ҵ�������£����ձض��������ɾ͡�");
	command("recruit " + ob->query("id") );
	ob->set("title","��������������Ҷ�");
}

void recruit_apprentice(object ob)
{
      if( ::recruit_apprentice(ob) )
      ob->set("class", "officer");
}

string huanggong()
{
        object ob=this_player();
	if (!ob->query_temp("dali_join"))
		return RANK_D->query_respect(ob) + "���㲻�Ǳ�������ӣ��˻��Ӻ�˵��";
	if (ob->query("job_time/����") + ob->query("job_time/����") < 200)
		return "�ҿ���Ϊ���������������Ļ���������Ŭ�����ɣ�";
	ob->set_temp("huanggong",1);
	return RANK_D->query_respect(ob)+"ֻҪ˵�����������ģ��Ϳ����빬�ˡ�";
}

