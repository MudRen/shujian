//feng-yiming.c  ��һ��

inherit NPC;

void create()
{

        set_name("��һ��", ({ "feng yiming", "feng" }));
        set("long", "����������������ҡ�����ȣ�����Ӣ�������������书������\n");
        set("gender", "����" );
        set("age", 23);
        set("no_quest", 1);
	set("attitude", "peaceful");
	set("shen", -2000);

	set("str", 22);
        set("int", 25);
        set("con", 22);
        set("dex", 21);
        set("unique", 1);
        
	set("max_qi", 1500);
        set("max_jing", 1500);
        set("neili", 1500);
        set("max_neili", 1500);

        set("jingli",1500);
        set("eff_jingli",1500);
        set("jiali", 30);   
	set("combat_exp", 200000);

	set_skill("force",100);
        set_skill("dodge",100);
        set_skill("strike",100);
        set_skill("parry",100);
        set_skill("wuhu-duanmendao", 120);
        set_skill("qingmang-jianfa", 120);
        set_skill("cuixin-zhang", 120);

        map_skill("blade", "wuhu-duanmendao");
        map_skill("parry", "wuhu-duanmendao");
        map_skill("dodge", "qinmang-jianfa");
        map_skill("strike", "cuixin-zhang");
        prepare_skill("strike","cuixin-zhang");
	setup();

	carry_object(ARMOR_D("cloth"))->wear();
        carry_object(BINGQI_D("blade"))->wield();
}

void die()
{
	object ob,me;
	me=this_player();
	message_vision("\n$N���һ��������һ��鴤���ۿ��ǻ���ˡ�\n",this_object());
	ob = unew("/d/foshan/npc/fengtiannan");
        if(!clonep(ob)){
           destruct(this_object());
           return;
        }
        if(clonep(ob) && ob->violate_unique()){
           destruct(this_object());
           destruct(ob);
           return ;
        } 
        message_vision("\n�����ϼ��Ҵҵ����˹�����һ�ѱ����һ����ʬ�壬���������\n",this_object());
	ob->move(environment(this_object()) );
::die();
}

void unconcious()
{ 
      die();
}
