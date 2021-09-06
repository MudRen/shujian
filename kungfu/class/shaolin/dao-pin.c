// Npc: /kungfu/class/shaolin/dao-pin.c

inherit NPC;
string ask_me();

void create()
{
	set_name("��Ʒ��ʦ", ({
		"daopin chanshi",
		"daopin",
		"chanshi",
	}));
	set("long",
		"����һλ��ĸߴ������ɮ�ˣ����۴�׳��������Բ�����ֱֳ�\n"
		"�У���һϮ�Ҳ�������ģ��ƺ���һ�����ա�\n"
	);


	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);
	set("str", 25);
	set("int", 18);
	set("con", 20);
	set("dex", 23);
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 450);
	set("max_neili", 450);
	set("jiali", 40);
	set("combat_exp",80000);
	set("score", 100);

	set_skill("force", 50);
	set_skill("yijin-jing", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("finger", 51);
	set_skill("mohe-zhi", 51);
	set_skill("blade", 54);
	set_skill("xiuluo-dao", 54);
	set_skill("parry", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "mohe-zhi");
	map_skill("blade", "xiuluo-dao");
	map_skill("parry", "xiuluo-dao");

	prepare_skill("finger", "mohe-zhi");

	create_family("������", 39, "����");
        set("inquiry", ([
            "���ֵ���" : (: ask_me :),
               	]));
        set("chandao_count",1);
	setup();

        carry_object("/d/shaolin/obj/jiedao")->wield();
        carry_object("/d/shaolin/obj/dao-cloth")->wear();
}

#include "/kungfu/class/shaolin/dao.h"

string ask_me()
{
 object ob;
 mapping fam;
 if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
 return RANK_D->query_respect(this_player()) + 
        	"�뱾��������������֪�˻��Ӻ�̸��";
       if (query("chandao_count") < 1)  
           return "�������ˣ��Ǳ������Ѿ��������ˡ�\n";
       ob=new("/d/shaolin/npc/obj/book-chandao");
       ob->move(this_player());
       add("chandao_count", -1);
       message_vision("��Ʒ�ӻ����ͳ�һ����������ݸ�$N��\n",this_player());
       return "�������ҷ��ŵ�����������Ҫ�ú��о���";
}        
