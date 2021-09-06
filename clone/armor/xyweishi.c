// xyweishi

inherit NPC;

void create()
{
	set_name("λʿ", ({ "wei shi", "wei", "shi" }));
	set("gender", "����");
	set("age", random(10) + 30);
	set("str", 30);
	set("dex", 30);
	set("long", "����Ӫ����ʹ��ľ�������˴󲿷ֶ����������ﾫ��ϸѡ�����ġ�\n"
                     "������ǿ��׳��һ�����գ�ü��֮����©�Ű�����\n");
	set("combat_exp", 750000);
	set("shen", 1000);
	set("attitude", "peaceful");

	set_skill("unarmed", 140);
	set_skill("force", 140);
	set_skill("sword", 140);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	set_temp("apply/attack", 500);
	set_temp("apply/defense", 500);
	set_temp("apply/armor", 500);
	set_temp("apply/damage", 500);

	set("neili", 1000);
        set("max_qi", 1200); 
        set("max_jing", 800);
        
	set("max_neili",1000);
	set("jiali", 100);
//         create_family("����Ӫ","λʿ");
         set("inquiry", ([
                "rumors" : "���������ι��е����ĺ���ƽ���ϰ��ն���֪�㰡��",
                "name" : "��ү�Ҿ�������Ӫ��λʿ���ٺ١�",
        ]) );

	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/armor/armor")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && living(this_object()) &&
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 0, ob);
	}
}
