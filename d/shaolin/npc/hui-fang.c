// Npc: /kungfu/class/shaolin/hui-kong.c
// Date: YZC 96/01/19

inherit NPC;
string ask_me();

void create()
{
	set_name("�۷�����", ({
		"huifang zunzhe",
		"huifang",
		"zunzhe",
	}));
	set("long",
		"����һλ���ް߰׵���ɮ����һϮ�಼������ġ�������Ըߣ�\n"
		"̫��Ѩ΢͹��˫Ŀ��������\n"
	);

        set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 450);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 50);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("hunyuan-yiqi", 70);
	set_skill("dodge", 70);
	set_skill("shaolin-shenfa", 70);
	set_skill("blade", 70);
	set_skill("xiuluo-dao", 70);
	set_skill("parry", 70);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("blade", "xiuluo-dao");
	map_skill("parry", "xiuluo-dao");

	create_family("������", 38, "����");
	setup();

        carry_object("/d/shaolin/obj/jiedao")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}
      
int accept_object(object who, object ob,object me)
{
        mapping fam; 
        me=this_object();
        if (!(fam = this_player()->query("family")) 
           || fam["family_name"] != "������"){
                command("hehe "+who->query("id"));
                command("say ����Ҷ�����ʲô��ͼ����");
        return 0;
        }
	if(!who->query_temp("lunzhi")){
		command("say ��������������ģ���ֵ����õ����޴�ʦ������");
		return 0;
	}
	if(ob->query("name")=="��ֵ��"){
	       	command("say �ðɣ����Ȼ�л��޴�ʦ�����ƣ�����������ͨ����һ�������ɡ�");
		who->apply_condition("sl_lunzhi",30);
		who->set_temp("lunzhied",1);
		return 1;
	}
       return 1;
}

